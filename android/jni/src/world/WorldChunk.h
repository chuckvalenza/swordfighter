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

		std::map<int, spUnit> tracked_NPCs;
		std::map<int, spUnit> tracked_enemies;
		std::map<int, spRigid> rigids;

		void generateTerrain(int);
	public:
		WorldChunk();

		void init(int);
		void addNPC(spUnit);
		void addEnemy(spUnit);
		void removeNPC(spUnit);
		void removeEnemy(spUnit);
		void addToCollisionSet(spUnit);
		void addToCollisionSet(std::map<int, spUnit>);
		std::map<int, spRigid> getRigids();
		std::map<int, spUnit> getEnemies();

		void redraw();
		void update(const UpdateState&);
};

#endif //ANDROID_WORLDTILE_H
