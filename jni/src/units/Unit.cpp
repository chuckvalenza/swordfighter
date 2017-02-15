/**
 * Unit.cpp
 *
 * Description: Abstract base class for units
 */

#include "units/Unit.h"

Unit::Unit()
{

}

void Unit::init(std::vector<spUnit>*)
{

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

void Unit::undoMove()
{
	world_coords = prev_coords;
}

Vector2 Unit::getWorldCoords()
{
	return world_coords;
}
