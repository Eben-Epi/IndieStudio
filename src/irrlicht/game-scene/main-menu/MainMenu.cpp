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
	this->_buttons.emplace_back(new Button({280, 100}, {20, 240, 110, 240 + 32}, NEW_GAME, this->_window.getGuiEnv(), "NEW GAME"));
	this->_buttons.emplace_back(new Button({280, 300}, {20, 240, 110, 240 + 32}, LOAD_GAME, this->_window.getGuiEnv(), "LOAD GAME"));
	this->_buttons.emplace_back(new Button({280, 500}, {20, 240, 110, 240 + 32}, EXIT, this->_window.getGuiEnv(), "EXIT"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "BOMBERMAN", true, true, true));
    this->_textBoxes[0]->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
    this->_textBoxes[0]->setBackgroundColor(irr::video::SColor(255, 255, 0, 0));
    this->_textBoxes[0]->setColorOfText(irr::video::SColor(255, 0, 0, 0));
}

bool Irrlicht::MainMenu::update()
{
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
	for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
            switch (i) {
                case NEW_GAME:
                    if (!this->_window.isValidGetterName("New Game Menu"))
                        this->_window.addGameSceneNewGameMenu("New Game Menu");
                    changeCurrentGameScene("New Game Menu");
                    break;
                case LOAD_GAME:
                    if (!this->_window.isValidGetterName("Game"))
                        this->_window.addGameSceneGame("Game");
                    changeCurrentGameScene("Game");
                    break;
                case EXIT:
                    this->_window.getDevice()->drop();
                    return (false);
                default:
                    break;
            }
        }
    }
	return (true);
}