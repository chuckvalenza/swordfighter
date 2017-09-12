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

void Attack::init(Vector2 perp_location, int perp_id_num, float c_bounds, float dmg)
{
	WorldObj::init();
	view = new Sprite;
	perp_loc = perp_location;
	perp_id = perp_id_num;
	collision_bounds = c_bounds;
	damage = dmg;
}

float Attack::getDamage()
{
	return damage;
}

float Attack::getCBounds()
{
	return collision_bounds;// * scale_multiplier;
}

int Attack::getPerpId()
{
	return perp_id;
}

Vector2 Attack::getPerpLoc()
{
	return perp_loc;
}

void Attack::redraw()
{

}

void Attack::update(const UpdateState&)
{

}
