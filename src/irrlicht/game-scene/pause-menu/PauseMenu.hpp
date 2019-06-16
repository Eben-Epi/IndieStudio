/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** PauseMenu.hpp
*/

#ifndef BOMBERMAN_PAUSEMENU_HPP
#define BOMBERMAN_PAUSEMENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../hud/Button.hpp"
#include "../../../map/Map.hpp"

namespace Irrlicht {
	enum PauseButtonsName
	{
		RESUME = 0,
		SAVE_AND_EXIT,
		PAUSE_EXIT
	};

	class PauseMenu : public GameScene {
	public:
		PauseMenu(Screen &screen, const std::string &name, unsigned id, Map::Map *map);

		~PauseMenu() = default;

		bool update() override;

	private:
		//PROPERTIES
		Map::Map *_map;
	};
}

#endif //BOMBERMAN_LOADGAMEMENU_HPP
