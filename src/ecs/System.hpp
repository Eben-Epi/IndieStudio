/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** System.hpp
*/

#ifndef BOMBERMAN_SYSTEM_HPP
#define BOMBERMAN_SYSTEM_HPP


#include <string>
#include "Entity.hpp"

namespace ECS
{
	class System {
	private:
		std::string _name;

	public:
		System(std::string &&name);
		std::string getName();
		virtual void updateEntity(Entity &entity) = 0;
	};
}


#endif //BOMBERMAN_SYSTEM_HPP
