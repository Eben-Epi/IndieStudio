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
#include "../components/PowerUpComponent.hpp"
#include "../components/KickerComponent.hpp"
#include "../../config.hpp"
#include "../components/OOBKillComponent.hpp"

ECS::Player::Player(unsigned id, Ressources &ressources) :
	Entity(id, "Player", {
		new PositionComponent({0, 0}, {PLAYERSIZE, PLAYERSIZE}),
		new HealthComponent(1),
		new OOBKillComponent({0, 0}, {20 * TILESIZE, 20 * TILESIZE}),
		new UltimeComponent(ressources.soundSystem),
		new UltInvincibilityComponent(),
		new MovableComponent(2.5),
		new CollisionComponent(0),
		new ColliderComponent(0),
        new CurseComponent(ressources.soundSystem),
        new BlockedComponent(),
		new PickerComponent(),
		new KickerComponent(),
		new BombDropperComponent(ressources.soundSystem),
		new DisplayableComponent("Player", ressources),
		new ControllableComponent(*ressources.inputs.at(id), id)
	})
{
}
