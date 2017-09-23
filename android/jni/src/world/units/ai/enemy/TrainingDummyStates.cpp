/**
 * TrainingDummyStates.cpp
 *
 * description: States used by the TrainingDummy
 */

#include "world/units/ai/enemy/TrainingDummyStates.h"
#include "world/units/ai/enemy/TrainingDummy.h"
#include "world/World.h"

/*================================= Patrol =================================*/

Patrol::Patrol()
{

}

Patrol* Patrol::Instance()
{
	static Patrol instance;
	return &instance;
}

void Patrol::enter(TrainingDummy* t)
{

}

void Patrol::execute(TrainingDummy* t)
{
	if (t->healthLost()) {
		t->getSM()->changeState(PursueEnemy::Instance());
	}
}

void Patrol::exit(TrainingDummy* t)
{

}

/*=============================== PursueEnemy ==============================*/

PursueEnemy::PursueEnemy()
{

}

PursueEnemy* PursueEnemy::Instance()
{
	static PursueEnemy instance;
	return &instance;
}

void PursueEnemy::enter(TrainingDummy* t)
{

}

void PursueEnemy::execute(TrainingDummy* t)
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

void PursueEnemy::exit(TrainingDummy* t)
{

}
