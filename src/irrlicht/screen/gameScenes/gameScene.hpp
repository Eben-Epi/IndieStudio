//
// Created by Eben on 05/06/2019.
//

#ifndef INDIE_GAMESCENE_HPP
#define INDIE_GAMESCENE_HPP


#include <irrlicht/ISceneManager.h>
#include "../../gameEngine/GameEngine.hpp"

namespace Irrlicht {

    class Screen;

    class GameScene {
    public:
        explicit GameScene(Screen &);

        ~GameScene() = default;

        //MEMBER FUNCTION
        void update();
        void addSmgr();
        void addGuiENV();

        //PROPERTIES
        Screen &_window;
        irr::scene::ISceneManager *_smgr;
        irr::gui::IGUIEnvironment *_guienv;
        GameEngine _gameEngine;
    };
}


#endif //INDIE_GAMESCENE_HPP
