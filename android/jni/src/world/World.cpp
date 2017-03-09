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

	chunk_size = world_chunks[0][0]->getWidth();
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
	addToChunks(dummy);

	dummy = new TrainingDummy;
	dummy->init();
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() - 400);
	dummy->attachTo(view);
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	addToChunks(dummy);

	dummy = new TrainingDummy;
	dummy->init();
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() + 400);
	dummy->attachTo(view);
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	addToChunks(dummy);
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

std::map<int, spUnit> World::getCollisionSet(spUnit obj)
{
	int x = obj->getWorldX() / chunk_size;
	int y = obj->getWorldY() / chunk_size;
	std::map<int, spUnit> col_set;

	DebugActor::instance->addDebugString("Chunk x: %d y: %d", x, y);

	for (int xm = -1; xm <= 1; xm++) {
		for (int ym = -1; ym <= 1; ym++) {
			if (x > 0 && x < WORLD_WIDTH - 1 && y > 0 && y < WORLD_HEIGHT) {
				std::map<int, spUnit> cur = world_chunks[x + xm][y + ym]->getRigids();
				col_set.insert(cur.begin(), cur.end());
			}
		}
	}

	return col_set;
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

void World::addToChunks(spUnit obj)
{
	int cur_x = obj->getWorldX() / chunk_size;
	int cur_y = obj->getWorldY() / chunk_size;

	world_chunks[cur_x][cur_y]->addUnit(obj);
}

void World::updateUnitChunk(spUnit obj)
{
	int cur_x = obj->getWorldX() / chunk_size;
	int cur_y = obj->getWorldY() / chunk_size;
	int next_x = obj->getWorldX() / chunk_size;
	int next_y = obj->getWorldY() / chunk_size;

	if (cur_x != next_x || cur_y != next_y) {
		world_chunks[cur_x][cur_y]->removeUnit(obj);
		world_chunks[next_x][next_y]->addUnit(obj);
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