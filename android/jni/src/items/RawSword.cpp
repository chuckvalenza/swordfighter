/**
 * RawSword.cpp
 *
 * Description: Raw sword item class
 */

#include "RawSword.h"

RawSword::RawSword()
{
	item_type = Wieldable::ItemType::SLASH;
	init("raw_sword", Item::WIELDABLE);
}
