/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ControlledByAISystem.cpp
*/

#include <random>
#include "ControlledByAISystem.hpp"
#include "../components/MovableComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/ControlledByAIComponent.hpp"
#include "../components/BombDropperComponent.hpp"
#include "../components/UltimeComponent.hpp"
#include "../ECSCore.hpp"
#include "../components/CurseComponent.hpp"
#include "../../config.hpp"
#include "../components/ColliderComponent.hpp"

namespace ECS
{
    ControlledByAISystem::ControlledByAISystem(ECS::ECSCore &core) :
        System("ControlledByAI", core)
    {
        this->_dependencies = {"Movable", "Position", "BombDropper", "Ultime"};
    }

    std::vector<Input::Action> getTheBestWay(std::vector<int> &bonusMalusZone)
    {
        int i;
        int j = 0;
        int nb = 1;
        std::vector<Input::Action> actions;
        std::random_device rand_device;

        for (i = 1; i < bonusMalusZone.size(); ++i) {
            if (bonusMalusZone[i] > bonusMalusZone[j]) {
                j = i;
                nb = 1;
            }
            else if (bonusMalusZone[i] == bonusMalusZone[j])
                ++nb;
        }
        if (nb > 1) {
            nb = rand_device() % nb + 1;
            for (i = 0; i < bonusMalusZone.size() && nb > 0; ++i) {
                if (bonusMalusZone[i] == bonusMalusZone[j])
                    --nb;
            }
            j = i - 1;
        }
        switch (j) {
            case 0:
                actions.push_back(Input::Action::ACTION_UP);
                break;
            case 1:
                actions.push_back(Input::Action::ACTION_LEFT);
                break;
            case 3:
                actions.push_back(Input::Action::ACTION_RIGHT);
                break;
            case 4:
                actions.push_back(Input::Action::ACTION_DOWN);
            default:
                break;
        }
        return (actions);
    }

    void updateRelativeVision(
        std::vector<ECS::Point> &cannotMoveThere,
        std::vector<ECS::Point> &relativeVision,
        std::vector<int> &bonusMalusZone,
        int dangerLevel
)
    {
        for (Point point : cannotMoveThere) {
            auto infoIt = bonusMalusZone.begin();
            for (auto it = relativeVision.begin(); it < relativeVision.end(); ++it) {
                if (it.base()->x == point.x && it.base()->y == point.y) {
                    *(infoIt.base()) += dangerLevel;
                    for (int score : bonusMalusZone)
                    break;
                }
                ++infoIt;
            }
        }
    }

    std::vector<ECS::Point> getRelativeVision(ECS::Point &point)
    {
        std::vector<ECS::Point> vision;

        vision.push_back({point.x, point.y - TILESIZE});
        vision.push_back({point.x - TILESIZE, point.y});
        vision.push_back({point.x, point.y});
        vision.push_back({point.x + TILESIZE, point.y});
        vision.push_back({point.x, point.y + TILESIZE});

        return (vision);
    }

    ECS::Point getRelativePos(ECS::Point &pos)
    {
        ECS::Point point;

        if ((int)(pos.x / TILESIZE * 10) % 10 >= 5)
            point.x = (int)(pos.x / TILESIZE) * (TILESIZE * 2);
        else
            point.x = (int)(pos.x / TILESIZE) * TILESIZE;
        if ((int)(pos.y / TILESIZE * 10) % 10 >= 5)
            point.y = (int)(pos.y / TILESIZE) * (TILESIZE * 2);
        else
            point.y = (int)(pos.y / TILESIZE) * TILESIZE;
        return (point);
    }

    std::vector<Input::Action> ControlledByAISystem::AIBrain(ECS::Entity &entity, MovableComponent &movable)
    {
        auto &in = reinterpret_cast<ControlledByAIComponent &>(entity.getComponentByName("ControlledByAI"));
        auto &pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
        std::vector<Entity *> colliders = this->_core.getEntitiesByComponent("Collider");
        std::vector<Entity *> explodableEntities = this->_core.getEntitiesByComponent("Explode");
        std::vector<Entity *> powerUps = this->_core.getEntitiesByComponent("PowerUp");
        Point relativePos = getRelativePos(pos.pos);
        std::vector<Point> relativeVision = getRelativeVision(relativePos);
        std::vector<Point> blockZone;
        std::vector<Point> dangerZone;
        std::vector<Point> bonusZone;
        std::vector<int> bonusMalusZone = {0, 0, 0, 0, 0};
        static int t = 0;
        static std::vector<Input::Action> actions;

        if (t == 0) {
            for (Entity *e : colliders) {
                auto &eCollide = reinterpret_cast<ColliderComponent &>(e->getComponentByName("Collider"));
                auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));

                if (eCollide.hardness >= 1)
                    blockZone.emplace_back(getRelativePos(ePos.pos));
            }
            updateRelativeVision(blockZone, relativeVision, bonusMalusZone, -1000000);
            for (Entity *e : explodableEntities) {
                auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));
                Point relaPos = getRelativePos(ePos.pos);

                dangerZone.push_back({relaPos.x + TILESIZE, relaPos.y});
                dangerZone.push_back({relaPos.x - TILESIZE, relaPos.y});
                dangerZone.push_back({relaPos.x, relaPos.y + TILESIZE});
                dangerZone.push_back({relaPos.x, relaPos.y - TILESIZE});
            }
            updateRelativeVision(dangerZone, relativeVision, bonusMalusZone, -20);

            for (Entity *e : powerUps) {
                auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));

                bonusZone.emplace_back(getRelativePos(ePos.pos));
            }
            updateRelativeVision(bonusZone, relativeVision, bonusMalusZone, 20);
            actions = getTheBestWay(bonusMalusZone);
        }
        ++t;
        if (t == 60)
            t = 0;
        return (actions);
    }

    void ControlledByAISystem::updateEntity(ECS::Entity &entity)
    {
        auto &mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
        auto &bombDropper = reinterpret_cast<BombDropperComponent &>(entity.getComponentByName("BombDropper"));
        auto &uc = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));
        std::vector<Input::Action> actions;
        unsigned char newDir = 0;

        actions = AIBrain(entity, mov);
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