//
// Created by cvalenza on 8/6/17.
//

#ifndef SWORD_FIGHTER_AI_H
#define SWORD_FIGHTER_AI_H

#include "oxygine-framework.h"
#include "world/units/Unit.h"

DECLARE_SMART(AI, spAI);

class AI : public Unit {
	protected:
		std::map<int, spUnit> known_units;
		std::map<int, spUnit> friendly_units;
		std::map<int, spUnit> enemy_units;
		spUnit target;
		int target_id;
	public:
		AI();

		virtual void makeDecision() = 0;
};

#endif //SWORD_FIGHTER_AI_H
