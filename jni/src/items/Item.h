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

class Item : virtual public Object {
	private:
	protected:
		std::string item_name;
		std::string menu_model; // for navigation in menus
		std::string world_model; // for when the item is on the ground
		std::string equipped_model; // for when it is equipped on a character
	public:
		enum ItemType {
			WEARABLE,
			WIELDABLE,
			CONSUMABLE,
			NONE
		};

		Item();
		ItemType type;
		void init(std::string, ItemType);
		std::string getName();
		virtual std::string menuStr() = 0;
		virtual std::string worldStr() = 0;
		virtual std::string equippedStr() = 0;
};

#endif //SWORD_FIGHTER_ITEM_H
