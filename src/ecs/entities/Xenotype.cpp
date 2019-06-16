/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Warrior.cpp
*/

#include "Xenotype.hpp"
#include "../components/UltShockWaveComponent.hpp"

ECS::Xenotype::Xenotype(unsigned id, ECS::Ressources &ressources) :
	Player(id, ressources, "Xenotype", new UltShockWaveComponent(), "alphaone")
{
}