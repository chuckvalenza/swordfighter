/**
 * TrainingDummy.h
 */

#ifndef SWORD_FIGHTER_TRAININGDUMMY_H
#define SWORD_FIGHTER_TRAININGDUMMY_H

#include "oxygine-framework.h"
#include "core_components/res.h"
#include "world/units/ai/AI.h"
#include "world/units/ai/enemy/TrainingDummyStates.h"
#include "world/units/UnitStateMachine.h"
#include "physics/Attack.h"

DECLARE_SMART(TrainingDummy, spTrainingDummy);

class TrainingDummy : public AI {
	private:
		UnitStateMachine<TrainingDummy>* state_machine;
	public:
		TrainingDummy();
		void init();
		spAttack attack(float);
		void move(float);
		void stopAttack();
		float getMoveMultiplier();
		float getCBounds();
		bool healthLost();
		int getThreatId();
		UnitStateMachine<TrainingDummy>* getSM();
		void redraw();
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_TRAININGDUMMY_H
