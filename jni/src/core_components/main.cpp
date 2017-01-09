/**
 * main.cpp
 *
 * Author: Chuck Valenza
 *
 * Description:
 *	A game where the player controls a sword fighter and fights NPCs
 */

#include "core/oxygine.h"
#include "Stage.h"
#include "DebugActor.h"

#include "core_components/swordfighter.h"

using namespace oxygine;

/**
 * Implement the basic game logic that occurs each loop
 */
int gameLoop()
{
	bool done = core::update(); // this will update things in the oxygine engine. input events are
								// passed to Stage::instance.handleEvent. if core::update returns
								// true, the program has been terminated by the user
	swordfighter_update();
	getStage()->update(); // update the stage and all actors

	if (core::beginRendering()) {
		Color clear_color(32, 32, 32, 255);
		Rect viewport(Point(0, 0), core::getDisplaySize());

		getStage()->render(clear_color, viewport); // render the next stage
		core::swapDisplayBuffers(); // swap the current buffer out
	}

	return done ? 1 : 0;
}

/**
 * The main run function that will be executed by main
 */
void run()
{
	ObjectBase::__startTracingLeaks(); // starts checking for leaked objects

	// set up the application description
	core::init_desc desc;
	desc.title = "Swordfighter";

	swordfighter_preinit();
	core::init(&desc);

	Stage::instance = new Stage(true);
	Point size = core::getDisplaySize();
	getStage()->setSize(size);

	// This is just to show debug information: FPS, memory usage, etc...
	DebugActor::show();

	// initialize the engine
	swordfighter_init();

	// execute the game logic loop
	while (1) {
		if (gameLoop()) {
			break;
		}
	}

	// clean-up
	ObjectBase::dumpCreatedObjects();
	swordfighter_destroy();
	core::release();
	ObjectBase::dumpCreatedObjects();

	// stop the thread checking for memory leaks
	ObjectBase::__stopTracingLeaks();
}

#ifdef __S3E__
int main(int argc, char* argv[])
{
	run();
	return 0;
}
#endif


#ifdef OXYGINE_SDL

#include "SDL_main.h"
#include "SDL.h"

extern "C" {
	void one(void* param) { gameLoop(); }
	void oneEmsc() { gameLoop(); }

	int main(int argc, char* argv[])
	{
		run();
		return 0;
	}
};
#endif

