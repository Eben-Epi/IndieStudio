/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** HealthComponent.cpp
*/

#include "HealthComponent.hpp"

namespace ECS
{
    Health::Health(unsigned int health)
    : Component("Health")
    {
        this->_health = health;
    }
}