/**
 * TrainingDummy.cpp
 */

#include "world/World.h"
#include "world/units/ai/enemy/TrainingDummy.h"
#define COLLISION_BOUNDS 70.0f

TrainingDummy::TrainingDummy()
{
	//set up state machine
	move_state = new UnitStateMachine<TrainingDummy>(this);
	move_state->setCurrentUnitState(TrainingDummyPatrol::Instance());
}

void TrainingDummy::init()
{
	Unit::init();
	health = prev_health = 100;

	collision_bounds = COLLISION_BOUNDS;

	view = new Sprite;
	view->setAnchor(0.5f, 0.5f);

	std::string dummy_str = "enemy-dummy";
	torso = new Sprite;
	torso->addTween(TweenAnim(res::r.getResAnim(dummy_str), 0, 0), 1);
	torso->attachTo(view);
	view->setSize(torso->getSize());
}

spAttack TrainingDummy::attack(float angle)
{
	return NULL;
}

void TrainingDummy::move(float angle)
{
	moved = true;

	view->setRotation(angle + M_PI);
}

void TrainingDummy::animStand()
{

}

void TrainingDummy::animMove()
{

}

void TrainingDummy::stopAttack()
{

}

float TrainingDummy::getMoveMultiplier()
{
	return 1;
}

UnitStateMachine<TrainingDummy>* TrainingDummy::getMoveState()
{
	return move_state;
}

void TrainingDummy::redraw()
{
	if (getPosition() != next_pos) {
		setPosition(next_pos);
	}
}

void TrainingDummy::update(const UpdateState& us)
{
	move_state->update();
}
