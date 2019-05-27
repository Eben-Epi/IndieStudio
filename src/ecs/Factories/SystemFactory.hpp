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
	class ECSCore;

	class SystemFactory {
	private:
		const ECSCore &_core;
		static std::map<std::string, std::function<System *(const ECSCore &core)>> _functions;

	public:
		explicit SystemFactory(const ECSCore &core);

		std::unique_ptr<System> build(std::string &&name, const ECSCore &core);
		std::vector<std::unique_ptr<System>> buildAll(const ECSCore &core);
	};
}


#endif //BOMBERMAN_SYSTEMFACTORY_HPP
