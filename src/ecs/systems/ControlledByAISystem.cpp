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
#include "../components/ExplodeComponent.hpp"

namespace ECS
{
    ControlledByAISystem::ControlledByAISystem(ECS::ECSCore &core) :
        System("ControlledByAI", core)
    {
        this->_dependencies = {"Movable", "Position", "BombDropper", "Ultime"};
    }

    bool canEscape(std::vector<int> &bonusMalusZone)
    {
        int escapableWays = 0;

        for (int score : bonusMalusZone) {
            if (score >= 0)
                ++escapableWays;
        }
        return (escapableWays == 2);
    }

    std::vector<Input::Action> getTheBestWay(std::vector<int> &bonusMalusZone, std::vector<Input::Action> previous)
    {
        int i;
        int j = 0;
        std::vector<int> pos = {0};
        std::vector<Input::Action> actions;
        std::random_device rand_device;

        for (i = 1; i < bonusMalusZone.size(); ++i) {
            if (bonusMalusZone[i] > bonusMalusZone[j]) {
                j = i;
                pos.clear();
                pos.push_back(i);
            }
            else if (bonusMalusZone[i] == bonusMalusZone[j])
                pos.push_back(i);
        }
        if (pos.size() > 1)
            j = rand_device() % (int)pos.size();
        switch (pos[j]) {
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
                break;
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
        int xTmp = (int)(pos.pos.x / TILESIZE * 100) % 100;
        int yTmp = (int)(pos.pos.x / TILESIZE * 100) % 100;
        static std::vector<Input::Action> actions {Input::ACTION_LEFT};
        static int time = 0;

        if ((xTmp <= 10 && yTmp <= 10) && time == 0) {
            for (Entity *e : colliders) {
                auto &eCollide = reinterpret_cast<ColliderComponent &>(e->getComponentByName("Collider"));
                auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));

                if (eCollide.hardness >= 1)
                    blockZone.emplace_back(getRelativePos(ePos.pos));
                else if (e->hasComponent("OnCollisionDamageDealer"))
                    blockZone.emplace_back(getRelativePos(ePos.pos));
            }
            updateRelativeVision(blockZone, relativeVision, bonusMalusZone, -1000000);
            for (Entity *e : explodableEntities) {
                auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));
                auto &eExpl = reinterpret_cast<ExplodeComponent &>(e->getComponentByName("Explode"));
                Point relaPos = getRelativePos(ePos.pos);

                for (int i = 0; i < eExpl.range; ++i) {
                    dangerZone.push_back({relaPos.x + (TILESIZE * i), relaPos.y});
                    dangerZone.push_back({relaPos.x - (TILESIZE * i), relaPos.y});
                    dangerZone.push_back({relaPos.x, relaPos.y + (TILESIZE * i)});
                    dangerZone.push_back({relaPos.x, relaPos.y - (TILESIZE * i)});
                }
            }
            updateRelativeVision(dangerZone, relativeVision, bonusMalusZone, -100);

            for (Entity *e : powerUps) {
                auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));

                bonusZone.emplace_back(getRelativePos(ePos.pos));
            }
            updateRelativeVision(bonusZone, relativeVision, bonusMalusZone, 10);
            actions = getTheBestWay(bonusMalusZone, actions);
            if (canEscape(bonusMalusZone)) {
                actions.push_back(Input::ACTION_ACTION);
            }
        }
        ++time;
        if (time == 3)
            time = 0;
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