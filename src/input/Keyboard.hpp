/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Keybord.hpp
*/

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Input.hpp"
#include "../irrlicht/GameScene/GameScene.hpp"

namespace Input
{
    class Keyboard : public Input {
    public:
        Keyboard(Irrlicht::GameScene &, std::vector<irr::EKEY_CODE> &&);

        ~Keyboard();

        std::vector<Action> getActions();

        void changeKey(Action, irr::EKEY_CODE);

    private:
        Irrlicht::GameScene &_scene;
        irr::SEvent *_event;
        std::vector<irr::EKEY_CODE> _keys;
    };
}


#endif