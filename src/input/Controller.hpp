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
        LEFT_JOYSTICK,
        RIGHT_JOYSTICK,
        RT,
        LT,
        NUMBER_BUTTONS
    };

    class Controller : public Input
    {
        public:
            Controller(Irrlicht::GameScene &, std::vector<ControllerButtons> &&, unsigned, unsigned threshold = 16384);
            ~Controller() = default;
            std::vector<Action> getActions();
            void changeKey(Action, unsigned); //keyCode -> controller Key Code
            bool isAI() override;

        private:
            Irrlicht::GameScene &_scene;
            std::vector<ControllerButtons> _keys;
            unsigned _id;
            unsigned _threshold;
    };
}

#endif