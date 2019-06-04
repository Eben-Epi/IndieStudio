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
    this->_dependencies = {"Collision", "Pickable"};
}

void ECS::PowerUpPickedSystem::updateEntity(ECS::Entity &entity)
{
    auto &pickable = reinterpret_cast<PickableComponent &>(entity.getComponentByName("Pickable"));
    if (pickable.pickedBy != nullptr) {
        reinterpret_cast<HealthComponent &>(pickable.pickedBy->getComponentByName("Health")).health = 0;
        PowerUpComponent &pucI = reinterpret_cast<PowerUpComponent &>(pickable.pickedBy->getComponentByName("PowerUp"));
        if (entity.hasComponent("Health"))
            reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health")).health += pucI.health;
        if (entity.hasComponent("Collider"))
            reinterpret_cast<ColliderComponent &>(entity.getComponentByName("Collider")).hardness += pucI.hardness;
        KickerComponent &kickerComponent = reinterpret_cast<KickerComponent &>(entity.getComponentByName("Kicker"));
        if (entity.hasComponent("Kicker") && pucI.kick)
            reinterpret_cast<KickerComponent &>(entity.getComponentByName("Kicker")).canKick = pucI.kick;
        if (entity.hasComponent("BombDropper")) {
            reinterpret_cast<BombDropperComponent &>(entity.getComponentByName("BombDropper")).max += pucI.nbBomb;
            reinterpret_cast<BombDropperComponent &>(entity.getComponentByName("BombDropper")).range += pucI.range;
        }
        if (entity.hasComponent("Movable") && pucI.speed == 1)
            reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable")).speed = pucI.speed;
    }
}