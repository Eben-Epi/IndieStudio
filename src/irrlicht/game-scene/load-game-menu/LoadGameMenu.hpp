/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** LoadGameMenu.hpp
*/

#ifndef BOMBERMAN_LOADGAMEMENU_HPP
#define BOMBERMAN_LOADGAMEMENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../main-menu/Button.hpp"
#include "../../textbox/TextBox.hpp"

namespace Irrlicht
{
	enum LoadGameButtonsName
	{
		LOAD_GAME_NEXT = 0,
		LOAD_GAME_BACK,
		SELECT_SLOT_LESS,
		SELECT_SLOT_MORE,

	};

	class LoadGameMenu : public GameScene
	{
		public:
			LoadGameMenu(Screen &screen, const std::string &name, unsigned id);
			~LoadGameMenu() = default;
			void changeCurrentGameScene(std::string sceneName);
			bool update() override;

		private:
			//PROPERTIES
			std::vector<std::unique_ptr<Button>> _buttons;
			std::vector<std::unique_ptr<TextBox>> _textBoxes;
	};
}

#endif //BOMBERMAN_MAINMENU_HPP
