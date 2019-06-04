/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpPickedSystem.cpp
*/

#include "PowerUpPickedSystem.hpp"
#include "../Components/PickableComponent.hpp"
#include "../Components/HealthComponent.hpp"
#include "../Components/PowerUpComponent.hpp"
#include "../Components/ColliderComponent.hpp"
#include "../Components/KickerComponent.hpp"
#include "../Components/BombDropperComponent.hpp"
#include "../Components/MovableComponent.hpp"

ECS::PowerUpPickedSystem::PowerUpPickedSystem(ECS::ECSCore &core):
    System("PowerUpPicked", core)
{
    this->_dependencies = {"Collision", "Pickable", "Health"};
}

void ECS::PowerUpPickedSystem::updateEntity(ECS::Entity &entity)
{
    auto &pickable = reinterpret_cast<PickableComponent &>(entity.getComponentByName("Pickable"));
    if (pickable.pickedBy != nullptr) {
        HealthComponent &tmpHealthComponent = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
        tmpHealthComponent.health = 0;
        PowerUpComponent &pucI = reinterpret_cast<PowerUpComponent &>(pickable.pickedBy->getComponentByName("PowerUp"));
        if (pickable.pickedBy->hasComponent("Health")) {
            HealthComponent &tmpPickedHealthComponent = reinterpret_cast<HealthComponent &>(pickable.pickedBy->getComponentByName("Health"));
            tmpPickedHealthComponent.health += pucI.health;
        }
        if (pickable.pickedBy->hasComponent("Collider")) {
            ColliderComponent &tmpColliderComponent = reinterpret_cast<ColliderComponent &>(pickable.pickedBy->getComponentByName("Collider"));
            tmpColliderComponent.hardness += pucI.hardness;
        }
        if (pickable.pickedBy->hasComponent("Kicker") && pucI.kick) {
            KickerComponent &tmpKickerComponent = reinterpret_cast<KickerComponent &>(pickable.pickedBy->getComponentByName("Kicker"));
            tmpKickerComponent.canKick = pucI.kick;
        }
        if (pickable.pickedBy->hasComponent("BombDropper")) {
            BombDropperComponent &tmpBombDropperComponent = reinterpret_cast<BombDropperComponent &>(pickable.pickedBy->getComponentByName("BombDropper"));
            tmpBombDropperComponent.max += pucI.nbBomb;
            tmpBombDropperComponent.range += pucI.range;
        }
        if (pickable.pickedBy->hasComponent("Movable") && pucI.speed == 1) {
            MovableComponent &tmpMovableComponent = reinterpret_cast<MovableComponent &>(pickable.pickedBy->getComponentByName("Movable"));
            tmpMovableComponent.speed = pucI.speed;
        }
    }
}