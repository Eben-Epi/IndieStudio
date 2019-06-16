/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltStrikeComponent.cpp
*/
#include "UltStrikeComponent.hpp"
#include "../Exceptions.hpp"

ECS::UltStrikeComponent::UltStrikeComponent():
        Component("UltStrike")
{
}

ECS::UltStrikeComponent::UltStrikeComponent(ECS::Ressources &ressources, std::istream &stream):
        UltStrikeComponent()
{
    std::string terminator;

    stream >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

std::ostream& ECS::UltStrikeComponent::serialize(std::ostream &stream) const
{
    return stream << "EndOfComponent";
}