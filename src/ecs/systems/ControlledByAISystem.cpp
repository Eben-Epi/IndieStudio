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
#include "../components/KickerComponent.hpp"

namespace ECS {
    ControlledByAISystem::ControlledByAISystem(ECS::ECSCore &core) :
        System("ControlledByAI", core) {
        this->_dependencies = {"Movable", "Position", "BombDropper", "Ultime"};
    }

    bool ControlledByAISystem::canEscape(std::vector<int> &bonusMalusZone) {
        int escapableWays = 0;
        static int bombTimer = 50;
        static int blocksDestroyed = 0;

        if (bombTimer != 0) {
            --bombTimer;
            return (false);
        }
        for (int score : bonusMalusZone) {
            if (score >= -1)
                ++escapableWays;
        }
        bombTimer = 50;
        if (escapableWays >= 2 && (bonusMalusZone[2] / 10 % 10 != 0 || blocksDestroyed > 20)) {
            ++blocksDestroyed;
            return (true);
        }
        return (false);
    }

    std::vector<Input::Action> ControlledByAISystem::getTheBestWay(std::vector<int> &bonusMalusZone) {
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
            } else if (bonusMalusZone[i] == bonusMalusZone[j])
                pos.push_back(i);
        }
        std::cout << "actions : " << pos.size() << " -> ";
        for (int posi : pos)
            std::cout << posi << " // ";
        std::cout << std::endl;
        if (pos.size() > 1)
            j = rand_device() % (int) pos.size();
        else
            j = 0;
        std::cout << "action engaged : " << pos[j] << " && with j : " << j << std::endl;
        switch (pos[j]) {
            /*case 0:
                actions.push_back(Input::Action::ACTION_UP);
                actions.push_back(Input::Action::ACTION_LEFT);
                break;*/
            case 0:
                actions.push_back(Input::Action::ACTION_UP);
                break;
                /*case 2:
                    actions.push_back(Input::Action::ACTION_UP);
                    actions.push_back(Input::Action::ACTION_RIGHT);
                    break;*/
            case 1:
                actions.push_back(Input::Action::ACTION_LEFT);
                break;
            case 3:
                actions.push_back(Input::Action::ACTION_RIGHT);
                break;
                /*case 6:
                    actions.push_back(Input::Action::ACTION_DOWN);
                    actions.push_back(Input::Action::ACTION_LEFT);
                    break;*/
            case 4:
                actions.push_back(Input::Action::ACTION_DOWN);
                break;
                /*case 8:
                    actions.push_back(Input::Action::ACTION_DOWN);
                    actions.push_back(Input::Action::ACTION_RIGHT);
                    break;*/
            default:
                break;
        }
        return (actions);
    }

    void ControlledByAISystem::updateRelativeVisionForBonuses(
        std::vector<ECS::Entity *> &cannotMoveThere,
        std::vector<ECS::Point> &relativeVision,
        std::vector<int> &bonusMalusZone,
        int dangerLevel
    )
    {
        for (Entity *e : cannotMoveThere) {
            auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));
            auto infoIt = bonusMalusZone.begin();
            Point newERelativePos = getRelativePosObj(ePos.pos);
            Point end = {newERelativePos.x + ePos.size.x, newERelativePos.y + ePos.size.y};

            for (int y = newERelativePos.y; y < end.y; y += TILESIZE) {
                for (int x = newERelativePos.x; x < end.x; x += TILESIZE) {
                    Point newPoint = {(double) x, (double) y};

                    for (auto it = relativeVision.begin(); it < relativeVision.end(); ++it) {
                        if (it.base()->x == newPoint.x && it.base()->y == newPoint.y) {
                            *(infoIt.base()) += dangerLevel;
                            break;
                        }
                        ++infoIt;
                    }
                }
            }
        }
    }

    void ControlledByAISystem::updateRelativeVisionForPredictions(
        std::vector<ECS::Entity *> &cannotMoveThere,
        std::vector<ECS::Point> &relativeVision,
        std::vector<int> &bonusMalusZone,
        int dangerLevel
    )
    {
        for (Entity *e : cannotMoveThere) {
            auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));
            auto &eExpl = reinterpret_cast<ExplodeComponent &>(e->getComponentByName("Explode"));
            std::vector<Point> dangerZone;
            Point relaPos = getRelativePosPlayer(ePos.pos);

            for (int i = 1; i < eExpl.range + 1; ++i) {
                dangerZone.push_back({relaPos.x + (TILESIZE * i), relaPos.y});
                dangerZone.push_back({relaPos.x - (TILESIZE * i), relaPos.y});
                dangerZone.push_back({relaPos.x, relaPos.y + (TILESIZE * i)});
                dangerZone.push_back({relaPos.x, relaPos.y - (TILESIZE * i)});
            }

            for (Point point : dangerZone) {
                auto infoIt = bonusMalusZone.begin();
                Point end = {point.x + ePos.size.x, point.y + ePos.size.y};

                for (int y = point.y; y < end.y; y += TILESIZE) {
                    for (int x = point.x; x < end.x; x += TILESIZE) {
                        Point newPoint = {(double) x, (double) y};

                        for (auto it = relativeVision.begin(); it < relativeVision.end(); ++it) {
                            if (it.base()->x == newPoint.x && it.base()->y == newPoint.y) {
                                *(infoIt.base()) += dangerLevel;
                                break;
                            }
                            ++infoIt;
                        }
                    }
                }
            }
        }

    }


    void ControlledByAISystem::updateRelativeVisionForBlocks(
        std::vector<ECS::Entity *> &cannotMoveThere,
        std::vector<ECS::Point> &relativeVision,
        std::vector<int> &bonusMalusZone,
        int dangerLevel
    )
    {
        std::vector<ECS::Point> relativeCorners = {
            {relativeVision[0].x - TILESIZE, relativeVision[0].y},
            {relativeVision[0].x + TILESIZE, relativeVision[0].y},
            {relativeVision[4].x - TILESIZE, relativeVision[4].y},
            {relativeVision[4].x + TILESIZE, relativeVision[4].y}
        };
        std::vector<int> bonusMalusCorners = {0, 0, 0, 0};

        for (Entity *e : cannotMoveThere) {
            auto &ePos = reinterpret_cast<PositionComponent &>(e->getComponentByName("Position"));
            Point newERelativePos = getRelativePosObj(ePos.pos);
            Point end = {newERelativePos.x + ePos.size.x, newERelativePos.y + ePos.size.y};

            for (int y = newERelativePos.y; y < end.y; y += TILESIZE) {
                for (int x = newERelativePos.x; x < end.x; x += TILESIZE) {
                    Point newPoint = {(double) x, (double) y};
                    auto infoIt = bonusMalusZone.begin();

                    for (auto it = relativeVision.begin(); it < relativeVision.end(); ++it) {
                        if (it.base()->x == newPoint.x && it.base()->y == newPoint.y) {
                            *(infoIt.base()) += dangerLevel;
                            if (e->hasComponent("Health"))
                                bonusMalusZone[2] -= 10;
                            break;
                        }
                        ++infoIt;
                    }
                    infoIt = bonusMalusCorners.begin();
                    for (auto it = relativeCorners.begin(); it < relativeCorners.end(); ++it) {
                        if (it.base()->x == newPoint.x && it.base()->y == newPoint.y) {
                            *(infoIt.base()) += dangerLevel;
                            break;
                        }
                        ++infoIt;
                    }
                }
            }
        }
        for (int j = 0; j < bonusMalusCorners.size(); ++j) {
            if (bonusMalusCorners[j] == -1000000) {
                bonusMalusZone[j % 2 ? 3 : 1] += -1;
                bonusMalusZone[j / 2 * 4] += -1;
            }
        }
    }

    std::vector<ECS::Point> ControlledByAISystem::getRelativeVision(ECS::Point &point)
    {
        std::vector<ECS::Point> vision;

        //vision.push_back({point.x - TILESIZE, point.y - TILESIZE});
        vision.push_back({point.x, point.y - TILESIZE});
        //vision.push_back({point.x + TILESIZE, point.y - TILESIZE});
        vision.push_back({point.x - TILESIZE, point.y});
        vision.push_back({point.x, point.y});
        vision.push_back({point.x + TILESIZE, point.y});
        //vision.push_back({point.x - TILESIZE, point.y + TILESIZE});
        vision.push_back({point.x, point.y + TILESIZE});
        //vision.push_back({point.x + TILESIZE, point.y + TILESIZE});


        return (vision);
    }

    ECS::Point ControlledByAISystem::getRelativePosPlayer(ECS::Point &pos)
    {
        ECS::Point point;

        if ((int)(pos.x / TILESIZE * 10) % 10 >= 7.5)
            point.x = (int)(pos.x / TILESIZE) * (TILESIZE * 2);
        else
            point.x = (int)(pos.x / TILESIZE) * TILESIZE;
        if ((int)(pos.y / TILESIZE * 10) % 10 >= 7.5)
            point.y = (int)(pos.y / TILESIZE) * (TILESIZE * 2);
        else
            point.y = (int)(pos.y / TILESIZE) * TILESIZE;
        return (point);
    }

    ECS::Point ControlledByAISystem::getRelativePosObj(ECS::Point &pos)
    {
        ECS::Point relative;

        relative.x = (int)(pos.x / TILESIZE) * TILESIZE;
        relative.y = (int)(pos.y / TILESIZE) * TILESIZE;
        return (relative);
    }

    std::vector<Input::Action> ControlledByAISystem::AIBrain(ECS::Entity &entity, BombDropperComponent &bombDropper)
    {
        auto &in = reinterpret_cast<ControlledByAIComponent &>(entity.getComponentByName("ControlledByAI"));
        auto &pos = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
        std::vector<Entity *> colliders = this->_core.getEntitiesByComponent("Collider");
        std::vector<Entity *> explodableEntities = this->_core.getEntitiesByComponent("Explode");
        std::vector<Entity *> powerUps = this->_core.getEntitiesByComponent("PowerUp");
        Point relativePosPlayer = getRelativePosPlayer(pos.pos);
        std::vector<Point> relativeVision = getRelativeVision(relativePosPlayer);
        std::vector<Entity *> blockZone;
        std::vector<int> bonusMalusZone = {0, 0, 0, 0, 0/*, 0, 0, 0, 0*/};
        //static int changingPosx = relativePos.x / TILESIZE;
        //static int changingPosy = relativePos.y / TILESIZE;
        int xTmp = (int)(pos.pos.x / TILESIZE * 100) % 100;
        int yTmp = (int)(pos.pos.y / TILESIZE * 100) % 100;
        static std::vector<Input::Action> actions {};
        static int timer = 0;

        //std::cout << "x : " << (int)(pos.pos.x / TILESIZE) << " // xTmp : " << xTmp << std::endl;
        //std::cout << "y : " << (int)(pos.pos.y / TILESIZE) << " // yTmp : " << yTmp << std::endl;
        if ((xTmp <= 10 && yTmp <= 10 && timer == 0) || actions.empty() || actions[0] == Input::ACTION_ACTION) {
            for (Entity *e : colliders) {
                auto &eCollide = reinterpret_cast<ColliderComponent &>(e->getComponentByName("Collider"));
                auto &eKicker = reinterpret_cast<KickerComponent &>(entity.getComponentByName("Kicker"));

                if (eCollide.hardness >= 1 || e->hasComponent("OnCollisionDamageDealer") || (!eKicker.canKick && e->hasComponent("Explode"))) {
                    blockZone.emplace_back(e);
                }
            }
            if (!blockZone.empty())
                updateRelativeVisionForBlocks(blockZone, relativeVision, bonusMalusZone, -1000000);
            ///add a fifth parameter with the type of entity on an enum and
            ///that enable us in blocks to know if we can go to angles

            if (!explodableEntities.empty())
                updateRelativeVisionForPredictions(explodableEntities, relativeVision, bonusMalusZone, -1000);

            std::cout << std::endl;

            if (!powerUps.empty())
                updateRelativeVisionForBonuses(powerUps, relativeVision, bonusMalusZone, 100);
            std::cout << "scores : ";
            for (int score : bonusMalusZone) {
                std::cout << score << " || ";
            }
            actions = getTheBestWay(bonusMalusZone);
            /*if (!actions.empty()) {
                changingPosx = relativePos.x / TILESIZE;
                changingPosy = relativePos.y / TILESIZE;
            }*/
            if (canEscape(bonusMalusZone) && !bombDropper.bombs.empty()) {
                actions.push_back(Input::ACTION_ACTION);
            }
            timer = 11;
        }
        if (timer > 0)
            --timer;
        return (actions);
    }

    void ControlledByAISystem::updateEntity(ECS::Entity &entity)
    {
        auto &mov = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));
        auto &bombDropper = reinterpret_cast<BombDropperComponent &>(entity.getComponentByName("BombDropper"));
        auto &uc = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));
        std::vector<Input::Action> actions;
        unsigned char newDir = 0;

        actions = AIBrain(entity, bombDropper);
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