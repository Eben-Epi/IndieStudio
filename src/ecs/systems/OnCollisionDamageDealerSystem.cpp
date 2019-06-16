/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** OnCollisionDamageDealerSystem.cpp
*/

#include "OnCollisionDamageDealerSystem.hpp"
#include "../ECSCore.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/OnCollisionDamageDealerComponent.hpp"
#include "../components/CollisionComponent.hpp"
#include "../components/HealthComponent.hpp"
#include "../Exceptions.hpp"
#include "../components/KillCounterComponent.hpp"

ECS::OnCollisionDamageDealerSystem::OnCollisionDamageDealerSystem(ECS::ECSCore &core):
    System("OnCollisionDamageDealer", core)
{
    this->_dependencies = {"Collision"};
}

void ECS::OnCollisionDamageDealerSystem::updateEntity(ECS::Entity &entity)
{
    CollisionComponent &cc = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
    OnCollisionDamageDealerComponent &ddc = reinterpret_cast<OnCollisionDamageDealerComponent &>(entity.getComponentByName("OnCollisionDamageDealer"));

    for (Entity *entityCollided : cc.entitiesCollided) {
        if (entityCollided->hasComponent("Health")) {
            HealthComponent &hc = reinterpret_cast<HealthComponent &>(entityCollided->getComponentByName("Health"));
            hc.takeDamage(ddc.damage);
        }
        if (ddc.ownerId != -1) {
            try {
                auto &owner = this->_core.getEntityById(ddc.ownerId);
                auto &kill_counter = reinterpret_cast<KillCounterComponent &>(owner.getComponentByName("KillCounter"));
                kill_counter.killQueue.push_back(Kill{entityCollided->getId(), entityCollided->getName()});
            }
            catch (NoSuchEntityException&) {}
        }
    }
}