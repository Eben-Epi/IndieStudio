/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.hpp
*/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Input.hpp"
#include "../irrlicht/screen/Screen.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"

namespace Input
{
    enum ControllerButtons {
        A = 0,
        B,
        X,
        Y,
        LB,
        RB,
        SELECT,
        START,
        MIDDLE,
        LJ_PRESSED,
        RJ_PRESSED,
        LEFT_CROSS,
        RIGHT_CROSS,
        UP_CROSS,
        DOWN_CROSS,
        LJ_HORIZONTAL,
        LJ_VERTICAL,
        RT,
        RJ_HORIZONTAL,
        RJ_VERTICAL,
        LT,
        NUMBER_BUTTONS
    };

    class Controller : public Input
    {
        public:
            Controller(Irrlicht::GameScene &, std::vector<ControllerButtons> &&, unsigned);
            ~Controller();
            std::vector<Action> getActions();
            void changeKey(Action, unsigned); //keyCode -> controller Key Code

        private:
            Irrlicht::GameScene &_scene;
            irr::SEvent *_event;
            std::vector<ControllerButtons> _keys;
            unsigned _id;
    };
}

#endif