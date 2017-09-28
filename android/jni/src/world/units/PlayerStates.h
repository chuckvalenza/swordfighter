/**
 * PlayerStates.h
 *
 * description: States used by the Player class
 */

#ifndef SWORD_FIGHTER_PLAYERSTATES_H
#define SWORD_FIGHTER_PLAYERSTATES_H

#include "oxygine-framework.h"
#include "world/units/UnitState.h"

using namespace oxygine;

class Player;

/*================================= PlayerStand =================================*/
class PlayerStand : public UnitState<Player> {
	private:
		PlayerStand();
	public:
		static PlayerStand* Instance();
		void enter(Player*);
		void execute(Player*);
		void exit(Player*);
};

/*=============================== PlayerMove ==============================*/
class PlayerMove : public UnitState<Player> {
	private:
		PlayerMove();
	public:
		static PlayerMove* Instance();
		void enter(Player*);
		void execute(Player*);
		void exit(Player*);
};

/*=============================== PlayerMeleeAttack ==============================*/
class PlayerMeleeAttack : public UnitState<Player> {
	private:
		PlayerMeleeAttack();
	public:
		static PlayerMeleeAttack* Instance();
		void enter(Player*);
		void execute(Player*);
		void exit(Player*);
};

/*=============================== PlayerPassive ==============================*/
class PlayerPassive : public UnitState<Player> {
	private:
		PlayerPassive();
	public:
		static PlayerPassive* Instance();
		void enter(Player*);
		void execute(Player*);
		void exit(Player*);
};

#endif //SWORD_FIGHTER_PLAYERSTATES_H
