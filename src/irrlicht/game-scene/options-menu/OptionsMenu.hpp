/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** option-menu.hpp
*/

#ifndef OPTION_MENU_HPP
#define OPTION_MENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../main-menu/Button.hpp"

namespace Irrlicht
{
	enum OptionButtonName
	{
		CHANGE_KEYS = 0,
		BACK,
		VOLUME,
		NUMBER_BUTTONS
	};

	class OptionsMenu : public GameScene
	{
		public:
			OptionsMenu(Screen &screen, const std::string &name, unsigned id);
			~OptionsMenu() = default;
			void changeCurrentGameScene(std::string sceneName);
			bool update() override;

		private:
			//PROPERTIES
			std::vector<std::unique_ptr<Button>> _buttons;
	};
}

#endif