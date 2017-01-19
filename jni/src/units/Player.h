/**
 * Player.h
 *
 * Description: Class for the player character
 */

#ifndef SWORD_FIGHTER_PLAYER_H
#define SWORD_FIGHTER_PLAYER_H

#include "oxygine-framework.h"

#include "core_components/Game.h"
#include "units/Unit.h"
#include "items/Wearable.h"
#include "items/Wieldable.h"
#include <chrono>

using namespace oxygine;

class Player : public Unit {
	private:
		spWieldable rh_item;
		spWieldable lh_item;
		spWearable headgear;
		spWearable chestpiece;
		spWearable pants;

		spSprite left_hand;
		spSprite right_hand;
		spSprite head;
		spSprite torso;
		spSprite legs;
	public:
		enum PlayerState {
			ATTACKING,
			BLOCKING,
			STANDING,
			MOVING
		};

		PlayerState state;

		Player();
		void init();
		void setTorso(spWearable);
/*
		void setRHItem(spWieldable);
		void setLHItem(spWieldable);
		void setHeadgear(spWearable);
		void setPants(spWearable);
		void setDir();
		void attack();
		void move(timeMS);
		void changeAnim(std::string, int);
*/
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_PLAYER_H
