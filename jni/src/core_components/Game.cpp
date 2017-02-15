/**
 * Game.cpp
 *
 * Description: Class which runs the actual game. Initializes world and manages
 * it...runs update loop.
 */

#include "core_components/Game.h"

#include <math.h>
#include "core/log.h"

Game::Game()
{
}

void Game::init()
{
	setSize(getStage()->getSize());

	screen = new Screen;
	screen->init(getWidth(), getHeight());

	//setScale(0.75);

	createWorld();
	createPlayer();
	createHUD();
}

void Game::createWorld()
{
	world = new World;
	world->setScreen(screen);
	world->init(&collision_set);
	std::vector<spUnit> new_units = world->getUnits();
	// a map will be better for this in future since removing them will be O(1)
	units.insert(units.end(), new_units.begin(), new_units.end());
	world->attachTo(this);
}

void Game::createPlayer()
{
	player = new Player;
	player->init(&collision_set);
	player->setPosition(screen->getSize() / 2.0f);
	player->setWorldCoords(world->getSize() / 2.0f);
	player->setNextPosition(world->getSize() / 2.0f);
	player->attachTo(this);
	player->setPriority(500);
	units.push_back(player);
}

void Game::createHUD()
{
	ui = new HUD;
	ui->setScreen(screen);
	ui->init(player, world);
	ui->attachTo(this);
	ui->setPriority(1000);
}

/**
 * Note:
 * Broad phase of collision starts in the update of each unit. If they move,
 * they are added to the collision set. Collision set then iterated through
 * each object. We could make this even more efficient possibly by finding a
 * way to make the set smaller here by basing the set off of locality.
 */
void Game::playerCollisionDetection()
{
	spUnit u1 = player;

	for (std::vector<spUnit>::iterator i1 = collision_set.begin();
		i1 != collision_set.end(); ++i1) {
		spUnit u2 = (*i1);

		if (u1 != u2) {
			float a_r = u1->getCBounds();
			float a_x = u1->getNextPosition().x;
			float a_y = u1->getNextPosition().y;
			float b_r = u2->getCBounds();
			float b_x = u2->getWorldX();
			float b_y = u2->getWorldY();
			float dist = hypot(a_x - b_x, a_y - b_y);

			if (dist < a_r + b_r) {
				Vector2 pos;
				float angle = atan2(a_y - b_y, a_x - b_x);
				float diff = a_r + b_r - dist;

				pos.x = a_x + cos(angle) * diff;
				pos.y = a_y + sin(angle) * diff;
				u1->setNextPosition(pos);

				pos = world->getNextPosition();
				pos.x -= cos(angle) * diff;
				pos.y -= sin(angle) * diff;
				world->setNextPosition(pos);
			}
		}
	}

	collision_set.clear();
}

void Game::redraw()
{
	world->redraw();
	player->redraw();
}

void Game::doUpdate(const UpdateState& us)
{
	ui->update(us);
	world->update(us);
	world->collisionDetection();
	player->update(us);
	playerCollisionDetection();
	redraw();
}
