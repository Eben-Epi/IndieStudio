/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseOnPickComponent.cpp
*/

#include "CurseOnPickComponent.hpp"
#include "../Exceptions.hpp"

ECS::CurseOnPickComponent::CurseOnPickComponent(Sound::SoundSystem &soundSystem):
    soundSystem(soundSystem),
    Component("CurseOnPick")
{}

ECS::CurseOnPickComponent::CurseOnPickComponent(unsigned id, Ressources &ressources, std::istream &stream):
    CurseOnPickComponent(ressources.soundSystem)
{
    std::string terminator;

    stream >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

std::ostream &ECS::CurseOnPickComponent::serialize(std::ostream &stream) const
{
    return stream << "EndOfComponent";
}