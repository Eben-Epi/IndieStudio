/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ControllableComponent.hpp"
#include "../Components/MovableComponent.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../../config.hpp"
#include "../Components/BlockedComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PowerUpPickedComponent.hpp"
#include "../Components/PickerComponent.hpp"

ECS::Player::Player(unsigned id, const Ressources &ressources) :
	Entity(id, "Player", {
		new ControllableComponent(*ressources.inputs.at(id), id),
		new MovableComponent(5),
        new PositionComponent({0, 0}, {TILESIZE - TILESIZE / 8, TILESIZE - TILESIZE / 8}),
        new HealthComponent(1),
		new PickerComponent(),
        new CollisionComponent(0),
        new ColliderComponent(0),
        new BlockedComponent(),
        new DisplayableComponent("Player", ressources)
    })
{}
>>>>>>> bce87bcaae8f65741f135fabcc487c0eda92b0c3
