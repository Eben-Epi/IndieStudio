/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** NameComponent.hpp
*/

#ifndef BOMBERMAN_NAMECOMPONENT_HPP
#define BOMBERMAN_NAMECOMPONENT_HPP


#include <string>
#include "../Ressources.hpp"

namespace ECS
{
	class NameComponent : public Component {
	public:
		std::string name;

		NameComponent(const std::string &name);
		NameComponent(unsigned id, Ressources &ressources, std::istream &stream);
		std::ostream &serialize(std::ostream &stream) const override;
	};
}


#endif //BOMBERMAN_NAMECOMPONENT_HPP
