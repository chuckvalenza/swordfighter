/**
 * Joystick.cpp
 *
 * Description: A joystick for user input
 */

#include "ui_components/Joystick.h"
#include "core_components/res.h"

Joystick::Joystick() : pressed(false), dir(0, 0)
{
	view = new Sprite;

	joystick = new Sprite;
	joystick->setResAnim(res::r.getResAnim("ui-joystick"));
	joystick->attachTo(view);
	view->setSize(joystick->getSize());

	finger = new Sprite;
	finger->setResAnim(res::r.getResAnim("ui-finger"));
	finger->attachTo(joystick);
	finger->setVisible(false);
	finger->setAnchor(Vector2(0.5f, 0.5f));
	finger->setTouchEnabled(false);

	view->addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &Joystick::onEvent));
	view->addEventListener(TouchEvent::TOUCH_UP, CLOSURE(this, &Joystick::onEvent));
	view->addEventListener(TouchEvent::MOVE, CLOSURE(this, &Joystick::onEvent));
}

void Joystick::setAction(DirectionalCommand* c)
{
	if (action) {
		delete action;
	}

	action = c;
}

void Joystick::onEvent(Event* ev)
{
	TouchEvent* te = safeCast<TouchEvent*>(ev);

	if (te->type == TouchEvent::TOUCH_DOWN) {
		finger->setVisible(true);
		joystick->setColor(Color::Red);
		pressed = true;
	}

	if (te->type == TouchEvent::TOUCH_UP) {
		finger->setVisible(false);
		joystick->setColor(Color::White);
		pressed = false;
	}

	Vector2 center = view->getSize() / 2;
	dir = te->localPosition - center;

	if (dir.length() > 100) {
		dir.normalizeTo(100);
	}

	finger->setPosition(center + dir);

	if (!pressed) {
		dir = Vector2(0, 0);
		action->undo();
	}
}

void Joystick::update(const UpdateState& us)
{
	if (pressed) {
		action->setDT(us.dt);
		action->setDir(dir);
		action->execute();
	}
}
