/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** KickerComponent.cpp
*/

#include <iostream>
#include "KickerComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS
{
    KickerComponent::KickerComponent() :
        Component("Kicker"),
        canKick(false)
    {
    }

    std::ostream& KickerComponent::serialize(std::ostream &stream) const
    {
        return stream << this->canKick << " EndOfComponent";
    }

    KickerComponent::KickerComponent(unsigned, ECS::Ressources &, std::istream &stream) :
        KickerComponent()
    {
        std::string terminator;

        stream >> this->canKick >> terminator;
        if (terminator != "EndOfComponent")
            throw InvalidSerializedStringException("The component terminator was not found");
    }
}