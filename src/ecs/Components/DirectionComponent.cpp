/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DirectionComponent.cpp
*/

#include "DirectionComponent.hpp"

namespace ECS
{
    DirectionComponent::DirectionComponent() :
    	Component("Direction"),
    	dir(UP)
    {
    }
}