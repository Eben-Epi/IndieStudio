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

namespace Irrlicht {
    enum SaveGameButtonsName
	{
		SAVE_MENU_LESS = 0,
		SAVE_MENU_MORE,
		SAVE,
	};

    class LoadGameMenu : public GameScene {
    public:
        LoadGameMenu(Screen &screen, const std::string &name, unsigned id);

        ~LoadGameMenu() = default;

        bool update() override;

    private:
        //PROPERTIES
        unsigned _slotNumber;
    };
}

#endif //BOMBERMAN_LOADGAMEMENU_HPP
