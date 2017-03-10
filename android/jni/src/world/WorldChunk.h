/**
 * WorldChunk.h
 *
 * Description: Divide world into chunks for better performance of physics
 * engine at larger scales
 */

#ifndef ANDROID_WORLDTILE_H
#define ANDROID_WORLDTILE_H

#include "oxygine-framework.h"

#include <map>
#include "core_components/DrawableObj.h"
#include "world/Terrain.h"
#include "units/enemies/TrainingDummy.h"

#define CHUNK_WIDTH 16
#define CHUNK_HEIGHT 16
#define TILE_WIDTH 200
#define TILE_HEIGHT 200

using namespace oxygine;

class WorldChunk : public DrawableObj {
	private:
		Terrain* ground_tiles[CHUNK_HEIGHT][CHUNK_HEIGHT];

		std::map<int, spUnit> tracked_units;
		std::map<int, spRigid> rigids;

		void generateTerrain(int);
	public:
		WorldChunk();

		void init(int);
		void addUnit(spUnit);
		void removeUnit(spUnit);
		void addToCollisionSet(spUnit);
		void addToCollisionSet(std::map<int, spUnit>);
		std::map<int, spRigid> getRigids();

		void redraw();
		void update(const UpdateState&);
};

#endif //ANDROID_WORLDTILE_H
