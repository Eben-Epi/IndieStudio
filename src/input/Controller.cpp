/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.cpp
*/

#include "Controller.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"

Input::Controller::Controller(Irrlicht::GameScene &scene, const std::vector<ControllerButtons> &keys, unsigned id, unsigned threshold) :
	_scene(scene),
	_keys(keys),
	_id(id),
	_threshold(threshold)
{
    if ((keys.size() != 3 && keys.size() != 6) || (keys.size() == 3 && keys[0] != LEFT_JOYSTICK && keys[0] != RIGHT_JOYSTICK))
        throw ControllerException("Invalid key vector given (size is invalid)");
}

std::vector<Input::Action> Input::Controller::getActions() { //WIP
	std::vector<Action> actions;
	int start = 1;
	float x;
	float y;

	if (this->_keys[0] == LEFT_JOYSTICK || this->_keys[0] == RIGHT_JOYSTICK) {
		x = this->_scene.getJoystickAxisPosition(this->_id, irr::SEvent::SJoystickEvent::AXIS_X + (this->_keys[0] == RIGHT_JOYSTICK) * 3);
		y = this->_scene.getJoystickAxisPosition(this->_id, irr::SEvent::SJoystickEvent::AXIS_Y + (this->_keys[0] == RIGHT_JOYSTICK) * 3);

		if (abs(y) > this->_threshold && y < 0)
			actions.push_back(Action::ACTION_UP);
		else if (abs(y) > this->_threshold)
			actions.push_back(Action::ACTION_DOWN);

		if (abs(x) > this->_threshold && x < 0)
			actions.push_back(Action::ACTION_LEFT);
		else if (abs(x) > this->_threshold)
			actions.push_back(Action::ACTION_RIGHT);
	} else {
		start = 4;
		for (unsigned i = 0; i < 4; i++)
			if (this->_scene.isJoystickButtonPressed(this->_id, this->_keys[i]))
				actions.push_back(static_cast<Action>(i));
	}
	for (unsigned i = 0; i + start < this->_keys.size(); i++) {
		unsigned axis = 0;

		switch (this->_keys[i + start]) {
		case LEFT_JOYSTICK:
			throw ControllerException("Invalid key vector given (LEFT_JOYSTICK is not a valid key)");
		case RIGHT_JOYSTICK:
			throw ControllerException("Invalid key vector given (RIGHT_JOYSTICK is not a valid key)");
		case RT:
			axis = irr::SEvent::SJoystickEvent::AXIS_V;
			break;
		case LT:
			axis = irr::SEvent::SJoystickEvent::AXIS_Z;
			break;
		default:
			if (this->_scene.isJoystickButtonPressed(this->_id, this->_keys[i + start]))
				actions.push_back(static_cast<Action>(i + 4));
			continue;
		}
		if (this->_scene.getJoystickAxisPosition(this->_id, axis) > 0)
			actions.push_back(static_cast<Action>(i + 4));
	}
	return (actions);
}

bool Input::Controller::isAI()
{
	return false;
}

void Input::Controller::changeKey(Action act, unsigned control) {
	joystickIn();
	switch (this->_act)
	{
	case ACTION_JOYSTICK:
		addJoystick(control);
		this->_act = Action::NO_ACTION;
		break;
	case ACTION_UP:
	case ACTION_DOWN:
	case ACTION_LEFT:
	case ACTION_RIGHT:
		if (this->_joystickOn == 3)
			removeJoystick();
		this->_keys[this->_act] = static_cast<ControllerButtons>(control);
		this->_act = Action::NO_ACTION;
		break;
	case ACTION_ACTION:
	case ACTION_ULT:
		this->_keys[this->_act - this->_joystickOn] = static_cast<ControllerButtons>(control);
		this->_act = Action::NO_ACTION;
		break;
	default:
		break;
	}
}

void Input::Controller::removeJoystick() {
	this->_keys[ACTION_UP] = static_cast<ControllerButtons>(Y);
	this->_keys[ACTION_DOWN] = static_cast<ControllerButtons>(A);
	this->_keys[ACTION_RIGHT] = static_cast<ControllerButtons>(B);
	this->_keys.push_back(static_cast<ControllerButtons>(X));
	this->_keys.push_back(static_cast<ControllerButtons>(RT));
	this->_keys.push_back(static_cast<ControllerButtons>(LT));
}

void Input::Controller::addJoystick(unsigned control) {
	if (this->_keys.size() == 3)
		this->_keys[ACTION_UP] = static_cast<ControllerButtons>(control);
	else {
		this->_keys.erase(this->_keys.begin() + ACTION_RIGHT);
		this->_keys.erase(this->_keys.begin() + ACTION_LEFT);
		this->_keys.erase(this->_keys.begin() + ACTION_DOWN);
		this->_keys[ACTION_UP] = static_cast<ControllerButtons>(control);
	}
}

void Input::Controller::joystickIn() {
	for (int i = 0; i < this->_keys.size(); i++)
		if (this->_keys[i] == LEFT_JOYSTICK || this->_keys[i] == RIGHT_JOYSTICK) {
			this->_joystickOn = 3;
			return;
		}
	this->_joystickOn = 0;
}

void Input::Controller::resetControl() {
	this->_keys = {LEFT_JOYSTICK, RT, LT};
}

std::string Input::Controller::getEnumControlString(Action code)
{
    if (this->_keys.size() == 3 && code < ::Input::Action::ACTION_ACTION)
        return Irrlicht::controller_code_str[this->_keys[0]];
    else if (this->_keys.size() == 3)
        return Irrlicht::controller_code_str[this->_keys[code - 3]];
    return (Irrlicht::controller_code_str[this->_keys[code]]);
}