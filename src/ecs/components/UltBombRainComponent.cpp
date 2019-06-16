/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltBombRainComponent.cpp
*/
#include "UltBombRainComponent.hpp"
#include "../Exceptions.hpp"

ECS::UltBombRainComponent::UltBombRainComponent():
    Component("UltBombRain"),
    timer(0),
    bombCount(0)
{}

ECS::UltBombRainComponent::UltBombRainComponent(ECS::Ressources &ressources, std::istream &stream):
    UltBombRainComponent()
{
    std::string terminator;

    stream >> this->timer >> this->bombCount >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

std::ostream& ECS::UltBombRainComponent::serialize(std::ostream &stream) const
{
    return stream << this->timer << " " << this->bombCount << " EndOfComponent";
}