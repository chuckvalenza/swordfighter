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
	public:
		AI();

		void moveToWaypoint(Vector2);
		void addKnownUnit(spUnit);
		void addFriendlyUnit(spUnit);
		void addEnemyUnit(spUnit);
};

#endif //SWORD_FIGHTER_AI_H
