/**
 * MoveCommand.cpp
 *
 * Description: Send move command to given unit in assigned direction
 */

#include "commands/MoveCommand.h"

MoveCommand::MoveCommand()
{
}

void MoveCommand::init(spUnit object)
{
	obj = object;
}

void MoveCommand::setDir(Vector2 direction)
{
	dir = direction;
}

void MoveCommand::setUnit(spUnit object)
{
	obj = object;
}

void MoveCommand::execute()
{
	//obj->move(dir);
}