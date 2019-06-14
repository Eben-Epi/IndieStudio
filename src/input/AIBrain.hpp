/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** AIBrain.hpp
*/

#ifndef BOMBERMAN_AIBRAIN_HPP
#define BOMBERMAN_AIBRAIN_HPP

#include "Input.hpp"
#include "../irrlicht/screen/Screen.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"
#include "../ecs/components/BombDropperComponent.hpp"
#include "../ecs/ECSCore.hpp"
#include "../ecs/components/PositionComponent.hpp"

namespace Input {
    class AIBrain : public Input {
    public:
        AIBrain(unsigned id, ECS::ECSCore &core);

        ~AIBrain() = default;

        std::vector<Action> getActions();

        bool canEscape(std::vector<int> &bonusMalusZone);

        std::vector<Action> getTheBestWay(
            std::vector<int> &bonusMalusZone,
            ECS::Entity *objective,
            ECS::Point &myPos
        );

        void updateRelativeVisionForBlocks(
            std::vector<ECS::Entity *> &cannotMoveThere,
            std::vector<ECS::Point> &relativeVision,
            std::vector<int> &bonusMalusZone,
            int dangerLevel
        );

        void updateRelativeVisionForPredictions(
            std::vector<ECS::Entity *> &cannotMoveThere,
            std::vector<ECS::Point> &relativeVision,
            std::vector<int> &bonusMalusZone,
            int dangerLevel
        );

        void updateRelativeVisionForBonuses(
            std::vector<ECS::Entity *> &cannotMoveThere,
            std::vector<ECS::Point> &relativeVision,
            std::vector<int> &bonusMalusZone,
            int dangerLevel
        );
        std::vector<ECS::Point> getRelativeVision(ECS::Point &point);
        ECS::Point getRelativePosPlayer(ECS::Point &pos);
        ECS::Point getRelativePosObj(ECS::Point &pos);
        ECS::Entity *setAIObjective(ECS::Entity &me, ECS::Entity *objective, std::vector<ECS::Entity *> bonuses);
        void initBadPos(ECS::PositionComponent &pos, int xTmp, int yTmp);

        void changeKey(Action, irr::EKEY_CODE);
        bool isAI() override;

        void resetControl() override {};

    private:
    	bool _init = false;
    	unsigned _id;
        ECS::Entity *_entity;
        ECS::BombDropperComponent *_bombDropper;
        ECS::ECSCore &_core;
        ECS::PositionComponent *_pos;
        std::vector<Action> _actions = {};
        ECS::Entity *_objective;
        int _timer = 0;
        int _onStepAbs;
    };
}

#endif //BOMBERMAN_AIBRAIN_HPP
