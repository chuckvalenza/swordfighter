/**
 * MoveCommand.cpp
 *
 * Description: Send move command to given unit in assigned direction
 */

#include "commands/MoveCommand.h"

MoveCommand::MoveCommand()
{

}

void MoveCommand::setWorld(World* w)
{
	world = w;
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

	obj->move(angle);

	Vector2 pos = world->getPosition();
	pos = pos - dir * (dt / 1000.0f) * 5; //player->getMoveMultiplier();
	//pos *= world->getTile(pos)->getMoveMultiplier()

	world->setPosition(pos);
}