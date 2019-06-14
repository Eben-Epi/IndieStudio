/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Warrior.cpp
*/

#include "Xenotype.hpp"
#include "../components/UltInvincibilityComponent.hpp"

ECS::Xenotype::Xenotype(unsigned id, ECS::Ressources &ressources) :
	Player(id, ressources, "Xenotype", new UltInvincibilityComponent(), "gunguy")
{
}