/**
 * Player.h
 *
 * Description: Class for the player character
 */

#ifndef SWORD_FIGHTER_PLAYER_H
#define SWORD_FIGHTER_PLAYER_H

#include "oxygine-framework.h"

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
		void attack(float);
		void move(float);
		void stopAttack();
		float getMoveMultiplier();
		float getCBounds();
		void redraw();
		void update(const UpdateState&);

		void setHeadgear(spWearable);
		void setTorso(spWearable);
		void setRHItem(spWieldable);
		void swingAnimation(timeMS);
/*
		void setLHItem(spWieldable);
		void setPants(spWearable);
*/
};

#endif //SWORD_FIGHTER_PLAYER_H
