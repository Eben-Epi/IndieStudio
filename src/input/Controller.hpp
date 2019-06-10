/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.hpp
*/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Input.hpp"
#include "../irrlicht/Screen/Screen.hpp"
#include "../irrlicht/GameScene/GameScene.hpp"

namespace Input
{
    class Controller : public Input
    {
        public:
            Controller(Irrlicht::GameScene &, std::vector<unsigned> &&, unsigned);
            ~Controller();
            std::vector<Action> getActions();
            void changeKey(Action, unsigned); //keyCode -> controller Key Code

        private:
            Irrlicht::GameScene &_scene;
            irr::SEvent *_event;
            std::vector<unsigned> _keys;
            unsigned _id;
    };
}

#endif