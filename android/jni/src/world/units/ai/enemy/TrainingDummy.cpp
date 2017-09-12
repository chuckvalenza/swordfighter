/**
 * TrainingDummy.cpp
 */

#include "world/units/ai/enemy/TrainingDummy.h"
#define COLLISION_BOUNDS 70.0f

TrainingDummy::TrainingDummy()
{

}

void TrainingDummy::init()
{
	Unit::init();
	health = prev_health = 100;
	alert_state = PASSIVE;

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

}

void TrainingDummy::stopAttack()
{

}

float TrainingDummy::getMoveMultiplier()
{
	return 0;
}

void TrainingDummy::makeDecision()
{
	// AI need perception. They need to see/hear/feel; start with feel
	if (health < prev_health) {
		// react to feeling the attack;
		// direction of the attack with respect to the enemy
		// discern who it was from and add that enemy to the list of tracked enemies.
		// if multiple attacks, select attack which caused most damage out of intersecting attacks;
		//   keep a copy of the highest damage and compare
		Vector2 atk_loc = recent_threat->getWorldCoords();
		Vector2 en_pos = recent_threat->getPerpLoc();
		// create a copy of the perp somehow
		Vector2 dir = en_pos - world_coords;
		float angle = atan2f(dir.y, dir.x);

		if (angle >= -3 && angle <= 1.5) {
			angle += M_PI / 2;
		} else {
			angle -= 1.5f * M_PI;
		}
		angle -= M_PI;
		view->setRotation(angle);


		alert_state = ALERT;
	} else if(alert_state == ALERT) {
	// need to create a copy of the target in the block above and rotate in this block
		Vector2 atk_loc = recent_threat->getWorldCoords();
		Vector2 en_pos = target->getWorldCoords();
		Vector2 dir = en_pos - world_coords;
		float angle = atan2f(dir.y, dir.x);

		if (angle >= -3 && angle <= 1.5) {
			angle += M_PI / 2;
		} else {
			angle -= 1.5f * M_PI;
		}
		angle -= M_PI;
		view->setRotation(angle);
	}
}

void TrainingDummy::redraw()
{
	if (getPosition() != next_pos) {
		setPosition(next_pos);
	}
}

void TrainingDummy::update(const UpdateState& us)
{
	makeDecision();
}
