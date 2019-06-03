/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedItem.cpp
*/

#include "DroppedItem.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/DisplayableComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/PositionComponent.hpp"
#include "../../config.hpp"
#include "../Components/PowerUpComponent.hpp"
#include "../Components/PickableComponent.hpp"
#include "../Components/PowerUpPickedComponent.hpp"

ECS::DroppedItem::DroppedItem(unsigned id, const Ressources &ressources) :
    Entity(id, "DroppedItem", {
        new HealthComponent(1),
        new DisplayableComponent("DroppedItem", ressources),
        new ColliderComponent(0),
        new PositionComponent({0, 0}, {TILESIZE, TILESIZE}),
        new PowerUpComponent(),
        new PickableComponent(),
        new PowerUpPickedComponent()
    })
{
    //TODO Changed Dropped item by Drop"NomDEL'entity" : eg. -> BonusBomb PowerUp(0, 1, false, 0, 0) ( un truc comme ça )
    //TODO certains bonus sont ephémères
}