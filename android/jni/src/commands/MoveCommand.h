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
#include "world/World.h"

using namespace oxygine;

class MoveCommand : public DirectionalCommand {
	private:
		World* world;
	public:
		MoveCommand();
		void setWorld(World*);
		void undo();
		void execute();
};

#endif //SWORD_FIGHTER_MOVECOMMAND_H
