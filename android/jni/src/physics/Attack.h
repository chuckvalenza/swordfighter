/**
 * Attack.h
 *
 * Description: Object for attack collision. Tracks location, radius, and damage
 *	of an attack event.
 */

#ifndef SWORD_FIGHTER_ATTACK_H
#define SWORD_FIGHTER_ATTACK_H

#include "oxygine-framework.h"

#include "world/WorldObj.h"

using namespace oxygine;

DECLARE_SMART(Attack, spAttack);

class Attack : public WorldObj {
	private:
		float damage;
		float collision_bounds;
		int perp_id;
		Vector2 perp_loc; // actor who created this attack
	public:
		Attack();
		~Attack();

		void init();
		void redraw();
		void update(const UpdateState&);

		void init(Vector2, int, float, float);
		float getCBounds();
		float getDamage();
		int getPerpId();
		Vector2 getPerpLoc();
};

#endif //SWORD_FIGHTER_ATTACK_H
