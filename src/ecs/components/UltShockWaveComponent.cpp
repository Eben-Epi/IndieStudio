/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltShockWaveComponent.cpp
*/

#include "UltShockWaveComponent.hpp"
#include "../Exceptions.hpp"

ECS::UltShockWaveComponent::UltShockWaveComponent():
    Component("UltShockWave"),
    timer(0),
    waveCount(0),
    origin({0, 0}),
    directon(0)
{
}

ECS::UltShockWaveComponent::UltShockWaveComponent(ECS::Ressources &ressources, std::istream &stream):
    UltShockWaveComponent()
{
    std::string terminator;

    stream >> this->timer >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

std::ostream& ECS::UltShockWaveComponent::serialize(std::ostream &stream) const
{
    return stream << this->timer <<" EndOfComponent";
}