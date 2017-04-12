/**
 * Player.h
 *
 * Description: Class for the player character
 */

#ifndef SWORD_FIGHTER_PLAYER_H
#define SWORD_FIGHTER_PLAYER_H

#include "oxygine-framework.h"

#include "world/units/Unit.h"
#include "world/items/items.h"
#include "world/items/Wearable.h"
#include "world/items/Wieldable.h"
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

		void attackAnim(timeMS);
		void createAttack(float, timeMS);
	public:
		bool moving;

		Wieldable::ItemType atk_type;

		Player();
		void init();
		spAttack attack(float);
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
