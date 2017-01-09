/**
 * AttackCommand.cpp
 *
 * Description: Send attack command to given unit in assigned direction
 */

#include "commands/AttackCommand.h"

AttackCommand::AttackCommand()
{

}

void AttackCommand::init(spUnit object)
{
	obj = object;
}

void AttackCommand::setDir(Vector2 direction)
{
	dir = direction;
}

void AttackCommand::setUnit(spUnit object)
{
	obj = object;
}

void AttackCommand::execute()
{
	//obj->attack(dir);
}