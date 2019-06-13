/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"

Irrlicht::MainMenu::MainMenu(Screen &screen, const std::string &name, unsigned id) :
	GameScene(screen, name, id)
{
	this->_buttons.emplace_back(new Button(ECS::Point{20, 20}, ECS::Vector2<unsigned>{10, 5}, START, "START"));
	this->_buttons.emplace_back(new Button(ECS::Point{20, 50}, ECS::Vector2<unsigned>{10, 5}, OPTIONS, "OPTIONS"));
	this->_buttons.emplace_back(new Button(ECS::Point{20, 70}, ECS::Vector2<unsigned>{10, 5}, EXIT, "EXIT"));
}

void Irrlicht::MainMenu::update()
{
	for (unsigned i = 0; i < this->_buttons.size(); i++)
		if (this->_buttons.at(i)->isPressed()) {
			switch (this->_buttons.at(i)->id)
			{
			case START:
				changeCurrentGameScene(START);
				break;
			case OPTIONS:
				changeCurrentGameScene(OPTIONS);
				break;
			case EXIT:
				this->_window.getDevice()->drop();
				exit(0); //TODO ON FAIT PAS ÇA PUTAIN <3
				break;
			default:
				break;
			}
		}
}

void Irrlicht::MainMenu::changeCurrentGameScene(ButtonName scene)
{
	this->_window.setCurrentGameScene(scene);
}