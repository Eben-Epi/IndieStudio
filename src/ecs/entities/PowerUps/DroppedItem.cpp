/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedItem.cpp
*/

#include "DroppedItem.hpp"
#include "../../components/HealthComponent.hpp"
#include "../../components/DisplayableComponent.hpp"
#include "../../components/ColliderComponent.hpp"
#include "../../components/PositionComponent.hpp"
#include "../../../config.hpp"
#include "../../components/PowerUpComponent.hpp"
#include "../../components/PickableComponent.hpp"
#include "../../components/PowerUpPickedComponent.hpp"
#include "../../components/MortalComponent.hpp"

ECS::DroppedItem::DroppedItem(unsigned id, Ressources &ressources, std::string &&texture, std::map<std::string, NumericValue> &&map) :
    Entity(id, "DroppedItem", {
        new HealthComponent(1),
        new DisplayableComponent(std::move(texture), ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent(ressources.soundSystem, map),
        new PickableComponent(),
        new PowerUpPickedComponent(),
        new MortalComponent()
    })
{
}