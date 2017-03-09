/**
 * World.h
 *
 * Description: Houses objects, terrain, shops, enemies, etc...
 */

#ifndef SWORD_FIGHTER_WORLD_H
#define SWORD_FIGHTER_WORLD_H

// defined values are only here until dynamic map loading gets implemented
#define WORLD_WIDTH 5
#define WORLD_HEIGHT 5

#include "oxygine-framework.h"

#include <map>
#include "core_components/Screen.h"
#include "core_components/DrawableObj.h"
#include "world/Terrain.h"
#include "world/WorldChunk.h"
#include "units/enemies/TrainingDummy.h"

using namespace oxygine;

class World : public DrawableObj {
	private:
		Screen* screen;

		WorldChunk* world_chunks[WORLD_WIDTH][WORLD_HEIGHT];
		float chunk_size;

		std::map<int, spUnit> enemies;
		std::map<int, spUnit> rigid_objs;
		std::map<int, spUnit> moved_objs;
	public:
		World();
		void init();
		void setScreen(Screen*);
		void loadTerrain();
		void loadEnemies();
		void loadNPCs();
		void loadItems();
		void loadChests();
		void loadShops();
		void addToChunks(spUnit obj);
		void updateUnitChunk(spUnit obj);
		std::map<int, spUnit> getCollisionSet(spUnit obj);
		std::map<int, spUnit> getMoved();
		std::map<int, spUnit> getRigids();
		void clearMoved();
		void redraw();
		void update(const UpdateState&);
};

#endif //SWORD_FIGHTER_WORLD_H
