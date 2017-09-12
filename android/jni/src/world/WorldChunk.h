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
#include "world/units/ai/enemy/TrainingDummy.h"
#include "physics/Attack.h"

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
		std::map<int, spAttack> attacks;

		void generateTerrain(int);
	public:
		WorldChunk();

		void init(int);
		void addNPC(spUnit);
		void addEnemy(spUnit);
		void addAttack(spAttack);
		void removeNPC(spUnit);
		void removeEnemy(spUnit);
		void removeAttack(spAttack);
		void addToCollisionSet(spUnit);
		void addToCollisionSet(std::map<int, spUnit>);
		std::map<int, spRigid> getRigids();
		std::map<int, spUnit> getEnemies();
		std::map<int, spAttack> getAttacks();

		void redraw();
		void update(const UpdateState&);
};

#endif //ANDROID_WORLDTILE_H
