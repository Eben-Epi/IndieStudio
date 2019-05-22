/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** BombDropperComponent.cpp
*/

#include "BombDropperComponent.hpp"

namespace ECS
{
    BombDropper::BombDropper()
    : Component ("BombDropper")
    {
        this->_max = 3;
        this->_range = 1;
        this->_timeToExplode = 2.0;
    }
}