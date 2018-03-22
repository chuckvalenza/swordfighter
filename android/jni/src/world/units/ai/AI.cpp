/**
 * AI.cpp
 *
 * description: AI Base class
 */

#include "AI.h"

AI::AI()
{

}

void AI::moveToWaypoint(Vector2 waypoint)
{
	Vector2 dir = waypoint - world_coords;
	float angle = atan2f(dir.y, dir.x);

	if (angle >= -3 && angle <= 1.5) {
		angle += M_PI / 2;
	} else {
		angle -= 1.5f * M_PI;
	}

	angle -= M_PI;
	setRotation(angle);

	float penalty = getMoveMultiplier();// * world->getMoveMultiplier(pos);

	Vector2 pos = getPosition();
	dir.normalize();
	pos += dir * penalty * 2.0f;
	setNextPosition(pos);
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
