/**
 * Player.cpp
 *
 * Description: Class for the player character
 */

#include "Player.h"

Player::Player()
{

}

void Player::init()
{
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

void Player::update(const UpdateState& us)
{
/*
	std::string torso_str = torso->equippedStr() + "-torso";
	//std::string rhi_str = rh_item->equippedStr() + "-rh";

	int ms = 1;

	if (state == STANDING) {
		torso->addTween(torso_str, 0, 0, ms);
		//rh_item->addTween(TweenAnim(res::r.getResAnim(rhi_str), 0, 0), ms);
	} else if (state == ATTACKING) {
		ms = 300;
		torso->addTween(torso_str, 1, 4, ms);
		//rm_item->addTween(TweenAnim(res::r.getResAnim(rhi_str), 1, 4), ms);
	}
*/
}
