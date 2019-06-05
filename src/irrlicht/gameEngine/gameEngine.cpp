//
// Created by Eben on 05/06/2019.
//

#include "gameEngine.hpp"

bool Irrlicht::gameEngine::isKeyPressed(irr::EKEY_CODE key) //a changer
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
            return false;
//    }
}

void Irrlicht::gameEngine::registerEntity(const std::string &name)
{
    this->_entities.emplace_back(name);
}

void Irrlicht::gameEngine::deleteEntity(unsigned id) {
    for (auto it = this->_entities.begin(); it < this->_entities.end(); it++)//delete a special cube here
        if (it->_id == id)
            this->_entities.erase(it);
}

void Irrlicht::gameEngine::setAnimation(unsigned entity_id, Animations anim) {
    for (auto &ent : this->_entities)
        if (ent._id == entity_id)
            ent._anim = anim;
}

void Irrlicht::gameEngine::setPosition(unsigned entity, float x, float y) {
        for (auto &ent : this->_entities)
            if (ent._id == entity)
                ent._pos = {x, y};
}

bool Irrlicht::gameEngine::areColliding(unsigned entity1, unsigned entity2) {
        std::vector<irrEntity *> vec;

        for (auto &ent : this->_entities)
            if (ent._id == entity1 || ent._id == entity2)
                vec.push_back(&ent);

        irrEntity &e1 = *vec.at(0);
        irrEntity &e2 = *vec.at(1);

        return !(
                e1._pos.x + e1._size.x < e2._pos.x ||
                e2._pos.x + e2._size.x < e1._pos.x ||
                e1._pos.y + e1._size.y < e2._pos.y ||
                e2._pos.y + e2._size.y < e1._pos.y
        );
}

bool Irrlicht::gameEngine::isJoystickButtonPressed(unsigned id, unsigned button)
{
    return (false); //TODO Joystick::isButtonPressed(id, button);
}

float Irrlicht::gameEngine::getJoystickAxisPosition(unsigned id, unsigned axis)
{
    return (false); //TODO sf::Joystick::getAxisPosition(id, static_cast<sf::Joystick::Axis>(axis));
}
