/**
 * Game.h
 *
 * Description: Class which runs the actual game. Initializes world and manages
 * it...runs update loop.
 */

#ifndef SWORD_FIGHTER_GAME_H
#define SWORD_FIGHTER_GAME_H

#include "oxygine-framework.h"

#include "ui_components/HUD.h"
#include "core_components/Screen.h"
#include "world/World.h"
#include "world/units/Player.h"
#include "physics/Physics.h"
#include "physics/Attack.h"

using namespace oxygine;

DECLARE_SMART(Game, spGame);
DECLARE_SMART(Unit, spUnit);

class Game : public Actor {
	private:
		HUD* ui;
		World* world;
		Screen* screen;
		spUnit player;
		Physics* physics;

		std::vector<spUnit> units;

		void createWorld();
		void createPlayer();
		void createHUD();

		void redraw();
	protected:
		void doUpdate(const UpdateState& us);
	public:
		Game();
		void init();
};

#endif //SWORD_FIGHTER_GAME_H
