/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusGhost.cpp
*/

#include "DroppedBonusGhost.hpp"
#include "../../components/HealthComponent.hpp"
#include "../../components/DisplayableComponent.hpp"
#include "../../components/ColliderComponent.hpp"
#include "../../components/PositionComponent.hpp"
#include "../../../config.hpp"
#include "../../components/PowerUpComponent.hpp"
#include "../../components/PickableComponent.hpp"
#include "../../components/PowerUpPickedComponent.hpp"
#include "../../components/MortalComponent.hpp"

ECS::DroppedBonusGhost::DroppedBonusGhost(unsigned id, Ressources &ressources) :
	DroppedItem(id, ressources, "DroppedBonusGhost", {{"Hardness", 1}})
{
}