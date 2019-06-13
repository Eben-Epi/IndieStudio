/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseSystem.cpp
*/
#include "CurseSystem.hpp"
#include "../components/CurseComponent.hpp"
#include "../components/CollisionComponent.hpp"

ECS::CurseSystem::CurseSystem(ECS::ECSCore &core):
    System("Curse", core)
{}

void ECS::CurseSystem::updateEntity(ECS::Entity &entity)
{
    auto &cc = reinterpret_cast<CurseComponent&>(entity.getComponentByName("Curse"));

    if (cc.effect == CurseComponent::CurseEffect::NONE)
    	return;

    if (cc.timeLeft > 0)
        cc.timeLeft -= 1;
    else if (cc.timeLeft == 0)
        cc.effect = CurseComponent::CurseEffect::NONE;

    if (!entity.hasComponent("Collision"))
        return;

    auto &e_collision = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
    for (auto &i : e_collision.entitiesCollided) {
        if (!i->hasComponent("Curse"))
            continue;
        auto &i_curse = reinterpret_cast<CurseComponent &>(i->getComponentByName("Curse"));
        i_curse.giveCurse(cc.effect, cc.timeLeft, false);
    }
}
