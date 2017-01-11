/**
 * Game.cpp
 *
 * Description: Class which runs the actual game. Initializes world and manages
 * it...runs update loop.
 */

#include "core_components/Game.h"

#include "units/Unit.h"

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
	//player = new Player;
	//player->setScreen(screen);
	//player->init(this); // attach view to game actor
}

void Game::createHUD()
{
//////////////
	spUnit player = new Unit;
//////////////
	ui = new HUD;
	ui->setScreen(screen);
	ui->init(this, player);
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
