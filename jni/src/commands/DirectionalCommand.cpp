//
// Created by cvalenza on 1/18/17.
//

#include "DirectionalCommand.h"

DirectionalCommand::DirectionalCommand()
{

}

void DirectionalCommand::init(spUnit u)
{
	obj = u;
}

void DirectionalCommand::setDir(Vector2 direction)
{
	dir = direction;
}
