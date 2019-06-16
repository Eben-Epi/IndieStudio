/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** AIBrain.cpp
*/

#include "AIBrain.hpp"
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
#include "../ecs/components/OOBKillComponent.hpp"



Input::AIBrain::AIBrain(unsigned id, ECS::ECSCore &core) :
    _core(core),
    _id(id)
{
}

bool Input::AIBrain::isAI()
{
    return true;
}

void Input::AIBrain::changeKey(Action, irr::EKEY_CODE) {}

//getActions is the last function in this file

void Input::AIBrain::initBadPos(ECS::PositionComponent &pos, int xTmp, int yTmp)
{
    if (xTmp <= 15 && yTmp <= 15)
        return;
    pos.pos.x = (int)(pos.pos.x / TILESIZE) * TILESIZE + 5;
    pos.pos.y = (int)(pos.pos.y / TILESIZE) * TILESIZE + 5;
}

ECS::Entity *Input::AIBrain::setAIObjective(ECS::Entity &me, std::vector<ECS::Entity *> &bonuses)
{
    std::vector<ECS::Entity *> players = this->_core.getEntitiesByName("Player");
    static int chase = -1;

    try {
    	if (chase >= 0)
            this->_core.getEntityById(chase);
    } catch (ECS::NoSuchEntityException &) {
        chase = -1;
    }
    if (players.size() == 1)
        return (nullptr);
    if (!_objective || chase == -1 || chase == me.getId()) {
        int nb = rand() % players.size();

        while (players[nb]->getId() == me.getId()) {
            nb = rand() % players.size();
        }
        chase = players[nb]->getId();
        return (players[nb]);
    }
    ECS::Entity *nearestEnt = &this->_core.getEntityById(chase);
    auto &firstPos = reinterpret_cast<ECS::PositionComponent &>(nearestEnt->getComponentByName("Position"));
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

    for (int score : bonusMalusZone) {
        if (score >= -2)
            ++escapableWays;
    }
    return (escapableWays >= 1 && (this->_onStepAbs >= 1 && this->_onStepAbs < 9));
}

std::vector<Input::Action> Input::AIBrain::getTheBestWay(std::vector<int> &bonusMalusZone, ECS::Point &myPos)
{
    int i;
    int j = 0;
    std::vector<int> pos = {0};
    std::vector<Action> actions;
    auto &objPos = reinterpret_cast<ECS::PositionComponent &>(_objective->getComponentByName("Position"));
    int xBestWay;
    int yBestWay;
    int moveChoice = 2;

    for (i = 1; i < bonusMalusZone.size(); ++i) {
        if (bonusMalusZone[i] > bonusMalusZone[j]) {
            j = i;
            pos.clear();
            pos.push_back(i);
        } else if (bonusMalusZone[i] >= bonusMalusZone[j])
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
    if (abs(objPos.pos.x - myPos.x) + abs(objPos.pos.y - myPos.y) < TILESIZE + 16 && _objective->getName() == "Player" && !_bombPlaced) {
        actions.push_back(ACTION_ACTION);
        return (actions);
    }
    if (abs(objPos.pos.x - myPos.x) > abs(objPos.pos.y - myPos.y)) {
        if (bonusMalusZone[xBestWay] < -999000 && canEscape(bonusMalusZone) && !_bombPlaced) {
            actions.push_back(ACTION_ACTION);
            return (actions);
        }
        if (bonusMalusZone[xBestWay] > -100)
            moveChoice = xBestWay;
        else if (bonusMalusZone[yBestWay] > -100)
            moveChoice = yBestWay;
        else {
            if (_bombPlaced && bonusMalusZone[2] > -100)
                moveChoice = 2;
            else
                moveChoice = pos[rand() % pos.size()];
        }
    } else {
        if (bonusMalusZone[yBestWay] < -999000 && canEscape(bonusMalusZone) && !_bombPlaced) {
            actions.push_back(ACTION_ACTION);
            return (actions);
        }
        if (bonusMalusZone[yBestWay] > -100)
            moveChoice = yBestWay;
        else if (bonusMalusZone[xBestWay] > -100)
            moveChoice = xBestWay;
        else {
            if (bonusMalusZone[2] > -100 && bonusMalusZone[j] < 0) {
                return (actions);
            } else {
                if (_bombPlaced && bonusMalusZone[2] > -100)
                    moveChoice = 2;
                else
                    moveChoice = pos[rand() % pos.size()];
            }
        }
    }

    switch (moveChoice) {
        case 0:
            actions.push_back(ACTION_UP);
            break;
        case 1:
            actions.push_back(ACTION_LEFT);
            break;
        case 3:
            actions.push_back(ACTION_RIGHT);
            break;
        case 4:
            actions.push_back(ACTION_DOWN);
            break;
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
                    if (it->x == newPoint.x && it->y == newPoint.y) {
                        *infoIt += dangerLevel;
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

            for (ECS::Point point : dangerZone) {
                auto infoIt = bonusMalusZone.begin();

                for (auto &j : relativeVision) {
                    if (j.x == point.x && j.y == point.y) {
                        *infoIt += (dangerLevel * (eExpl.range + 1 - i));
                        break;
                    }
                    ++infoIt;
                }
            }
            dangerZone.clear();
        }
    }
}

void Input::AIBrain::updatingRelativeFurther(std::vector<ECS::Point> &relativeFurther, ECS::Point &newERelativePos) {
    for (int i = 0; i < relativeFurther.size(); ++i) {
        switch (i) {
            case 0:
                if (relativeFurther[i].y < newERelativePos.y
                    && newERelativePos.y < getRelativePosPlayer(_pos->pos).y
                    && relativeFurther[i].x == newERelativePos.x)
                    relativeFurther[i].y = newERelativePos.y;
            case 1:
                if (relativeFurther[i].x < newERelativePos.x
                    && newERelativePos.x < getRelativePosPlayer(_pos->pos).x
                    && relativeFurther[i].y == newERelativePos.y)
                    relativeFurther[i].x = newERelativePos.x;
            case 2:
                if (relativeFurther[i].x > newERelativePos.x
                    && newERelativePos.x > getRelativePosPlayer(_pos->pos).x
                    && relativeFurther[i].y == newERelativePos.y)
                    relativeFurther[i].x = newERelativePos.x;
            case 3:
                if (relativeFurther[i].y > newERelativePos.y
                    && newERelativePos.y > getRelativePosPlayer(_pos->pos).y
                    && relativeFurther[i].x == newERelativePos.x)
                    relativeFurther[i].y = newERelativePos.y;
            default:
                break;
        }
    }
}

void Input::AIBrain::bombPlacedChangesBonusMalusZoneScore(
    std::vector<int> &bonusMalusZone,
    std::vector<int> &bonusMalusCorners,
    std::vector<ECS::Point> &relativeFurther,
    std::vector<ECS::Point> &relativeVision
)
{
    if (_bombPlaced) {
        for (int j = 0; j < bonusMalusCorners.size(); ++j) {
            if (bonusMalusCorners[j] < -990000) {
                bonusMalusZone[j % 2 ? 3 : 1] += -20;
                bonusMalusZone[j / 2 * 4] += -20;
            }
        }

        int j = 0;
        for (int k = 0; k < bonusMalusZone.size(); ++k) {
            if (k != 2) {
                bonusMalusZone[k] += (int) (abs(relativeFurther[j].x - relativeVision[k].x) +
                                            abs(relativeFurther[j].y - relativeVision[k].y))
                                     / TILESIZE * 70;
                ++j;
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
    auto &oob = reinterpret_cast<ECS::OOBKillComponent &>(this->_entity->getComponentByName("OOBKill"));
    std::vector<ECS::Point> relativeFurther = {
        {relativeVision[0].x, oob.p1.y},
        {oob.p1.x, relativeVision[1].y},
        {oob.p2.x, relativeVision[2].y},
        {relativeVision[3].x, oob.p2.y}
    };
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
                    if (it->x == newPoint.x && it->y == newPoint.y) {
                        if (e->getName() != "Player")
                            *infoIt += dangerLevel;
                        if (e->hasComponent("OnCollisionDamageDealer") || e->hasComponent("Explode"))
                            *infoIt += 5000;
                        else if (e->hasComponent("Health")) {
                            bonusMalusZone[2] += -20;
                            if (e->getName() == "Player") {
                                *infoIt += -500;
                                if (!_bombPlaced && bonusMalusZone[2] > -100)
                                    bonusMalusZone[2] = -20;
                            }
                        }
                        break;
                    }
                    ++infoIt;
                }
                if (_bombPlaced && e->getName() != "Player") {

                    infoIt = bonusMalusCorners.begin();
                    for (auto it = relativeCorners.begin(); it < relativeCorners.end(); ++it) {
                        if (it->x == newPoint.x && it->y == newPoint.y) {
                            *infoIt += dangerLevel;
                            break;
                        }
                        ++infoIt;
                    }
                    updatingRelativeFurther(relativeFurther, newERelativePos);
                }
            }
        }
    }
    bombPlacedChangesBonusMalusZoneScore(bonusMalusZone, bonusMalusCorners, relativeFurther, relativeVision);
}

std::vector<ECS::Point> Input::AIBrain::getRelativeVision(ECS::Point &point)
{
    std::vector<ECS::Point> vision;

    vision.push_back({point.x, point.y - TILESIZE});
    vision.push_back({point.x - TILESIZE, point.y});
    vision.push_back({point.x, point.y});
    vision.push_back({point.x + TILESIZE, point.y});
    vision.push_back({point.x, point.y + TILESIZE});

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

void Input::AIBrain::setUltimeIfGot(std::vector<int> &bonusMalusZone)
{
    auto &ultComp = reinterpret_cast<ECS::UltimeComponent &>(_entity->getComponentByName("Ultime"));

    if (bonusMalusZone[2] > -100 && !_bombPlaced && ultComp.hasUlt)
        _actions.emplace_back(ACTION_ULT);
}

std::vector<Input::Action> Input::AIBrain::getActions() {
    if (!this->_init) {
    	this->_entity = &this->_core.getEntityById(this->_id);
    	this->_pos = &reinterpret_cast<ECS::PositionComponent &>(this->_entity->getComponentByName("Position"));
    	this->_bombDropper = &reinterpret_cast<ECS::BombDropperComponent &>(this->_entity->getComponentByName("BombDropper"));

        _xTmp = (int)(this->_pos->pos.x / TILESIZE * 100) % 100;
        _yTmp = (int)(this->_pos->pos.y / TILESIZE * 100) % 100;

        initBadPos(*this->_pos, _xTmp, _yTmp);
        this->_init = true;
    }

    _xTmp = (int)(this->_pos->pos.x / TILESIZE * 100) % 100;
    _yTmp = (int)(this->_pos->pos.y / TILESIZE * 100) % 100;
    std::vector<ECS::Entity *> colliders = this->_core.getEntitiesByComponent("Collider");
    std::vector<ECS::Entity *> explodableEntities = this->_core.getEntitiesByComponent("Explode");
    std::vector<ECS::Entity *> powerUps = this->_core.getEntitiesByComponent("PowerUp");
    std::vector<ECS::Entity *> players = this->_core.getEntitiesByName("Player");
    ECS::Point relativePosPlayer = getRelativePosPlayer(this->_pos->pos);
    std::vector<ECS::Point> relativeVision = getRelativeVision(relativePosPlayer);
    std::vector<ECS::Entity *> blockZone;
    std::vector<int> bonusMalusZone = {0, 0, -2, 0, 0};

    if ((_xTmp <= 10 && _yTmp <= 10) || !_objective || _actions.empty()) {
        _objective = setAIObjective(*this->_entity, powerUps);
        if (_objective == nullptr) {
            _actions.clear();
            return (_actions);
        }
        _bombPlaced = _bombDropper->bombs.size() == 1;
        for (ECS::Entity *e : colliders) {
            auto &eCollide = reinterpret_cast<ECS::ColliderComponent &>(e->getComponentByName("Collider"));
            auto &eKicker = reinterpret_cast<ECS::KickerComponent &>(this->_entity->getComponentByName("Kicker"));

            if (eCollide.hardness >= 1 || e->hasComponent("OnCollisionDamageDealer") ||
            e->hasComponent("Explode") || e->hasComponent("CurseOnPick")) {
                blockZone.emplace_back(e);
            }
        }
        for (ECS::Entity *e : players) {
            if (e->getId() != _entity->getId())
                blockZone.emplace_back(e);
        }
        if (!blockZone.empty())
            updateRelativeVisionForBlocks(blockZone, relativeVision, bonusMalusZone, -1000000);

        if (!explodableEntities.empty())
            updateRelativeVisionForPredictions(explodableEntities, relativeVision, bonusMalusZone, -1100);

        if (!powerUps.empty())
            updateRelativeVisionForBonuses(powerUps, relativeVision, bonusMalusZone, 100);

        this->_onStepAbs = (bonusMalusZone[2] + 2);
        if (this->_onStepAbs < 0)
            this->_onStepAbs *= -1;
        this->_onStepAbs = this->_onStepAbs % 100 / 10;

        setUltimeIfGot(bonusMalusZone);

        _actions = getTheBestWay(bonusMalusZone, relativePosPlayer);
    }
    return (_actions);
}

std::string Input::AIBrain::getEnumControlString(Action code) {
    return ("");
}
