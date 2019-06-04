/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** HealthComponent.hpp
*/

#ifndef HEALTHCOMPONENT_HPP
#define HEALTHCOPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class HealthComponent : public Component
    {
        public:
            unsigned int health;
            HealthComponent(unsigned int health);
            HealthComponent(const Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif