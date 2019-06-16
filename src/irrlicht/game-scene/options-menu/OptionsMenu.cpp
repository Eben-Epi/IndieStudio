/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** option-menu.cpp
*/

#include "OptionsMenu.hpp"

Irrlicht::OptionsMenu::OptionsMenu(Screen &screen, const std::string &name, unsigned id) : GameScene(screen, name, id)
{
	this->_buttons.emplace_back(new Button({280, 100}, {20, 240, 110, 240 + 32}, CHANGE_KEYS, this->_window.getGuiEnv(), "CHANGE_KEYS"));
	this->_buttons.emplace_back(new Button({10, 600}, {20, 240, 110, 240 + 32}, BACK_OPTIONS, this->_window.getGuiEnv(), "BACK"));
	this->_buttons.emplace_back(new Button({180, 250}, {20, 240, 110, 240 + 32}, VOLUME_LESS, this->_window.getGuiEnv(), "LESS"));
	//TODO afficher du text qui représente le volume entre les boutons
	this->_buttons.emplace_back(new Button({380, 250}, {20, 240, 110, 240 + 32}, VOLUME_MORE, this->_window.getGuiEnv(), "MORE"));
	this->_buttons.emplace_back(new Button({280, 350}, {20, 240, 110, 240 + 32}, VOLUME_MUTE, this->_window.getGuiEnv(), "MUTE"));
}

bool Irrlicht::OptionsMenu::update()
{
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
	for (unsigned i = 0; i < this->_buttons.size(); i++)
	{
		if (this->isGuiButtonPressed(i))
		{
			switch (i)
			{
			// case CHANGE_KEYS:
			// 	if (!this->_window.isValidGetterName("KeysChanging"))
			// 		this->_window.addKeyChangingScene("KeysChanging");
			// 	changeCurrentGameScene("KeysChanging");
			// 	break;
			case BACK_OPTIONS:
				changeCurrentGameScene("Main Menu");
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