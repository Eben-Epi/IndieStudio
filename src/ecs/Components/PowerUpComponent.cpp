/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpComponent.cpp
*/

#include <iostream>
#include "PowerUpComponent.hpp"

namespace ECS
{
    PowerUpComponent::PowerUpComponent(std::map<std::string, NumericValue> map) :
    	Component("PowerUp"),
    	health(map["Health"]),
    	speed(map["Speed"]),
    	nbBomb(map["Bomb"]),
    	kick(map["Kick"]),
    	hardness(map["Hardness"]),
    	range(map["Range"])
    {

    }

    std::ostream& PowerUpComponent::serialize(std::ostream &stream) const
    {
    	return stream << health << ' ' << speed << ' ' << nbBomb << ' ' << kick << ' ' << hardness << "EndOfComponent";
    }
}