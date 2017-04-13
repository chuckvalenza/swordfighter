/**
 * swordfighter.cpp
 *
 * Description: Creates the game class and loads resources. Can eventually be
 * used to load the menu.
 */

#include "oxygine-framework.h"

#include "core_components/swordfighter.h"
#include "core_components/res.h"
#include "core_components/Game.h"

using namespace oxygine;

void swordfighter_preinit()
{
}

void swordfighter_init()
{
	// load resources? swordfighter is vague. not exactly sure what this does.
	res::load();

	// create our game
	spGame game = new Game;
	game->init();
	game->attachTo(getStage());
}

void swordfighter_update()
{
}

void swordfighter_destroy()
{
	res::free();
}
