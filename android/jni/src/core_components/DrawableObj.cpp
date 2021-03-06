/**
 * DrawableObj.cpp
 *
 * Description: Object that is drawable on screen. Gives a basis for all
 * drawable items to be adjusted in size and position easily, regardless of
 * model.
 */

#include "core_components/DrawableObj.h"

DrawableObj::DrawableObj()
{

}

void DrawableObj::setRotation(float x)
{
	view->setRotation(x);
}

void DrawableObj::setPosition(Vector2 v)
{
	current_loc = v;
	view->setPosition(v);
}

void DrawableObj::setNextPosition(Vector2 v)
{
	next_pos = v;
}

void DrawableObj::setSize(const Vector2& size)
{
	view->setSize(size);
}

Vector2 DrawableObj::getSize()
{
	return view->getSize();
}

Vector2 DrawableObj::getPosition()
{
	return view->getPosition();
}

Vector2 DrawableObj::getNextPosition()
{
	return next_pos;
}

void DrawableObj::setX(float x)
{
	view->setX(x);
}

void DrawableObj::setY(float y)
{
	view->setY(y);
}

float DrawableObj::getX()
{
	return view->getX();
}

float DrawableObj::getY()
{
	return view->getY();
}

void DrawableObj::setWidth(float w)
{
	view->setWidth(w);
}

void DrawableObj::setHeight(float h)
{
	view->setHeight(h);
}

float DrawableObj::getWidth()
{
	return view->getWidth();
}

float DrawableObj::getHeight()
{
	return view->getHeight();
}

void DrawableObj::setPriority(short p)
{
	view->setPriority(p);
}

void DrawableObj::attachTo(spActor parent)
{
	view->attachTo(parent);
}

void DrawableObj::detach()
{
	if (view) {
		view->detach();
	}
}
