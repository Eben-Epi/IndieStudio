/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Gunguy.cpp
*/

#include "Gunguy.hpp"
#include "../components/UltInvincibilityComponent.hpp"

ECS::Gunguy::Gunguy(unsigned id, ECS::Ressources &ressources) :
	Player(id, ressources, "gunguy", new UltInvincibilityComponent())
{
}
