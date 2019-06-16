/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** SaveMenu.hpp
*/

#ifndef BOMBERMAN_SAVEGAMEMENU_HPP
#define BOMBERMAN_SAVEGAMEMENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../hud/Button.hpp"
#include "../../../map/Map.hpp"

namespace Irrlicht {
    enum SaveGameButtonsName
	{
		SAVE_MENU_LESS = 0,
		SAVE_MENU_MORE,
		SAVE,
	};

    class SaveMenu : public GameScene {
    public:
        SaveMenu(Screen &screen, const std::string &name, unsigned id, Map::Map *map);

        ~SaveMenu() = default;

        bool update() override;

    private:
        //PROPERTIES
        unsigned _slotNumber;
        Map::Map *_map;
    };
}

#endif //BOMBERMAN_LOADGAMEMENU_HPP
