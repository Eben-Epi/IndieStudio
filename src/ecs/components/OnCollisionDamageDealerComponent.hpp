/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** OnCollisionDamageDealerComponent.hpp
*/

#ifndef BOMBERMAN_ONCOLLISIONDAMAGEDEALERCOMPONENT_HPP
#define BOMBERMAN_ONCOLLISIONDAMAGEDEALERCOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class OnCollisionDamageDealerComponent : public Component
    {
    public:
        int damage;
        int ownerId; // -1 if no owner
        OnCollisionDamageDealerComponent(int damage);
        OnCollisionDamageDealerComponent(unsigned id, Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
}


#endif //BOMBERMAN_ONCOLLISIONDAMAGEDEALERCOMPONENT_HPP
