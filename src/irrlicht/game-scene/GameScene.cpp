//
// Created by Eben on 05/06/2019.
//

#include "GameScene.hpp"
#include "../screen/Screen.hpp"
#include "../Exceptions.hpp"

Irrlicht::GameScene::GameScene(Screen &window, std::string name, unsigned id) :
	_window(window),
	sceneName(std::move(name)),
	id(id),
	_entitiesId(0),
	_eventReceiver(window.getEventReceiver())
{
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

Irrlicht::IrrEntity& Irrlicht::GameScene::_getEntity(unsigned entity_id)
{
	for (auto &ent : this->_entities)
		if (ent->id == entity_id)
			return *ent;
	throw NoSuchEntityException("Cannot find entity with id " + std::to_string(entity_id));
}

void Irrlicht::GameScene::setAnimation(unsigned entity_id, Animations anim) {
    this->_getEntity(entity_id).setAnimation(anim);
}

void Irrlicht::GameScene::setRotation(unsigned entity, float y)
{
	this->_getEntity(entity).setRotation(y);
}

void Irrlicht::GameScene::setPosition(unsigned entity, float x, float z)
{
	this->_getEntity(entity).setPos(x, -z);
}

void Irrlicht::GameScene::setScale(unsigned entity, float x, float z)
{
	this->_getEntity(entity).setScale(x, z);
}

void Irrlicht::GameScene::setSize(unsigned entity, float x, float z)
{
	this->_getEntity(entity).setSize(x, z);
}

ECS::Vector2<float> Irrlicht::GameScene::getSize(unsigned entity)
{
	return this->_getEntity(entity).getSize();
}

bool Irrlicht::GameScene::areColliding(unsigned entity1, unsigned entity2)
{
	this->_getEntity(entity1);
	this->_getEntity(entity2);
	return false;
}

bool Irrlicht::GameScene::isJoystickButtonPressed(unsigned joystickId, unsigned button)
{
	return (this->_eventReceiver.isJoystickKeyPressed(joystickId, button));
}

float Irrlicht::GameScene::getJoystickAxisPosition(unsigned joystickId, unsigned axis)
{
	return (this->_eventReceiver.getJoystickAxisPosition(joystickId, axis));
}

bool Irrlicht::GameScene::isGuiButtonPressed(unsigned id) {
    return (this->_eventReceiver.isGuiButtonPressed(id));
}

bool Irrlicht::GameScene::isJoystickAxisPressed(unsigned joystickId, ControllerAxisGS button, unsigned threshold)
{
	float value = 0;

	switch (button) {
	case LEFT_JOYSTICK_UP:
	case LEFT_JOYSTICK_DOWN:
		value = this->getJoystickAxisPosition(joystickId, irr::SEvent::SJoystickEvent::AXIS_Y);
		break;
	case LEFT_JOYSTICK_LEFT:
	case LEFT_JOYSTICK_RIGHT:
		value = this->getJoystickAxisPosition(joystickId, irr::SEvent::SJoystickEvent::AXIS_X);
		break;
	case RIGHT_JOYSTICK_UP:
	case RIGHT_JOYSTICK_DOWN:
		value = this->getJoystickAxisPosition(joystickId, irr::SEvent::SJoystickEvent::AXIS_U);
		break;
	case RIGHT_JOYSTICK_LEFT:
	case RIGHT_JOYSTICK_RIGHT:
		value = this->getJoystickAxisPosition(joystickId, irr::SEvent::SJoystickEvent::AXIS_R);
		break;
	case RT:
		value = this->getJoystickAxisPosition(joystickId, irr::SEvent::SJoystickEvent::AXIS_Z);
		break;
	case LT:
		value = this->getJoystickAxisPosition(joystickId, irr::SEvent::SJoystickEvent::AXIS_V);
		break;

	default :
		return (false);
	}
	return (abs(value) > threshold);
}

void Irrlicht::GameScene::addCamera(float posX, float posY, float posZ, float lookAtX, float lookAtY, float lookAtZ) {
	this->_window.getSmgr()->addCameraSceneNode(0, irr::core::vector3df(posX, posY, posZ), irr::core::vector3df(lookAtX, lookAtY, lookAtZ));
}

bool Irrlicht::GameScene::update() {
    return (true);
}

void Irrlicht::GameScene::changeCurrentGameScene(std::string sceneName)
{
    for (auto &_button : this->_buttons)
        _button->setVisible(false);
    for (auto &_textBox : this->_textBoxes)
        _textBox->setVisible(false);
    this->_window.setCurrentGameScene(sceneName);
}


