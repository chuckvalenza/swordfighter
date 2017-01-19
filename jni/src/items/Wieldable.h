//
// Created by cvalenza on 1/18/17.
//

#ifndef SWORD_FIGHTER_WIELDABLE_H
#define SWORD_FIGHTER_WIELDABLE_H

#include "oxygine-framework.h"

#include "items/Item.h"
#include "core_components/DrawableObj.h"
#include "core_components/res.h"

using namespace oxygine;

DECLARE_SMART(Wieldable, spWieldable);

class Wieldable : public Item {
	private:
		float damage;
	public:
		enum ItemType {
			SLASH,
			BOW,
			SHIELD
		};

		ItemType item_type;

		Wieldable();
		float getDamage();
		void setDamage(float);
		int getItemType();
		void setItemType(ItemType);
};

#endif //SWORD_FIGHTER_WIELDABLE_H
