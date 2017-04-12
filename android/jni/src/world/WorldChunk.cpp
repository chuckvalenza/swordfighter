/**
 * WorldChunk.cpp
 *
 * Description: Divide world into chunks for better performance of physics
 * engine at larger scales
 */

#include "world/WorldChunk.h"

WorldChunk::WorldChunk()
{
}

void WorldChunk::init(int seed)
{
	view = new Sprite;
	generateTerrain(seed);
}

void WorldChunk::generateTerrain(int seed)
{
	// need to replace with seed-based random generation
	for (int y = 0; y < CHUNK_HEIGHT; y++) {
		for (int x = 0; x < CHUNK_WIDTH; x++) {
			ground_tiles[x][y] = new Terrain;
			if (y % 3 == 0 || x % 3 == 0) {
				ground_tiles[x][y]->init(1.0, "world-dirt");
			} else {
				ground_tiles[x][y]->init(0.9, "world-grass");
			}
			ground_tiles[x][y]->setX(x * TILE_WIDTH);
			ground_tiles[x][y]->setY(y * TILE_WIDTH);
			ground_tiles[x][y]->attachTo(view);

		}
	}

	view->setWidth(16 * TILE_WIDTH);
	view->setHeight(16 * TILE_WIDTH);
}

void WorldChunk::addNPC(spUnit obj)
{
	tracked_NPCs.insert(std::pair<int, spUnit>(obj->id(), obj));
	rigids.insert(std::pair<int, spRigid>(obj->id(), obj));
}

void WorldChunk::removeNPC(spUnit obj)
{
	tracked_NPCs.erase(obj->id());
	rigids.erase(obj->id());
}

void WorldChunk::addEnemy(spUnit obj)
{
	tracked_enemies.insert(std::pair<int, spUnit>(obj->id(), obj));
	rigids.insert(std::pair<int, spRigid>(obj->id(), obj));
}

void WorldChunk::removeEnemy(spUnit obj)
{
	tracked_enemies.erase(obj->id());
	rigids.erase(obj->id());
}

std::map<int, spRigid> WorldChunk::getRigids()
{
	return rigids;
}

std::map<int, spUnit> WorldChunk::getEnemies()
{
	return tracked_enemies;
}

void WorldChunk::redraw()
{

}

void WorldChunk::update(const UpdateState& us)
{

}
