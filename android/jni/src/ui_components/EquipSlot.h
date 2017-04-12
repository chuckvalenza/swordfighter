/**
 * EquipSlot.h
 *
 * Description: A slot for equipment in menus
 */

#ifndef SWORD_FIGHTER_EQUIPSLOT_H
#define SWORD_FIGHTER_EQUIPSLOT_H

#include "oxygine-framework.h"

#include "core_components/DrawableObj.h"
#include "commands/Command.h"
#include "world/items/Item.h"
#include "world/items/items.h"

using namespace oxygine;

DECLARE_SMART(EquipSlot, spEquipSlot);
DECLARE_SMART(Item, spItem);

class EquipSlot : public DrawableObj {
	private:
		bool unpressed;
		spSprite equip_slot;
		spSprite item_sprite;
		spItem item;
		Command* action;
	public:
		EquipSlot();
		void setAction(Command*);
		void setItem(spItem);
		void onEvent(Event*);
		void redraw();
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_EQUIPSLOT_H
