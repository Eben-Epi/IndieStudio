/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedItem.cpp
*/

#include "DroppedItem.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/DisplayableComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../components/PowerUpComponent.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/PowerUpPickedComponent.hpp"

ECS::DroppedItem::DroppedItem(unsigned id, Ressources &ressources) :
    Entity(id, "DroppedItem", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedItem", ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent(ressources.soundSystem, {}),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
    //TODO Changed Dropped item by Drop"NomDEL'entity" : eg. -> BonusBomb PowerUp(0, 1, false, 0, 0) ( un truc comme ça )
    //TODO certains bonus sont ephémères
}