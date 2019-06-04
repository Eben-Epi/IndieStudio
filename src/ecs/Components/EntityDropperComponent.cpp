/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** EntityDropperComponent.cpp
*/

#include "EntityDropperComponent.hpp"

namespace ECS
{
    EntityDropperComponent::EntityDropperComponent() :
    	Component("EntityDropper")
    {
    }

    std::ostream& EntityDropperComponent::serialize(std::ostream &stream) const
    {
        for (const std::string &bonus : this->items)
        {
            stream << bonus + " ";
        }
        return stream << "EndOfComponent";
    }
}
