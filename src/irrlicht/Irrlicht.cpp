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
	Irrlicht::Irrlicht(ECS::Vector2<unsigned> gridSize) :
		_gridSize(gridSize),
		_window(sf::VideoMode(640, 480), "Arcade")
	{
		this->_window.setFramerateLimit(30);
	}

	void Irrlicht::createEntity(ECS::Entity entity)
	{
		irrEntity newEntity(entity);

		this->_entities.push_back(newEntity);
	}

	bool Irrlicht::areColliding(unsigned entity1, unsigned entity2)
	{
		unsigned int ent1 = -1;
		unsigned int ent2 = -1;

		for (unsigned int i = 0; i < this->_entities.size(); i++) {
			if (this->_entities.at(i).id == entity1)
				ent1 = i;
			else if (this->_entities.at(i).id == entity2)
				ent2 = i;
		}

		if (this->_entities.at(ent1).pos.x >= this->_entities.at(ent2).pos.x && this->_entities.at(ent1).pos.x <= this->_entities.at(ent2).pos.x + this->_entities.at(ent1).size.x)
			if (this->_entities.at(ent1).pos.y >= this->_entities.at(ent2).pos.y && this->_entities.at(ent1).pos.y <= this->_entities.at(ent2).pos.y + this->_entities.at(ent1).size.y)
				return (true);
		return (false);
	}

	void Irrlicht::drawRect(ECS::Point pos, ECS::Vector2<unsigned> size, Color color, bool filled)
	{
		pos.x *= 640. / this->_gridSize.x;
		pos.y *= 480. / this->_gridSize.y;
		size.x *= 640. / this->_gridSize.x;
		size.y *= 480. / this->_gridSize.y;
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

	irrEntity::irrEntity(ECS::Entity entity)
	{
		this->id = entity.getId();
		std::vector<std::unique_ptr<ECS::Component>> components = entity.getComponents();

		for (unsigned int i = 0; i < components.size(); i++) {
			if (components[i]->getName() == "Position") {
				this->pos = dynamic_cast<unique_ptr<ECS::PositionComponent>>(components[i])->pos;
			}
			if (components[i]->getName() == "Size") {
				this->pos = dynamic_cast<unique_ptr<ECS::PositionComponent>>(components[i])->size;
			}
		}
		if (entity.getName() == "Player")
			this->color = 0e1670;
		else if (entity.getName() == "Wall")
			this->color = 8b2020;
		else if (entity.getName() == "Brick")
			this->color = f90061;
		else if (entity.getName() == "Bomb")
			this->color = 666666;
		else
			this->color = ffffff;
	}
}