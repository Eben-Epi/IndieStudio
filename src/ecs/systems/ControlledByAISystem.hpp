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

namespace ECS
{
    class ControlledByAISystem : public System {
    public:
        ControlledByAISystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
        std::vector<Input::Action> AIBrain(Entity &entity, BombDropperComponent &bombDropper);
        bool canEscape(std::vector<int> &bonusMalusZone);
        std::vector<Input::Action> getTheBestWay(std::vector<int> &bonusMalusZone);

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
    };
}

#endif //BOMBERMAN_CONTROLLEDBYAISYSTEM_HPP
