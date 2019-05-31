/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ColliderComponent.hpp
*/

#ifndef BOMBERMAN_COLLIDERCOMPONENT_HPP
#define BOMBERMAN_COLLIDERCOMPONENT_HPP


#include "../Component.hpp"

namespace ECS
{
	class ColliderComponent : public Component {
	public:
		unsigned int hardness;
		explicit ColliderComponent(unsigned hardness);
	};
}


#endif //BOMBERMAN_COLLIDERCOMPONENT_HPP
