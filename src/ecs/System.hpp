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
	class ECSCore;

	class System {
	private:
		std::string	_name;

	protected:
		const ECSCore	&_core;

	public:
		explicit System(std::string &&name, const ECSCore &core);
		std::string	getName() const;
		virtual void	updateEntity(Entity &entity) = 0;
	};
}


#endif //BOMBERMAN_SYSTEM_HPP
