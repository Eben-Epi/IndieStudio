/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Displayable.cpp
*/


#include "DisplayableComponent.hpp"
#include "../Ressources.hpp"
#include "../../irrlicht/Animations.hpp"

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

	DisplayableComponent::~DisplayableComponent()
	{
		this->screen.deleteEntity(this->entityId);
	}

	std::ostream& DisplayableComponent::serialize(std::ostream &stream) const
	{
		return stream << spriteId << ' ' << animation << " EndOfComponent";
	}
}