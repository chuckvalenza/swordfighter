//
// Created by cvalenza on 2/17/17.
//

#include "world/items/armor/EmptyTorso.h"

EmptyTorso::EmptyTorso()
{
	item_type = Wearable::ItemType::CHESTPIECE;
	effect_type = Wearable::ItemEffect::NONE;
	init("empty", Item::WEARABLE);
}
