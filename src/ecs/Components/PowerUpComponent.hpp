/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpComponent.hpp
*/

#ifndef POWERUPCOMPONENT_HPP
#define POWERUPCOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class PowerUpComponent : public Component
    {
        public:
            unsigned int health;
            float speed;
            unsigned int nbBomb;
            bool kick;
            unsigned int hardness;
            PowerUpComponent(unsigned int health = 0, float speed = 0, unsigned int nbBomb = 0, bool kick = false, unsigned int hardness = 0);
            PowerUpComponent(const Ressources &ressources, std::istream &stream);
	    std::ostream &serialize(std::ostream &stream) const override;
    };
} // namespace ECS

#endif