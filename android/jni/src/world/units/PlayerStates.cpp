/**
 * PlayerStates.cpp
 *
 * description: States used by the Player class
 */

#include "world/units/PlayerStates.h"
#include "world/units/Player.h"
#include "world/World.h"

/*================================= PlayerStand =================================*/

PlayerStand::PlayerStand()
{

}

PlayerStand* PlayerStand::Instance()
{
	static PlayerStand instance;
	return &instance;
}

void PlayerStand::enter(Player* p)
{

}

void PlayerStand::execute(Player* p)
{
/*
	if (p->isWalking()) {
		p->getMoveState()->changeState(PlayerMove::Instance());
	}
*/
}

void PlayerStand::exit(Player* p)
{

}

/*=============================== PlayerMove ==============================*/

PlayerMove::PlayerMove()
{

}

PlayerMove* PlayerMove::Instance()
{
	static PlayerMove instance;
	return &instance;
}

void PlayerMove::enter(Player* p)
{

}

void PlayerMove::execute(Player* p)
{

}

void PlayerMove::exit(Player* p)
{

}

/*=============================== PlayerMeleeAttack ==============================*/

PlayerMeleeAttack::PlayerMeleeAttack()
{

}

PlayerMeleeAttack* PlayerMeleeAttack::Instance()
{
	static PlayerMeleeAttack instance;
	return &instance;
}

void PlayerMeleeAttack::enter(Player* p)
{

}

void PlayerMeleeAttack::execute(Player* p)
{

}

void PlayerMeleeAttack::exit(Player* p)
{

}

/*=============================== PlayerPassive ==============================*/

PlayerPassive::PlayerPassive()
{

}

PlayerPassive* PlayerPassive::Instance()
{
	static PlayerPassive instance;
	return &instance;
}

void PlayerPassive::enter(Player* p)
{

}

void PlayerPassive::execute(Player* p)
{

}

void PlayerPassive::exit(Player* p)
{

}
