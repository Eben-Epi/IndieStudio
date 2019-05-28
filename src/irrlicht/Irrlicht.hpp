/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Irrlicht.hpp
*/

#ifndef BOMBERMAN_IRRLICHT_HPP
#define BOMBERMAN_IRRLICHT_HPP


#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animations.hpp"
#include "../ecs/Entity.hpp"
#include "../ecs/data/Vector2.hpp"

#define TRANSFORM_COLOR_TO_SFML_COLOR(color) sf::Color(static_cast<sf::Uint8>(color >> 16), static_cast<sf::Uint8>(color >> 8), static_cast<sf::Uint8>(color))

namespace Irrlicht
{
	typedef unsigned Color;

	class IrrEntity {
	public:
		unsigned id;
		ECS::Point pos;
		Animations anim;
		ECS::Vector2<unsigned> size;
		Color color;

		IrrEntity(const std::string &name, unsigned id);
	};

	class Irrlicht {
	private:
		std::vector<IrrEntity> _entities;
		sf::RectangleShape _rectangle;
		sf::RenderWindow _window;
		unsigned _lastId;

		void drawRect(ECS::Point pos, ECS::Vector2<unsigned> size, Color color = 0xFFFFFF, bool filled = false);

	public:
		Irrlicht();

		unsigned registerEntity(const std::string &name);
		bool areColliding(unsigned entity1, unsigned entity2);
		void setAnimation(unsigned entity, Animations anim);
		void setPosition(unsigned entity, float x, float y);
		void display();
		bool isEnd();
	};
}


#endif //BOMBERMAN_IRRLICHT_HPP
