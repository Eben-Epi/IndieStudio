/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** PowerUpComponent.hpp
*/

#ifndef POWERUPCOMPONENT_HPP
#define POWERUPCOMPONENT_HPP

#include "Component.hpp"

namespace ECS
{
    class PowerUp : public Component
    {
        public:
            unsigned int _health;
            float _speed;
            unsigned int _nbBomb;
            bool _kick;
            unsigned int _hardness;
            PowerUp(unsigned int health = 0, float speed = 0, unsigned int nbBomb = 0, bool kick = false, unsigned int hardness = 0);
    };
} // namespace ECS

#endif