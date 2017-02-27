/**
 * World.cpp
 *
 * Description: Houses objects, terrain, shops, enemies, etc...
 */

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
	loadEnemies();
}

void World::loadTerrain()
{
	// right now, this just generates something because we do not have loading
	// from file yet
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

	view->setWidth(50 * TILE_WIDTH);
	view->setHeight(50 * TILE_HEIGHT);
	Vector2 p = -(view->getSize() / 2) + screen->getSize() / 2;
	view->setPosition(p);
	next_pos = p;
}

void World::setScreen(Screen* s)
{
	screen = s;
}

void World::loadEnemies()
{
	spTrainingDummy dummy = new TrainingDummy;
	dummy->init();
	dummy->setPosition(view->getSize() / 2);
	dummy->setY(dummy->getY() - 400);
	dummy->attachTo(view);
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));

	dummy = new TrainingDummy;
	dummy->init();
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() - 400);
	dummy->attachTo(view);
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));

	dummy = new TrainingDummy;
	dummy->init();
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() + 400);
	dummy->attachTo(view);
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));
}

void World::loadNPCs()
{

}

void World::loadItems()
{

}

void World::loadChests()
{

}


void World::loadShops()
{

}

std::map<int, spUnit> World::getRigids()
{
	return rigid_objs;
}

std::map<int, spUnit> World::getMoved()
{
	return moved_objs;
}

void World::redraw()
{
	if (getPosition() != next_pos) {
		setPosition(next_pos);
	}
}

void World::clearMoved()
{
	moved_objs.clear();
}

void World::update(const UpdateState& us)
{
	for (std::map<int, spUnit>::iterator i = enemies.begin();
		i != enemies.end(); ++i) {
		spUnit cur = i->second;
		cur->update(us);
		if (cur->hasMoved()) {
			moved_objs.insert(std::pair<int, spUnit>(cur->id(), cur));
		}
	}
}