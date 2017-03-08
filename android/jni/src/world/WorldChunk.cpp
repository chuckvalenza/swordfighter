/**
 * WorldChunk.cpp
 *
 * Description: Divide world into chunks for better performance of physics
 * engine at larger scales
 */

#include "WorldChunk.h"

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

void WorldChunk::addToCollisionSet(spUnit obj)
{
	collision_set.insert(std::pair<int, spUnit>(obj->id(), obj));
}

void WorldChunk::addToCollisionSet(std::map<int, spUnit> new_objs)
{
	collision_set.insert(new_objs.begin(), new_objs.end());
	for (std::map<int, spUnit>::iterator i = new_objs.begin();
		i != new_objs.end(); ++i) {
		spUnit obj = i->second;
		collision_set.insert(std::pair<int, spUnit>(obj->id(), obj));
	}
}

void WorldChunk::redraw()
{

}

void WorldChunk::update(const UpdateState& us)
{

}

	/*
	grass_terrain.init(0.9, "world-grass");
	grass_terrain.attachTo(view);
	dirt_terrain(1.0, "world-dirt");
	dirt_terrain.attachTo(view);
	water_terrain(0.6, "world-water");
	water_terrain.attachTo(view);

	for (int y = 0; y < 51; y++) {
		for (int x = 0; x < 51; x++) {
			ground_tiles[x][y] = new Terrain;
			if (y % 5 == 0 || x % 3 == 0)
				ground_tiles[x][y]->init(1.0, "world-dirt");
			else
				ground_tiles[x][y]->init(0.9, "world-grass");
			ground_tiles[x][y]->setX(x * TILE_WIDTH);
			ground_tiles[x][y]->setY(y * TILE_HEIGHT);
			ground_tiles[x][y]->attachTo(view);
		}
	}

	spTrainingDummy dummy = new TrainingDummy;
	dummy->init();
	dummy->setPosition(view->getSize() / 2);
	dummy->setY(dummy->getY() - 400);
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	insertIntoChunks(dummy);

	dummy = new TrainingDummy;
	dummy->init();
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() - 400);
	dummy->attachTo(view);
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	insertIntoChunks(dummy);

	dummy = new TrainingDummy;
	dummy->init();
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() + 400);
	dummy->attachTo(view);
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	insertIntoChunks(dummy);
	*/
