//
// Created by cvalenza on 1/9/17.
//

#ifndef SWORD_FIGHTER_WORLD_H
#define SWORD_FIGHTER_WORLD_H

// defined values are only here until dynamic map loading gets implemented
#define WIDTH 500
#define HEIGHT 500
#define TILE_WIDTH 200
#define TILE_HEIGHT 200

#include "oxygine-framework.h"

#include "core_components/DrawableObj.h"
#include "world/Terrain.h"

using namespace oxygine;

class World : public DrawableObj {
	private:
		Terrain grass_terrain;
		Terrain dirt_terrain;
		Terrain water_terrain;
		Terrain* ground_tiles[WIDTH][HEIGHT];
	public:
		World();
		void init();
		void loadTerrain();
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_WORLD_H
