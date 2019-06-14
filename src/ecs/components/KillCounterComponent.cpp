/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KillCounterComponent.cpp
*/
#include "KillCounterComponent.hpp"
#include "../Exceptions.hpp"

ECS::KillCounterComponent::KillCounterComponent(Sound::SoundSystem &soundSystem):
    Component("KillCounter"),
    multikillCount(0),
    multikillTimer(0),
    killQueue({}),
    killedId({}),
    soundSystem(soundSystem)
{}

ECS::KillCounterComponent::KillCounterComponent(ECS::Ressources &ressources, std::istream &stream):
    KillCounterComponent(ressources.soundSystem)
{
    std::string terminator;

    stream >> multikillCount >> multikillTimer >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

std::ostream& ECS::KillCounterComponent::serialize(std::ostream &stream) const
{
    return stream << multikillCount << " "<< multikillTimer << " EndOfComponent";
}