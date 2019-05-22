/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** HealthComponent.hpp
*/

#ifndef HEALTHCOMPONENT_HPP
#define HEALTHCOPONENT_HPP

#include "Component.hpp"

namespace ECS
{
    class Health : public Component
    {
        public:
            unsigned int _health;
            Health(unsigned int health);
    };
} // namespace ECS

#endif