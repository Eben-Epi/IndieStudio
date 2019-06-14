/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ControlledByAISystem.hpp
*/

#ifndef BOMBERMAN_CONTROLLEDBYAISYSTEM_HPP
#define BOMBERMAN_CONTROLLEDBYAISYSTEM_HPP


#include "../System.hpp"
#include "../../input/Input.hpp"
#include "../components/BombDropperComponent.hpp"
#include "../components/PositionComponent.hpp"

namespace ECS
{
    class ControlledByAISystem : public System {
    public:
        ControlledByAISystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
        std::vector<Input::Action> AIBrain(Entity &entity, BombDropperComponent &bombDropper);
        bool canEscape(std::vector<int> &bonusMalusZone, int onStepAbs);

        std::vector<Input::Action> getTheBestWay(
            std::vector<int> &bonusMalusZone,
            Entity *objective,
            Point &myPos,
            int onStepAbs
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
        Entity *setAIObjective(Entity &me, Entity *objective, std::vector<Entity *> bonuses);
        bool initBadPos(PositionComponent &pos, int xTmp, int yTmp);
    };
}

#endif //BOMBERMAN_CONTROLLEDBYAISYSTEM_HPP
