/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** OwnerComponent.cpp
*/
#include "OwnerComponent.hpp"
#include "../Exceptions.hpp"

ECS::OwnerComponent::OwnerComponent():
    Component("Owner"),
    ownerId(-1)
{}

ECS::OwnerComponent::OwnerComponent(ECS::Ressources &ressources, std::istream &stream):
    OwnerComponent()
{
    std::string terminator;

    stream >> ownerId >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

std::ostream& ECS::OwnerComponent::serialize(std::ostream &stream) const
{
    return stream << ownerId << " EndOfComponent";
}

bool ECS::OwnerComponent::hasOwner()
{
    return (this->ownerId != -1);
}