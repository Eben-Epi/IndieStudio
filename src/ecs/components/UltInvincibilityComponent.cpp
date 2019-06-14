/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltInvincibilityComponent.cpp
*/

#include "UltInvincibilityComponent.hpp"
#include "../Exceptions.hpp"

ECS::UltInvincibilityComponent::UltInvincibilityComponent():
    Component("UltInvincibility"),
    timeLeft(0),
    isOnUse(false),
    oldPassThrough(0)
{}

ECS::UltInvincibilityComponent::UltInvincibilityComponent(unsigned id, ECS::Ressources &ressources, std::istream &stream):
    UltInvincibilityComponent()
{
    std::string terminator;

    stream >> this->timeLeft >> this->isOnUse >> this->oldPassThrough >> terminator;
    if (terminator != "EndOfComponent")
        throw InvalidSerializedStringException("The component terminator was not found");
}

std::ostream& ECS::UltInvincibilityComponent::serialize(std::ostream &stream) const
{
    return stream << this->timeLeft << " " << this->isOnUse << " " << this->oldPassThrough << " EndOfComponent";
}