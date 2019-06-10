/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ControlledByAISystem.hpp
*/

#ifndef BOMBERMAN_CONTROLLEDBYAISYSTEM_HPP
#define BOMBERMAN_CONTROLLEDBYAISYSTEM_HPP


#include "../System.hpp"

namespace ECS
{
    class ControlledByAISystem : public System {
    public:
        ControlledByAISystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
        std::vector<Input::Action> AIBrain(Entity &entity);
    };
}

#endif //BOMBERMAN_CONTROLLEDBYAISYSTEM_HPP
