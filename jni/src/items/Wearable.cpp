/**
 * Wearable.cpp
 *
 * Description: Class of items that are wearable
 */

#include "Wearable.h"

Wearable::Wearable()
{

}

float Wearable::getBuff()
{
	return buff_val;
}

void Wearable::setBuff(float v)
{
	buff_val = v;
}

int Wearable::getBuffType()
{
	return effect_type;
}

void Wearable::setBuffType(ItemEffect t)
{
	effect_type = t;
}

std::string Wearable::menuStr()
{
	return menu_model;
}

std::string Wearable::worldStr()
{
	return world_model;
}

std::string Wearable::equippedStr()
{
	if (item_type == Wearable::ItemType::HEADGEAR) {
		return equipped_model + "-head";
	} else if (item_type == Wearable::ItemType::CHESTPIECE) {
		return equipped_model + "-torso";
	} else if (item_type == Wearable::ItemType::PANTS) {
		return equipped_model + "-legs";
	}
}
