/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Controller.cpp
*/

#include "Controller.hpp"
#include "../../Screen/gameScenes/GameScene.hpp"

Irrlicht::Controller::Controller(GameScene &scene, std::vector<unsigned> &&keys, unsigned id) :
    _scene(scene),
    _keys(keys),
    _id(id)
{
//    if (keys.size() != ::Input::NB_OF_ACTIONS)
  //      throw ControllerErrors(); // la condition est pas bonne , enfin je croit, je revienderais dessu quand je retournerais sur les inputs

  //TODO THROW INVALID ARG AND NOT CONTROLLER ERROR
}

Irrlicht::Controller::~Controller() {}

std::vector<Input::Action> Irrlicht::Controller::getActions() { //does not work
    std::vector<::Input::Action> actions;

    for (unsigned i = 0; i < this->_keys.size(); i++) {
        if (this->_scene._gameEngine.isJoystickButtonPressed(_id, this->_keys[i]))
            actions.push_back(static_cast<::Input::Action>(i));
    }
    return (actions);
}

void Irrlicht::Controller::changeKey(::Input::Action, unsigned) {}