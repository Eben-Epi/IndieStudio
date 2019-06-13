/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Button.hpp
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../../../ecs/data/Vector2.hpp"

namespace Irrlicht
{
	class Button {
		Button(Point pos, Vector2<unsigned> size);
		~Button();

	private:
		Point _pos;
		Vector2<unsigned> _size;
	};
} // namespace Irrlicht

#endif