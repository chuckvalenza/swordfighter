/**
 * Wieldable.cpp
 *
 * Description: Wieldable class of objects
 */

#include "world/items/Wieldable.h"

Wieldable::Wieldable()
{

}

float Wieldable::getDamage()
{
	return damage;
}

float Wieldable::getSize()
{
	return atk_size;
}

void Wieldable::setDamage(float d)
{
	damage = d;
}

int Wieldable::getItemType()
{
	return item_type;
}

void Wieldable::setItemType(ItemType t)
{
	item_type = t;
}

std::string Wieldable::menuStr()
{
	return menu_model;
}

std::string Wieldable::worldStr()
{
	return world_model;
}

std::string Wieldable::equippedStr()
{
	return equipped_model;
}
