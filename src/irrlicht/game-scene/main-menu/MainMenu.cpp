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
	this->_buttons.emplace_back(new Button({280, 300}, {20, 240, 110, 240 + 32}, LOAD, this->_window.getGuiEnv(), "LOAD"));
	this->_buttons.emplace_back(new Button({280, 500}, {20, 240, 110, 240 + 32}, EXIT, this->_window.getGuiEnv(), "EXIT"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "BOMBERMAN", true, true, true));
    this->_textBoxes[0]->setBackgroundColor(irr::video::SColor(255, 255, 0, 0));
    this->_textBoxes[0]->setColorOfText(irr::video::SColor(255, 0, 0, 0));
}

bool Irrlicht::MainMenu::update()
{
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
	for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
            for (unsigned i = 0; i < this->_buttons.size(); i++)
                this->_buttons.at(i)->setVisible(false);
            for (unsigned i = 0; i < this->_textBoxes.size(); i++)
                this->_textBoxes.at(i)->setVisible(false);
            switch (i) {
                case START:
                    if (!this->_window.isValidGetterName("Start"))
                        this->_window.addGameSceneGame("Start");
                    changeCurrentGameScene("Start");
                    break;
                case LOAD:
                    if (!this->_window.isValidGetterName("LoadGame"))
                        this->_window.addGameSceneLoadGame("LoadGame");
                    changeCurrentGameScene("LoadGame");
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