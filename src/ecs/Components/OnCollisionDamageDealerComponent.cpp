/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** OnCollisionDamageDealerComponent.cpp
*/

#include "OnCollisionDamageDealerComponent.hpp"

namespace ECS
{
    OnCollisionDamageDealerComponent::OnCollisionDamageDealerComponent(int damage) :
        Component("OnCollisionDamageDealer"),
        damage(damage)
    {
    }
}