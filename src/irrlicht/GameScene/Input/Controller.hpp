/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.hpp
*/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Input.hpp"
#include "../../Screen/Screen.hpp"
#include "../../GameScene/GameScene.hpp"

namespace Irrlicht
{
    class Controller : public Input::Input
    {
        public:
            Controller(GameScene &, std::vector<unsigned> &&, unsigned);
            ~Controller();
            std::vector<::Input::Action> getActions();
            void changeKey(::Input::Action, unsigned); //keyCode -> controller Key Code

        private:
            GameScene &_scene;
            irr::SEvent *_event;
            std::vector<unsigned> _keys;
            unsigned _id;
    };
}

#endif