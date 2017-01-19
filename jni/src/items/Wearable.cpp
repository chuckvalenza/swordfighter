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