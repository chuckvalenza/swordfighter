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
#include "world/WorldChunk.h"

using namespace oxygine;

class World : public DrawableObj {
	private:
		Screen* screen;

		WorldChunk* world_chunks[WORLD_WIDTH][WORLD_HEIGHT];
		float chunk_size;

		std::map<int, spUnit> units;
		std::map<int, spUnit> enemies;
		std::map<int, spUnit> moved_objs;
		std::map<int, spRigid> rigid_objs;
		std::map<int, spAttack> attack_objs;
	public:
		World();
		void init();
		void setScreen(Screen*);
		void setPlayer(spUnit);
		void loadTerrain();
		void loadEnemies();
		void loadNPCs();
		void loadItems();
		void loadChests();
		void loadShops();
		void addEnemyToChunks(spUnit obj);
		void addNPCToChunks(spUnit obj);
		void removeEnemyFromChunks(spUnit obj);
		void removeNPCFromChunks(spUnit obj);
		void updateEnemyChunk(spUnit obj);
		void updateNPCChunk(spUnit obj);
		spUnit getUnit(int);
		std::map<int, spUnit> getMoved();
		std::map<int, spRigid> getRigids();
		std::map<int, spAttack> getAttacks();
		std::map<int, spUnit> getLocalEnemies(spWorldObj obj);
		std::map<int, spRigid> getCollisionSet(spRigid obj);
		std::map<int, spAttack> getLocalAttacks(spWorldObj obj);
		void clearMoved();
		void clearAttacks();
		void redraw();
		void update(const UpdateState&);

		spSprite getView();
};

#endif //SWORD_FIGHTER_WORLD_H
