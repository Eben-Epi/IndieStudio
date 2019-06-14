/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** option-menu.cpp
*/

#include "OptionsMenu.hpp"

Irrlicht::OptionsMenu::OptionsMenu(Screen &screen, const std::string &name, unsigned id) : GameScene(screen, name, id)
{
	this->_buttons.emplace_back(new Button({280, 100}, {20, 240, 110, 240 + 32}, CHANGE_KEYS, this->_window.getGuiEnv(), "CHANGE_KEYS"));
	this->_buttons.emplace_back(new Button({280, 500}, {20, 240, 110, 240 + 32}, BACK, this->_window.getGuiEnv(), "BACK"));
}

bool Irrlicht::OptionsMenu::update()
{
	for (unsigned i = 0; i < this->_buttons.size(); i++)
	{
		if (this->isGuiButtonPressed(i))
		{
			switch (i)
			{
			case CHANGE_KEYS:
				changeCurrentGameScene("ChangeKeys");
				break;
			case BACK:
				changeCurrentGameScene("MainMenu");
				break;
			default:
				break;
			}
		}
	}
	return (true);
}

void Irrlicht::OptionsMenu::changeCurrentGameScene(std::string sceneName)
{
	for (unsigned i = 0; i < this->_buttons.size(); i++)
		this->_buttons.at(i)->setVisible(false);
	this->_window.setCurrentGameScene(sceneName);
}