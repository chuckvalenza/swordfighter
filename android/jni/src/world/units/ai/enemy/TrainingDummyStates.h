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
class World;

/*================================= TrainingDummyPatrol =================================*/
class TrainingDummyPatrol : public UnitState<TrainingDummy> {
	private:
		TrainingDummyPatrol();

		World* world;
	public:
		static TrainingDummyPatrol* Instance();
		void enter(TrainingDummy*);
		void execute(TrainingDummy*);
		void exit(TrainingDummy*);
};

/*=============================== TrainingDummyPursueEnemy ==============================*/
class TrainingDummyPursueEnemy : public UnitState<TrainingDummy> {
	private:
		TrainingDummyPursueEnemy();
	public:
		static TrainingDummyPursueEnemy* Instance();
		void enter(TrainingDummy*);
		void execute(TrainingDummy*);
		void exit(TrainingDummy*);
};

#endif //SWORD_FIGHTER_TRAININGDUMMYSTATES_H
