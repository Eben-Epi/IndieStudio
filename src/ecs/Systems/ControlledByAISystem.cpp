/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ControlledByAISystem.cpp
*/

#include "ControlledByAISystem.hpp"
#include "../Components/MovableComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/ControlledByAIComponent.hpp"
#include "../Components/BombDropperComponent.hpp"
#include "../Components/UltimeComponent.hpp"
#include "../ECSCore.hpp"
#include "../Components/CurseComponent.hpp"
#include "../../config.hpp"

namespace ECS
{
    ControlledByAISystem::ControlledByAISystem(ECS::ECSCore &core) :
        System("ControlledByAI", core)
    {
        this->_dependencies = {"Movable", "Position", "BombDropper", "Ultime"};
    }

    std::vector<ECS::Point> getRelativeVision(ECS::Point &point)
    {
        std::vector<ECS::Point> vision;

        vision.push_back({point.x - TILESIZE, point.y - TILESIZE});
        vision.push_back({point.x, point.y - TILESIZE});
        vision.push_back({point.x + TILESIZE, point.y - TILESIZE});
        vision.push_back({point.x - TILESIZE, point.y});
        vision.push_back({point.x + TILESIZE, point.y});
        vision.push_back({point.x - TILESIZE, point.y + TILESIZE});
        vision.push_back({point.x, point.y + TILESIZE});
        vision.push_back({point.x + TILESIZE, point.y + TILESIZE});

        return (vision);
    }

    ECS::Point getRelativePos(ECS::Point &pos)
    {
        ECS::Point point;

        if ((int)(pos.x / TILESIZE * 10) % 10 >= 5)
            point.x = pos.x / TILESIZE * (TILESIZE + 1);
        else
            point.x = pos.x / TILESIZE * TILESIZE;
        if ((int)(pos.y / TILESIZE * 10) % 10 >= 5)
            point.y = pos.y / TILESIZE * (TILESIZE + 1);
        else
            point.y = pos.y / TILESIZE * TILESIZE;
        return (point);
    }

    std::vector<Input::Action> ControlledByAISystem::AIBrain(ECS::Entity &entity, MovableComponent &movableComponent)
    {
        auto &in = reinterpret_cast<ControlledByAIComponent &>(entity.getComponentByName("ControlledByAI"));
        auto &pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
        std::vector<Entity *> entities = this->_core.getEntitiesByComponent("Position");
        std::vector<Entity *> explodableEntities = this->_core.getEntitiesByComponent("Explode");
        std::vector<Point> cannotMoveThere;
        Point relativePos = getRelativePos(pos.pos);
        std::vector<Point> relativeVision = getRelativeVision(relativePos);

        for (Entity *e : explodableEntities) {
            if (e->hasComponent("Explodable")) {
                auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));

                cannotMoveThere.emplace_back(ePos.pos);
                cannotMoveThere.push_back({ePos.pos.x + TILESIZE, ePos.pos.y});
                cannotMoveThere.push_back({ePos.pos.x - TILESIZE, ePos.pos.y});
                cannotMoveThere.push_back({ePos.pos.x, ePos.pos.y + TILESIZE});
                cannotMoveThere.push_back({ePos.pos.x, ePos.pos.y - TILESIZE});
            }
        }
        for (Point point : cannotMoveThere)
            for (Point vision : relativeVision) (pos.pos.x == point.x && pos.pos.y == point.y)

        for (Entity *e : entities) {
            if (e->hasComponent("Collider") && !e->hasComponent("Collision"))
        }
    }

    void ControlledByAISystem::updateEntity(ECS::Entity &entity)
    {
        auto &mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
        auto &bombDropper = reinterpret_cast<BombDropperComponent &>(entity.getComponentByName("BombDropper"));
        auto &uc = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));
        std::vector<Input::Action> actions = AIBrain(entity, mov);
        unsigned char newDir = 0;

        uc.castUlt = false;
        bombDropper.dropBomb = false;
        for (auto &action : actions) {
            switch (action) {
                case Input::ACTION_UP:
                case Input::ACTION_DOWN:
                case Input::ACTION_LEFT:
                case Input::ACTION_RIGHT:
                    newDir = 1U << action;
                    break;
                case Input::ACTION_ACTION:
                    bombDropper.dropBomb = true;
                    break;
                case Input::ACTION_ULT:
                    uc.castUlt = true;
            }
        }
        if (newDir) {
            if (IS_CURSED(entity, CurseComponent::REVERSECONTROL))
                mov.dir = (newDir << 2) | (newDir >> 2);
            else
                mov.dir = newDir;
            mov.speed = mov.speed > 0 ? mov.speed : mov.maxSpeed / 2;
        } else
            mov.speed = 0;
    }
}