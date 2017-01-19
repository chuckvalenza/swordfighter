/**
 * Item.cpp
 *
 * Description: Abstract class representing items.
 */

#include "Item.h"

Item::Item()
{
}

void Item::init(std::string str, ItemType t)
{
	type = t;
	item_name = str;
	menu_model = "ui-" + str;
	world_model = "world-" + str;
	equipped_model = "player-" + str;
}

std::string Item::menuStr()
{
	return menu_model;
}

std::string Item::worldStr()
{
	return world_model;
}

std::string Item::equippedStr()
{
	return equipped_model;
}
