/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Displayable.cpp
*/

#include "DisplayableComponent.hpp"

namespace ECS
{
	DisplayableComponent::DisplayableComponent(std::string &&spriteId) :
		Component("Displayable"),
		spriteId(spriteId)
	{
	}
}