/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusKick.cpp
*/

#include "DroppedBonusKick.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../Components/PowerUpComponent.hpp"
#include "../Components/PickableComponent.hpp"
#include "../Components/PowerUpPickedComponent.hpp"

ECS::DroppedBonusKick::DroppedBonusKick(unsigned id, const Ressources &ressources) :
    Entity(id, "DroppedBonusKick", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusKick", ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent({
            std::pair<std::string, NumericValue>("Kick", true)
        }),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}