/**
 * @class Game
 * @file Game.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 22/04/2024
 */
#include "Game.h"

#include <iostream>

#include "Organism/Human.h"
#include "Utility/Menu.h"


void Game::setUpScreen() {
	clearScreen();
	int sizeX, sizeY;
	std::cout << "Enter dimenstions for the board: ";
	std::cout << "X: ";
	std::cin >> sizeX;
	std::cout << "Y: ";
	std::cin >> sizeY;

	t_gameWorld_p = new World(sizeX);

	t_gameWorld_p->addOrganism(new Human(), sizeX / 2, sizeX / 2);
}

void Game::clearScreen() { std::cout << "\033[2J\033[H"; }

void Game::printInputHelp() {
	std::cout << std::endl
			  << "Enter Options:" << std::endl
			  << " - N - next Turn" << std::endl
			  << " - AWDS - human moves" << std::endl
			  << " - X - Human Ability" << std::endl
			  << " - Q - Quit" << std::endl
			  << "Input: ";
}

void Game::init() {
	std::cout << "Starting Game:" << std::endl << " - C - New Game" << std::endl << " - B - Load State" << std::endl;
	std::cout << "Select Option: ";

	InputCommands commands = Menu::getSelectedOptions();
	if (commands[Menu::NewGame]) {
		setUpScreen();
	} else if (commands[Menu::LoadState]) {
		t_gameWorld_p->loadGameState();
	}
}

void Game::run() {
	clearScreen();
	t_gameWorld_p->drawWorld();

	InputCommands commands;
	t_gameWorld_p->setCommands(commands);

	printInputHelp(); // for first input
	while (true) {

		// input next line from input
		commands |= Menu::getSelectedOptions(); // |= to save commands in between not full frames. NextFrame
		if (commands[Menu::QuitGame])
			break;
		if (!commands[Menu::NextFrame])
			continue;

		clearScreen();
		t_gameWorld_p->updateWorld();
		t_gameWorld_p->drawWorld();

		commands.reset(); // set all commads to false
		printInputHelp(); // For next commad input
	}
}
