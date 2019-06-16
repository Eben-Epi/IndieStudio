/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** KeyManagingMenu.cpp
*/

#include "KeyManagingMenu.hpp"

Irrlicht::KeyManagingMenu::KeyManagingMenu(Screen &screen, const std::string &name, unsigned id) : GameScene(screen, name, id)
{
	//afficher du text qui représente chaque player en colonne et chaque key en lignes
	this->_buttons.emplace_back(new Button({10, 600}, {20, 240, 110, 240 + 32}, BACKBACK, this->_window.getGuiEnv(), "BACK"));

	this->_buttons.emplace_back(new Button({150, 200}, {20, 240, 110, 240 + 32}, P1_UP, this->_window.getGuiEnv(), "UP"));
	this->_buttons.emplace_back(new Button({150, 260}, {20, 240, 110, 240 + 32}, P1_DOWN, this->_window.getGuiEnv(), "DOWN"));
	this->_buttons.emplace_back(new Button({150, 320}, {20, 240, 110, 240 + 32}, P1_LEFT, this->_window.getGuiEnv(), "LEFT"));
	this->_buttons.emplace_back(new Button({150, 380}, {20, 240, 110, 240 + 32}, P1_RIGHT, this->_window.getGuiEnv(), "RIGHT"));
	this->_buttons.emplace_back(new Button({150, 440}, {20, 240, 110, 240 + 32}, P1_DROP, this->_window.getGuiEnv(), "DROP"));
	this->_buttons.emplace_back(new Button({150, 500}, {20, 240, 110, 240 + 32}, P1_ULT, this->_window.getGuiEnv(), "ULT"));

	this->_buttons.emplace_back(new Button({270, 500}, {20, 240, 110, 240 + 32}, P2_UP, this->_window.getGuiEnv(), "ULT"));
	this->_buttons.emplace_back(new Button({270, 200}, {20, 240, 110, 240 + 32}, P2_DOWN, this->_window.getGuiEnv(), "UP"));
	this->_buttons.emplace_back(new Button({270, 260}, {20, 240, 110, 240 + 32}, P2_LEFT, this->_window.getGuiEnv(), "DOWN"));
	this->_buttons.emplace_back(new Button({270, 320}, {20, 240, 110, 240 + 32}, P2_RIGHT, this->_window.getGuiEnv(), "LEFT"));
	this->_buttons.emplace_back(new Button({270, 380}, {20, 240, 110, 240 + 32}, P2_DROP, this->_window.getGuiEnv(), "RIGHT"));
	this->_buttons.emplace_back(new Button({270, 440}, {20, 240, 110, 240 + 32}, P2_ULT, this->_window.getGuiEnv(), "DROP"));

	this->_buttons.emplace_back(new Button({390, 200}, {20, 240, 110, 240 + 32}, P3_UP, this->_window.getGuiEnv(), "UP"));
	this->_buttons.emplace_back(new Button({390, 260}, {20, 240, 110, 240 + 32}, P3_DOWN, this->_window.getGuiEnv(), "DOWN"));
	this->_buttons.emplace_back(new Button({390, 320}, {20, 240, 110, 240 + 32}, P3_LEFT, this->_window.getGuiEnv(), "LEFT"));
	this->_buttons.emplace_back(new Button({390, 380}, {20, 240, 110, 240 + 32}, P3_RIGHT, this->_window.getGuiEnv(), "RIGHT"));
	this->_buttons.emplace_back(new Button({390, 440}, {20, 240, 110, 240 + 32}, P3_DROP, this->_window.getGuiEnv(), "DROP"));
	this->_buttons.emplace_back(new Button({390, 500}, {20, 240, 110, 240 + 32}, P3_ULT, this->_window.getGuiEnv(), "ULT"));

	this->_buttons.emplace_back(new Button({510, 200}, {20, 240, 110, 240 + 32}, P4_UP, this->_window.getGuiEnv(), "UP"));
	this->_buttons.emplace_back(new Button({510, 260}, {20, 240, 110, 240 + 32}, P4_DOWN, this->_window.getGuiEnv(), "DOWN"));
	this->_buttons.emplace_back(new Button({510, 320}, {20, 240, 110, 240 + 32}, P4_LEFT, this->_window.getGuiEnv(), "LEFT"));
	this->_buttons.emplace_back(new Button({510, 380}, {20, 240, 110, 240 + 32}, P4_RIGHT, this->_window.getGuiEnv(), "RIGHT"));
	this->_buttons.emplace_back(new Button({510, 440}, {20, 240, 110, 240 + 32}, P4_DROP, this->_window.getGuiEnv(), "DROP"));
	this->_buttons.emplace_back(new Button({510, 500}, {20, 240, 110, 240 + 32}, P4_ULT, this->_window.getGuiEnv(), "ULT"));
}

bool Irrlicht::KeyManagingMenu::update()
{
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
	for (unsigned i = 0; i < this->_buttons.size(); i++)
	{
		if (this->isGuiButtonPressed(i))
		{
			switch (i)
			{
			case BACKBACK:
				changeCurrentGameScene("OptionsMenu");
				break;
			default:
				break;
			}
		}
	}
	return (true);
}

void Irrlicht::KeyManagingMenu::changeCurrentGameScene(std::string sceneName)
{
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(false);
	this->_window.setCurrentGameScene(sceneName);
}