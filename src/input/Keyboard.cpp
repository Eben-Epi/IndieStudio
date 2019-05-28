/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Keyboard.cpp
*/

#include "Keybord.hpp"

input::Keyborad::Keyborad() {}

input::Keyborad::~Keyborad() {}

std::vector<input::Action> input::Keyborad::getNextAction() {return(std::vector{input::Action::ACTION});}

void input::Keyborad::changeKey(input::Action, irr::EKEY_CODE) {}