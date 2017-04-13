/**
 * EmptyItem.cpp
 *
 * Description: Empty item class
 */

#include "world/items/armor/EmptyItem.h"

EmptyItem::EmptyItem()
{
	init("empty", Item::NONE);
}

std::string EmptyItem::menuStr()
{
	return menu_model;
}

std::string EmptyItem::worldStr()
{
	return world_model;
}

std::string EmptyItem::equippedStr()
{
	return equipped_model;
}
