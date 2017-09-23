/**
 * AI.cpp
 *
 * description: AI Base class
 */

#include "AI.h"

AI::AI()
{

}

void AI::addKnownUnit(spUnit new_unit)
{
	known_units.insert(std::pair<int, spUnit>(target_id, target));
}

void AI::addFriendlyUnit(spUnit new_unit)
{
	friendly_units.insert(std::pair<int, spUnit>(target_id, target));
}

void AI::addEnemyUnit(spUnit new_unit)
{
	enemy_units.insert(std::pair<int, spUnit>(target_id, target));
}
