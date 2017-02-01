//
// Created by cvalenza on 1/9/17.
//

#include "World.h"

World::World()
{

}

void World::init()
{
	view = new Sprite;

	/*
	grass_terrain.init(0.9, "world-grass");
	grass_terrain.attachTo(view);
	dirt_terrain(1.0, "world-dirt");
	dirt_terrain.attachTo(view);
	water_terrain(0.6, "world-water");
	water_terrain.attachTo(view);
	*/

	loadTerrain();
}

void World::loadTerrain()
{
	// right now, this just generates something because we do not have loading
	// from file yet
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 11; x++) {
			ground_tiles[x][y] = new Terrain;
			if (y % 10 == 0 || x % 3 == 0)
				ground_tiles[x][y]->init(1.0, "world-dirt");
			else
				ground_tiles[x][y]->init(0.9, "world-grass");
			ground_tiles[x][y]->setX(x * TILE_WIDTH);
			ground_tiles[x][y]->setY(y * TILE_HEIGHT);
			ground_tiles[x][y]->attachTo(view);
		}
	}
}

void World::update(const UpdateState&)
{

}