/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** PowerUpComponent.cpp
*/

#include "PowerUpComponent.hpp"

namespace ECS
{
    PowerUp::PowerUp(unsigned int health = 0, float speed = 0, unsigned int nbBomb = 0, bool kick = false, unsigned int hardness = 0)
    : Component("PowerUp")
    {
        this->_health = health;
        this->_speed = speed;
        this->_nbBomb = nbBomb;
        this->_kick = kick;
        this->_hardness = hardness;
    }
}