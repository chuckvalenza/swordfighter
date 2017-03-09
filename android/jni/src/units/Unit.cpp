/**
 * Unit.cpp
 *
 * Description: Abstract base class for units
 */

#include "units/Unit.h"

Unit::Unit()
{

}

int Unit::id()
{
	return unit_id;
}

void Unit::init()
{
	static int id_counter = 0;
	unit_id = ++id_counter;
}

float Unit::getWorldX()
{
	return world_coords.x;
}

float Unit::getWorldY()
{
	return world_coords.y;
}

void Unit::setX(float x)
{
	world_coords.x = x;
	DrawableObj::setX(x);
}

void Unit::setY(float y)
{
	world_coords.y = y;
	DrawableObj::setY(y);
}

void Unit::setPosition(Vector2 v)
{
	world_coords = v;
	DrawableObj::setPosition(v);
}

void Unit::setWorldCoords(Vector2 v)
{
	prev_coords = world_coords;
	world_coords = v;
}

bool Unit::hasMoved()
{
	return moved;
}

void Unit::unsetMoved()
{
	moved = false;
}


Vector2 Unit::getWorldCoords()
{
	return world_coords;
}
