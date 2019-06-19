/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Input.hpp
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <vector>
#include <irrlicht/irrlicht.h>
#include <irrlicht/Keycodes.h>
#include <irrlicht/ILogger.h>
#include <irrlicht/irrString.h>
#include <irrlicht/IEventReceiver.h>
#include "./error/Errors.hpp"

namespace Input {
    enum Action {
        ACTION_UP,
        ACTION_RIGHT,
        ACTION_DOWN,
        ACTION_LEFT,
        ACTION_ACTION,
        ACTION_ULT,
        NB_OF_ACTIONS,
        ACTION_JOYSTICK,
        NO_ACTION
    };

    enum KeysButtonName
    {
        BACK_FROM_KEYS_MANAGING = 0,
        NEXT_FROM_KEYS_MANAGING,
        P1_UP,
        P1_RIGHT,
        P1_DOWN,
        P1_LEFT,
        P1_DROP,
        P1_ULT,
        P2_UP,
        P2_RIGHT,
        P2_DOWN,
        P2_LEFT,
        P2_DROP,
        P2_ULT,
        P3_UP,
        P3_RIGHT,
        P3_DOWN,
        P3_LEFT,
        P3_DROP,
        P3_ULT,
        P4_UP,
        P4_RIGHT,
        P4_DOWN,
        P4_LEFT,
        P4_DROP,
        P4_ULT,
        P1_INPUT_CHOICE,
        P2_INPUT_CHOICE,
        P3_INPUT_CHOICE,
        P4_INPUT_CHOICE
    };

    class Input {
    public:
        virtual std::vector<Action> getActions() = 0;
        virtual bool isAI() = 0;
        virtual void resetControl() = 0;
        virtual std::string getEnumControlString(Action code) = 0;

    private:
    };
}

#endif
