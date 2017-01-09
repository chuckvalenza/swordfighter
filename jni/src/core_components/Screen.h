/**
 * Screen.h
 *
 * Description: Contains the dimensions of the device screen.
 */

#ifndef SWORD_FIGHTER_SCREEN_H
#define SWORD_FIGHTER_SCREEN_H

#include "oxygine-framework.h"

using namespace oxygine;

class Screen {
	private:
		Vector2 dimensions;
	public:
		Screen();
		void init(float width, float height);
		float getWidth();
		float getHeight();
		Vector2 getSize();
};

#endif //SWORD_FIGHTER_SCREEN_H
