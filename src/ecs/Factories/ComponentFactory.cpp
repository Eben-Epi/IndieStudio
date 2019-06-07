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
#include "../Components/ExplodeComponent.hpp"
#include "../Components/EntityDropperComponent.hpp"
#include "../Components/PowerUpComponent.hpp"
#include "../Components/PowerUpPickedComponent.hpp"
#include "../Components/PickableComponent.hpp"
#include "../Components/PickerComponent.hpp"
#include "../Components/OnCollisionDamageDealerComponent.hpp"
#include "../Components/KickerComponent.hpp"
#include "../Components/MortalComponent.hpp"

namespace ECS 
{
	std::map<std::string, std::function<Component *(const Ressources &ressources, std::istream &stream)>> ComponentFactory::_functions = {
		{"Blocked", [](const Ressources &ressources, std::istream &stream) { return new BlockedComponent(ressources, stream); }},
		{"BombDropper", [](const Ressources &ressources, std::istream &stream) { return new BombDropperComponent(ressources, stream); }},
		{"Buffed", [](const Ressources &ressources, std::istream &stream) { return new BuffedComponent(ressources, stream); }},
		{"Collider", [](const Ressources &ressources, std::istream &stream) { return new ColliderComponent(ressources, stream); }},
		{"Collision", [](const Ressources &ressources, std::istream &stream) { return new CollisionComponent(ressources, stream); }},
		{"Controllable", [](const Ressources &ressources, std::istream &stream) { return new ControllableComponent(ressources, stream); }},
		{"Curse", [](const Ressources &ressources, std::istream &stream) { return new CurseComponent(ressources, stream); }},
		{"Displayable", [](const Ressources &ressources, std::istream &stream) { return new DisplayableComponent(ressources, stream); }},
		{"EntityDropper", [](const Ressources &ressources, std::istream &stream) { return new EntityDropperComponent(ressources, stream); }},
		{"Ephemeral", [](const Ressources &ressources, std::istream &stream) { return new EphemeralComponent(ressources, stream); }},
		{"Explode", [](const Ressources &ressources, std::istream &stream) { return new ExplodeComponent(ressources, stream); }},
		{"Health", [](const Ressources &ressources, std::istream &stream) { return new HealthComponent(ressources, stream); }},
		{"Kickable", [](const Ressources &ressources, std::istream &stream) { return new KickableComponent(ressources, stream); }},
		{"Kicker", [](const Ressources &ressources, std::istream &stream) { return new KickerComponent(ressources, stream); }},
		{"Movable", [](const Ressources &ressources, std::istream &stream) { return new MovableComponent(ressources, stream); }},
		{"OnCollisionDamageDealer", [](const Ressources &ressources, std::istream &stream) { return new OnCollisionDamageDealerComponent(ressources, stream); }},
		{"Pickable", [](const Ressources &ressources, std::istream &stream) { return new PickableComponent(ressources, stream); }},
		{"Picker", [](const Ressources &ressources, std::istream &stream) { return new PickerComponent(ressources, stream); }},
		{"Position", [](const Ressources &ressources, std::istream &stream) { return new PositionComponent(ressources, stream); }},
		{"Blocked", [](const Ressources &ressources, std::istream &stream) { return new BlockedComponent(ressources, stream); }},
		{"Collider", [](const Ressources &ressources, std::istream &stream) { return new ColliderComponent(ressources, stream); }},
		{"Ultime", [](const Ressources &ressources, std::istream &stream) { return new UltimeComponent(ressources, stream); }},
		{"PowerUp", [](const Ressources &ressources, std::istream &stream) { return new PowerUpComponent(ressources, stream); }},
		{"PowerUpPicked", [](const Ressources &ressources, std::istream &stream) { return new PowerUpPickedComponent(ressources, stream); }},
		{"Mortal", [](const Ressources &ressources, std::istream &stream) { return new MortalComponent(ressources, stream); }},
	};

	ComponentFactory::ComponentFactory(const ECS::Ressources &ressources) :
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