/**
 * Game.cpp
 *
 * Description: Class which runs the actual game. Initializes world and manages
 * it...runs update loop.
 */

#include "core_components/Game.h"

Game::Game()
{
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

void Game::redraw()
{
	world->redraw();
	player->redraw();
}

void Game::doUpdate(const UpdateState& us)
{
	ui->update(us);
	world->update(us);
	player->update(us);
	redraw();
}
