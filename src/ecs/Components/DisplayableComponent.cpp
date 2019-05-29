/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Displayable.cpp
*/

#include "../../irrlicht/Animations.hpp"
#include "DisplayableComponent.hpp"
#include "../Ressources.hpp"

namespace ECS
{
	DisplayableComponent::DisplayableComponent(std::string &&spriteId, const Ressources &ressources) :
		Component("Displayable"),
		screen(ressources.screen),
		entityId(this->screen.registerEntity(spriteId)),
		spriteId(spriteId),
		animation(Irrlicht::IDLE)
	{
	}
}