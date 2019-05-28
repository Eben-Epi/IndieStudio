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
#include <vector>

namespace input
{
    class Input
    {
        public:
            Input();
            ~Input();
            virtual std::vector<input::Action> getNextAction() = 0;

        private:
    };

    enum Action {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ACTION,
        ULT
    };
}

#endif