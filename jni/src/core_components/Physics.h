/**
 * Physics.h
 *
 * Description: Physics engine class
 */

#ifndef SWORD_FIGHTER_PHYSICS_H
#define SWORD_FIGHTER_PHYSICS_H

#include "oxygine-framework.h"

#include "world/World.h"
#include "units/Unit.h"
#include "units/Player.h"
#include <map>

using namespace oxygine;

class Physics {
	private:
		spUnit player;
		World* world;
		std::map<int, spUnit> collision_set;
	public:
		Physics();

		void setPlayer(spUnit);
		void setWorld(World*);
		void addToCollisionSet(spUnit);
		void addToCollisionSet(std::map<int, spUnit>);
		void collisionDetection(spUnit);
		void clearCollisionSet();
};

#endif //SWORD_FIGHTER_PHYSICS_H
