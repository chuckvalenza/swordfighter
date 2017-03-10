/**
 * Unit.cpp
 *
 * Description: Abstract base class for units
 */

#include "units/Unit.h"

Unit::Unit()
{

}

void Unit::init()
{
	Rigid::init();
}

bool Unit::hasMoved()
{
	return moved;
}

void Unit::unsetMoved()
{
	moved = false;
}
