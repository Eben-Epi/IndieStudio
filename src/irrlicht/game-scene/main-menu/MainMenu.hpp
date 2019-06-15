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
#include "../../textbox/TextBox.hpp"

namespace Irrlicht
{
	enum ButtonName
	{
		START = 0,
		OPTIONS,
		EXIT,
		// S_LOAD,
		// S_NEW,
		// BACK,
        //NUMBER_BUTTONS
	};

	class MainMenu : public GameScene
	{
		public:
			MainMenu(Screen &screen, const std::string &name, unsigned id);
			~MainMenu() = default;
			void changeCurrentGameScene(std::string sceneName);
			bool update() override;

		private:
			//PROPERTIES
			std::vector<std::unique_ptr<Button>> _buttons;
			std::vector<std::unique_ptr<TextBox>> _textBoxes;
	};
}

#endif //BOMBERMAN_MAINMENU_HPP
