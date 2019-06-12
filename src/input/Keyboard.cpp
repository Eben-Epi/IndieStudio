/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Keyboard.cpp
*/

#include "Keyboard.hpp"

Input::Keyboard::Keyboard(Irrlicht::GameScene &scene, std::vector<irr::EKEY_CODE> &&keys) :
    _scene(scene),
    _keys(keys)
{
   if (keys.size() != NB_OF_ACTIONS)
       throw KeyboardException("Invalid number of keys");
}

Input::Keyboard::~Keyboard() {}

std::vector<Input::Action> Input::Keyboard::getActions() {
    std::vector<Action> actions;

    for (unsigned i = 0; i < this->_keys.size(); i++)
        if (this->_scene.isKeyPressed(this->_keys[i]))
            actions.push_back(static_cast<Action>(i));
    return (actions);
}

void Input::Keyboard::changeKey(Action, irr::EKEY_CODE) {}