/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** HealthSystem.hpp
*/

#ifndef BOMBERMAN_HEALTHSYSTEM_HPP
#define BOMBERMAN_HEALTHSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class HealthSystem : public System {
    public:
    	HealthSystem(ECSCore &);

        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_HEALTHSYSTEM_HPP
