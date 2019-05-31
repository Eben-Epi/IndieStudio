/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** OnCollisionDamageDealerComponent.hpp
*/

#ifndef BOMBERMAN_ONCOLLISIONDAMAGEDEALERCOMPONENT_HPP
#define BOMBERMAN_ONCOLLISIONDAMAGEDEALERCOMPONENT_HPP

#include "../Component.hpp"

namespace ECS
{
    class OnCollisionDamageDealerComponent : public Component
    {
    public:
        int damage;
        OnCollisionDamageDealerComponent(int damage);
    };
}


#endif //BOMBERMAN_ONCOLLISIONDAMAGEDEALERCOMPONENT_HPP
