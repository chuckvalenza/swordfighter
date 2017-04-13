/**
 * EquipCommand.cpp
 *
 * Description: Send an equip item command to the assigned unit
 */

#include "commands/EquipCommand.h"

EquipCommand::EquipCommand()
{
}

void EquipCommand::init(spPlayer u, spItem i)
{
	item = i;
	player = u;
}

void EquipCommand::setItem(spItem i)
{
	item = i;
}

void EquipCommand::setUnit(spPlayer u)
{
	player = u;
}

void EquipCommand::execute()
{
	if (item->type == Item::WIELDABLE) {
		player->setRHItem(safeSpCast<Wieldable>(item));
	} else if (item->type == Item::WEARABLE) {
		player->setTorso(safeSpCast<Wearable>(item));
	}
}
