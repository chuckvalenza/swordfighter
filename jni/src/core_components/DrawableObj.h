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

class DrawableObj : virtual public Object {
	protected:
		spSprite view;
		Vector2 current_loc;
		Vector2 next_pos;
	public:
		DrawableObj();

		void setRotation(float);
		void setPosition(Vector2);
		void setNextPosition(Vector2);
		void setSize(const Vector2& size);
		void setX(float);
		void setY(float);
		void setWidth(float);
		void setHeight(float);
		void setPriority(short);

		Vector2 getPosition();
		Vector2 getNextPosition();
		Vector2 getSize();
		float getX();
		float getY();
		float getWidth();
		float getHeight();

		void attachTo(spActor);
		virtual void redraw() = 0;
		virtual void update(const UpdateState&) = 0;
};

#endif //SWORD_FIGHTER_DRAWABLEOBJ_H
