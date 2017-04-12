/**
 * Joystick.h
 *
 * Description: A joystick for user input
 */

#ifndef SWORD_FIGHTER_JOYSTICK_H
#define SWORD_FIGHTER_JOYSTICK_H

#include "oxygine-framework.h"

#include "core_components/DrawableObj.h"
#include "commands/DirectionalCommand.h"
#include "world/units/Unit.h"

using namespace oxygine;

DECLARE_SMART(Joystick, spJoystick);

class Joystick : public DrawableObj {
	private:
		bool pressed;
		bool unpressed;
		spSprite joystick;
		spSprite finger;
		DirectionalCommand* action;
		DirectionalCommand* undo_action;
		Vector2 dir;
	public:
		Joystick();
		void setAction(DirectionalCommand*);
		void onEvent(Event*);
		void redraw();
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_JOYSTICK_H
