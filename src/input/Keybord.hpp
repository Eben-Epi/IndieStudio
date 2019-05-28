/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Keybord.hpp
*/

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Input.hpp"

namespace input
{
    class Keyborad : public Input
    {
        public:
            Keyborad();
            ~Keyborad();
            std::vector<input::Action> getNextAction();
            void changeKey(input::Action, irr::EKEY_CODE);

        private:
    };
}

#endif