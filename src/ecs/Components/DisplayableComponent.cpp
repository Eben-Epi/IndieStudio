/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Displayable.cpp
*/


#include "DisplayableComponent.hpp"
#include "../Ressources.hpp"
#include "../../irrlicht/Animations.hpp"
#include "../Exceptions.hpp"

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

	DisplayableComponent::DisplayableComponent(const ECS::Ressources &ressources, std::istream &stream) :
		Component("Blocked"),
		screen(ressources.screen),
		entityId(0),
		spriteId(""),
		animation(Irrlicht::IDLE)
	{
		std::string terminator;
		unsigned val;

		stream >> this->spriteId >> val >> terminator;
		this->entityId = this->screen.registerEntity(spriteId);
		this->animation = static_cast<Irrlicht::Animations>(val);
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}
}