//
// Created by cvalenza on 2/17/17.
//

#include "EmptyHead.h"

EmptyHead::EmptyHead()
{
	item_type = Wearable::ItemType::HEADGEAR;
	effect_type = Wearable::ItemEffect::NONE;
	init("empty", Item::WEARABLE);
}
