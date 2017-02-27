/**
 * DirectionalCommand.cpp
 *
 * Description: Command executed on player with specified direction
 */

#include "DirectionalCommand.h"

DirectionalCommand::DirectionalCommand()
{

}

void DirectionalCommand::init(spUnit u)
{
	obj = u;
	dt = 1;
}

void DirectionalCommand::setDT(float delta)
{
	dt = delta;
}

void DirectionalCommand::setDir(Vector2 direction)
{
	dir = direction;
}
