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

	loadTerrain();
	loadEnemies();
}

void World::setScreen(Screen* s)
{
	screen = s;
}

/**
 * Generate terrain in all chunks based on the random seed
 */
void World::loadTerrain()
{
	// right now, this just generates something because we do not have loading
	// from file yet
	int seed = 1;
	for (int x = 0; x < WORLD_WIDTH; x++) {
		for (int y = 0; y < WORLD_HEIGHT; y++) {
			world_chunks[x][y] = new WorldChunk;
			world_chunks[x][y]->init(seed);
			world_chunks[x][y]->setX(x * CHUNK_WIDTH * TILE_WIDTH);
			world_chunks[x][y]->setY(y * CHUNK_WIDTH * TILE_WIDTH);
			world_chunks[x][y]->attachTo(view);
		}
	}

	view->setWidth(WORLD_WIDTH * CHUNK_WIDTH * TILE_WIDTH);
	view->setHeight(WORLD_HEIGHT * CHUNK_WIDTH * TILE_WIDTH);
	Vector2 p = -(view->getSize() / 2) + screen->getSize() / 2;
	view->setPosition(p);
	next_pos = p;
}

/**
 * Generate enemies based on the random seed and then load them into
 * their corresponding chunks
 */
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

/**
 * Generate NPCs based on the random seed and then load them into
 * their corresponding chunks. Kill NPCs who are dead from save file.
 */
void World::loadNPCs()
{

}

/**
 * Generate items based on the random seed and then load them into
 * their corresponding chunks. Load previously dropped items from save file.
 */
void World::loadItems()
{

}

/**
 * Generate loot chests based on the random seed and then load them into their
 * corresponding chunks. Open and empty already looted chests from save file.
 */
void World::loadChests()
{

}


void World::loadShops()
{

}

std::map<int, spUnit>* World::getCollisionSet(spUnit)
{
	return &enemies;
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