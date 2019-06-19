/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.hpp
*/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Input.hpp"

namespace Irrlicht {
    class GameScene;
}

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
            Controller(Irrlicht::GameScene &, const std::vector<ControllerButtons> &, unsigned, unsigned threshold = 16384);
            ~Controller() = default;
            std::vector<Action> getActions();
            void changeKey(Action, unsigned); //keyCode -> controller Key Code
            bool isAI() override;
            void addJoystick(unsigned);
            void joystickIn();
            void removeJoystick();
            void resetControl() override;
            std::string getEnumControlString(Action code);

        private:
            Irrlicht::GameScene &_scene;
            std::vector<ControllerButtons> _keys;
            unsigned _id;
            unsigned _threshold;
            int _joystickOn = 0;
            Action _act = Action::NO_ACTION;
    };
}

#endif