/**
 * Rigid.cpp
 *
 * Description: Rigid object which collide in physics collision detection
 */

#include "physics/Rigid.h"

void Rigid::init()
{
	WorldObj::init();
}

float Rigid::getCBounds()
{
	return collision_bounds;// * scale_multiplier;
}

