/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.cpp
*/

#include "Controller.hpp"

Input::Controller::Controller() {}

Input::Controller::~Controller() {}

std::vector<Input::Action> Input::Controller::getActions() {
    std::vector<Action> Actions;
    return(Actions);
}

void Input::Controller::changeKey(Action, irr::EKEY_CODE) {}