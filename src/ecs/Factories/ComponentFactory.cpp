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
#include "../Components/CurseComponent.hpp"
#include "../Components/UltimeComponent.hpp"

namespace ECS 
{
	std::map<std::string, std::function<Component *(Ressources &ressources, std::istream &stream)>> ComponentFactory::_functions = {
		{"BombDropper", [](Ressources &ressources, std::istream &stream) { return new BombDropperComponent(ressources, stream); }},
		{"Buffed", [](Ressources &ressources, std::istream &stream) { return new BuffedComponent(ressources, stream); }},
		{"Collision", [](Ressources &ressources, std::istream &stream) { return new CollisionComponent(ressources, stream); }},
		{"Curse", [](Ressources &ressources, std::istream &stream) { return new CurseComponent(ressources, stream); }},
		{"Controllable", [](Ressources &ressources, std::istream &stream) { return new ControllableComponent(ressources, stream); }},
		{"Displayable", [](Ressources &ressources, std::istream &stream) { return new DisplayableComponent(ressources, stream); }},
		{"Ephemeral", [](Ressources &ressources, std::istream &stream) { return new EphemeralComponent(ressources, stream); }},
		{"Health", [](Ressources &ressources, std::istream &stream) { return new HealthComponent(ressources, stream); }},
		{"Kickable", [](Ressources &ressources, std::istream &stream) { return new KickableComponent(ressources, stream); }},
		{"Movable", [](Ressources &ressources, std::istream &stream) { return new MovableComponent(ressources, stream); }},
		{"Position", [](Ressources &ressources, std::istream &stream) { return new PositionComponent(ressources, stream); }},
		{"Blocked", [](Ressources &ressources, std::istream &stream) { return new BlockedComponent(ressources, stream); }},
		{"Collider", [](Ressources &ressources, std::istream &stream) { return new ColliderComponent(ressources, stream); }},
		{"Ultime", [](Ressources &ressources, std::istream &stream) { return new UltimeComponent(ressources, stream); }}
	};

	ComponentFactory::ComponentFactory(ECS::Ressources &ressources) :
		_ressources(ressources)
	{
	}

	std::unique_ptr<Component> ComponentFactory::build(const std::string &name, std::istream &stream) const
	{
		try {
			return std::unique_ptr<Component>(ComponentFactory::_functions[name](this->_ressources, stream));
		} catch (std::bad_function_call &) {
			throw NoSuchComponentException("Cannot build component called " + name);
		}
	}
}