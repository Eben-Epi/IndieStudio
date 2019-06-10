/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** ControlledByAIComponent.cpp
*/

#include "ControlledByAIComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    ControlledByAIComponent::ControlledByAIComponent(unsigned smartness, bool isControlled) :
        Component("ControlledByAI"),
        smartness(smartness),
        isControlled(isControlled)
    {
    }

    std::ostream& ControlledByAIComponent::serialize(std::ostream &stream) const
    {
        return stream << smartness << " EndOfComponent";
    }

    ControlledByAIComponent::ControlledByAIComponent(ECS::Ressources &ressources, std::istream &stream) :
        Component("ControlledByAI")
    {
        std::string terminator;

        stream >> smartness >> terminator;
        if (terminator != "EndOfComponent")
            throw InvalidSerializedStringException("The component terminator was not found");
    }
}