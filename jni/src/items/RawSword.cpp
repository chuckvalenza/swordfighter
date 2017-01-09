/**
 * RawSword.cpp
 *
 * Description: Raw sword item class
 */

#include "RawSword.h"

RawSword::RawSword()
{
	init("raw_sword");
}

int RawSword::getDmg()
{
	return damage;
}
