/**
 * RawSword.h
 *
 * Description: Raw sword item class
 */

#ifndef SWORD_FIGHTER_RAWSWORD_H
#define SWORD_FIGHTER_RAWSWORD_H

#include "oxygine-framework.h"

#include "items/Item.h"

using namespace oxygine;

class RawSword : public Item {
	private:
		int damage;
	public:
		RawSword();
		int getDmg();
};

#endif //SWORD_FIGHTER_RAWSWORD_H
