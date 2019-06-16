/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** HowToPlayMenu.hpp
*/

#ifndef BOMBERMAN_HOWTOPLAYGAMEMENU_HPP
#define BOMBERMAN_HOWTOPLAYGAMEMENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../hud/Button.hpp"

namespace Irrlicht {
    enum HowToPlayButtonsName
	{
		HTP_GAME_BACK = 0,
	};

    class HowToPlayMenu : public GameScene {
    public:
        HowToPlayMenu(Screen &screen, const std::string &name, unsigned id);

        ~HowToPlayMenu() = default;

        bool update() override;

    private:
        //PROPERTIES
    };
}

#endif //BOMBERMAN_LOADGAMEMENU_HPP
