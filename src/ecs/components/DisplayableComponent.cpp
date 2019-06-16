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
#include "../../irrlicht/game-scene/GameScene.hpp"

namespace ECS
{
	DisplayableComponent::DisplayableComponent(std::string &&spriteId, Ressources &ressources) :
		Component("Displayable"),
		gameScene(ressources.gameScene),
		entityId(this->gameScene.registerEntity(spriteId)),
		spriteId(spriteId),
		animation(Irrlicht::IDLE)
	{
	}

	DisplayableComponent::~DisplayableComponent()
	{
		this->gameScene.deleteEntity(this->entityId);
	}

	std::ostream& DisplayableComponent::serialize(std::ostream &stream) const
	{
		return stream << spriteId << ' ' << animation << " EndOfComponent";
	}

	DisplayableComponent::DisplayableComponent(unsigned id, ECS::Ressources &ressources, std::istream &stream) :
		Component("Displayable"),
		gameScene(ressources.gameScene),
		entityId(0),
		spriteId(""),
		animation(Irrlicht::IDLE)
	{
		std::string terminator;
		unsigned val;

		stream >> this->spriteId >> val >> terminator;
		this->entityId = this->gameScene.registerEntity(spriteId);
		this->animation = static_cast<Irrlicht::Animations>(val);
		if (terminator != "EndOfComponent")
			throw InvalidSerializedStringException("The component terminator was not found");
	}
}