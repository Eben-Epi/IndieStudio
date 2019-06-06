/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Keybord.hpp
*/

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Input.hpp"
#include "../../Screen/gameScenes/GameScene.hpp"

namespace Irrlicht {
    class Keyboard : public Input::Input {
    public:
        Keyboard(GameScene &, std::vector<irr::EKEY_CODE> &&);

        ~Keyboard();

        std::vector<::Input::Action> getActions();

        void changeKey(::Input::Action, irr::EKEY_CODE);

    private:
        GameScene &_scene;
        irr::SEvent *_event;
        std::vector<irr::EKEY_CODE> _keys;
    };
}


#endif