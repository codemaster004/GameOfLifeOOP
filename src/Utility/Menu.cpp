/**
 * @class Menu
 * @file MEnu.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 22/04/2024
 */
#include "Menu.h"

#include <iostream>


InputCommands Menu::getSelectedOptions() {
	// input line from user
	std::string line;
	std::cin >> line;

	// store all commands inputed
	InputCommands resultingCommand;

	// simple interate over inputed line
	// todo: replace with more sufisticated input method than std::cin
	for (const char c: line) {
		switch (c) {
			case 'n':
				resultingCommand.set(NextFrame);
				break;
			case 'c':
				resultingCommand.set(NewGame);
				break;
			case 'q':
				resultingCommand.set(QuitGame);
				break;
			case 'v':
				resultingCommand.set(WriteState);
				break;
			case 'b':
				resultingCommand.set(LoadState);
				break;
			case 'a':
				resultingCommand.set(HumanLeft);
				break;
			case 'w':
				resultingCommand.set(HumanUp);
				break;
			case 'd':
				resultingCommand.set(HumanRight);
				break;
			case 's':
				resultingCommand.set(HumanDown);
				break;
			case 'x':
				resultingCommand.set(HumanSpecial);
				break;
			default:
				break;
		}
	}

	return resultingCommand;
}
