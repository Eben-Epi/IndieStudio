/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** KeyManagingMenu.hpp
*/

#ifndef DEMO_MENU_HPP
#define DEMO_MENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../hud/Button.hpp"
#include "../../../input/AIBrain.hpp"
#include "../../../map/Map.hpp"

namespace Irrlicht
{
	class DemoMenu : public GameScene
	{
	public:
		DemoMenu(Screen &screen, const std::string &name, unsigned id);
		~DemoMenu() override = default;
		bool update() override;

	private:
		//PROPERTIES
		unsigned _clock = 0;
		unsigned _gameClock = 0;
		std::unique_ptr<Map::Map> _map;
		std::vector<std::unique_ptr<Input::Input>> _ais;
	};
}

#endif