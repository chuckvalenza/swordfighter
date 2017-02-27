/**
 * EquipSlot.cpp
 *
 * Description: A slot for equipment in menus
 */

#include "EquipSlot.h"
#include "core_components/res.h"

EquipSlot::EquipSlot()
{
	view = new Sprite;

	equip_slot = new Sprite;
	equip_slot->setResAnim(res::r.getResAnim("ui-equipslot"));
	//equip_slot->setAnchor(0.0f, 0.5f);
	equip_slot->attachTo(view);
	equip_slot->addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &EquipSlot::onEvent));
	equip_slot->addEventListener(TouchEvent::TOUCH_UP, CLOSURE(this, &EquipSlot::onEvent));
	view->setSize(equip_slot->getSize());

	item_sprite = new Sprite;
	item = new EmptyItem;
	item_sprite->setResAnim(res::r.getResAnim(item->menuStr()));
	item_sprite->attachTo(view);
	item_sprite->addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &EquipSlot::onEvent));
	item_sprite->addEventListener(TouchEvent::TOUCH_UP, CLOSURE(this, &EquipSlot::onEvent));
}

void EquipSlot::setItem(spItem i)
{
	item = i;
	item_sprite->setResAnim(res::r.getResAnim(item->menuStr()));
	item_sprite->attachTo(view);
}

void EquipSlot::setAction(Command* c)
{
	action = c;
}

void EquipSlot::onEvent(Event* ev)
{
	TouchEvent* te = safeCast<TouchEvent*>(ev);

	if (te->type == TouchEvent::TOUCH_DOWN) {
		equip_slot->setColor(Color::Red);
	}

	if (te->type == TouchEvent::TOUCH_UP) {
		equip_slot->setColor(Color::White);
		unpressed = true;
	}
}

void EquipSlot::redraw()
{

}

void EquipSlot::update(const UpdateState& us)
{
	if (unpressed && item->type != Item::NONE) {
		action->execute();
	}
	//equip_slot->setColor(Color::Yellow);

	unpressed = false;
}
