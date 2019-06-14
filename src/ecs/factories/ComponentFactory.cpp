/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ComponentFactory.cpp
*/

#include "ComponentFactory.hpp"
#include "../Exceptions.hpp"
#include "../components/BombDropperComponent.hpp"
#include "../components/BuffedComponent.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/ControllableComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/EphemeralComponent.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/KickableComponent.hpp"
#include "../components/MovableComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/BlockedComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/CurseComponent.hpp"
#include "../components/UltimeComponent.hpp"
#include "../components/ExplodeComponent.hpp"
#include "../components/EntityDropperComponent.hpp"
#include "../components/PowerUpComponent.hpp"
#include "../components/PowerUpPickedComponent.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/PickerComponent.hpp"
#include "../components/OnCollisionDamageDealerComponent.hpp"
#include "../components/KickerComponent.hpp"
#include "../components/MortalComponent.hpp"
#include "../components/UltInvincibilityComponent.hpp"
#include "../components/CurseOnPickComponent.hpp"
#include "../components/OOBKillComponent.hpp"
#include "../components/UltShockWaveComponent.hpp"
#include "../components/OwnerComponent.hpp"
#include "../components/KillCounterComponent.hpp"

namespace ECS 
{
	std::map<std::string, std::function<Component *(Ressources &ressources, std::istream &stream)>> ComponentFactory::_functions = {
		{"Blocked", [](Ressources &ressources, std::istream &stream) { return new BlockedComponent(ressources, stream); }},
		{"BombDropper", [](Ressources &ressources, std::istream &stream) { return new BombDropperComponent(ressources, stream); }},
		{"Buffed", [](Ressources &ressources, std::istream &stream) { return new BuffedComponent(ressources, stream); }},
		{"Collider", [](Ressources &ressources, std::istream &stream) { return new ColliderComponent(ressources, stream); }},
		{"Collision", [](Ressources &ressources, std::istream &stream) { return new CollisionComponent(ressources, stream); }},
		{"Controllable", [](Ressources &ressources, std::istream &stream) { return new ControllableComponent(ressources, stream); }},
		{"Curse", [](Ressources &ressources, std::istream &stream) { return new CurseComponent(ressources, stream); }},
		{"CurseOnPick", [](Ressources &ressources, std::istream &stream) { return new CurseOnPickComponent(ressources, stream); }},
		{"Displayable", [](Ressources &ressources, std::istream &stream) { return new DisplayableComponent(ressources, stream); }},
		{"EntityDropper", [](Ressources &ressources, std::istream &stream) { return new EntityDropperComponent(ressources, stream); }},
		{"Ephemeral", [](Ressources &ressources, std::istream &stream) { return new EphemeralComponent(ressources, stream); }},
		{"Explode", [](Ressources &ressources, std::istream &stream) { return new ExplodeComponent(ressources, stream); }},
		{"Health", [](Ressources &ressources, std::istream &stream) { return new HealthComponent(ressources, stream); }},
		{"Kickable", [](Ressources &ressources, std::istream &stream) { return new KickableComponent(ressources, stream); }},
		{"Kicker", [](Ressources &ressources, std::istream &stream) { return new KickerComponent(ressources, stream); }},
        {"KillCounter", [](Ressources &ressources, std::istream &stream) { return new KillCounterComponent(ressources, stream); }},
		{"Movable", [](Ressources &ressources, std::istream &stream) { return new MovableComponent(ressources, stream); }},
		{"OnCollisionDamageDealer", [](Ressources &ressources, std::istream &stream) { return new OnCollisionDamageDealerComponent(ressources, stream); }},
        {"OOBKill", [](Ressources &ressources, std::istream &stream) { return new OOBKillComponent(ressources, stream); }},
        {"Owner", [](Ressources &ressources, std::istream &stream) { return new OwnerComponent(ressources, stream); }},
        {"Pickable", [](Ressources &ressources, std::istream &stream) { return new PickableComponent(ressources, stream); }},
		{"Picker", [](Ressources &ressources, std::istream &stream) { return new PickerComponent(ressources, stream); }},
		{"Position", [](Ressources &ressources, std::istream &stream) { return new PositionComponent(ressources, stream); }},
		{"Blocked", [](Ressources &ressources, std::istream &stream) { return new BlockedComponent(ressources, stream); }},
		{"Collider", [](Ressources &ressources, std::istream &stream) { return new ColliderComponent(ressources, stream); }},
		{"Ultime", [](Ressources &ressources, std::istream &stream) { return new UltimeComponent(ressources, stream); }},
		{"PowerUp", [](Ressources &ressources, std::istream &stream) { return new PowerUpComponent(ressources, stream); }},
		{"PowerUpPicked", [](Ressources &ressources, std::istream &stream) { return new PowerUpPickedComponent(ressources, stream); }},
		{"Mortal", [](Ressources &ressources, std::istream &stream) { return new MortalComponent(ressources, stream); }},
		{"Ultime", [](Ressources &ressources, std::istream &stream) { return new UltimeComponent(ressources, stream); }},
		{"UltInvincibility", [](Ressources &ressources, std::istream &stream) { return new UltInvincibilityComponent(ressources, stream); }},
        {"UltShockWave", [](Ressources &ressources, std::istream &stream) { return new UltShockWaveComponent(ressources, stream); }}
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