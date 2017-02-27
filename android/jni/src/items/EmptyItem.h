/**
 * EmptyItem.h
 *
 * Description: Empty item class
 */

#ifndef SWORD_FIGHTER_EMPTYITEM_H
#define SWORD_FIGHTER_EMPTYITEM_H

#include "oxygine-framework.h"

#include "items/Item.h"

using namespace oxygine;

class EmptyItem : public Item {
	public:
		EmptyItem();
		std::string menuStr();
		std::string worldStr();
		std::string equippedStr();
};

#endif //SWORD_FIGHTER_EMPTYITEM_H
