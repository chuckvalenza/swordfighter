/**
 * MoveCommand.h
 *
 * Description: Send move command to given unit in assigned direction
 */

#ifndef SWORD_FIGHTER_MOVECOMMAND_H
#define SWORD_FIGHTER_MOVECOMMAND_H

#include "oxygine-framework.h"

#include "commands/Command.h"
#include "units/Unit.h"

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class MoveCommand : public Command {
	private:
		spUnit obj;
		Vector2 dir;
	public:
		MoveCommand();
		void init(spUnit);
		void setDir(Vector2);
		void setUnit(spUnit);
		virtual void execute();
};

#endif //SWORD_FIGHTER_MOVECOMMAND_H
