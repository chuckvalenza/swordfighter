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

class Unit : public DrawableObj {
	protected:
	public:
		Unit();
		virtual void init();
		virtual void update(const UpdateState& us) {}
};

#endif //SWORD_FIGHTER_UNIT_H
