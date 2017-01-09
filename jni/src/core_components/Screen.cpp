/**
 * Screen.cpp
 *
 * Description: Contains the dimensions of the device screen.
 */

#include "core_components/Screen.h"

Screen::Screen()
{
}

void Screen::init(float width, float height)
{
	dimensions.x = width;
	dimensions.y = height;
}

float Screen::getWidth()
{
	return dimensions.x;
}

float Screen::getHeight()
{
	return dimensions.y;
}

Vector2 Screen::getSize()
{
	return dimensions;
}
