/**
 * PatrolWaypoint.h
 *
 * Description: A temporary waypoint to control randomized movement jitter
 */

#ifndef SWORD_FIGHTER_PATROLWAYPOINT_H
#define SWORD_FIGHTER_PATROLWAYPOINT_H

#include "world/WorldObj.h"

class PatrolWaypoint : public WorldObj {
	private:
	public:
		float radius;
		float dist;
		float jitter;

		PatrolWaypoint();
		float rand1toNeg1();
		void redraw();
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_PATROLWAYPOINT_H
