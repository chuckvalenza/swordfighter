/**
 * Item.h
 *
 * Description: Abstract class representing items.
 */

#ifndef SWORD_FIGHTER_ITEM_H
#define SWORD_FIGHTER_ITEM_H

#include "oxygine-framework.h"

using namespace oxygine;

DECLARE_SMART(Item, spItem);

class Item : public Object {
	protected:
		std::string menu_model; // for navigation in menus
		std::string world_model; // for when the item is on the ground
		std::string equipped_model; // for when it is equipped on a character
	public:
		Item();
		void init(std::string);
		std::string menuStr();
		std::string worldStr();
		std::string equippedStr();
};

#endif //SWORD_FIGHTER_ITEM_H
