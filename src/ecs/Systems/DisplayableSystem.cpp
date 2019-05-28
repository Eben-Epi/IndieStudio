/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DisplayableSystem.cpp
*/

#include "DisplayableSystem.hpp"


ECS::DisplayableSystem::DisplayableSystem(ECS::ECSCore &core):
    System("Displayable", core)
{}

void ECS::DisplayableSystem::updateEntity(ECS::Entity &entity)
{
    // TODO: afficher l'entité (ouais c'est cool)
}