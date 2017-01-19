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
	rh_item->init("empty", Item::WIELDABLE);
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

	state = STANDING;
}

void Player::setTorso(spWearable new_item)
{
	chestpiece = new_item;
	std::string str = chestpiece->equippedStr();
	torso->setResAnim(res::r.getResAnim(str));
	torso->addTween(TweenAnim(res::r.getResAnim(str), 0, 0), 1);
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
