/**
 * Unit.h
 *
 * Description: Abstract base class for units
 */

#ifndef SWORD_FIGHTER_UNIT_H
#define SWORD_FIGHTER_UNIT_H

#include "oxygine-framework.h"

#include "physics/Rigid.h"
#include "physics/Attack.h"
#include <map>

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class Unit : public Rigid {
	protected:
		float health;
		float prev_health;
		bool moved;
		bool attacked;

		enum AttackState {
			NOT_ATTACKED,
			ATTACKING,
			ATTACKED
		};

		AttackState atk_state;

		enum AlertState {
			PASSIVE,
			ALERT
		};

		AlertState alert_state;

		float atk_radius;
		spAttack atk;

		spSprite head;
		spSprite torso;
		spSprite legs;

		std::vector<spUnit>* collision_set;

		spAttack recent_threat;
	public:
		Unit();
		~Unit();

		virtual void init();
		virtual spAttack attack(float) = 0;
		virtual void move(float) = 0;
		virtual void stopAttack() = 0;
		virtual float getMoveMultiplier() = 0;
		virtual void redraw() {};
		virtual void update(const UpdateState& us) {}

		bool hasMoved();
		void unsetMoved();
		bool hasAttacked();
		float takeDamage(float, spAttack);
		float getHealth();
		spAttack getAttack();
};

#endif //SWORD_FIGHTER_UNIT_H
