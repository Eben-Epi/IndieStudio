/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ColliderComponent.cpp
*/

#include <iostream>
#include "ColliderComponent.hpp"

ECS::ColliderComponent::ColliderComponent(unsigned hardness) :
	Component("Collider"),
	hardness(hardness)
{

}

std::ostream& ECS::ColliderComponent::serialize(std::ostream &stream) const
{
	return stream << hardness << " EndOfComponent";
}