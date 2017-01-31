/**
 * MoveCommand.cpp
 *
 * Description: Send move command to given unit in assigned direction
 */

#include "commands/MoveCommand.h"

MoveCommand::MoveCommand()
{

}

void MoveCommand::undo()
{

}

void MoveCommand::execute()
{
	float angle = atan2f(dir.y, dir.x);

	if (angle >= -3 && angle <= 1.5) {
		angle += M_PI / 2;
	} else {
		angle -= 1.5f * M_PI;
	}

	obj->move(angle, 500);
}