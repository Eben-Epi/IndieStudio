/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Entity.hpp
*/

#ifndef BOMBERMAN_ENTITY_HPP
#define BOMBERMAN_ENTITY_HPP


#include <vector>
#include <memory>
#include "Component.hpp"

namespace ECS
{
	class Entity {
	private:
		bool _destroy;
		unsigned _id;
		std::string _name;
		std::vector<std::unique_ptr<Component>> _components;

	public:
		Entity(unsigned id, std::string &&name, std::vector<Component *> &&components);
		void destroy();
		bool isDestroyed();
		unsigned getId() const;
		std::string getName() const;
		bool hasComponent(const std::string &name) const;
		Component &getComponentByName(const std::string &name) const;
		std::vector<std::unique_ptr<Component>> &getComponents();
		/*Component &addComponent(Component *component);

		template<typename type, typename... Args>
		type &addComponent(Args... args) {
			this->_components.emplace_back(new type(args...));
			return *this->_components.back();
		}*/
	};
}


#endif //BOMBERMAN_ENTITY_HPP
