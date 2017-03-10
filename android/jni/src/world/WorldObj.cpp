/**
 * WorldObj.cpp
 *
 * Description: Objects which reside in the world
 */

#include "world/WorldObj.h"

void WorldObj::init()
{
	static int id_counter = 0;
	obj_id = ++id_counter;
}

int WorldObj::id()
{
	return obj_id;
}

void WorldObj::setX(float x)
{
	world_coords.x = x;
	DrawableObj::setX(x);
}

void WorldObj::setY(float y)
{
	world_coords.y = y;
	DrawableObj::setY(y);
}

void WorldObj::setPosition(Vector2 v)
{
	world_coords = v;
	DrawableObj::setPosition(v);
}

void WorldObj::setWorldCoords(Vector2 v)
{
	prev_coords = world_coords;
	world_coords = v;
}

float WorldObj::getWorldX()
{
	return world_coords.x;
}

float WorldObj::getWorldY()
{
	return world_coords.y;
}

Vector2 WorldObj::getWorldCoords()
{
	return world_coords;
}
