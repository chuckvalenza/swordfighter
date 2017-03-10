/**
 * Unit.h
 *
 * Description: Abstract base class for units
 */

#ifndef SWORD_FIGHTER_UNIT_H
#define SWORD_FIGHTER_UNIT_H

#include "oxygine-framework.h"

#include "physics/Rigid.h"
#include <map>

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class Unit : public Rigid {
	protected:
		bool moved;

		spSprite head;
		spSprite torso;
		spSprite legs;

		std::vector<spUnit>* collision_set;
	public:
		Unit();

		virtual void init();
		virtual void attack(float) = 0;
		virtual void move(float) = 0;
		virtual void stopAttack() = 0;
		virtual float getMoveMultiplier() = 0;
		virtual void redraw() {};
		virtual void update(const UpdateState& us) {}

		bool hasMoved();
		void unsetMoved();
};

#endif //SWORD_FIGHTER_UNIT_H
