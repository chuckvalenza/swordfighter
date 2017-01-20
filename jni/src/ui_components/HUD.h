/**
 * HUD.h
 *
 * Description: Controls and HUD for game
 */

#ifndef SWORD_FIGHTER_HUD_H
#define SWORD_FIGHTER_HUD_H

#include "oxygine-framework.h"

#include "core_components/Screen.h"
#include "ui_components/Joystick.h"
#include "ui_components/EquipSlot.h"

using namespace oxygine;

class HUD : public DrawableObj {
	private:
		Screen* screen;

		spJoystick left_joy;
		spJoystick right_joy;

		spEquipSlot quick_slot1;
		spEquipSlot quick_slot2;
		spEquipSlot quick_slot3;
		spEquipSlot quick_slot4;
	public:
		HUD();
		void setScreen(Screen*);
		void init(spActor, spUnit);
		void setScale(float);
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_HUD_H
