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
#include "../../config.hpp"

namespace ECS
{
    class HealthComponent : public Component
    {
        public:
            unsigned int health;
            int invunerabilityTimeLeft;
            bool takeDamage(int damage=1, unsigned invulnerability_given=FRAME_RATE);
            HealthComponent(unsigned int health, unsigned unvulnerability = 0);
            HealthComponent(unsigned id, Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif