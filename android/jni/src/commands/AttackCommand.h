/**
 * AttackCommand.h
 *
 * Description: Send attack command to given unit in assigned direction
 */

#ifndef SWORD_FIGHTER_ATTACKCOMMAND_H
#define SWORD_FIGHTER_ATTACKCOMMAND_H

#include "oxygine-framework.h"

#include "commands/DirectionalCommand.h"
#include "world/units/Unit.h"

using namespace oxygine;

class AttackCommand : public DirectionalCommand {
	private:
	public:
		AttackCommand();
		void undo();
		void execute();
};

#endif //SWORD_FIGHTER_ATTACKCOMMAND_H
