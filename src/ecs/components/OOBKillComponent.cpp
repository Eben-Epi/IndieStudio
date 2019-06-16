/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** OOBKillComponent.cpp
*/
#include "OOBKillComponent.hpp"
#include "../Exceptions.hpp"

ECS::OOBKillComponent::OOBKillComponent(ECS::Point p1, ECS::Point p2, bool size_mode):
    Component("OOBKill")
{
    this->p1 = p1;
    if (size_mode)
        this->p2 = {p1.x + p2.x, p1.y + p2.y};
    else
        this->p2 = p2;
}

ECS::OOBKillComponent::OOBKillComponent(unsigned id, ECS::Ressources &ressources, std::istream &stream):
    OOBKillComponent({0, 0}, {0, 0})
{
    std::string terminator;

    stream >> p1.x >> p1.y >> p2.x >> p2.y >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

std::ostream& ECS::OOBKillComponent::serialize(std::ostream &stream) const
{
    return stream << this->p1.x << ' ' << this->p1.y << ' ' << this->p2.x << ' ' << this->p2.y << " EndOfComponent";
}