/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Irrlicht.cpp
*/

#include <memory>
#include "Irrlicht.hpp"
#include "../ecs/Components/PositionComponent.hpp"

namespace Irrlicht
{
	Irrlicht::Irrlicht() :
		_window(sf::VideoMode(640, 512), "Irrlicht"),
		_lastId(0)
	{
		this->_window.setFramerateLimit(30);
	}

	unsigned Irrlicht::registerEntity(const std::string &name)
	{
		this->_entities.emplace_back(name, this->_lastId);
		return this->_lastId++;
	}

	void Irrlicht::setAnimation(unsigned entity, Animations anim)
	{
		for (auto &ent : this->_entities)
			if (ent.id == entity)
				ent.anim = anim;
	}

	void Irrlicht::setPosition(unsigned entity, float x, float y)
	{
		for (auto &ent : this->_entities)
			if (ent.id == entity)
				ent.pos = {x, y};
	}

	void Irrlicht::display()
	{
		this->_window.clear();
		for (auto &ent : this->_entities)
			this->drawRect(ent.pos, ent.size, ent.color, true);
		this->_window.display();
	}

	bool Irrlicht::areColliding(unsigned entity1, unsigned entity2)
	{
		std::vector<IrrEntity *> vec;

		for (auto &ent : this->_entities)
			if (ent.id == entity1 || ent.id == entity2)
				vec.push_back(&ent);

		IrrEntity &e1 = *vec.at(0);
		IrrEntity &e2 = *vec.at(1);

		return !(
			e1.pos.x + e1.size.x < e2.pos.x ||
			e2.pos.x + e2.size.x < e1.pos.x ||
			e1.pos.y + e1.size.y < e2.pos.y ||
			e2.pos.y + e2.size.y < e1.pos.y
		);
	}

	void Irrlicht::drawRect(ECS::Point pos, ECS::Vector2<unsigned> size, Color color, bool filled)
	{
		pos.x += 1;
		pos.y += 1;
		if (size.x <= 1 || size.y <= 1)
			return;
		size.x -= 1;
		size.y -= 1;
		this->_rectangle.setPosition(pos.x, pos.y);
		this->_rectangle.setSize(sf::Vector2f(size.x, size.y));
		this->_rectangle.setOutlineThickness(1);
		this->_rectangle.setOutlineColor(TRANSFORM_COLOR_TO_SFML_COLOR(color));
		if (filled)
			this->_rectangle.setFillColor(TRANSFORM_COLOR_TO_SFML_COLOR(color));
		else
			this->_rectangle.setFillColor(sf::Color(0, 0, 0, 0));
		this->_window.draw(this->_rectangle);
	}

	IrrEntity::IrrEntity(const std::string &name, unsigned id) :
		id{id},
		pos{0, 0},
		anim{IDLE},
		size{64, 64}
	{
		if (name == "Player") {
			this->color = 0x0e1670;
			this->size = {
				50,
				50
			};
		} else if (name == "Wall")
			this->color = 0x8b2020;
		else if (name == "Brick")
			this->color = 0xf90061;
		else if (name == "Bomb")
			this->color = 0x666666;
		else
			this->color = 0xffffff;
	}

	bool Irrlicht::isEnd()
	{
		sf::Event event;

		while (this->_window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				return true;
		return false;
	}
}