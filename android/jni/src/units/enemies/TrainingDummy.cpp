/**
 * TrainingDummy.cpp
 */

#include "units/enemies/TrainingDummy.h"
#define COLLISION_BOUNDS 70.0f

TrainingDummy::TrainingDummy()
{

}

void TrainingDummy::init()
{
	Unit::init();

	collision_bounds = COLLISION_BOUNDS;

	view = new Sprite;
	view->setAnchor(0.5f, 0.5f);

	std::string dummy_str = "enemy-dummy";
	torso = new Sprite;
	torso->addTween(TweenAnim(res::r.getResAnim(dummy_str), 0, 0), 1);
	torso->attachTo(view);
	view->setSize(torso->getSize());
}

void TrainingDummy::attack(float angle)
{

}

void TrainingDummy::move(float angle)
{

}

void TrainingDummy::stopAttack()
{

}

float TrainingDummy::getMoveMultiplier()
{
	return 0;
}

void TrainingDummy::redraw()
{
	if (getPosition() != next_pos) {
		setPosition(next_pos);
	}
}

void TrainingDummy::update(const UpdateState& us)
{
}
