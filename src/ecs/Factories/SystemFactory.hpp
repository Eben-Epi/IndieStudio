/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SystemFactory.hpp
*/

#ifndef BOMBERMAN_SYSTEMFACTORY_HPP
#define BOMBERMAN_SYSTEMFACTORY_HPP


#include <map>
#include <memory>
#include <functional>
#include "../System.hpp"

namespace ECS
{
	class SystemFactory {
	public:
		static std::map<std::string, std::function<System *()>> functions;

		static std::unique_ptr<System> build(std::string &&name);
		static std::vector<std::unique_ptr<System>> buildAll();
	};
}


#endif //BOMBERMAN_SYSTEMFACTORY_HPP
