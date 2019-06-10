/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Bedrock.cpp
*/

#include "Bedrock.hpp"
#include "../Ressources.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"

ECS::Bedrock::Bedrock(unsigned id, Ressources &ressources) :
	Entity(id, "Bedrock", {
		new DisplayableComponent("Wall", ressources),
		new ColliderComponent(3),
		new PositionComponent({0, 0}, {TILESIZE, TILESIZE})
	})
{
}