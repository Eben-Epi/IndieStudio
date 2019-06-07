/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusRange.cpp
*/

#include "DroppedBonusRange.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../Components/PowerUpComponent.hpp"
#include "../Components/PickableComponent.hpp"
#include "../Components/PowerUpPickedComponent.hpp"

ECS::DroppedBonusRange::DroppedBonusRange(unsigned id, Ressources &ressources) :
    Entity(id, "DroppedBonusRange", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusRange", ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent({
            std::pair<std::string, NumericValue>("Range", 1)
        }),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}