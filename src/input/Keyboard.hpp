/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Keybord.hpp
*/

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Input.hpp"

namespace Input
{
    class Keyboard : public Input
    {
        public:
            Keyboard(Irrlicht::Irrlicht &, std::vector<irr::EKEY_CODE> &&);
            ~Keyboard();
            std::vector<Action> getActions();
            void changeKey(Action, irr::EKEY_CODE);

        private:
            Irrlicht::Irrlicht &_irrlicht;
            irr::SEvent *_event;
            std::vector<irr::EKEY_CODE> _keys;
    };
}

#endif