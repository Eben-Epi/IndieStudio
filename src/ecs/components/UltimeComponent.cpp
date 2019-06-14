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
    soundSystem(soundSystem),
    castUlt(false),
    hasUlt(false)
{}

std::ostream& ECS::UltimeComponent::serialize(std::ostream &stream) const
{
    return stream << this->charge << " " << hasUlt <<" EndOfComponent";
}

ECS::UltimeComponent::UltimeComponent(unsigned, ECS::Ressources &ressources, std::istream &stream):
    Component("Ultime"),
    soundSystem(ressources.soundSystem),
    castUlt(false),
    charge(0),
    hasUlt(false)
{
    std::string terminator;

    stream >> charge >> hasUlt >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

bool ECS::UltimeComponent::ultimeIsReady()
{
    return (this->charge >= 10000);
}

void ECS::UltimeComponent::resetUlt()
{
    this->charge = 0;
    this->hasUlt = false;
}