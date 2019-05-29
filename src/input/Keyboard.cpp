/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Keyboard.cpp
*/

#include "Keyboard.hpp"
#include <iostream>

Input::Keyborad::Keyborad(Irrlicht::Irrlicht &irrlicht, std::vector<irr::EKEY_CODE> &&keys) :
    _irrlicht(irrlicht),
    _keys(keys)
{
    if (keys.size() != NB_OF_ACTIONS)
        throw std::exception();//MYSUPEREXCPETION
}

Input::Keyborad::~Keyborad() {}

std::vector<Input::Action> Input::Keyborad::getActions() {
    std::vector<Action> actions;

    for (unsigned i = 0; i < this->_keys.size(); i++)
        if (this->_irrlicht.isKeyPressed(this->_keys[i]))
            actions.push_back(static_cast<Action>(i));
    return (actions);
}

void Input::Keyborad::changeKey(Action, irr::EKEY_CODE) {}