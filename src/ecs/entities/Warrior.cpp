/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Warrior.cpp
*/

#include "Warrior.hpp"
#include "../components/UltInvincibilityComponent.hpp"

ECS::Warrior::Warrior(unsigned id, ECS::Ressources &ressources) :
	Player(id, ressources, "warrior", new UltInvincibilityComponent())
{
}