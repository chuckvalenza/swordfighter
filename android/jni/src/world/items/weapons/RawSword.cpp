/**
 * RawSword.cpp
 *
 * Description: Raw sword item class
 */

#include "world/items/weapons/RawSword.h"

RawSword::RawSword()
{
	damage = 20;
	atk_size = 75;
	item_type = Wieldable::ItemType::SLASH;
	init("raw_sword", Item::WIELDABLE);
}
