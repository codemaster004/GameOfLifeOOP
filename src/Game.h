/**
 * Created by Filip Dabkowski on 22/04/2024.
 */

#ifndef GAME_H
#define GAME_H

#include "World.h"

class Game {
	World* t_gameWorld_p;

	void setUpScreen();

	static void clearScreen();

	static void printInputHelp();

public:
	Game() : t_gameWorld_p(nullptr) {}

	void init();

	void run();

	~Game() { delete t_gameWorld_p; }
};


#endif // GAME_H
