/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** OnCollisionDamageDealerSystem.hpp
*/

#ifndef BOMBERMAN_ONCOLLISIONDAMAGEDEALERSYSTEM_HPP
#define BOMBERMAN_ONCOLLISIONDAMAGEDEALERSYSTEM_HPP

#include "../System.hpp"

namespace ECS {
    class OnCollisionDamageDealerSystem : public System {
    public:
        OnCollisionDamageDealerSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_ONCOLLISIONDAMAGEDEALERSYSTEM_HPP
