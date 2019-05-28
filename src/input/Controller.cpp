/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.cpp
*/

#include "Controller.hpp"

input::Controller::Controller() {}

input::Controller::~Controller() {}

std::vector<input::Action> input::Controller::getNextAction() {return(std::vector{input::Action::ACTION});}

void input::Controller::changeKey(input::Action, irr::EKEY_CODE) {}