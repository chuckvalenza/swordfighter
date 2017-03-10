/**
 * Holographic.h
 *
 * Description: Holographic object which is visible but does not collide in
 *     physics collision detection
 */

#ifndef SWORD_FIGHTER_HOLOGRAPHIC_H
#define SWORD_FIGHTER_HOLOGRAPHIC_H

#include "oxygine-framework.h"

#include "world/WorldObj.h"

using namespace oxygine;

DECLARE_SMART(Holographic, spHolographic);

class Holographic : public WorldObj {

};

#endif //SWORD_FIGHTER_HOLOGRAPHIC_H
