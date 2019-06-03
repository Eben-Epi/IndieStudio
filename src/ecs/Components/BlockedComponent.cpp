/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedComponent.cpp
*/

#include <iostream>
#include "BlockedComponent.hpp"

ECS::BlockedComponent::BlockedComponent() :
	Component("Block")
{}

std::ostream &ECS::BlockedComponent::serialize(std::ostream &stream) const
{
	return stream;
}