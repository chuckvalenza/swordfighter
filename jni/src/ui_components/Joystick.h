/**
 * Joystick.h
 *
 * Description: A joystick for user input
 */

#ifndef SWORD_FIGHTER_JOYSTICK_H
#define SWORD_FIGHTER_JOYSTICK_H

#include "oxygine-framework.h"

#include "core_components/DrawableObj.h"
#include "commands/Command.h"

using namespace oxygine;

DECLARE_SMART(Joystick, spJoystick);

class Joystick : public DrawableObj {
	private:
		bool pressed;
		spSprite joystick;
		spSprite finger;
		Command* action;
		Vector2 dir;
	public:
		Joystick();
		void setAction(Command*);
		void onEvent(Event*);
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_JOYSTICK_H
