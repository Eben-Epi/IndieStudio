/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AIPlayer.cpp
*/

#include "AIPlayer.hpp"
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
#include "../../config.hpp"
#include "../components/ControlledByAIComponent.hpp"

ECS::AIPlayer::AIPlayer(unsigned id, Ressources &ressources) :
    Entity(id, "AIPlayer", {
        new PositionComponent({0, 0}, {TILESIZE - TILESIZE / 8, TILESIZE - TILESIZE / 8}),
        new HealthComponent(1),
        new UltimeComponent(ressources.soundSystem),
        new UltInvincibilityComponent(),
        new CurseComponent(),
        new MovableComponent(2.5),
        new CollisionComponent(0),
        new ColliderComponent(0),
        new BlockedComponent(),
        new BombDropperComponent(ressources.soundSystem),
        new DisplayableComponent("Player", ressources),
        new ControlledByAIComponent(3)
    })
{
}
