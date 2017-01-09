/**
 * EquipCommand.cpp
 *
 * Description: Send an equip item command to the assigned unit
 */

#include "EquipCommand.h"

EquipCommand::EquipCommand()
{
}

void EquipCommand::init(spUnit u, spItem i)
{
	item = i;
	player = u;
}

void EquipCommand::setItem(spItem i)
{
	item = i;
}

void EquipCommand::setUnit(spUnit u)
{
	player = u;
}

void EquipCommand::execute()
{
	//player->setWeapon(item);
}
