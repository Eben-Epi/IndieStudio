/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.cpp
*/

#include "Controller.hpp"

Input::Controller::Controller(Irrlicht::Irrlicht &irrlicht, std::vector<unsigned> &&keys, unsigned id) :
    _irrlicht(irrlicht),
    _keys(keys),
    _id(id)
{
//    if (keys.size() != NB_OF_ACTIONS)
//        throw std::exception();//MYSUPEREXCPETION
}

Input::Controller::~Controller() {}

std::vector<Input::Action> Input::Controller::getActions() { //does not work
    std::vector<Action> actions;
    int action;
    for (unsigned i = 0; i < this->_keys.size(); i++) {
        if (this->_irrlicht.isJoystickButtonPressed(_id, this->_keys[i]))
            actions.push_back(static_cast<Action>(i));
    }
    return (actions);
}

void Input::Controller::changeKey(Action, unsigned) {}