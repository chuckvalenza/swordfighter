/**
 * AttackCommand.cpp
 *
 * Description: Send attack command to given unit in assigned direction
 */

#include "commands/AttackCommand.h"

AttackCommand::AttackCommand()
{

}

void AttackCommand::undo()
{
	obj->stopAttack();
}

void AttackCommand::execute()
{
	float angle = atan2f(dir.y, dir.x);

	if (angle >= -3 && angle <= 1.5) {
		angle += M_PI / 2;
	} else {
		angle -= 1.5f * M_PI;
	}

	obj->attack(angle);
}