/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EventReceiver.cpp
*/

#include "EventReceiver.hpp"

Irrlicht::EventReceiver::EventReceiver() {
	for (auto i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
		this->_keys[i] = false;
}

void Irrlicht::EventReceiver::update()
{
	for (auto i = 0; i < this->_keys.size(); i++)
		this->_keys[i] = false;
}

void Irrlicht::EventReceiver::onEvent(const irr::SEvent &event)
{
	this->_keys[event.KeyInput.Key] = event.KeyInput.PressedDown;
}

bool Irrlicht::EventReceiver::isKeyPressed(const irr::EKEY_CODE keyCode) const
{
	return this->_keys[keyCode];
}