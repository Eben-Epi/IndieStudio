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
		gameEngine(ressources.gameScene.gameEngine),
		entityId(this->gameEngine.registerEntity(spriteId)),
		spriteId(spriteId),
		animation(Irrlicht::IDLE)
	{
	}

	DisplayableComponent::~DisplayableComponent()
	{
		this->gameEngine.deleteEntity(this->entityId);
	}

	std::ostream& DisplayableComponent::serialize(std::ostream &stream) const
	{
		return stream << spriteId << ' ' << animation << " EndOfComponent";
	}

	DisplayableComponent::DisplayableComponent(const ECS::Ressources &ressources, std::istream &stream) :
		Component("Displayable"),
		gameEngine(ressources.gameScene.gameEngine),
		entityId(0),
		spriteId(""),
		animation(Irrlicht::IDLE)
	{
		std::string terminator;
		unsigned val;

		stream >> this->spriteId >> val >> terminator;
		this->entityId = this->gameEngine.registerEntity(spriteId);
		this->animation = static_cast<Irrlicht::Animations>(val);
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}
}