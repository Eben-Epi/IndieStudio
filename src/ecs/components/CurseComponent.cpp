/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseComponent.cpp
*/

#include <iostream>
#include "CurseComponent.hpp"
#include "../Exceptions.hpp"


ECS::CurseComponent::CurseComponent():
    Component("Curse"),
    effect(NONE),
    timeLeft(-1)
{}

ECS::CurseComponent::CurseComponent(ECS::Ressources &ressources, std::istream &stream):
    CurseComponent()
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

bool ECS::CurseComponent::giveCurse(ECS::CurseComponent::CurseEffect effect, int time, bool force)
{
    if (this->timeLeft > 0 && !force)
        return false;
    this->effect = effect;
    this->timeLeft = time;
    return true;
}

std::ostream& ECS::CurseComponent::serialize(std::ostream &stream) const
{
    return stream << this->effect << " " << this->timeLeft << " " << "EndOfComponent";
}