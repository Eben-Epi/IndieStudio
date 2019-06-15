/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** DroppedBonusGhost.hpp
*/

#ifndef BOMBERMAN_DROPPEDBONUSGHOST_HPP
#define BOMBERMAN_DROPPEDBONUSGHOST_HPP


#include "DroppedItem.hpp"

namespace ECS
{
	class DroppedBonusGhost : public DroppedItem {
	public:
		explicit DroppedBonusGhost(unsigned id, Ressources &ressources);
	};
}


#endif //BOMBERMAN_DROPPEDBONUSGHOST_HPP
