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

#define ATK_PENALTY 0.7f

class Player : public Unit {
	private:
		std::chrono::milliseconds atk_anim_timer;

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

		void attackAnim(timeMS ms);
	public:
		bool moving;
		enum AttackType {
			SWING,
			RANGE,
			PUNCH,
			NONE
		};

		AttackType atk_type;

		Player();
		void init();
		void setHeadgear(spWearable);
		void setTorso(spWearable);
		void setRHItem(spWieldable);
		void attack(float);
		void move(float);
		void swingAnimation(timeMS);
		void stopAttack();
		float getMoveMultiplier();
/*
		void setLHItem(spWieldable);
		void setPants(spWearable);
*/
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_PLAYER_H
