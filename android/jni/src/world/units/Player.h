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
#include "world/units/PlayerStates.h"
#include "world/units/UnitStateMachine.h"

using namespace oxygine;

class Player : public Unit {
	private:
		spWieldable rh_item;
		spWieldable lh_item;
		spWearable headgear;
		spWearable chestpiece;
		spWearable pants;

		void attackAnim(timeMS);
		void createAttack(float, timeMS);

		UnitStateMachine<Player>* move_state;
		UnitStateMachine<Player>* rh_state;
		UnitStateMachine<Player>* lh_state;
	public:
		bool moving;

		Wieldable::ItemType atk_type;

		Player();

		void animUseRH();
		void animUseLH();
		void swingAnimation(timeMS);

		void setHeadgear(spWearable);
		void setChestpiece(spWearable);
		void setRHItem(spWieldable);
		void setLHItem(spWieldable);
		void setPants(spWearable);

		UnitStateMachine<Player>* getMoveState();
		UnitStateMachine<Player>* getRHState();
		UnitStateMachine<Player>* getLHState();

		// inherited functions
		void init();
		spAttack attack(float);
		void move(float);
		void animStand();
		void animMove();
		void stopAttack();
		float getMoveMultiplier();
		void redraw();
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_PLAYER_H
