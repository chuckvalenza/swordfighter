/**
 * Game.cpp
 *
 * Description: Class which runs the actual game. Initializes world and manages
 * it...runs update loop.
 */

#include "core_components/Game.h"

#include <math.h>
#include <map>
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

	physics = new Physics;

	createWorld();
	createPlayer();
	createHUD();

	physics->setWorld(world);
	physics->setPlayer(player);
}

void Game::createWorld()
{
	world = new World;
	world->setScreen(screen);
	world->init();
	world->attachTo(this);
}

void Game::createPlayer()
{
	player = new Player;
	player->init();
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

void Game::redraw()
{
	world->redraw();
	player->redraw();
}

void Game::doUpdate(const UpdateState& us)
{
	ui->update(us);
	world->update(us);

	physics->addToCollisionSet(player);
	physics->addToCollisionSet(world->getRigids());

	std::map<int, spUnit> moved_units = world->getMoved();
	for (std::map<int, spUnit>::iterator i = moved_units.begin();
		i != moved_units.end(); ++i) {
		physics->collisionDetection(i->second);
	}
	world->clearMoved();

	player->update(us);
	if (player->hasMoved()) {
		physics->collisionDetection(player);
	}

	physics->clearCollisionSet();
	redraw();
}
