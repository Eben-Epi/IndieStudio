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
#include "../hud/Button.hpp"
#include "../../textbox/TextBox.hpp"

namespace Irrlicht
{
	enum MainMenuButtonName
	{
		NEW_GAME = 0,
		LOAD_GAME,
		HOW_TO_PLAY,
		EXIT,
	};

	class MainMenu : public GameScene
	{
		private:
			unsigned _clock = 0;
			std::vector<std::unique_ptr<Input::Input>> _inputs;

		public:
			MainMenu(Screen &screen, const std::string &name, unsigned id);
			~MainMenu() = default;
			bool update() override;
	};
}

#endif //BOMBERMAN_MAINMENU_HPP
