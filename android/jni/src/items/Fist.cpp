/**
 * Fist.cpp
 *
 * Description: Fist item class
 */

#include "Fist.h"

Fist::Fist()
{
	item_type = Wieldable::ItemType::PUNCH;
	init("fist", Item::WIELDABLE);
}
