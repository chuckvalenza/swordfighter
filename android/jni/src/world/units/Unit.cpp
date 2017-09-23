/**
 * Unit.cpp
 *
 * Description: Abstract base class for units
 */

#include "world/World.h"
#include "world/units/Unit.h"

Unit::Unit()
{

}

Unit::~Unit()
{
	if (view) {
		view->detach();
	}
}

void Unit::init()
{
	Rigid::init();
}

bool Unit::hasMoved()
{
	return moved;
}

void Unit::unsetMoved()
{
	moved = false;
}

bool Unit::hasAttacked()
{
	if (atk_state == ATTACKING) {
		return true;
	}

	return false;
}

float Unit::takeDamage(float damage, spAttack en_atk)
{
	health -= damage;

	if (health < 0) {
		health = 0;
	}

	recent_threat = en_atk;
	recent_threat_id = en_atk->getPerpId();

	return health;
}

float Unit::getHealth()
{
	return health;
}

spAttack Unit::getAttack()
{
	return atk;
}

void Unit::setWorld(World* w)
{
	world = w;
}

World* Unit::getWorld()
{
	return world;
}