/**
 * PatrolWaypoint.cpp
 *
 * Description: A temporary waypoint to control randomized movement jitter
 */

#include "world/units/ai/PatrolWaypoint.h"
#include "core_components/res.h"

PatrolWaypoint::PatrolWaypoint()
{
	WorldObj::init();
	view = new Sprite;
	radius = 15.0f;
	dist = 1.0f;
	jitter = 1.0f;
}

float PatrolWaypoint::rand1toNeg1()
{
	return (rand() / (RAND_MAX + 1.0f)) - (rand() / (RAND_MAX + 1.0f));
}

void PatrolWaypoint::redraw()
{

}

void PatrolWaypoint::update(const UpdateState& us)
{

}
