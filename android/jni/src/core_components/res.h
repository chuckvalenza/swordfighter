/**
 * res.h
 *
 * Description: Load all resources from XMLs
 */

#ifndef SWORD_FIGHTER_RES_H
#define SWORD_FIGHTER_RES_H

#include "oxygine-framework.h"

using namespace oxygine;

namespace res {
	extern Resources r;
	void load();
	void free();
}

#endif //SWORD_FIGHTER_RES_H
