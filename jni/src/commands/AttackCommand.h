/**
 * AttackCommand.h
 *
 * Description: Send attack command to given unit in assigned direction
 */

#ifndef SWORD_FIGHTER_ATTACKCOMMAND_H
#define SWORD_FIGHTER_ATTACKCOMMAND_H

#include "oxygine-framework.h"

#include "commands/DirectionalCommand.h"
#include "units/Unit.h"

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class AttackCommand : public DirectionalCommand {
	private:
	public:
		AttackCommand();
		virtual void execute();
};

#endif //SWORD_FIGHTER_ATTACKCOMMAND_H
