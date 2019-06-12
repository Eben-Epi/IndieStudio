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
	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick < 4)
		this->_joystickState[event.JoystickEvent.Joystick] = event.JoystickEvent;
	return (true);
}

bool Irrlicht::EventReceiver::isKeyPressed(const irr::EKEY_CODE keyCode) const
{
	return (this->_keys[keyCode]);
}

const irr::SEvent::SJoystickEvent &Irrlicht::EventReceiver::GetJoystickState(unsigned id) const
{
	return (this->_joystickState.at(id));
}

bool Irrlicht::EventReceiver::isJoystickKeyPressed(unsigned id, irr::u32 key) const
{
	return (this->_joystickState.at(id).IsButtonPressed(key));
}

float Irrlicht::EventReceiver::getJoystickAxisPosition(unsigned id, irr::s16 axis) const
{
	return (this->_joystickState.at(id).Axis[axis]);
}
