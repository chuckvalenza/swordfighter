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
	atk_anim_timer = std::chrono::milliseconds(0);

	atk_radius = PLAYER_ATK_RADIUS;

	moved = false;
	attacked = false;
	atk_state = NOT_ATTACKED;
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
	if (rh_item->item_type == Wieldable::ItemType::SLASH) {
		atk_type = Wieldable::ItemType::SLASH;
	} else if (rh_item->item_type == Wieldable::ItemType::PUNCH) {
		atk_type = Wieldable::ItemType::PUNCH;
	}

	view->setRotation(angle);

	angle -= M_PI / 2;

	using namespace std::chrono;
	int ms = 300;

	milliseconds cur_time = duration_cast<milliseconds>
		(system_clock::now().time_since_epoch());

	if (cur_time - atk_anim_timer > milliseconds(ms)) {
		atk_state = NOT_ATTACKED;
		attacked = false;
		if (atk_type == Wieldable::ItemType::SLASH) {
			std::string chestpiece_str = chestpiece->equippedStr();
			torso->addTween(TweenAnim(res::r.getResAnim(chestpiece_str), 5, 8), ms);

			std::string rhi_str = rh_item->equippedStr() + "-rh";
			right_hand->addTween(TweenAnim(res::r.getResAnim(rhi_str), 1, 4), ms);
		} else if (atk_type == Wieldable::ItemType::PUNCH) {
			std::string chestpiece_str = chestpiece->equippedStr();
			torso->addTween(TweenAnim(res::r.getResAnim(chestpiece_str), 1, 4), ms);

			std::string rhi_str = rh_item->equippedStr() + "-rh";
			right_hand->addTween(TweenAnim(res::r.getResAnim(rhi_str), 1, 4), ms);
		}

		atk_anim_timer = cur_time;
	} else if (cur_time - atk_anim_timer + milliseconds(ms) / 2 > milliseconds(ms)
		&& !attacked) {
		atk_state = ATTACKING;
		attacked = true;
		atk = new Attack();
		float x_offset = (atk_radius + rh_item->getSize()) * cos(angle);
		float y_offset = (atk_radius + rh_item->getSize()) * sin(angle);
		atk->init(world_coords, obj_id, rh_item->getSize(), rh_item->getDamage());
		atk->setX(getWorldX() + x_offset);
		atk->setY(getWorldY() + y_offset);
	} else if (atk_state == ATTACKING) {
		atk_state = ATTACKED;
	} else if (atk_state == ATTACKED) {
		atk = NULL;
	}

	return atk;
}

void Player::stopAttack()
{
	atk_type = Wieldable::ItemType::NONE;
	attacked = false;
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

float Player::getMoveMultiplier()
{
	if(atk_type == Wieldable::ItemType::NONE) {
		return 1.0f;
	}

	return ATK_PENALTY;
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

}
