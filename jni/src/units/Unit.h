/**
 * Unit.h
 *
 * Description: Abstract base class for units
 */

#ifndef SWORD_FIGHTER_UNIT_H
#define SWORD_FIGHTER_UNIT_H

#include "oxygine-framework.h"

using namespace oxygine;

class Unit : public Object {
	protected:
		spSprite view;
	public:
		Unit();
		virtual void init();
		virtual void update(const UpdateState& us) {}
};

#endif //SWORD_FIGHTER_UNIT_H
