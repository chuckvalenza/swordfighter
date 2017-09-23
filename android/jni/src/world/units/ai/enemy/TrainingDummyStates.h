/**
 * TrainingDummyStates.h
 *
 * description: States used by the TrainingDummy
 */

#ifndef SWORD_FIGHTER_TRAININGDUMMYSTATES_H
#define SWORD_FIGHTER_TRAININGDUMMYSTATES_H

#include "oxygine-framework.h"
#include "world/units/UnitState.h"

using namespace oxygine;

class TrainingDummy;

/*================================= Patrol =================================*/
class Patrol : public UnitState<TrainingDummy> {
	private:
		Patrol();
	public:
		static Patrol* Instance();
		void enter(TrainingDummy*);
		void execute(TrainingDummy*);
		void exit(TrainingDummy*);
};

/*=============================== PursueEnemy ==============================*/
class PursueEnemy : public UnitState<TrainingDummy> {
	private:
		PursueEnemy();
	public:
		static PursueEnemy* Instance();
		void enter(TrainingDummy*);
		void execute(TrainingDummy*);
		void exit(TrainingDummy*);
};

#endif //SWORD_FIGHTER_TRAININGDUMMYSTATES_H
