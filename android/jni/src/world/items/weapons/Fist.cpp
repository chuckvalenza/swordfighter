/**
 * Fist.cpp
 *
 * Description: Fist item class
 */

#include "world/items/weapons/Fist.h"

Fist::Fist()
{
	damage = 5;
	atk_size = 32.5;
	item_type = Wieldable::ItemType::PUNCH;
	init("fist", Item::WIELDABLE);
}
