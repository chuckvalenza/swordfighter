/**
 * World.cpp
 *
 * Description: Houses objects, terrain, shops, enemies, etc...
 */

#include "world/World.h"
#include "world/Terrain.h"
#include "world/units/ai/enemy/TrainingDummy.h"

World::World()
{

}

void World::init()
{
	view = new Sprite;

	loadTerrain();
	loadEnemies();
}

spSprite World::getView() {
	return view;
}

void World::setScreen(Screen* s)
{
	screen = s;
}

void World::setPlayer(spUnit player)
{
	units.insert(std::pair<int, spUnit>(0, player));
	rigid_objs.insert(std::pair<int, spUnit>(0, player));
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
	dummy->setWorld(this);
	dummy->setPosition(view->getSize() / 2);
	dummy->setY(dummy->getY() - 400);
	dummy->attachTo(view);
	units.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	addEnemyToChunks(dummy);

	dummy = new TrainingDummy;
	dummy->init();
	dummy->setWorld(this);
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() - 400);
	dummy->attachTo(view);
	units.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	addEnemyToChunks(dummy);

	dummy = new TrainingDummy;
	dummy->init();
	dummy->setWorld(this);
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() + 400);
	dummy->attachTo(view);
	units.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	enemies.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	rigid_objs.insert(std::pair<int, spUnit>(dummy->id(), dummy));
	addEnemyToChunks(dummy);
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

spUnit World::getUnit(int id)
{
	return units.at(id);
}

std::map<int, spUnit> World::getMoved()
{
	return moved_objs;
}

std::map<int, spRigid> World::getRigids()
{
	return rigid_objs;
}

std::map<int, spAttack> World::getAttacks()
{
	return attack_objs;
}

std::map<int, spUnit> World::getLocalEnemies(spWorldObj obj)
{
	int x = obj->getWorldX() / chunk_size;
	int y = obj->getWorldY() / chunk_size;
	std::map<int, spUnit> en_set;

	for (int xm = -1; xm <= 1; xm++) {
		for (int ym = -1; ym <= 1; ym++) {
			if (x > 0 && x < WORLD_WIDTH - 1 && y > 0 && y < WORLD_HEIGHT) {
				std::map<int, spUnit> cur = world_chunks[x + xm][y + ym]->getEnemies();
				en_set.insert(cur.begin(), cur.end());
			}
		}
	}

	return en_set;
}

std::map<int, spRigid> World::getCollisionSet(spRigid obj)
{
	int x = obj->getWorldX() / chunk_size;
	int y = obj->getWorldY() / chunk_size;
	std::map<int, spRigid> col_set;

	for (int xm = -1; xm <= 1; xm++) {
		for (int ym = -1; ym <= 1; ym++) {
			if (x > 0 && x < WORLD_WIDTH - 1 && y > 0 && y < WORLD_HEIGHT) {
				std::map<int, spRigid> cur = world_chunks[x + xm][y + ym]->getRigids();
				col_set.insert(cur.begin(), cur.end());
			}
		}
	}

	return col_set;
}

std::map<int, spAttack> World::getLocalAttacks(spWorldObj obj)
{
	int x = obj->getWorldX() / chunk_size;
	int y = obj->getWorldY() / chunk_size;
	std::map<int, spAttack> atk_set;

	for (int xm = -1; xm <= 1; xm++) {
		for (int ym = -1; ym <= 1; ym++) {
			if (x > 0 && x < WORLD_WIDTH - 1 && y > 0 && y < WORLD_HEIGHT) {
				std::map<int, spAttack> cur = world_chunks[x + xm][y + ym]->getAttacks();
				atk_set.insert(cur.begin(), cur.end());
			}
		}
	}

	return atk_set;
}

float World::getMoveMultiplier(Vector2 pos)
{
	int x = pos.x / chunk_size;
	int y = pos.y / chunk_size;
	// need to get based off of tile; suggest subtracting x * TILE_SIZE then
	// figuring which tile you land in in a same wat inside each chunk
	//return  world_chunks[x][y]->getTileMultiplier();
	return 1.0f;
}

void World::redraw()
{
	if (getPosition() != next_pos) {
		setPosition(next_pos);
	}

	for (std::map<int, spRigid>::iterator i = rigid_objs.begin();
		i != rigid_objs.end(); ++i) {
		i->second->redraw();
	}
}

void World::addEnemyToChunks(spUnit obj)
{
	int cur_x = obj->getWorldX() / chunk_size;
	int cur_y = obj->getWorldY() / chunk_size;

	world_chunks[cur_x][cur_y]->addEnemy(obj);
}

void World::removeEnemyFromChunks(spUnit obj)
{
	int cur_x = obj->getWorldX() / chunk_size;
	int cur_y = obj->getWorldY() / chunk_size;

	world_chunks[cur_x][cur_y]->removeEnemy(obj);
}

void World::updateEnemyChunk(spUnit obj)
{
	int cur_x = obj->getWorldX() / chunk_size;
	int cur_y = obj->getWorldY() / chunk_size;
	int next_x = obj->getWorldX() / chunk_size;
	int next_y = obj->getWorldY() / chunk_size;

	if (cur_x != next_x || cur_y != next_y) {
		world_chunks[cur_x][cur_y]->removeEnemy(obj);
		world_chunks[next_x][next_y]->addEnemy(obj);
	}
}

void World::addNPCToChunks(spUnit obj)
{
	int cur_x = obj->getWorldX() / chunk_size;
	int cur_y = obj->getWorldY() / chunk_size;

	world_chunks[cur_x][cur_y]->addNPC(obj);
}

void World::removeNPCFromChunks(spUnit obj)
{
	int cur_x = obj->getWorldX() / chunk_size;
	int cur_y = obj->getWorldY() / chunk_size;

	world_chunks[cur_x][cur_y]->removeNPC(obj);
}

void World::updateNPCChunk(spUnit obj)
{
	int cur_x = obj->getWorldX() / chunk_size;
	int cur_y = obj->getWorldY() / chunk_size;
	int next_x = obj->getWorldX() / chunk_size;
	int next_y = obj->getWorldY() / chunk_size;

	if (cur_x != next_x || cur_y != next_y) {
		world_chunks[cur_x][cur_y]->removeNPC(obj);
		world_chunks[next_x][next_y]->addNPC(obj);
	}
}

void World::clearMoved()
{
	moved_objs.clear();
}

void World::clearAttacks()
{
	for (std::map<int, spAttack>::iterator i = attack_objs.begin();
		i != attack_objs.end(); ++i) {
		spAttack cur = i->second;
		cur->detach();
	}
	attack_objs.clear();
}

void World::update(const UpdateState& us)
{
	for (std::map<int, spUnit>::iterator i = enemies.begin();
		i != enemies.end(); ++i) {
		spUnit cur = i->second;
		cur->update(us);
		if (cur->getHealth() <= 0.0f) {
			enemies.erase(cur->id());
			rigid_objs.erase(cur->id());
			removeEnemyFromChunks(cur);
		} else {
			if (cur->hasMoved()) {
				moved_objs.insert(std::pair<int, spUnit>(cur->id(), cur));
			}
			if (cur->hasAttacked()) {
				spAttack nAtk = cur->getAttack();
				attack_objs.insert(std::pair<int, spAttack>(nAtk->id(), nAtk));
			}
		}
	}
}