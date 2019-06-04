/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusHardness.cpp
*/

#include "DroppedBonusHardness.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../Components/PowerUpComponent.hpp"
#include "../Components/PickableComponent.hpp"
#include "../Components/PowerUpPickedComponent.hpp"

ECS::DroppedBonusHardness::DroppedBonusHardness(unsigned id, const Ressources &ressources) :
    Entity(id, "DroppedBonusHardness", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedBonusHardness", ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent({
            std::pair<std::string, NumericValue>("Hardness", 1)
        }),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
}