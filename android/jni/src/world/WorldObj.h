/**
 * WorldObj.h
 *
 * Description: Objects which reside in the world
 */

#ifndef SWORD_FIGHTER_WORLDOBJECT_H
#define SWORD_FIGHTER_WORLDOBJECT_H

#include "oxygine-framework.h"

#include "core_components/DrawableObj.h"

using namespace oxygine;

DECLARE_SMART(WorldObj, spWorldObj);

class WorldObj : public DrawableObj {
	protected:
		int obj_id;
		Vector2 world_coords;
		Vector2 prev_coords;
	public:
		virtual void init();

		int id();
		void setX(float);
		void setY(float);
		void setPosition(Vector2);
		void setWorldCoords(Vector2);
		float getWorldX();
		float getWorldY();
		Vector2 getWorldCoords();
};

#endif //SWORD_FIGHTER_WORLDOBJECT_H
