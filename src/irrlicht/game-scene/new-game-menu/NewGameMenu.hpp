//
// Created by eben_epitech on 6/15/19.
//

#ifndef BOMBERMAN_NEWGAMEMENU_HPP
#define BOMBERMAN_NEWGAMEMENU_HPP

#include <vector>
#include <memory>
#include "../GameScene.hpp"
#include "../hud/Button.hpp"

namespace Irrlicht {
    enum NewGameMenuButtonName {
        NUMBER_OF_PLAYERS_LESS = 0,
        NUMBER_OF_PLAYERS_MORE,
        NUMBER_OF_AI_LESS,
        NUMBER_OF_AI_MORE,
        SOUND_LESS,
        SOUND_MORE,
        SOUND_MUTE,
        NEXT_FROM_NEW_GAME,
        BACK_FROM_NEW_GAME
    };

    class NewGameMenu : public GameScene {
    public:
        NewGameMenu(Screen &screen, const std::string &name, unsigned id);
        ~NewGameMenu() = default;

        bool update() override;

    private:
        //PROPERTIES
        unsigned _playersNumber;
        unsigned _soundVolume;
        unsigned _iaNumber;
        unsigned _tmpSoundVolume;
    };
}


#endif //BOMBERMAN_NEWGAMEMENU_HPP
