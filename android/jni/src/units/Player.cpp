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

	chestpiece = new EmptyTorso;
	torso = new Sprite;
	torso->attachTo(view);
	setTorso(chestpiece);

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

	moved = false;
}

void Player::setHeadgear(spWearable new_item)
{
	headgear = new_item;
	std::string str = headgear->equippedStr();
	head->removeTweens();
	head->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
}

void Player::setTorso(spWearable new_item)
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

void Player::attackAnim(int ms)
{
	using namespace std::chrono;
	milliseconds cur_time = duration_cast<milliseconds>
		(system_clock::now().time_since_epoch());

	if (cur_time - atk_anim_timer > milliseconds(ms)) {
		if (atk_type == Wieldable::ItemType::SLASH) {
			std::string chestpiece_str = chestpiece->equippedStr();
			torso->addTween(TweenAnim(res::r.getResAnim(chestpiece_str), 1, 4), ms);

			std::string rhi_str = rh_item->equippedStr() + "-rh";
			right_hand->addTween(TweenAnim(res::r.getResAnim(rhi_str), 1, 4), ms);
		} else if (atk_type == Wieldable::ItemType::PUNCH) {
			std::string chestpiece_str = chestpiece->equippedStr();
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
		atk_type = Wieldable::ItemType::SLASH;
	} else if (rh_item->item_type == Wieldable::ItemType::PUNCH) {
		atk_type = Wieldable::ItemType::PUNCH;
	}

	view->setRotation(angle);
	attackAnim(300);
}

void Player::stopAttack()
{
	atk_type = Wieldable::ItemType::NONE;
	move(view->getRotation());
}

void Player::move(float angle)
{
	moved = true;

	if (atk_type == Wieldable::ItemType::NONE) {
		view->setRotation(angle);
	}
}

float Player::getMoveMultiplier()
{
	if(atk_type == Wieldable::ItemType::NONE) {
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
