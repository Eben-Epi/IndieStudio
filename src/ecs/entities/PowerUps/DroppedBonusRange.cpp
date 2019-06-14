/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusRange.cpp
*/

#include "DroppedBonusRange.hpp"
#include "../../components/HealthComponent.hpp"
#include "../../components/DisplayableComponent.hpp"
#include "../../components/ColliderComponent.hpp"
#include "../../components/PositionComponent.hpp"
#include "../../../config.hpp"
#include "../../components/PowerUpComponent.hpp"
#include "../../components/PickableComponent.hpp"
#include "../../components/PowerUpPickedComponent.hpp"
#include "../../components/MortalComponent.hpp"

ECS::DroppedBonusRange::DroppedBonusRange(unsigned id, Ressources &ressources) :
    DroppedItem(id, ressources, "DroppedBonusRange", {{"Range", 1}})
{
}