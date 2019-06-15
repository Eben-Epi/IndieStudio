/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SystemFactory.cpp
*/

#include "SystemFactory.hpp"
#include "../Exceptions.hpp"
#include "../systems/HealthSystem.hpp"
#include "../systems/CollisionSystem.hpp"
#include "../systems/DisplayableSystem.hpp"
#include "../systems/PositionSystem.hpp"
#include "../systems/MovableSystem.hpp"
#include "../systems/KickableSystem.hpp"
#include "../systems/EphemeralSystem.hpp"
#include "../systems/ControllableSystem.hpp"
#include "../systems/BuffedSystem.hpp"
#include "../systems/BombDropperSystem.hpp"
#include "../systems/BlockedSystem.hpp"
#include "../systems/ColliderSystem.hpp"
#include "../systems/CurseSystem.hpp"
#include "../systems/KickerSystem.hpp"
#include "../systems/PickerSystem.hpp"
#include "../systems/PickableSystem.hpp"
#include "../systems/ExplodeSystem.hpp"
#include "../systems/OnCollisionDamageDealerSystem.hpp"
#include "../systems/PowerUpPickedSystem.hpp"
#include "../systems/PowerUpSystem.hpp"
#include "../systems/UltimeSystem.hpp"
#include "../systems/EntityDropperSystem.hpp"
#include "../systems/MortalSystem.hpp"
#include "../systems/UltInvincibilitySystem.hpp"
#include "../systems/CurseOnPickSystem.hpp"
#include "../systems/OOBKillSystem.hpp"
#include "../systems/UltShockWaveSystem.hpp"
#include "../systems/OwnerSystem.hpp"
#include "../systems/KillCounterSystem.hpp"
#include "../systems/NameSystem.hpp"
#include "../systems/UltStrikeSystem.hpp"
#include "../systems/UltBombRainSystem.hpp"

namespace ECS
{
	SystemFactory::SystemFactory(ECS::ECSCore &core) :
		_core(core)
	{
	}

	std::map<std::string, std::function<System *(ECS::ECSCore &core)>> SystemFactory::_functions = {
		{"Blocked", [](ECS::ECSCore &core) { return new BlockedSystem(core); }},
		{"BombDropper", [](ECS::ECSCore &core) { return new BombDropperSystem(core); }},
		{"Buffed", [](ECS::ECSCore &core) { return new BuffedSystem(core); }},
		{"Collider", [](ECS::ECSCore &core) { return new ColliderSystem(core); }},
		{"Collision", [](ECS::ECSCore &core) { return new CollisionSystem(core); }},
		{"Controllable", [](ECS::ECSCore &core) { return new ControllableSystem(core); }},
		{"Curse", [](ECS::ECSCore &core) { return new CurseSystem(core); }},
		{"CurseOnPick", [](ECS::ECSCore &core) { return new CurseOnPickSystem(core); }},
		{"Displayable", [](ECS::ECSCore &core) { return new DisplayableSystem(core); }},
		{"EntityDropper", [](ECS::ECSCore &core) { return new EntityDropperSystem(core); }},
		{"Ephemeral", [](ECS::ECSCore &core) { return new EphemeralSystem(core); }},
		{"Explode", [](ECS::ECSCore &core) { return new ExplodeSystem(core); }},
		{"Health", [](ECS::ECSCore &core) { return new HealthSystem(core); }},
		{"Kickable", [](ECS::ECSCore &core) { return new KickableSystem(core); }},
		{"Kicker", [](ECS::ECSCore &core) { return new KickerSystem(core); }},
		{"KillCounter", [](ECS::ECSCore &core) { return new KillCounterSystem(core); }},
		{"Movable", [](ECS::ECSCore &core) { return new MovableSystem(core); }},
		{"OnCollisionDamageDealer", [](ECS::ECSCore &core) { return new OnCollisionDamageDealerSystem(core); }},
		{"OOBKill", [](ECS::ECSCore &core) { return new OOBKillSystem(core); }},
		{"Owner", [](ECS::ECSCore &core) { return new OwnerSystem(core); }},
		{"Pickable", [](ECS::ECSCore &core) { return new PickableSystem(core); }},
		{"Picker", [](ECS::ECSCore &core) { return new PickerSystem(core); }},
		{"Position", [](ECS::ECSCore &core) { return new PositionSystem(core); }},
		{"PowerUp", [](ECS::ECSCore &core) { return new PowerUpSystem(core); }},
		{"PowerUpPicked", [](ECS::ECSCore &core) { return new PowerUpPickedSystem(core); }},
		{"Ultime", [](ECS::ECSCore &core) { return new UltimeSystem(core); }},
		{"Mortal", [](ECS::ECSCore &core) { return new MortalSystem(core); }},
        {"UltBombRain", [](ECS::ECSCore &core) { return new UltBombRainSystem(core); }},
		{"UltInvincibility", [](ECS::ECSCore &core) { return new UltInvincibilitySystem(core); }},
		{"UltShockWave", [](ECS::ECSCore &core) { return new UltShockWaveSystem(core); }},
        {"UltStrike", [](ECS::ECSCore &core) { return new UltStrikeSystem(core); }},
        {"Name", [](ECS::ECSCore &core) { return new NameSystem(core); }}
	};

	std::unique_ptr<System> SystemFactory::build(std::string &&name) const
	{
		try {
			return std::unique_ptr<System>(SystemFactory::_functions[name](this->_core));
		} catch (std::bad_function_call &) {
			throw NoSuchSystemException("Cannot create system called " + name);
		}
	}

	std::vector<std::unique_ptr<System>> SystemFactory::buildAll() const
	{
		std::vector<std::unique_ptr<System>> vec{SystemFactory::_functions.size()};
		int i = 0;

		for (auto &fun : SystemFactory::_functions)
			vec[i++] = std::unique_ptr<System>(fun.second(this->_core));
		return vec;
	}
}