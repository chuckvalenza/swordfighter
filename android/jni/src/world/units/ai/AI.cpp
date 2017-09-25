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
	known_units.insert(std::pair<int, spUnit>(new_unit->id(), new_unit));
}

void AI::addFriendlyUnit(spUnit new_unit)
{
	friendly_units.insert(std::pair<int, spUnit>(new_unit->id(), new_unit));
}

void AI::addEnemyUnit(spUnit new_unit)
{
	enemy_units.insert(std::pair<int, spUnit>(new_unit->id(), new_unit));
}
