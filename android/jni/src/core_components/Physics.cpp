/**
 * Physics.cpp
 *
 * Description: Physics engine class
 */

#include "Physics.h"

Physics::Physics()
{

}

void Physics::setPlayer(spUnit p)
{
	player = p;
}

void Physics::setWorld(World* w)
{
	world = w;
}

void Physics::addToCollisionSet(spUnit obj)
{
	collision_set.insert(std::pair<int, spUnit>(obj->id(), obj));
}

void Physics::addToCollisionSet(std::map<int, spUnit> new_objs)
{
	//collision_set.insert(new_objs.begin(), new_objs.end());
	for (std::map<int, spUnit>::iterator i = new_objs.begin();
		i != new_objs.end(); ++i) {
		spUnit obj = i->second;
		collision_set.insert(std::pair<int, spUnit>(obj->id(), obj));
	}
}

/**
 * Note:
 * Broad phase of collision starts in the update of each unit. If they move,
 * they are added to the collision set. Collision set then iterated through
 * each object. We could make this even more efficient possibly by finding a
 * way to make the set smaller here by basing the set off of locality.
 */
void Physics::collisionDetection(spUnit u1)
{
	for (std::map<int, spUnit>::iterator i = collision_set.begin();
		i != collision_set.end(); ++i) {
		spUnit u2 = i->second;

		if (u1 != u2) {
			float a_r = u1->getCBounds();
			float a_x = u1->getNextPosition().x;
			float a_y = u1->getNextPosition().y;
			float b_r = u2->getCBounds();
			float b_x = u2->getWorldX();
			float b_y = u2->getWorldY();
			float dist = hypot(a_x - b_x, a_y - b_y);

			if (dist < a_r + b_r) {
				Vector2 pos;
				float angle = atan2(a_y - b_y, a_x - b_x);
				float diff = a_r + b_r - dist;

				pos.x = a_x + cos(angle) * diff;
				pos.y = a_y + sin(angle) * diff;
				u1->setNextPosition(pos);

				if (u1->id() == player->id()) {
					pos = world->getNextPosition();
					pos.x -= cos(angle) * diff;
					pos.y -= sin(angle) * diff;
					world->setNextPosition(pos);
				}
			}
		}
	}

	u1->unsetMoved();
}

void Physics::clearCollisionSet()
{
	collision_set.clear();
}
