/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** MovableComponent.cpp
*/

#include "MovableComponent.hpp"

namespace ECS
{
    Movable::Movable(float speed)
    : Component("Movable")
    {
        this->_speed = speed;
    }
}