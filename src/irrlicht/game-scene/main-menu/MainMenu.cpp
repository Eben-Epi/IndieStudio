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
	this->_buttons.emplace_back(new Button({280, 100}, {20, 240, 110, 240 + 32}, START, this->_window.getGuiEnv(), "START"));
	this->_buttons.emplace_back(new Button({280, 300}, {20, 240, 110, 240 + 32}, OPTIONS, this->_window.getGuiEnv(), "OPTIONS"));
	this->_buttons.emplace_back(new Button({280, 500}, {20, 240, 110, 240 + 32}, EXIT, this->_window.getGuiEnv(), "EXIT"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "BOMBERMAN", true, true, true));
    for (unsigned i = 0; i < this->_textBoxes.size(); i++)
        this->_textBoxes[i]->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
}

bool Irrlicht::MainMenu::update()
{
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
	for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
            for (unsigned i = 0; i < this->_buttons.size(); i++)
                this->_buttons.at(i)->setVisible(false);
            switch (i) {
                case START:
                    if (!this->_window.isValidGetterName("Game"))
                        this->_window.addGameSceneGame("Game");
                    changeCurrentGameScene("Game");
                    break;
                case OPTIONS:
                    if (!this->_window.isValidGetterName("Options"))
                        this->_window.addGameSceneOptions("Options");
                    changeCurrentGameScene("Options");
                    break;
                case EXIT:
                    this->_window.getDevice()->drop();
                    return (false);
                    break;
                default:
                    break;
            }
        }
    }
	return (true);
}

void Irrlicht::MainMenu::changeCurrentGameScene(std::string sceneName)
{
	this->_window.setCurrentGameScene(sceneName);
}