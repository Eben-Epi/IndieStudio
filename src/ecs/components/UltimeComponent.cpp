/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltimeComponent.cpp
*/
#include "UltimeComponent.hpp"
#include "../Exceptions.hpp"

ECS::UltimeComponent::UltimeComponent(Sound::SoundSystem &soundSystem):
    Component("Ultime"),
    charge(0),
    soundSystem(soundSystem)
{}

std::ostream& ECS::UltimeComponent::serialize(std::ostream &stream) const
{
    return stream << this->charge << " EndOfComponent";
}

ECS::UltimeComponent::UltimeComponent(ECS::Ressources &ressources, std::istream &stream):
    Component("Ultime"),
    soundSystem(ressources.soundSystem)
{
    std::string terminator;

    stream >> charge >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

bool ECS::UltimeComponent::ultimeIsReady()
{
    return (this->charge >= 10000);
}