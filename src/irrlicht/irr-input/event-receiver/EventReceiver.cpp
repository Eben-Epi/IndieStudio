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
	for (auto i = 0; i < MAX_BUTTON_ON_SCREEN; i++)
		this->_buttonsStates.push_back(false);
}

bool Irrlicht::EventReceiver::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		this->_keys[event.KeyInput.Key] = event.KeyInput.PressedDown;
		return (true);
	}
	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick < 4) {
        this->_joystickState[event.JoystickEvent.Joystick] = event.JoystickEvent;
        return (true);
    }
    if (event.EventType == irr::EET_GUI_EVENT) {
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
                this->_buttonsStates[event.GUIEvent.Caller->getID()] = true;
        return (true);
    }
	return (false);
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

bool Irrlicht::EventReceiver::isGuiButtonPressed(unsigned id) {
    return (this->_buttonsStates.at(id));
}

void Irrlicht::EventReceiver::resetButtonsStates() {
    for (auto i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
        this->_keys[i] = false;
    for (auto i = 0; i < MAX_BUTTON_ON_SCREEN; i++)
        this->_buttonsStates[i] = false;
}

irr::EKEY_CODE Irrlicht::EventReceiver::returnNextKeyPressed() {
    for (auto i = 0; i != irr::KEY_KEY_CODES_COUNT; i++) {
        if (this->isKeyPressed(static_cast<irr::EKEY_CODE>(i)))
            return static_cast<irr::EKEY_CODE>(i);
    }
    return(irr::KEY_KEY_CODES_COUNT);
}
