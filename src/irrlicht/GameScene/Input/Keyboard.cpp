/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Keyboard.cpp
*/

#include "Keyboard.hpp"

Irrlicht::Keyboard::Keyboard(GameScene &scene, std::vector<irr::EKEY_CODE> &&keys) :
    _scene(scene),
    _keys(keys)
{
//    if (keys.size() != Input::NB_OF_ACTIONS)
//        throw KeyboardErrors();
//      TODO THROW INVALID ARG
}

Irrlicht::Keyboard::~Keyboard() {}

std::vector<Input::Action> Irrlicht::Keyboard::getActions() {
    std::vector<::Input::Action> actions;

    for (unsigned i = 0; i < this->_keys.size(); i++)
        if (this->_scene.isKeyPressed(this->_keys[i]))
            actions.push_back(static_cast<::Input::Action>(i));
    return (actions);
}

void Irrlicht::Keyboard::changeKey(::Input::Action, irr::EKEY_CODE) {}