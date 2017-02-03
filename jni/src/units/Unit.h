/**
 * Unit.h
 *
 * Description: Abstract base class for units
 */

#ifndef SWORD_FIGHTER_UNIT_H
#define SWORD_FIGHTER_UNIT_H

#include "oxygine-framework.h"

#include "core_components/DrawableObj.h"

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class Unit : public DrawableObj {
	protected:
		spSprite head;
		spSprite torso;
		spSprite legs;
	public:
		Unit();
		virtual void init();
		virtual void attack(float) = 0;
		virtual void move(float) = 0;
		virtual void stopAttack() = 0;
		virtual float getMoveMultiplier() = 0;
		virtual void update(const UpdateState& us) {}
};

#endif //SWORD_FIGHTER_UNIT_H
