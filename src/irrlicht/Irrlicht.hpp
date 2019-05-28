/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Irrlicht.hpp
*/

#ifndef BOMBERMAN_IRRLICHT_HPP
#define BOMBERMAN_IRRLICHT_HPP


#include <string>
#include "Animations.hpp"

namespace Irrlicht
{
	class Irrlicht {
	public:
		Irrlicht();

		unsigned registerEntity(const std::string &name);
		bool areColliding(unsigned entity1, unsigned entity2);
		void setAnimation(unsigned entity, Animations anim);
		void setPosition(unsigned entity, float x, float y);
	};
}


#endif //BOMBERMAN_IRRLICHT_HPP
