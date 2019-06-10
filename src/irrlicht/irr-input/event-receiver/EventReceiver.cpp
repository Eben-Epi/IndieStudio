/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EventReceiver.cpp
*/

#include <iostream>
#include "EventReceiver.hpp"

Irrlicht::EventReceiver::EventReceiver() {
	for (auto i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
		this->_keys.push_back(false);
}

bool Irrlicht::EventReceiver::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		this->_keys[event.KeyInput.Key] = event.KeyInput.PressedDown;
	return (true);
}

bool Irrlicht::EventReceiver::isKeyPressed(const irr::EKEY_CODE keyCode) const
{
	return this->_keys[keyCode];
}