/**
 * Player.cpp
 *
 * Description: Class for the player character
 */

#include "Player.h"

#define COLLISION_BOUNDS 57.5f

Player::Player()
{

}

void Player::init()
{
	unit_id = 0;

	view = new Sprite;
	view->setAnchor(0.5f, 0.62f);

	headgear = new Wearable;
	headgear->init("empty", Item::WEARABLE);
	std::string headgear_str = headgear->equippedStr() + "-legs";

	rh_item = new Wieldable;
	rh_item->init("raw_sword", Item::WIELDABLE);
	std::string rhi_str = rh_item->equippedStr() + "-rh";

	chestpiece = new Wearable;
	chestpiece->init("empty", Item::WEARABLE);
	std::string chestpiece_str = chestpiece->equippedStr() + "-torso";

	pants = new Wearable;
	pants->init("empty", Item::WEARABLE);
	std::string pants_str = pants->equippedStr() + "-head";

	head = new Sprite;
	head->addTween(TweenAnim(res::r.getResAnim(headgear_str), 0, 0), 1);
	head->attachTo(view);

	right_hand = new Sprite;
	right_hand->addTween(TweenAnim(res::r.getResAnim(rhi_str), 0, 0), 1);
	right_hand->attachTo(view);

	torso = new Sprite;
	torso->addTween(TweenAnim(res::r.getResAnim(chestpiece_str), 0, 0), 1);
	torso->attachTo(view);
	view->setSize(torso->getSize());

	legs = new Sprite;
	legs->addTween(TweenAnim(res::r.getResAnim(pants_str), 0, 0), 1);
	legs->attachTo(view);

	atk_type = NONE;
	atk_anim_timer = std::chrono::milliseconds(0);

	moved = false;
}

void Player::setHeadgear(spWearable new_item)
{
	headgear = new_item;
	std::string str = headgear->equippedStr();
	head->setResAnim(res::r.getResAnim(str));
	head->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
}

void Player::setTorso(spWearable new_item)
{
	chestpiece = new_item;
	std::string str = chestpiece->equippedStr();
	torso->setResAnim(res::r.getResAnim(str));
	torso->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
}

void Player::setRHItem(spWieldable new_item)
{
	rh_item = new_item;
	std::string str = rh_item->equippedStr();
	right_hand->setResAnim(res::r.getResAnim(str));
	right_hand->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
}

void Player::attackAnim(int ms)
{
	using namespace std::chrono;
	milliseconds cur_time = duration_cast<milliseconds>
		(system_clock::now().time_since_epoch());

	if (cur_time - atk_anim_timer > milliseconds(ms)) {
		if (atk_type == SWING) {
			std::string chestpiece_str = chestpiece->equippedStr() + "-torso";
			torso->addTween(TweenAnim(res::r.getResAnim(chestpiece_str), 1, 4), ms);

			std::string rhi_str = rh_item->equippedStr() + "-rh";
			right_hand->addTween(TweenAnim(res::r.getResAnim(rhi_str), 1, 4), ms);
		}

		atk_anim_timer = cur_time;
	}
}

void Player::attack(float angle)
{
	if (rh_item->item_type == Wieldable::ItemType::SLASH) {
		atk_type = SWING;
	}

	view->setRotation(angle);
	attackAnim(300);
}

void Player::stopAttack()
{
	atk_type = NONE;
	move(view->getRotation());
}

void Player::move(float angle)
{
	timeMS ms = 1;

	moved = true;

	if (atk_type == NONE) {
		view->setRotation(angle);

		std::string chestpiece_str = chestpiece->equippedStr() + "-torso";
		torso->removeTweens();
		torso->addTween(TweenAnim(res::r.getResAnim(chestpiece_str), 0, 0), ms);

		std::string rhi_str = rh_item->equippedStr() + "-rh";
		right_hand->removeTweens();
		right_hand->addTween(TweenAnim(res::r.getResAnim(rhi_str), 0, 0), ms);
	}
}

float Player::getMoveMultiplier()
{
	if(atk_type == NONE) {
		return 1.0f;
	}

	return ATK_PENALTY;
}

float Player::getCBounds()
{
	return COLLISION_BOUNDS;// * scale_multiplier;
}

void Player::redraw()
{
	if (getWorldCoords() != next_pos) {
		setWorldCoords(next_pos);
	}
}

void Player::update(const UpdateState& us)
{
}
