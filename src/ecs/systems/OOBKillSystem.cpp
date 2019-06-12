/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** OOBKillSystem.cpp
*/
#include "OOBKillSystem.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/OOBKillComponent.hpp"
#include "../components/HealthComponent.hpp"

ECS::OOBKillSystem::OOBKillSystem(ECS::ECSCore &core):
    System("OOBKill", core)
{
    this->_dependencies = {"Health", "Position"};
}

void ECS::OOBKillSystem::updateEntity(ECS::Entity &entity)
{
    auto &self = reinterpret_cast<OOBKillComponent &>(entity.getComponentByName("OOBKill"));
    auto &pc = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));

    if (pc.pos.x < self.p1.x || pc.pos.y < self.p1.y
                             || (pc.pos.x + pc.size.x) > self.p2.x || (pc.pos.y + pc.size.y) > self.p2.y) {
        auto &hc = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
        hc.health = 0;
    }
}