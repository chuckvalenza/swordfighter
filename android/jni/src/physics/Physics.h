/**
 * Physics.h
 *
 * Description: Physics engine class
 */

#ifndef SWORD_FIGHTER_PHYSICS_H
#define SWORD_FIGHTER_PHYSICS_H

#include "oxygine-framework.h"

#include "core_components/DrawableObj.h"
#include "world/World.h"
#include "units/Unit.h"
#include "units/Player.h"
#include <map>

using namespace oxygine;

class Physics {
	private:
		spUnit player;
		World* world;
	public:
		Physics();

		void setPlayer(spUnit);
		void setWorld(World*);
		void attackDetection(spAttack);
		void collisionDetection(spRigid);
};

#endif //SWORD_FIGHTER_PHYSICS_H
