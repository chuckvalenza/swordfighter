/**
 * TrainingDummyStates.cpp
 *
 * description: States used by the TrainingDummy
 */

#include "world/units/ai/enemy/TrainingDummyStates.h"
#include "world/units/ai/enemy/TrainingDummy.h"
#include "world/World.h"

/*================================= TrainingDummyPatrol =================================*/

TrainingDummyPatrol::TrainingDummyPatrol()
{

}

TrainingDummyPatrol* TrainingDummyPatrol::Instance()
{
	static TrainingDummyPatrol instance;
	return &instance;
}

void TrainingDummyPatrol::enter(TrainingDummy* t)
{

}

void TrainingDummyPatrol::execute(TrainingDummy* t)
{
	if (t->healthLost()) {
		t->getMoveState()->changeState(TrainingDummyPursueEnemy::Instance());
	}

	static int counter = 0;
	Vector2 dir;
	if(counter < 500)
		dir.x = 1;
	if(counter > 500)
		dir.x = -1;

	dir.y = 0;

	float angle = atan2f(dir.y, dir.x);

	if (angle >= -3 && angle <= 1.5) {
		angle += M_PI / 2;
	} else {
		angle -= 1.5f * M_PI;
	}

	t->move(angle);

	float penalty = t->getMoveMultiplier() * world->getMoveMultiplier(t->getWorldCoords());

	Vector2 pos;
	pos = t->getPosition();
	pos += dir * 2 * penalty;
	if(counter > 1000)
		counter = 0;

	t->setNextPosition(pos);

	counter++;
}

void TrainingDummyPatrol::exit(TrainingDummy* t)
{

}

/*=============================== TrainingDummyPursueEnemy ==============================*/

TrainingDummyPursueEnemy::TrainingDummyPursueEnemy()
{

}

TrainingDummyPursueEnemy* TrainingDummyPursueEnemy::Instance()
{
	static TrainingDummyPursueEnemy instance;
	return &instance;
}

void TrainingDummyPursueEnemy::enter(TrainingDummy* t)
{

}

void TrainingDummyPursueEnemy::execute(TrainingDummy* t)
{
	int en_id = t->getThreatId();
	Vector2 en_pos = t->getWorld()->getUnit(en_id)->getWorldCoords();
	Vector2 dir = en_pos - t->getWorldCoords();
	float angle = atan2f(dir.y, dir.x);

	if (angle >= -3 && angle <= 1.5) {
		angle += M_PI / 2;
	} else {
		angle -= 1.5f * M_PI;
	}

	angle -= M_PI;
	t->setRotation(angle);
}

void TrainingDummyPursueEnemy::exit(TrainingDummy* t)
{

}
