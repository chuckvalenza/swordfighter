//
// Created by cvalenza on 1/18/17.
//

#ifndef SWORD_FIGHTER_DIRECTIONALCOMMAND_H
#define SWORD_FIGHTER_DIRECTIONALCOMMAND_H

#include "commands/Command.h"
#include "units/Unit.h"

class DirectionalCommand : public Command {
	protected:
		spUnit obj;
		Vector2 dir;
	public:
		DirectionalCommand();
		void init(spUnit);
		void setDir(Vector2);
		virtual void undo() = 0;
};

#endif //SWORD_FIGHTER_DIRECTIONALCOMMAND_H
