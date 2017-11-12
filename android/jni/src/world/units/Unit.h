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
#include <chrono>

using namespace oxygine;

DECLARE_SMART(Unit, spUnit);

class World;

class Unit : public Rigid {
	protected:
		float health;
		float prev_health;
		bool moved;
		bool atk_anim_running;
		std::chrono::milliseconds atk_anim_start_time;
		int atk_anim_duration;

		// it's time to overhaul how you are executing attacks. This temporary version
		// is just causing too much headache to implement correctly and was knowingly
		// implemented poorly

		enum AttackState {
			NOT_ATTACKING,
			ANIM_STARTED,
			ANIM_RUNNING,
			IS_ATTACKING,
			HAS_ATTACKED
		};

		AttackState atk_state;

		float atk_radius;
		spAttack atk;

		spSprite head;
		spSprite torso;
		spSprite left_hand;
		spSprite right_hand;
		spSprite legs;

		spAttack recent_threat;
		int recent_threat_id;

		World* world;
	public:
		Unit();
		~Unit();

		virtual void init();
		virtual spAttack attack(float) = 0;
		virtual void move(float) = 0;
		//virtual void animMeleeAttack() = 0;
		//virtual void animRangedAttack() = 0;
		virtual void animStand() = 0;
		virtual void animMove() = 0;
		virtual void stopAttack() = 0;
		virtual float getMoveMultiplier() = 0;
		virtual void redraw() {}
		virtual void update(const UpdateState& us) {}

		void setWorld(World*);
		void unsetMoved();
		bool hasMoved();
		bool hasAttacked();
		bool atkAnimRunning();
		bool healthLost();
		float takeDamage(float, spAttack);
		float getHealth();
		int getThreatId();
		spAttack getAttack();
		World* getWorld();
};

#endif //SWORD_FIGHTER_UNIT_H
