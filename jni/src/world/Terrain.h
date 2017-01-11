/**
 * Terrain.h
 *
 * Description: Terrain tile utilizing flyweight pattern
 */

#ifndef SWORD_FIGHTER_TERRAIN_H
#define SWORD_FIGHTER_TERRAIN_H

#include "oxygine-framework.h"

#include "core_components/DrawableObj.h"
#include "core_components/res.h"

using namespace oxygine;

class Terrain : public DrawableObj {
	private:
		spSprite texture;
		float move_speed;
	public:
		Terrain();
		void init(float, std::string);
		float getMoveSpeed();
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_TERRAIN_H
