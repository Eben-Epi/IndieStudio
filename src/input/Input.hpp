/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Input.hpp
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <irrlicht/irrlicht.h>
#include <irrlicht/Keycodes.h>
#include <irrlicht/ILogger.h>
#include <irrlicht/irrString.h>
#include <irrlicht/IEventReceiver.h>
#include "../irrlicht/Irrlicht.hpp"
#include "./error/Errors.hpp"
#include <iostream>
#include <vector>

namespace Input
{
    enum Action {
        ACTION_UP,
        ACTION_LEFT,
        ACTION_DOWN,
        ACTION_RIGHT,
        ACTION_ACTION,
        ACTION_ULT,
        NB_OF_ACTIONS
    };
    class Input
    {
        public:
            virtual std::vector<Action> getActions() = 0;

        private:
    };
}

#endif