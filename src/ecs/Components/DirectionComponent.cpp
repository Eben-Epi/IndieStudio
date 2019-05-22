/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DirectionComponent.cpp
*/

#include "DirectionComponent.hpp"

namespace ECS
{
    Direction::Direction()
    : Component("Direction")
    {
        this->_dir = UP;
    }
}