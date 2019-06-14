/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Gunguy.cpp
*/

#include "Alphaone.hpp"
#include "../components/UltInvincibilityComponent.hpp"

ECS::Alphaone::Alphaone(unsigned id, ECS::Ressources &ressources) :
	Player(id, ressources, "Alphaone", new UltInvincibilityComponent(), "cyrak")
{
}
