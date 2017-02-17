/**
 * Wieldable.cpp
 *
 * Description: Wieldable class of objects
 */

#include "Wieldable.h"

Wieldable::Wieldable()
{

}

float Wieldable::getDamage()
{
	return damage;
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
