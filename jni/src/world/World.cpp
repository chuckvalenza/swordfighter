//
// Created by cvalenza on 1/9/17.
//

#include "World.h"

World::World()
{

}

void World::init(std::vector<spUnit>* c_set)
{
	collision_set = c_set;

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
	dummy->init(collision_set);
	dummy->setPosition(view->getSize() / 2);
	dummy->setY(dummy->getY() - 400);
	dummy->attachTo(view);
	enemies.push_back(dummy);

	dummy = new TrainingDummy;
	dummy->init(collision_set);
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() - 400);
	dummy->attachTo(view);
	enemies.push_back(dummy);

	dummy = new TrainingDummy;
	dummy->init(collision_set);
	dummy->setPosition(view->getSize() / 2);
	dummy->setX(dummy->getX() + 400);
	dummy->attachTo(view);
	enemies.push_back(dummy);
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

std::vector<spUnit> World::getUnits()
{
	return enemies;
}

/**
 * iterate through all objects and do broad collision detection
 */
void World::collisionDetection()
{
	for (std::vector<spUnit>::iterator i1 = collision_set->begin();
		i1 != collision_set->end(); ++i1) {
		for (std::vector<spUnit>::iterator i2 = enemies.begin();
			i2 != enemies.end(); ++i2) {
			spUnit u1 = (*i1);
			spUnit u2 = (*i2);

			if (u1 != u2) {
				float a_r = u1->getCBounds();
				float a_x = u1->getNextPosition().x;
				float a_y = u1->getNextPosition().y;

				float b_r = u2->getCBounds();
				float b_x = u2->getWorldX();
				float b_y = u2->getWorldY();

				float dx = a_x - b_x;
				float dy = a_y - b_y;
				float dist = hypot(dx, dy);

				if (dist < a_r + b_r) {
					Vector2 pos;
					float angle = atan2(a_y - b_y, a_x - b_x);
					float diff = a_r + b_r - dist;

					pos.x = a_x + cos(angle) * diff;
					pos.y = a_y + sin(angle) * diff;
					u1->setNextPosition(pos);
				}
			}
		}
	}
}

void World::redraw()
{
	if (getPosition() != next_pos) {
		setPosition(next_pos);
	}
}

void World::update(const UpdateState&)
{
	for (std::vector<spUnit>::iterator i = enemies.begin(); i != enemies.end();
		++i) {
		collision_set->push_back(*i);
	}
}