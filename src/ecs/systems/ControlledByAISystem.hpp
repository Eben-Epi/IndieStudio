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
    };
}

#endif //BOMBERMAN_CONTROLLEDBYAISYSTEM_HPP
