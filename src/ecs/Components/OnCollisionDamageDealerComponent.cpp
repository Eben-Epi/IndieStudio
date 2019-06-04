/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** OnCollisionDamageDealerComponent.cpp
*/

#include <iostream>
#include "OnCollisionDamageDealerComponent.hpp"

namespace ECS
{
    OnCollisionDamageDealerComponent::OnCollisionDamageDealerComponent(int damage) :
        Component("OnCollisionDamageDealer"),
        damage(damage)
    {
    }

    std::ostream& OnCollisionDamageDealerComponent::serialize(std::ostream &stream) const
    {
    	return stream << damage << " EndOfComponent";
    }
}