#include <utility>

//
// Created by Eben on 05/06/2019.
//

#include "GameScene.hpp"
#include "../screen/Screen.hpp"

Irrlicht::GameScene::GameScene(Screen &window, const std::string &name, unsigned id) :
    _window(window),
    sceneName(name),
    id(id),
    _entitiesId(0),
    _eventReceiver(window.getEventReceiver())
{
    this->_window.getSmgr()->addCameraSceneNode(0, irr::core::vector3df(75, 125, 15), irr::core::vector3df(75, 15, 55));
}

bool Irrlicht::GameScene::isKeyPressed(irr::EKEY_CODE key)
{
    return (this->_eventReceiver.isKeyPressed(key));
}

unsigned int Irrlicht::GameScene::registerEntity(const std::string &name)
{
    this->_entities.emplace_back(
    	new IrrEntity{
    		name,
    		this->_entitiesId,
    		this->_window.getSmgr(),
    		this->_window.getDriver()
    	}
    );
    return(this->_entitiesId++);
}

void Irrlicht::GameScene::deleteEntity(unsigned id) {
    for (auto it = this->_entities.begin(); it < this->_entities.end(); it++)
        while (it < this->_entities.end() && (*it)->id == id)
            this->_entities.erase(it);
}

void Irrlicht::GameScene::setAnimation(unsigned entity_id, Animations anim) {
    for (auto &ent : this->_entities)
        if (ent->id == entity_id)
            ent->anim = anim;
}

void Irrlicht::GameScene::setPosition(unsigned entity, float x, float y) {
    for (auto &ent : this->_entities)
        if (ent->id == entity)
            ent->setPos(x, y);
}

bool Irrlicht::GameScene::areColliding(unsigned entity1, unsigned entity2) {
	return false;
}

//TODO ZARGITH add to event receiver http://irrlicht.sourceforge.net/docu/example019.html

bool Irrlicht::GameScene::isJoystickButtonPressed(unsigned id, unsigned button)
{
    return (false); //TODO Joystick::isButtonPressed(id, button);
}

float Irrlicht::GameScene::getJoystickAxisPosition(unsigned id, unsigned axis)
{
    return (false); //TODO sf::Joystick::getAxisPosition(id, static_cast<sf::Joystick::Axis>(axis));
}

void Irrlicht::GameScene::update() {
}
