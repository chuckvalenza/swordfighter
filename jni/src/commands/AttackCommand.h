/**
 * AttackCommand.h
 *
 * Description: Send attack command to given unit in assigned direction
 */

#ifndef SWORD_FIGHTER_ATTACKCOMMAND_H
#define SWORD_FIGHTER_ATTACKCOMMAND_H

#include "oxygine-framework.h"

#include "commands/Command.h"
#include "units/Unit.h"

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class AttackCommand : public Command {
	private:
		spUnit obj;
		Vector2 dir;
	public:
		AttackCommand();
		void init(spUnit);
		void setDir(Vector2);
		void setUnit(spUnit);
		virtual void execute();
};

#endif //SWORD_FIGHTER_ATTACKCOMMAND_H
