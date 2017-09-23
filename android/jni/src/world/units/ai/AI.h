/**
 * AI.h
 *
 * description: AI Base class
 */

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

		void addKnownUnit(spUnit new_unit);
		void addFriendlyUnit(spUnit new_unit);
		void addEnemyUnit(spUnit new_unit);
};

#endif //SWORD_FIGHTER_AI_H
