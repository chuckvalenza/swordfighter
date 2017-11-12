/**
 * Player.cpp
 *
 * Description: Class for the player character
 */

#include "world/units/Player.h"
#include <math.h>

#define COLLISION_BOUNDS 57.5f
#define PLAYER_ATK_RADIUS 125;
#define ATK_PENALTY 0.7f

Player::Player()
{
	move_state = new UnitStateMachine<Player>(this);
	move_state->setCurrentUnitState(PlayerStand::Instance());

	rh_state = new UnitStateMachine<Player>(this);
	rh_state->setCurrentUnitState(PlayerPassive::Instance());

	lh_state = new UnitStateMachine<Player>(this);
	lh_state->setCurrentUnitState(PlayerPassive::Instance());

	atk_anim_running = false;
}

void Player::init()
{
	obj_id = 0;
	health = prev_health = 100;

	collision_bounds = COLLISION_BOUNDS;

	view = new Sprite;
	view->setAnchor(0.5f, 0.62f);

	chestpiece = new EmptyTorso;
	torso = new Sprite;
	torso->attachTo(view);
	setChestpiece(chestpiece);

	rh_item = new Fist;
	right_hand = new Sprite;
	right_hand->attachTo(view);
	setRHItem(rh_item);

	headgear = new EmptyHead;
	head = new Sprite;
	head->attachTo(view);
	setHeadgear(headgear);

	view->setSize(torso->getSize());

	atk_type = Wieldable::ItemType::NONE;
	atk_anim_start_time = std::chrono::milliseconds(-100000);

	atk_radius = PLAYER_ATK_RADIUS;

	moved = false;
	atk_state = Unit::AttackState::NOT_ATTACKING;
}

void Player::setHeadgear(spWearable new_item)
{
	headgear = new_item;
	std::string str = headgear->equippedStr();
	head->removeTweens();
	head->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
}

void Player::setChestpiece(spWearable new_item)
{
	chestpiece = new_item;
	std::string str = chestpiece->equippedStr();
	torso->removeTweens();
	torso->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
}

void Player::setRHItem(spWieldable new_item)
{
	rh_item = new_item;
	std::string str = rh_item->equippedStr() + "-rh";
	right_hand->removeTweens();
	right_hand->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
}

void Player::setLHItem(spWieldable new_item)
{
	lh_item = new_item;
	std::string str = lh_item->equippedStr() + "-lh";
	left_hand->removeTweens();
	left_hand->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
}

void Player::setPants(spWearable new_item)
{
	pants = new_item;
	std::string str = pants->equippedStr();
	legs->removeTweens();
	legs->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
}

spAttack Player::attack(float angle)
{
	// determine what type of attack will be down based on what we are wielding
	if (rh_item->item_type == Wieldable::ItemType::SLASH) {
		atk_type = Wieldable::ItemType::SLASH;
	} else if (rh_item->item_type == Wieldable::ItemType::PUNCH) {
		atk_type = Wieldable::ItemType::PUNCH;
	}

	// rotate character in direction of attack, then change angle for other
	// calculations
	view->setRotation(angle);
	angle -= M_PI / 2;

	// set up time (ms) variables:
	//   - ms = milliseconds of attack animation
	//   - animation time of current attack, and
	//   - current time
	//   - time since we last started an attack animation
	using namespace std::chrono;
	int ms = 300;
	milliseconds a_time = milliseconds(ms);
	milliseconds cur_time = duration_cast<milliseconds>
		(system_clock::now().time_since_epoch());
	milliseconds time_since_start = cur_time - atk_anim_start_time;

	// conditions to start animation:
	//			have not attacked yet -OR- last time we attacked was over animation time
	//			atk_anim_running is false
	// actions:
	// 			1. atk_create_state -> not attacking
	// 			2. atk_anim_start_time (re)starts
	//			3. anim_running -> true
	if ((atk_state == Unit::AttackState::NOT_ATTACKING
		||  time_since_start > a_time) && !atk_anim_running) {
		atk_state = Unit::AttackState::NOT_ATTACKING;
		atk_anim_start_time = duration_cast<milliseconds>
			(system_clock::now().time_since_epoch());
		atk_anim_running = true;


	// conditions to create, remove, stop:
	// 			time since start is greater than 150ms
	// 			atk_anim_running == true
	} else if (time_since_start > a_time / 2 && atk_anim_running) {
		// conditions to create attack:
		//			atk_state == NOT
		// actions:
		// 			1. create attack object
		// 			2. atk_create_state -> is attacking
		if (atk_state == Unit::AttackState::NOT_ATTACKING) {
			atk = new Attack();
			float x_offset = (atk_radius + rh_item->getSize()) * cos(angle);
			float y_offset = (atk_radius + rh_item->getSize()) * sin(angle);
			atk->init(world_coords, obj_id, rh_item->getSize(), rh_item->getDamage());
			atk->setX(getWorldX() + x_offset);
			atk->setY(getWorldY() + y_offset);
			atk_state = Unit::AttackState::IS_ATTACKING;

		// conditions to remove attack:
		//			atk_state == IS
		// actions:
		// 			1. atk_create_state -> has attacking
		//			2. (deleting attack will be taken care of by world)
		} else if (atk_state == Unit::AttackState::IS_ATTACKING) {
			atk_state = Unit::AttackState::HAS_ATTACKED;

		// conditions to stop animation:
		// 			time since start is greater than 300ms
		//			atk_state == HAS
		// actions:
		// 			1. atk_anim_running -> false
		//			2. atk_state -> NOT
		} else if (time_since_start > a_time && atk_state == Unit::AttackState::HAS_ATTACKED) {
			atk_state = Unit::AttackState::NOT_ATTACKING;
			atk_anim_running = false;
		}
	}

	return atk;
}

void Player::stopAttack()
{
	atk_type = Wieldable::ItemType::NONE;
	atk_state = Unit::AttackState::NOT_ATTACKING;
	move(view->getRotation());
}

void Player::move(float angle)
{
	moved = true;

	if (atk_type == Wieldable::ItemType::NONE) {
		view->setRotation(angle);
	}
}

void Player::animStand()
{

}

void Player::animMove()
{

}

void Player::animUseRH()
{
	using namespace std::chrono;
	atk_anim_duration = 300;
	milliseconds a_time = milliseconds(atk_anim_duration);
	milliseconds cur_time = duration_cast<milliseconds>
			(system_clock::now().time_since_epoch());
	milliseconds time_since_start = cur_time - atk_anim_start_time;

	if ((atk_state == Unit::AttackState::NOT_ATTACKING
		||  time_since_start > a_time) && !atk_anim_running) {
		if (atk_type == Wieldable::ItemType::SLASH) {
			std::string chestpiece_str = chestpiece->equippedStr();
			torso->addTween(TweenAnim(res::r.getResAnim(chestpiece_str), 5, 8), atk_anim_duration);

			std::string rhi_str = rh_item->equippedStr() + "-rh";
			right_hand->addTween(TweenAnim(res::r.getResAnim(rhi_str), 1, 4), atk_anim_duration);
		} else if (atk_type == Wieldable::ItemType::PUNCH) {
			std::string chestpiece_str = chestpiece->equippedStr();
			torso->addTween(TweenAnim(res::r.getResAnim(chestpiece_str), 1, 4), atk_anim_duration);

			std::string rhi_str = rh_item->equippedStr() + "-rh";
			right_hand->addTween(TweenAnim(res::r.getResAnim(rhi_str), 1, 4), atk_anim_duration);
		}
	}
}

void Player::animUseLH()
{

}

float Player::getMoveMultiplier()
{
	if(atk_type == Wieldable::ItemType::NONE) {
		return 1.0f;
	}

	return ATK_PENALTY;
}

spWieldable Player::getRHItem()
{
	return rh_item;
}

spWieldable Player::getLHItem()
{
	return lh_item;
}

long Player::getAnimUseRHTimer()
{
	using namespace std::chrono;
	milliseconds cur_time = duration_cast<milliseconds>
			(system_clock::now().time_since_epoch());
	milliseconds time_since_start = cur_time - atk_anim_start_time;
	return time_since_start.count();
}

UnitStateMachine<Player>* Player::getMoveState()
{
	return move_state;
}

UnitStateMachine<Player>* Player::getRHState()
{
	return rh_state;
}

UnitStateMachine<Player>* Player::getLHState()
{
	return lh_state;
}

void Player::redraw()
{
	if (getWorldCoords() != next_pos) {
		setWorldCoords(next_pos);
	}

	if (atk_type == Wieldable::ItemType::NONE) {
		timeMS ms = 1;
		std::string chestpiece_str = chestpiece->equippedStr();
		torso->addTween(TweenAnim(res::r.getResAnim(chestpiece_str), 0, 0), ms);

		std::string rhi_str = rh_item->equippedStr() + "-rh";
		right_hand->addTween(TweenAnim(res::r.getResAnim(rhi_str), 0, 0), ms);
	}
}

void Player::update(const UpdateState& us)
{
	move_state->update();
	rh_state->update();
	lh_state->update();
}
