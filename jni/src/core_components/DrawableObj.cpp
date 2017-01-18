/**
 * DrawableObj.cpp
 *
 * Description: Object that is drawable on screen. Gives a basis for all
 * drawable items to be adjusted in size and position easily, regardless of
 * model.
 */

#include "DrawableObj.h"

DrawableObj::DrawableObj()
{

}

void DrawableObj::setRotation(float x)
{
	view->setRotation(x);
}

void DrawableObj::setPosition(Vector2 v)
{
	view->setPosition(v);
}

Vector2 DrawableObj::getPosition()
{
	return view->getPosition();
}

void DrawableObj::setX(float x)
{
	view->setX(x);
}

void DrawableObj::setY(float y)
{
	view->setY(y);
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

void DrawableObj::attachTo(spActor parent)
{
	view->attachTo(parent);
}

