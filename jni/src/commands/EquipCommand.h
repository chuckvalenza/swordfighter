/**
 * EquipCommand.h
 *
 * Description: Send an equip item command to the assigned unit
 */

#ifndef SWORD_FIGHTER_EQUIPCOMMAND_H
#define SWORD_FIGHTER_EQUIPCOMMAND_H

#include "oxygine-framework.h"

#include "commands/Command.h"
#include "units/Unit.h"
#include "items/Item.h"

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class EquipCommand : public Command {
	private:
		spUnit player;
		spItem item;
	public:
		EquipCommand();
		void init(spUnit, spItem);
		void setItem(spItem);
		void setUnit(spUnit);
		virtual void execute();
};

#endif //SWORD_FIGHTER_EQUIPCOMMAND_H
