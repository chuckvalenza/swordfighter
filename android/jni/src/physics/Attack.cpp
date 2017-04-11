/**
 * Attack.cpp
 *
 * Description: Object for attack collision. Tracks location, radius, and damage
 *	of an attack event.
 */

#include "physics/Attack.h"
#include "core_components/res.h"

Attack::Attack()
{

}

Attack::~Attack()
{

}

void Attack::init()
{
	WorldObj::init();
}

void Attack::init(float c_bounds, float dmg)
{
	WorldObj::init();
	view = new Sprite;
	damage = dmg;
	collision_bounds = c_bounds;
}

float Attack::getDamage()
{
	return damage;
}

float Attack::getCBounds()
{
	return collision_bounds;// * scale_multiplier;
}

void Attack::redraw()
{

}

void Attack::update(const UpdateState&)
{

}
