//
// Created by Eben on 05/06/2019.
//

#ifndef INDIE_GAMEENGINE_HPP
#define INDIE_GAMEENGINE_HPP

#include <string>
#include <irrlicht/Keycodes.h>
#include <irrlicht/IEventReceiver.h>
#include <irrlicht/IVideoDriver.h>
#include <irrlicht/irrlicht.h>
#include <iostream>
#include "../Animations.hpp"
#include "../../ecs/Entity.hpp"
#include "../../ecs/data/Vector2.hpp"
#include "IrrEntity/IrrEntity.hpp"

namespace Irrlicht {

    class GameEngine {
    public:
        GameEngine();
        ~GameEngine() = default;

        unsigned int registerEntity(const std::string &name);
        void deleteEntity(unsigned id);
        bool areColliding(unsigned entity1, unsigned entity2);
        void setAnimation(unsigned entity, Animations anim);
        void setPosition(unsigned entity, float x, float y);
        bool isKeyPressed(irr::EKEY_CODE key);
        bool isJoystickButtonPressed(unsigned id, unsigned button);
        float getJoystickAxisPosition(unsigned id, unsigned axis);
        // TODO void createMesh() or cube;

        std::vector<IrrEntity> _entities;
        unsigned _entity_id;
    };
}


#endif //INDIE_GAMEENGINE_HPP
