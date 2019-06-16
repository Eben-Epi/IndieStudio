/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseComponent.cpp
*/

#include <iostream>
#include "CurseComponent.hpp"
#include "../Exceptions.hpp"


ECS::CurseComponent::CurseComponent(Sound::SoundSystem &soundSystem):
    Component("Curse"),
    soundSystem(soundSystem),
    effect(NONE),
    timeLeft(0)
{}

ECS::CurseComponent::CurseComponent(unsigned id, ECS::Ressources &ressources, std::istream &stream):
    CurseComponent(ressources.soundSystem)
{
    unsigned tmp;
    std::string terminator;

    stream >> tmp;
    this->effect = static_cast<CurseEffect>(tmp);
    stream >> this->timeLeft;
    stream >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

bool ECS::CurseComponent::giveCurse(CurseEffect eff, int time, bool force, bool playSound)
{
    if (this->timeLeft > 0 && !force)
        return false;
    this->effect = eff;
    this->timeLeft = time;
    if (playSound)
        this->soundSystem.playSound("skull");
    return true;
}

std::ostream& ECS::CurseComponent::serialize(std::ostream &stream) const
{
    return stream << this->effect << " " << this->timeLeft << " " << "EndOfComponent";
}