//
// Created by eben_epitech on 6/15/19.
//

#ifndef BOMBERMAN_LOADGAMEMENU_HPP
#define BOMBERMAN_LOADGAMEMENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../hud/Button.hpp"

namespace Irrlicht {
    enum LoadGameMenuButtonName {
        SLOT_ONE = 0,
        SLOT_TWO,
        SLOT_THREE,
        SLOT_FOUR,
        SLOT_FIVE,
        BACK_FROM_LOAD_GAME,
    };

    class LoadGameMenu : public GameScene {
    public:
        LoadGameMenu(Screen &screen, const std::string &name, unsigned id);

        ~LoadGameMenu() = default;

        bool update() override;

    private:
        //PROPERTIES
    };
}

#endif //BOMBERMAN_LOADGAMEMENU_HPP
