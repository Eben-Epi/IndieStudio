/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** AIBrain.cpp
*/

#include "AIBrain.hpp"
#include <random>
#include "../ecs/components/MovableComponent.hpp"
#include "../ecs/components/PositionComponent.hpp"
#include "../ecs/components/BombDropperComponent.hpp"
#include "../ecs/components/UltimeComponent.hpp"
#include "../ecs/ECSCore.hpp"
#include "../ecs/components/CurseComponent.hpp"
#include "../ecs/../config.hpp"
#include "../ecs/components/ColliderComponent.hpp"
#include "../ecs/components/ExplodeComponent.hpp"
#include "../ecs/components/KickerComponent.hpp"
#include "../ecs/Exceptions.hpp"

void Input::AIBrain::initBadPos(ECS::PositionComponent &pos, int xTmp, int yTmp)
{
    if (xTmp <= 15 && yTmp <= 15)
        return;
    pos.pos.x = (int)(pos.pos.x / TILESIZE) * TILESIZE + 5;
    pos.pos.y = (int)(pos.pos.y / TILESIZE) * TILESIZE + 5;
}

Input::AIBrain::AIBrain(unsigned id, ECS::ECSCore &core) :
    _core(core),
    _id(id)
{
}

ECS::Entity *Input::AIBrain::setAIObjective(ECS::Entity &me, ECS::Entity *objective, std::vector<ECS::Entity *> bonuses)
{
    std::vector<ECS::Entity *> players = this->_core.getEntitiesByName("Player");
    static int chase = -1;

    try {
    	if (chase >= 0)
            this->_core.getEntityById(chase);
    } catch (ECS::NoSuchEntityException &) {
        chase = -1;
    }
    std::cout << players.size() << " players remaining" << std::endl;
    if (players.size() == 1)
        return (nullptr);
    if (!objective || chase == -1) {
        std::random_device randomDev;
        int nb = randomDev() % players.size();

        while (players[nb]->getId() == me.getId())
            nb = randomDev() % players.size();
        chase = players[nb]->getId();
        return (players[nb]);
    }
    ECS::Entity *nearestEnt = &this->_core.getEntityById(chase);
    auto &firstPos = reinterpret_cast<ECS::PositionComponent &>(nearestEnt->getComponentByName("Position"));
    ECS::Point nearestPos = firstPos.pos;
    auto &myPos = reinterpret_cast<ECS::PositionComponent &>(me.getComponentByName("Position"));
    double myDist = abs(myPos.pos.x - firstPos.pos.x) + abs(myPos.pos.y - firstPos.pos.y);

    for (auto &bonus : bonuses) {
        auto &nextPos = reinterpret_cast<ECS::PositionComponent &>(bonus->getComponentByName("Position"));
        double distNext = abs(myPos.pos.x - nextPos.pos.x) + abs(myPos.pos.y - nextPos.pos.y);

        if (myDist > distNext) {
            nearestEnt = bonus;
            myDist = distNext;
        }
    }
    return (nearestEnt);
}



bool Input::AIBrain::canEscape(std::vector<int> &bonusMalusZone)
{
    int escapableWays = 0;
    static int bombTimer = 50;
    static int blocksDestroyed = 0;

    if (bombTimer > 0) {
        --bombTimer;
        return (false);
    }
    for (int score : bonusMalusZone) {
        if (score >= -2)
            ++escapableWays;
    }

    std::cout << "onStep : " << this->_onStepAbs << std::endl;
    if (escapableWays >= 1 && ((this->_onStepAbs >= 1 && this->_onStepAbs < 9) || blocksDestroyed > 20)) {
        ++blocksDestroyed;
        bombTimer = 50;
        return (true);
    }
    return (false);
}

std::vector<Input::Action> Input::AIBrain::getTheBestWay(
    std::vector<int> &bonusMalusZone,
    ECS::Entity *objective,
    ECS::Point &myPos
)
{
    int i;
    int j = 0;
    std::vector<int> pos = {0};
    std::vector<Action> actions;
    std::random_device rand_device;
    auto &objPos = reinterpret_cast<ECS::PositionComponent &>(objective->getComponentByName("Position"));
    ECS::Point relaObjPos = getRelativePosObj(objPos.pos);
    std::vector<int> bestWays;
    int xBestWay;
    int yBestWay;
    int moveChoice = 2;

    for (i = 1; i < bonusMalusZone.size(); ++i) {
        if (bonusMalusZone[i] > bonusMalusZone[j] + 3) {
            j = i;
            pos.clear();
            pos.push_back(i);
        } else if (bonusMalusZone[i] >= bonusMalusZone[j] - 3)
            pos.push_back(i);
    }
    if (objPos.pos.x - myPos.x > 0) {
        xBestWay = 3;
    } else {
        xBestWay = 1;
    }
    if (objPos.pos.y - myPos.y > 0) {
        yBestWay = 4;
    } else {
        yBestWay = 0;
    }
    if (abs(relaObjPos.x - myPos.x) > abs(relaObjPos.y - myPos.y)) {
        if (bonusMalusZone[xBestWay] < -999000 && this->_onStepAbs >= 1 && this->_onStepAbs < 9 && canEscape(bonusMalusZone))
            actions.push_back(ACTION_ACTION);
        for (int posi : pos) {
            if (posi == yBestWay) {
                moveChoice = yBestWay;
                break;
            }
        }
        for (int posi : pos) {
            if (posi == xBestWay) {
                moveChoice = xBestWay;
                break;
            }
        }
    } else if (relaObjPos.y - myPos.y != 0) {
        if (bonusMalusZone[yBestWay] < -999000 && this->_onStepAbs >= 1 && this->_onStepAbs < 9 && canEscape(bonusMalusZone))
            actions.push_back(ACTION_ACTION);
        for (int posi : pos) {
            if (posi == xBestWay) {
                moveChoice = xBestWay;
                break;
            }
        }
        for (int posi : pos) {
            if (posi == yBestWay) {
                moveChoice = yBestWay;
                break;
            }
        }
    }
    std::cout << "moveChoice : " << moveChoice << std::endl;
    if (bonusMalusZone[moveChoice] < -100) {
        moveChoice = pos[rand_device() % pos.size()];
    }

    std::cout << "actions : " << pos.size() << " -> ";
    for (int posi : pos)
        std::cout << posi << " // ";
    std::cout << std::endl;
    std::cout << "action engaged : " << moveChoice << std::endl;
    switch (moveChoice) {
        /*case 0:
            actions.push_back(Input::Action::ACTION_UP);
            actions.push_back(Input::Action::ACTION_LEFT);
            break;*/
        case 0:
            actions.push_back(ACTION_UP);
            break;
            /*case 2:
                actions.push_back(Input::Action::ACTION_UP);
                actions.push_back(Input::Action::ACTION_RIGHT);
                break;*/
        case 1:
            actions.push_back(ACTION_LEFT);
            break;
        case 3:
            actions.push_back(ACTION_RIGHT);
            break;
            /*case 6:
                actions.push_back(Input::Action::ACTION_DOWN);
                actions.push_back(Input::Action::ACTION_LEFT);
                break;*/
        case 4:
            actions.push_back(ACTION_DOWN);
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

void Input::AIBrain::updateRelativeVisionForBonuses(
    std::vector<ECS::Entity *> &cannotMoveThere,
    std::vector<ECS::Point> &relativeVision,
    std::vector<int> &bonusMalusZone,
    int dangerLevel
)
{
    for (ECS::Entity *e : cannotMoveThere) {
        auto &ePos = reinterpret_cast<ECS::PositionComponent &>(e->getComponentByName("Position"));
        auto infoIt = bonusMalusZone.begin();
        ECS::Point newERelativePos = getRelativePosObj(ePos.pos);
        ECS::Point end = {newERelativePos.x + ePos.size.x, newERelativePos.y + ePos.size.y};

        for (int y = newERelativePos.y; y < end.y; y += TILESIZE) {
            for (int x = newERelativePos.x; x < end.x; x += TILESIZE) {
                ECS::Point newPoint = {(double) x, (double) y};

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

void Input::AIBrain::updateRelativeVisionForPredictions(
    std::vector<ECS::Entity *> &cannotMoveThere,
    std::vector<ECS::Point> &relativeVision,
    std::vector<int> &bonusMalusZone,
    int dangerLevel
)
{
    for (ECS::Entity *e : cannotMoveThere) {
        auto &ePos = reinterpret_cast<ECS::PositionComponent &>(e->getComponentByName("Position"));
        auto &eExpl = reinterpret_cast<ECS::ExplodeComponent &>(e->getComponentByName("Explode"));
        std::vector<ECS::Point> dangerZone;
        ECS::Point relaPos = getRelativePosPlayer(ePos.pos);

        for (int i = 1; i < eExpl.range + 1; ++i) {
            dangerZone.push_back({relaPos.x + (TILESIZE * i), relaPos.y});
            dangerZone.push_back({relaPos.x - (TILESIZE * i), relaPos.y});
            dangerZone.push_back({relaPos.x, relaPos.y + (TILESIZE * i)});
            dangerZone.push_back({relaPos.x, relaPos.y - (TILESIZE * i)});
        }

        for (ECS::Point point : dangerZone) {
            auto infoIt = bonusMalusZone.begin();
            ECS::Point end = {point.x + ePos.size.x, point.y + ePos.size.y};

            for (int y = point.y; y < end.y; y += TILESIZE) {
                for (int x = point.x; x < end.x; x += TILESIZE) {
                    ECS::Point newPoint = {(double) x, (double) y};

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


void Input::AIBrain::updateRelativeVisionForBlocks(
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

    for (ECS::Entity *e : cannotMoveThere) {
        auto &ePos = reinterpret_cast<ECS::PositionComponent &>(e->getComponentByName("Position"));
        ECS::Point newERelativePos = getRelativePosObj(ePos.pos);
        ECS::Point end = {newERelativePos.x + ePos.size.x, newERelativePos.y + ePos.size.y};

        for (int y = newERelativePos.y; y < end.y; y += TILESIZE) {
            for (int x = newERelativePos.x; x < end.x; x += TILESIZE) {
                ECS::Point newPoint = {(double) x, (double) y};
                auto infoIt = bonusMalusZone.begin();

                for (auto it = relativeVision.begin(); it < relativeVision.end(); ++it) {
                    if (it.base()->x == newPoint.x && it.base()->y == newPoint.y) {
                        *(infoIt.base()) += dangerLevel;
                        if (e->hasComponent("OnCollisionDamageDealer") || e->hasComponent("Explode"))
                            *(infoIt.base()) += 5000;
                        if (e->hasComponent("Health"))
                            bonusMalusZone[2] += -10;
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

std::vector<ECS::Point> Input::AIBrain::getRelativeVision(ECS::Point &point)
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

ECS::Point Input::AIBrain::getRelativePosPlayer(ECS::Point &pos)
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

ECS::Point Input::AIBrain::getRelativePosObj(ECS::Point &pos)
{
    ECS::Point relative;

    relative.x = (int)(pos.x / TILESIZE) * TILESIZE;
    relative.y = (int)(pos.y / TILESIZE) * TILESIZE;
    return (relative);
}

std::vector<Input::Action> Input::AIBrain::getActions() {
    if (!this->_init) {
    	this->_entity = &this->_core.getEntityById(this->_id);
    	this->_pos = &reinterpret_cast<ECS::PositionComponent &>(this->_entity->getComponentByName("Position"));
    	this->_bombDropper = &reinterpret_cast<ECS::BombDropperComponent &>(this->_entity->getComponentByName("BombDropper"));

	int xTmp = (int)(this->_pos->pos.x / TILESIZE * 100) % 100;
	int yTmp = (int)(this->_pos->pos.y / TILESIZE * 100) % 100;

	initBadPos(*this->_pos, xTmp, yTmp);
	this->_init = true;
    }
    std::vector<ECS::Entity *> colliders = this->_core.getEntitiesByComponent("Collider");
    std::vector<ECS::Entity *> explodableEntities = this->_core.getEntitiesByComponent("Explode");
    std::vector<ECS::Entity *> powerUps = this->_core.getEntitiesByComponent("PowerUp");
    ECS::Point relativePosPlayer = getRelativePosPlayer(this->_pos->pos);
    std::vector<ECS::Point> relativeVision = getRelativeVision(relativePosPlayer);
    std::vector<ECS::Entity *> blockZone;
    std::vector<int> bonusMalusZone = {0, 0, -2, 0, 0/*, 0, 0, 0, 0*/};
    //static int changingPosx = relativePos.x / TILESIZE;
    //static int changingPosy = relativePos.y / TILESIZE;
    int xTmp = (int)(this->_pos->pos.x / TILESIZE * 100) % 100;
    int yTmp = (int)(this->_pos->pos.y / TILESIZE * 100) % 100;

    //std::cout << "x : " << (int)(pos.pos.x / TILESIZE) << " // xTmp : " << xTmp << std::endl;
    //std::cout << "y : " << (int)(pos.pos.y / TILESIZE) << " // yTmp : " << yTmp << std::endl;
    if ((xTmp <= 15 && yTmp <= 15 && _timer == 0) || !_objective) {
        _objective = setAIObjective(*this->_entity, _objective, powerUps);
        if (_objective == nullptr) {
            _actions.clear();
            return (_actions);
        }
        std::cout << _objective->getName() << std::endl;
        for (ECS::Entity *e : colliders) {
            auto &eCollide = reinterpret_cast<ECS::ColliderComponent &>(e->getComponentByName("Collider"));
            auto &eKicker = reinterpret_cast<ECS::KickerComponent &>(this->_entity->getComponentByName("Kicker"));

            if (eCollide.hardness >= 1 || e->hasComponent("OnCollisionDamageDealer") || (/* !eKicker.canKick && */ e->hasComponent("Explode"))) {
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
        std::cout << std::endl;
        this->_onStepAbs = (bonusMalusZone[2] + 2);
        if (this->_onStepAbs < 0)
            this->_onStepAbs *= -1;
        this->_onStepAbs = this->_onStepAbs % 100 / 10;
        std::cout << "onStepLOL : " << this->_onStepAbs << std::endl;
        _actions = getTheBestWay(bonusMalusZone, _objective, relativePosPlayer);
        /*if (!_actions.empty()) {
            changingPosx = relativePos.x / TILESIZE;
            changingPosy = relativePos.y / TILESIZE;
        }*/
        if (canEscape(bonusMalusZone) && !_actions.empty() && _actions[0] != ACTION_ACTION) {
            _actions.push_back(ACTION_ACTION);
        }
        _timer = 2;
    }
    if (_timer > 0)
        --_timer;
    return (_actions);
}

bool Input::AIBrain::isAI()
{
	return true;
}

void Input::AIBrain::changeKey(Action, irr::EKEY_CODE) {}