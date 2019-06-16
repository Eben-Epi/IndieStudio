/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MortalComponent.hpp
*/

#ifndef BOMBERMAN_MORTALCOMPONENT_HPP
#define BOMBERMAN_MORTALCOMPONENT_HPP


#include "../Ressources.hpp"
#include "../Component.hpp"

namespace ECS
{
	class MortalComponent : public Component {
	public:
		MortalComponent();
		MortalComponent(const unsigned id, Ressources &ressources, std::istream &stream);
		std::ostream &serialize(std::ostream &stream) const override;
	};
}


#endif //BOMBERMAN_MORTALCOMPONENT_HPP
