#include <utility>

//
// Created by Eben on 05/06/2019.
//

#include "GameScene.hpp"
#include "../Screen/Screen.hpp"

Irrlicht::GameScene::GameScene(Screen &window, std::string name, unsigned id) :
    _window(window),
    sceneName(std::move(name)),
    id(id)
{
    this->_guienv = nullptr;
    this->_smgr = nullptr;
}

bool Irrlicht::GameScene::isKeyPressed(irr::EKEY_CODE key) //a changer
{
//    switch (key) {
//        case irr::KEY_KEY_Z:
//            return sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
//        case irr::KEY_KEY_Q:
//            return sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
//        case irr::KEY_KEY_S:
//            return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
//        case irr::KEY_KEY_D:
//            return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
//        case irr::KEY_SPACE:
//            return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
//        default:
//            return false;
//    }
    return (true);
}

unsigned int Irrlicht::GameScene::registerEntity(const std::string &name)
{
    _entities_id++;
    this->_entities.emplace_back(name, _entities_id);
    return(_entities_id);
}

void Irrlicht::GameScene::deleteEntity(unsigned id) {
    for (auto it = this->_entities.begin(); it < this->_entities.end(); it++)//delete a special cube here
        if (it->_id == id)
            this->_entities.erase(it);
}

void Irrlicht::GameScene::setAnimation(unsigned entity_id, Animations anim) {
    for (auto &ent : this->_entities)
        if (ent._id == entity_id)
            ent._anim = anim;
}

void Irrlicht::GameScene::setPosition(unsigned entity, float x, float y) {
        for (auto &ent : this->_entities)
            if (ent._id == entity)
                ent._pos = {x, y};
}

bool Irrlicht::GameScene::areColliding(unsigned entity1, unsigned entity2) {
        std::vector<IrrEntity *> vec;

        for (auto &ent : this->_entities)
            if (ent._id == entity1 || ent._id == entity2)
                vec.push_back(&ent);

        IrrEntity &e1 = *vec.at(0);
        IrrEntity &e2 = *vec.at(1);

        return !(
                e1._pos.x + e1._size.x < e2._pos.x ||
                e2._pos.x + e2._size.x < e1._pos.x ||
                e1._pos.y + e1._size.y < e2._pos.y ||
                e2._pos.y + e2._size.y < e1._pos.y
        );
}

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
