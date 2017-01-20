/**
 * MoveCommand.h
 *
 * Description: Send move command to given unit in assigned direction
 */

#ifndef SWORD_FIGHTER_MOVECOMMAND_H
#define SWORD_FIGHTER_MOVECOMMAND_H

#include "oxygine-framework.h"

#include "commands/DirectionalCommand.h"
#include "units/Unit.h"

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class MoveCommand : public DirectionalCommand {
	private:
	public:
		MoveCommand();
		virtual void execute();
};

#endif //SWORD_FIGHTER_MOVECOMMAND_H
