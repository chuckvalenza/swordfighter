/**
 * HUD.cpp
 *
 * Description: Controls and HUD for game
 */

#include "ui_components/HUD.h"

#include "commands/MoveCommand.h"
#include "commands/AttackCommand.h"
#include "commands/EquipCommand.h"
#include "units/Unit.h"
#include "items/Item.h"
#include "items/items.h"

HUD::HUD()
{
	left_joy = new Joystick;
	right_joy = new Joystick;
	quick_slot1 = new EquipSlot;
	quick_slot2 = new EquipSlot;
	quick_slot3 = new EquipSlot;
	quick_slot4 = new EquipSlot;
}

void HUD::init(spUnit player, World* world)
{
	float center_w = screen->getWidth() / 2.0f;
	float center_h = screen->getHeight() / 2.0f;

	view = new Sprite;

	left_joy->setY(center_h - left_joy->getHeight());
	left_joy->setX(right_joy->getWidth() * 0.25f);
	MoveCommand* mc = new MoveCommand;
	mc->init(player);
	mc->setWorld(world);
	left_joy->setAction(mc);
	left_joy->attachTo(view);

	right_joy->setY(center_h - right_joy->getHeight());
	right_joy->setX(screen->getWidth() - (right_joy->getWidth() * 1.25f));
	AttackCommand* ac = new AttackCommand;
	ac->init(player);
	right_joy->setAction(ac);
	right_joy->attachTo(view);

	float slot_halfw = quick_slot1->getWidth() / 2.0f;
	float slot_width = quick_slot1->getWidth();
	float quick_bar_y = screen->getHeight() - quick_slot1->getHeight();

	// this is temporary until there is a need to load previous info.
	// until then, quick slots will load blank.
	spItem item1, item2, item3, item4;
	item1 = new RawSword;
	item2 = new RawSword;
	item3 = new EmptyItem;
	item4 = new EmptyItem;

	quick_slot1->setX(center_w - slot_width * 2.0f);
	quick_slot1->setY(quick_bar_y);
	EquipCommand* ec1 = new EquipCommand;
	ec1->init(player, item1);
	quick_slot1->setItem(item1);
	quick_slot1->attachTo(view);

	quick_slot2->setX(center_w - slot_width);
	quick_slot2->setY(quick_bar_y);
	EquipCommand* eq2 = new EquipCommand;
	eq2->init(player, item2);
	quick_slot2->setItem(item2);
	quick_slot2->attachTo(view);

	quick_slot3->setX(screen->getWidth() / 2);
	quick_slot3->setY(quick_bar_y);
	EquipCommand* eq3 = new EquipCommand;
	eq3->init(player, item3);
	quick_slot3->setItem(item3);
	quick_slot3->attachTo(view);

	quick_slot4->setX(screen->getWidth() / 2 + quick_slot4->getWidth());
	quick_slot4->setY(quick_bar_y);
	EquipCommand* eq4 = new EquipCommand;
	eq4->init(player, item4);
	quick_slot4->setItem(item4);
	quick_slot4->attachTo(view);
}

void HUD::setScreen(Screen* s)
{
	screen = s;
}

void HUD::setScale(float scale)
{
/*
	left_joy->setScale(scale);
	right_joy->setScale(scale);
	quick_slot1->setScale(scale);
	quick_slot2->setScale(scale);
	quick_slot3->setScale(scale);
	quick_slot4->setScale(scale);
*/
}

void HUD::redraw()
{

}

/**
 * Iterate through all HUD objects and update them
 */
void HUD::update(const UpdateState& us)
{
	left_joy->update(us);
	right_joy->update(us);
}