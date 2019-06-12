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

    if (cc.timeLeft > 0)
        cc.timeLeft -= 1;

    else if (cc.timeLeft == 0) {
        cc.effect = CurseComponent::CurseEffect::NONE;
        cc.timeLeft = -1;
    }

    if (cc.timeLeft <= 0 || !entity.hasComponent("Collision"))
        return;

    auto &e_collision = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
    printf("Entities Collided : [");
    for (auto &i : e_collision.entitiesCollided) {
        if (!i->hasComponent("Curse"))
            continue;
        printf("%s (%d), ", i->getName().c_str(), i->getId());
        auto &i_curse = reinterpret_cast<CurseComponent &>(i->getComponentByName("Curse"));
        printf("result of give curse %d\n", i_curse.giveCurse(cc.effect, cc.timeLeft, false));
    }
    printf("]\n");
}