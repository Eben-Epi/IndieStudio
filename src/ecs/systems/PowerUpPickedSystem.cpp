/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** PowerUpPickedSystem.cpp
*/

#include "PowerUpPickedSystem.hpp"
#include "../components/PickableComponent.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/PowerUpComponent.hpp"
#include "../components/ColliderComponent.hpp"
#include "../components/KickerComponent.hpp"
#include "../components/BombDropperComponent.hpp"
#include "../components/MovableComponent.hpp"

ECS::PowerUpPickedSystem::PowerUpPickedSystem(ECS::ECSCore &core):
    System("PowerUpPicked", core)
{
    this->_dependencies = {"Collision", "Pickable", "Health"};
}

void ECS::PowerUpPickedSystem::updateEntity(ECS::Entity &entity)
{
    auto &pickable = reinterpret_cast<PickableComponent &>(entity.getComponentByName("Pickable"));
    if (pickable.pickedBy != nullptr) {
        HealthComponent &hc = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
        PowerUpComponent &pucI = reinterpret_cast<PowerUpComponent &>(pickable.pickedBy->getComponentByName("PowerUp"));

        hc.health = 0;
        if (pickable.pickedBy->hasComponent("Health")) {
            auto &tphc = reinterpret_cast<HealthComponent &>(pickable.pickedBy->getComponentByName("Health"));

            tphc.health += pucI.health;
        }
        if (pickable.pickedBy->hasComponent("Collider")) {
            auto &cc = reinterpret_cast<ColliderComponent &>(pickable.pickedBy->getComponentByName("Collider"));

            cc.hardness += pucI.hardness;
        }
        if (pickable.pickedBy->hasComponent("Kicker") && pucI.kick) {
            auto &kc = reinterpret_cast<KickerComponent &>(pickable.pickedBy->getComponentByName("Kicker"));

            kc.canKick = pucI.kick;
        }
        if (pickable.pickedBy->hasComponent("BombDropper")) {
            auto &bdc = reinterpret_cast<BombDropperComponent &>(pickable.pickedBy->getComponentByName("BombDropper"));

            bdc.max += pucI.nbBomb;
            bdc.range += pucI.range;
        }
        if (pickable.pickedBy->hasComponent("Movable") && pucI.speed == 1) {
            auto &mc = reinterpret_cast<MovableComponent &>(pickable.pickedBy->getComponentByName("Movable"));

            mc.speed = pucI.speed;
        }
    }
}