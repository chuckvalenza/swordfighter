//
// Created by cvalenza on 2/17/17.
//

#include "EmptyLegs.h"

EmptyLegs::EmptyLegs()
{
	item_type = Wearable::ItemType::PANTS;
	effect_type = Wearable::ItemEffect::NONE;
	init("empty", Item::WEARABLE);
}
