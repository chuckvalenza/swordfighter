/**
 * Wieldable.h
 *
 * Description: Wieldable class of objects
 */

#ifndef SWORD_FIGHTER_WIELDABLE_H
#define SWORD_FIGHTER_WIELDABLE_H

#include "oxygine-framework.h"

#include "items/Item.h"
#include "core_components/DrawableObj.h"
#include "core_components/res.h"

using namespace oxygine;

DECLARE_SMART(Wieldable, spWieldable);

class Wieldable : public Item {
	protected:
		float damage;
		float atk_size;
	public:
		enum ItemType {
			SLASH,
			RANGE,
			PUNCH,
			SHIELD,
			NONE
		};

		ItemType item_type;

		Wieldable();
		float getDamage();
		float getSize();
		void setDamage(float);
		int getItemType();
		void setItemType(ItemType);
		std::string menuStr();
		std::string worldStr();
		std::string equippedStr();
};

#endif //SWORD_FIGHTER_WIELDABLE_H
