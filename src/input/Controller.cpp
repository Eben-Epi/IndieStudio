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
//    if (keys.size() != NB_OF_ACTIONS)
//        throw ControllerErrors(); // la condition est pas bonne , enfin je croit, je revienderais dessu quand je retournerais sur les inputs

  //TODO THROW INVALID ARG AND NOT CONTROLLER ERROR
}

Input::Controller::~Controller() {}

std::vector<Input::Action> Input::Controller::getActions() { //WIP
    std::vector<Action> actions;

    for (unsigned i = 0; i < this->_keys.size(); i++) {
        if (i < 15 && this->_scene.isJoystickButtonPressed(this->_keys[i]))
            actions.push_back(static_cast<Action>(i));
        else if (i > 14) {
        //TODO vérifier valeur max tableau Axis de IEventReceiver
        }
//        std::cout << "key " << this->_keys[i] << " is " << this->_scene.isJoystickButtonPressed(this->_keys[i]) << std::endl;
    }
    return (actions);
}

void Input::Controller::changeKey(Action, unsigned) {}