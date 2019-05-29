/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** HealthComponent.hpp
*/

#ifndef HEALTHCOMPONENT_HPP
#define HEALTHCOPONENT_HPP

#include "../Component.hpp"

namespace ECS
{
    class HealthComponent : public Component
    {
        public:
            unsigned int health;
            HealthComponent(unsigned int health);
    };
} // namespace ECS

#endif