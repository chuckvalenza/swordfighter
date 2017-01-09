/**
 * DrawableObj.h
 *
 * Description: Object that is drawable on screen. Gives a basis for all
 * drawable items to be adjusted in size and position easily, regardless of
 * model.
 */

#ifndef SWORD_FIGHTER_DRAWABLEOBJ_H
#define SWORD_FIGHTER_DRAWABLEOBJ_H

#include "oxygine-framework.h"

using namespace oxygine;

class DrawableObj : public Object {
	protected:
		spSprite view;
	public:
		DrawableObj();
		void setX(float);
		void setY(float);
		void setWidth(float);
		void setHeight(float);
		float getWidth();
		float getHeight();
		void attachTo(spActor);
		virtual void update(const UpdateState&) = 0;
};

#endif //SWORD_FIGHTER_DRAWABLEOBJ_H
