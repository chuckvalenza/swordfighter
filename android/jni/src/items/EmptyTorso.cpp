//
// Created by cvalenza on 2/17/17.
//

#include "EmptyTorso.h"

EmptyTorso::EmptyTorso()
{
	item_type = Wearable::ItemType::CHESTPIECE;
	effect_type = Wearable::ItemEffect::NONE;
	init("empty", Item::WEARABLE);
}
