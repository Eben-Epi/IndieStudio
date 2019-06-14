/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MovableSystem.cpp
*/
#include "MovableSystem.hpp"
#include "../components/MovableComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../data/Directions.hpp"
#include "../../config.hpp"
#include "../components/CurseComponent.hpp"

ECS::MovableSystem::MovableSystem(ECS::ECSCore &core):
    System("Movable", core)
{
    this->_dependencies = {"Position"};
}

void ECS::MovableSystem::updateEntity(ECS::Entity &entity)
{
    auto &mc = reinterpret_cast<MovableComponent&>(entity.getComponentByName("Movable"));
    auto &pc = reinterpret_cast<PositionComponent&>(entity.getComponentByName("Position"));

    if (mc.speed > 0) {
        mc.speed += mc.maxSpeed / (FRAME_RATE / 2);
        if (IS_CURSED(entity, CurseComponent::ULTRASPEED))
            mc.speed = 10;
        else if (IS_CURSED(entity, CurseComponent::ULTRASLOW))
            mc.speed = 0.8f;
        else if (mc.speed > mc.maxSpeed)
            mc.speed = mc.maxSpeed;
        if (mc.speed > HARD_MOUVEMENT_SPEED_CAP)
            mc.speed = HARD_MOUVEMENT_SPEED_CAP;
        if (mc.dir & ECS::Directions::RIGHT)
            pc.pos.x += mc.speed;
        if (mc.dir & ECS::Directions::LEFT)
            pc.pos.x -= mc.speed;
        if (mc.dir & ECS::Directions::UP)
            pc.pos.y -= mc.speed;
        if (mc.dir & ECS::Directions::DOWN)
            pc.pos.y += mc.speed;
    }
}