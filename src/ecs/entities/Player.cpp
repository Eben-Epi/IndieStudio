/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/ControllableComponent.hpp"
#include "../components/MovableComponent.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/BlockedComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/CurseComponent.hpp"
#include "../components/UltimeComponent.hpp"
#include "../components/BombDropperComponent.hpp"
#include "../components/UltInvincibilityComponent.hpp"
#include "../components/PickerComponent.hpp"
#include "../components/KickerComponent.hpp"
#include "../../config.hpp"
#include "../components/OOBKillComponent.hpp"
#include "../components/MortalComponent.hpp"

ECS::Player::Player(unsigned id, Ressources &ressources, std::string &&texture, Component *ultimate) :
	Entity(id, "Player", {
		new PositionComponent({0, 0}, {PLAYERSIZE, PLAYERSIZE}),
		new HealthComponent(1),
		new OOBKillComponent({-TILESIZE, -TILESIZE}, {20 * TILESIZE, 20 * TILESIZE}),
		new UltimeComponent(ressources.soundSystem),
		ultimate,
		new MovableComponent(2.5),
		new CollisionComponent(0),
		new ColliderComponent(0),
		new CurseComponent(ressources.soundSystem),
		new BlockedComponent(),
		new PickerComponent(),
		new KickerComponent(),
		new MortalComponent(),
		new BombDropperComponent(ressources.soundSystem),
		new DisplayableComponent(std::move(texture), ressources),
		new ControllableComponent(*ressources.inputs.at(id), id)
	})
{
}
