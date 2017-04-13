/**
 * Physics.cpp
 *
 * Description: Physics engine class
 */

#include "physics/Physics.h"

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

/**
 * Note:
 * Broad phase of collision starts in the update of each unit. If they move,
 * they are added to the collision set. Collision set then iterated through
 * each object. We could make this even more efficient possibly by finding a
 * way to make the set smaller here by basing the set off of locality.
 */
void Physics::attackDetection(spAttack u1)
{
	std::map<int, spUnit> collision_set = world->getLocalEnemies(u1);

	for (std::map<int, spUnit>::iterator i = collision_set.begin();
		i != collision_set.end(); ++i) {
		spUnit u2 = i->second;

		float a_x = u1->getWorldX();
		float a_y = u1->getWorldY();
		float b_x = u2->getWorldX();
		float b_y = u2->getWorldY();
		float dist = hypot(a_x - b_x, a_y - b_y);

		if (dist < u1->getCBounds() + u2->getCBounds()) {
			log::error("HEALTH %f", u2->takeDamage(u1->getDamage()));
		}
	}
}

/**
 * Note:
 * Broad phase of collision starts in the update of each unit. If they move,
 * they are added to the collision set. Collision set then iterated through
 * each object. We could make this even more efficient possibly by finding a
 * way to make the set smaller here by basing the set off of locality.
 */
void Physics::collisionDetection(spRigid u1)
{
	std::map<int, spRigid> collision_set;
	collision_set = world->getCollisionSet(u1);

	for (std::map<int, spRigid>::iterator i = collision_set.begin();
		i != collision_set.end(); ++i) {
		spRigid u2 = i->second;

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
}
