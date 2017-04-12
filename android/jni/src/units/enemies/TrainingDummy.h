/**
 * TrainingDummy.h
 */

#ifndef SWORD_FIGHTER_TRAININGDUMMY_H
#define SWORD_FIGHTER_TRAININGDUMMY_H

#include "oxygine-framework.h"
#include "core_components/res.h"
#include "units/Unit.h"
#include "physics/Attack.h"

DECLARE_SMART(TrainingDummy, spTrainingDummy);

class TrainingDummy : public Unit {
	private:
	public:
		TrainingDummy();
		void init();
		spAttack attack(float);
		void move(float);
		void stopAttack();
		float getMoveMultiplier();
		float getCBounds();
		void redraw();
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_TRAININGDUMMY_H
