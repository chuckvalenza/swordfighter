/**
 * Rigid.h
 *
 * Description: Rigid object which collide in physics collision detection
 */

#ifndef SWORD_FIGHTER_RIGID_H
#define SWORD_FIGHTER_RIGID_H

#include "oxygine-framework.h"

#include "world/WorldObj.h"

using namespace oxygine;

DECLARE_SMART(Rigid, spRigid);

class Rigid : public WorldObj {
	protected:
		float collision_bounds;
	public:
		virtual void init();

		float getCBounds();
};

#endif //SWORD_FIGHTER_RIGID_H
