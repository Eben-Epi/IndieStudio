/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** MainMenu.hpp
*/

#ifndef BOMBERMAN_MAINMENU_HPP
#define BOMBERMAN_MAINMENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "Button.hpp"

namespace Irrlicht
{
	enum ButtonName
	{
		START = 0,
		OPTIONS,
		EXIT,
		// S_LOAD,
		// S_NEW,
		// O_VOLUME,
		// O_V_MORE,
		// O_V_LESS,
		// O_KEYS,
		// O_K_P1_UP,
		// O_K_P1_DOWN,
		// O_K_P1_LEFT,
		// O_K_P1_RIGHT,
		// O_K_P1_BOMB,
		// O_K_P1_ULT,
		// O_K_P2_UP,
		// O_K_P2_DOWN,
		// O_K_P2_LEFT,
		// O_K_P2_RIGHT,
		// O_K_P2_BOMB,
		// O_K_P2_ULT,
		// O_K_P3_UP,
		// O_K_P3_DOWN,
		// O_K_P3_LEFT,
		// O_K_P3_RIGHT,
		// O_K_P3_BOMB,
		// O_K_P3_ULT,
		// O_K_P4_UP,
		// O_K_P4_DOWN,
		// O_K_P4_LEFT,
		// O_K_P4_RIGHT,
		// O_K_P4_BOMB,
		// O_K_P4_ULT,
		// BACK,
		NUMBER_BUTTONS
	};

	class MainMenu : public GameScene
	{
		public:
			MainMenu(Screen &screen, const std::string &name, unsigned id);
			~MainMenu() = default;
			void changeCurrentGameScene(ButtonName scene);
			void update();

		private:
			//PROPERTIES
			std::vector<std::unique_ptr<Button>> _buttons;
	};
}

#endif //BOMBERMAN_MAINMENU_HPP
