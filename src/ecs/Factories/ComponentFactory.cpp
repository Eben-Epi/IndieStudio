/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ComponentFactory.cpp
*/

#include "ComponentFactory.hpp"
#include "../Components/BombDropperComponent.hpp"
#include "../Components/BuffedComponent.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/ControllableComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/EphemeralComponent.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/KickableComponent.hpp"
#include "../Components/MovableComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/BlockedComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Exceptions.hpp"

namespace ECS 
{
	std::map<std::string, std::function<Component *(const Ressources &ressources, std::istream &stream)>> ComponentFactory::_functions = {
		{"BombDropper", [](const Ressources &ressources, std::istream &stream) { return new BombDropperComponent(ressources, stream); }},
		{"Buffed", [](const Ressources &ressources, std::istream &stream) { return new BuffedComponent(ressources, stream); }},
		{"Collision", [](const Ressources &ressources, std::istream &stream) { return new CollisionComponent(ressources, stream); }},
		{"Curse", [](const Ressources &ressources, std::istream &stream) { return new CurseComponent(ressources, stream); }},
		{"Controllable", [](const Ressources &ressources, std::istream &stream) { return new ControllableComponent(ressources, stream); }},
		{"Displayable", [](const Ressources &ressources, std::istream &stream) { return new DisplayableComponent(ressources, stream); }},
		{"Ephemeral", [](const Ressources &ressources, std::istream &stream) { return new EphemeralComponent(ressources, stream); }},
		{"Health", [](const Ressources &ressources, std::istream &stream) { return new HealthComponent(ressources, stream); }},
		{"Kickable", [](const Ressources &ressources, std::istream &stream) { return new KickableComponent(ressources, stream); }},
		{"Movable", [](const Ressources &ressources, std::istream &stream) { return new MovableComponent(ressources, stream); }},
		{"Position", [](const Ressources &ressources, std::istream &stream) { return new PositionComponent(ressources, stream); }},
		{"Blocked", [](const Ressources &ressources, std::istream &stream) { return new BlockedComponent(ressources, stream); }},
		{"Collider", [](const Ressources &ressources, std::istream &stream) { return new ColliderComponent(ressources, stream); }}
	};

	std::unique_ptr<Component> ComponentFactory::build(const std::string &name, std::ostream &stream) const
	{
		try {
			return std::unique_ptr<Component>(ComponentFactory::_functions[name](this->_ressources, stream));
		} catch (std::bad_function_call &) {
			throw NoSuchComponentException("Cannot build component called " + name);
		}
	}
}