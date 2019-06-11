/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.cpp
*/

#include "Controller.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"

Input::Controller::Controller(Irrlicht::GameScene &scene, std::vector<ControllerButtons> &&keys, unsigned id) :
	_scene(scene),
	_keys(keys),
	_id(id)
{
    if (keys.size() != 3 && keys.size() != 6)
        throw ControllerErrors(); // la condition est pas bonne , enfin je croit, je revienderais dessu quand je retournerais sur les inputs

  //TODO THROW INVALID ARG AND NOT CONTROLLER ERROR
}

Input::Controller::~Controller() {}

std::vector<Input::Action> Input::Controller::getActions() { //WIP
	std::vector<Action> actions;
	float value = 0;

	for (unsigned i = 0; i < this->_keys.size(); i++) {
		if (this->_keys[i] < 15 && this->_scene.isJoystickButtonPressed(this->_keys[i]))
			if (this->_keys[0] == LEFT_JOYSTICK || this->_keys[0] == RIGHT_JOYSTICK || this->_keys[1] == LEFT_JOYSTICK || this->_keys[1] == RIGHT_JOYSTICK)
				actions.push_back(static_cast<Action>(3 + i));
			else
				actions.push_back(static_cast<Action>(i));
		else if (this->_keys[i] > 14) {
			if (this->_keys[i] == ControllerButtons::LEFT_JOYSTICK) {

				value = this->_scene.getJoystickAxisPosition(1);
				if (value > 16384) {
					actions.push_back(Action::ACTION_DOWN);
					break;
				} else if (value < -16384) {
					actions.push_back(Action::ACTION_UP);
					break;
				}

				value = this->_scene.getJoystickAxisPosition(0);
				if (value > 16384) {
					actions.push_back(Action::ACTION_RIGHT);
					break;
				} else if (value < -16384)
					actions.push_back(Action::ACTION_LEFT);
			} else if (this->_keys[i] == ControllerButtons::RIGHT_JOYSTICK) {

				value = this->_scene.getJoystickAxisPosition(3);
				if (value > 16384) {
					actions.push_back(Action::ACTION_DOWN);
					break;
				} else if (value < -16384) {
					actions.push_back(Action::ACTION_UP);
					break;
				}

				value = this->_scene.getJoystickAxisPosition(4);
				if (value > 16384) {
					actions.push_back(Action::ACTION_RIGHT);
					break;
				} else if (value < -16384)
					actions.push_back(Action::ACTION_LEFT);
			} else if (this->_keys[i] == ControllerButtons::RT) {
				value = this->_scene.getJoystickAxisPosition(5);
				if (value >= 0){
					if (this->_keys[0] == LEFT_JOYSTICK || this->_keys[0] == RIGHT_JOYSTICK || this->_keys[1] == LEFT_JOYSTICK || this->_keys[1] == RIGHT_JOYSTICK)
						actions.push_back(static_cast<Action>(3 + i));
					else
						actions.push_back(static_cast<Action>(i));
					break;
				}
			} else if (this->_keys[i] == LT) {
				value = this->_scene.getJoystickAxisPosition(2);
				if (value >= 0) {
					if (this->_keys[0] == LEFT_JOYSTICK || this->_keys[0] == RIGHT_JOYSTICK || this->_keys[1] == LEFT_JOYSTICK || this->_keys[1] == RIGHT_JOYSTICK)
						actions.push_back(static_cast<Action>(3 + i));
					else
						actions.push_back(static_cast<Action>(i));
					break;
				}
			}
			
			//TODO vérifier valeur max tableau Axis de IEventReceiver
		}
//        std::cout << "key " << this->_keys[i] << " is " << this->_scene.isJoystickButtonPressed(this->_keys[i]) << std::endl;
	}
	return (actions);
}

void Input::Controller::changeKey(Action, unsigned) {}