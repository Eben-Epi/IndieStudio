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
#include "../components/NameComponent.hpp"
#include "../components/UltStrikeComponent.hpp"
#include "../components/UltBombRainComponent.hpp"

namespace ECS
{
	std::map<std::string, std::function<Component *(unsigned id, Ressources &ressources, std::istream &stream)>> ComponentFactory::_functions{
		{"Blocked", [](unsigned id, Ressources &ressources, std::istream &stream) { return new BlockedComponent(id, ressources, stream); }},
		{"BombDropper", [](unsigned id, Ressources &ressources, std::istream &stream) { return new BombDropperComponent(id, ressources, stream); }},
		{"Buffed", [](unsigned id, Ressources &ressources, std::istream &stream) { return new BuffedComponent(id, ressources, stream); }},
		{"Collider", [](unsigned id, Ressources &ressources, std::istream &stream) { return new ColliderComponent(id, ressources, stream); }},
		{"Collision", [](unsigned id, Ressources &ressources, std::istream &stream) { return new CollisionComponent(id, ressources, stream); }},
		{"Controllable", [](unsigned id, Ressources &ressources, std::istream &stream) { return new ControllableComponent(id, ressources, stream); }},
		{"Curse", [](unsigned id, Ressources &ressources, std::istream &stream) { return new CurseComponent(id, ressources, stream); }},
		{"CurseOnPick", [](unsigned id, Ressources &ressources, std::istream &stream) { return new CurseOnPickComponent(id, ressources, stream); }},
		{"Displayable", [](unsigned id, Ressources &ressources, std::istream &stream) { return new DisplayableComponent(id, ressources, stream); }},
		{"EntityDropper", [](unsigned id, Ressources &ressources, std::istream &stream) { return new EntityDropperComponent(id, ressources, stream); }},
		{"Ephemeral", [](unsigned id, Ressources &ressources, std::istream &stream) { return new EphemeralComponent(id, ressources, stream); }},
		{"Explode", [](unsigned id, Ressources &ressources, std::istream &stream) { return new ExplodeComponent(id, ressources, stream); }},
		{"Health", [](unsigned id, Ressources &ressources, std::istream &stream) { return new HealthComponent(id, ressources, stream); }},
		{"Kickable", [](unsigned id, Ressources &ressources, std::istream &stream) { return new KickableComponent(id, ressources, stream); }},
		{"Kicker", [](unsigned id, Ressources &ressources, std::istream &stream) { return new KickerComponent(id, ressources, stream); }},
		{"Movable", [](unsigned id, Ressources &ressources, std::istream &stream) { return new MovableComponent(id, ressources, stream); }},
		{"OnCollisionDamageDealer", [](unsigned id, Ressources &ressources, std::istream &stream) { return new OnCollisionDamageDealerComponent(id, ressources, stream); }},
		{"OOBKill", [](unsigned id, Ressources &ressources, std::istream &stream) { return new OOBKillComponent(id, ressources, stream); }},
		{"Pickable", [](unsigned id, Ressources &ressources, std::istream &stream) { return new PickableComponent(id, ressources, stream); }},
		{"Picker", [](unsigned id, Ressources &ressources, std::istream &stream) { return new PickerComponent(id, ressources, stream); }},
		{"Position", [](unsigned id, Ressources &ressources, std::istream &stream) { return new PositionComponent(id, ressources, stream); }},
		{"Blocked", [](unsigned id, Ressources &ressources, std::istream &stream) { return new BlockedComponent(id, ressources, stream); }},
		{"Collider", [](unsigned id, Ressources &ressources, std::istream &stream) { return new ColliderComponent(id, ressources, stream); }},
		{"Ultime", [](unsigned id, Ressources &ressources, std::istream &stream) { return new UltimeComponent(id, ressources, stream); }},
		{"PowerUp", [](unsigned id, Ressources &ressources, std::istream &stream) { return new PowerUpComponent(id, ressources, stream); }},
		{"PowerUpPicked", [](unsigned id, Ressources &ressources, std::istream &stream) { return new PowerUpPickedComponent(id, ressources, stream); }},
		{"Mortal", [](unsigned id, Ressources &ressources, std::istream &stream) { return new MortalComponent(id, ressources, stream); }},
		{"Ultime", [](unsigned id, Ressources &ressources, std::istream &stream) { return new UltimeComponent(id, ressources, stream); }},
		{"KillCounter", [](unsigned, Ressources &ressources, std::istream &stream) { return new KillCounterComponent(ressources, stream); }},
        {"Owner", [](unsigned, Ressources &ressources, std::istream &stream) { return new OwnerComponent(ressources, stream); }},
        {"UltBombRain", [](unsigned id, Ressources &ressources, std::istream &stream) { return new UltBombRainComponent(ressources, stream); }},
        {"UltInvincibility", [](unsigned id, Ressources &ressources, std::istream &stream) { return new UltInvincibilityComponent(id, ressources, stream); }},
        {"UltShockWave", [](unsigned, Ressources &ressources, std::istream &stream) { return new UltShockWaveComponent(ressources, stream); }},
        {"UltStrike", [](unsigned, Ressources &ressources, std::istream &stream) { return new UltStrikeComponent(ressources, stream); }},
        {"Name", [](unsigned id, Ressources &ressources, std::istream &stream) { return new NameComponent(id, ressources, stream); }}
	};

	ComponentFactory::ComponentFactory(ECS::Ressources &ressources) :
		_ressources(ressources)
	{
	}

	std::unique_ptr<Component> ComponentFactory::build(const std::string &name, unsigned owner_id, std::istream &stream) const
	{
		try {
			return std::unique_ptr<Component>(ComponentFactory::_functions[name](owner_id, this->_ressources, stream));
		} catch (std::bad_function_call &) {
			throw NoSuchComponentException("Cannot build component called " + name);
		}
	}
}