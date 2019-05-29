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

#include <vector>

namespace Input
{
    enum Action {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ACTION,
        ULT,
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