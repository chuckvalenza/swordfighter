/**
 * EquipCommand.h
 *
 * Description: Send an equip item command to the assigned unit
 */

#ifndef SWORD_FIGHTER_EQUIPCOMMAND_H
#define SWORD_FIGHTER_EQUIPCOMMAND_H

#include "oxygine-framework.h"

#include "commands/Command.h"
#include "world/units/Player.h"
#include "world/items/Item.h"
#include "world/items/Wearable.h"
#include "world/items/Wieldable.h"

using namespace oxygine;

DECLARE_SMART(Player, spPlayer);

class EquipCommand : public Command {
	private:
		spPlayer player;
		spItem item;
	public:
		EquipCommand();
		void init(spPlayer, spItem);
		void setItem(spItem);
		void setUnit(spPlayer);
		void execute();
};

#endif //SWORD_FIGHTER_EQUIPCOMMAND_H
