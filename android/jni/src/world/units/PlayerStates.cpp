/**
 * PlayerStates.cpp
 *
 * description: States used by the Player class
 */

#include "world/units/PlayerStates.h"
#include "world/units/Player.h"
#include "world/World.h"

/*================================ PlayerStand ===============================*/

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
	if (p->hasMoved()) {
		p->getMoveState()->changeState(PlayerMove::Instance());
	}

	p->animStand();
}

void PlayerStand::exit(Player* p)
{

}

/*================================= PlayerMove ===============================*/

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
	if (!p->hasMoved()) {
		p->getMoveState()->changeState(PlayerStand::Instance());
	}

	p->animMove();
}

void PlayerMove::exit(Player* p)
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
	if (p->atkAnimRunning()) {
		if (p->getRHItem()->getItemType() == Wieldable::ItemType::SLASH) {
			p->getRHState()->changeState(PlayerMeleeAttack::Instance());
		} else if (p->getRHItem()->getItemType() == Wieldable::ItemType::PUNCH) {
			p->getRHState()->changeState(PlayerMeleeAttack::Instance());
		} else if (p->getRHItem()->getItemType() == Wieldable::ItemType::RANGE) {
			// nothing yet
		} else if (p->getRHItem()->getItemType() == Wieldable::ItemType::SHIELD) {
			// nothing yet
		}
	}
}

void PlayerPassive::exit(Player* p)
{

}

/*============================= PlayerMeleeAttack ============================*/

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
	p->animUseRH();
}

void PlayerMeleeAttack::execute(Player* p)
{
	if (p->getAnimUseRHTimer() > 300) {
		p->animUseRH();
	}

	if (!p->hasAttacked()) {
		p->getRHState()->changeState(PlayerPassive::Instance());
	}
}

void PlayerMeleeAttack::exit(Player* p)
{

}

