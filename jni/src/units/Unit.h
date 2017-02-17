/**
 * Unit.h
 *
 * Description: Abstract base class for units
 */

#ifndef SWORD_FIGHTER_UNIT_H
#define SWORD_FIGHTER_UNIT_H

#include "oxygine-framework.h"

#include "core_components/DrawableObj.h"

#include <map>

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class Unit : public DrawableObj {
	protected:
		int unit_id;

		Vector2 world_coords;
		Vector2 prev_coords;
		bool moved;

		spSprite head;
		spSprite torso;
		spSprite legs;

		std::vector<spUnit>* collision_set;
	public:
		Unit();

		virtual void init();
		virtual void attack(float) = 0;
		virtual void move(float) = 0;
		virtual void stopAttack() = 0;
		virtual float getMoveMultiplier() = 0;
		virtual float getCBounds() = 0;
		virtual void redraw() {};
		virtual void update(const UpdateState& us) {}

		int id();
		void setX(float);
		void setY(float);
		float getWorldX();
		float getWorldY();
		void setPosition(Vector2);
		void setWorldCoords(Vector2);
		bool hasMoved();
		void unsetMoved();
		void undoMove();
		Vector2 getWorldCoords();
};

#endif //SWORD_FIGHTER_UNIT_H
