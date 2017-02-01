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
	world->init(this);
}

void Game::createPlayer()
{
	player = new Player;
	player->init();
	player->setPosition(screen->getSize() /2.0f);
	player->attachTo(this);
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

void Game::doUpdate(const UpdateState& us)
{
	ui->update(us);
}
