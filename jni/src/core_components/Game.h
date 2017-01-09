/**
 * Game.h
 *
 * Description: Class which runs the actual game. Initializes world and manages
 * it...runs update loop.
 */

#ifndef SWORD_FIGHTER_GAME_H
#define SWORD_FIGHTER_GAME_H

#include "oxygine-framework.h"

#include "ui_components/UI.h"
#include "core_components/Screen.h"

using namespace oxygine;

DECLARE_SMART(Game, spGame);
DECLARE_SMART(Unit, spUnit);

class Game : public Actor {
	private:
		UI* ui;
		Screen* screen;

		void createWorld();
		void createPlayer();
		void createUI();
	protected:
		void doUpdate(const UpdateState& us);
	public:
		Game();
		void init();
};

#endif //SWORD_FIGHTER_GAME_H
