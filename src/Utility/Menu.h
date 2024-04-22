/**
 * Created by Filip Dabkowski on 22/04/2024.
 */

#ifndef MENU_H
#define MENU_H

#include <bitset>


using InputCommands = std::bitset<16>;

class Menu {
public:
	enum MenuOptions {
		NextFrame,
		NewGame,
		QuitGame,
		WriteState,
		LoadState,
		HumanUp,
		HumanDown,
		HumanLeft,
		HumanRight,
		HumanSpecial,
	};

	static InputCommands getSelectedOptions();
};


#endif // MENU_H
