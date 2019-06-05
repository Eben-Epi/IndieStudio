//
// Created by Eben on 05/06/2019.
//

#ifndef INDIE_GAMESCENE_HPP
#define INDIE_GAMESCENE_HPP


#include <irrlicht/ISceneManager.h>
#include "../screen.hpp"
#include "../../gameEngine/gameEngine.hpp"

namespace Irrlicht {
    class gameScene {
    public:
        explicit gameScene(screen);

        ~gameScene() = default;

        //MEMBER FUNCTION
        void update();
        void addSmgr();
        void addGuiENV();

        //PROPERTIES
        screen &_window;
        irr::scene::ISceneManager *_smgr;
        irr::gui::IGUIEnvironment *_guienv;
        gameEngine _gameEngine;
    };
}


#endif //INDIE_GAMESCENE_HPP
