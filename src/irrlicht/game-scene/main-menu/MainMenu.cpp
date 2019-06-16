/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"
#include "../../../config.hpp"

Irrlicht::MainMenu::MainMenu(Screen &screen, const std::string &name, unsigned id) :
	GameScene(screen, name, id)
{
    this->_window.soundSystem.setBackgroundMusic("title_screen_loop");
    this->_window.soundSystem.playSoundOverBackgroundMusic("title_screen_intro");
    this->_buttons.emplace_back(new Button({280, 150}, {20, 240, 110, 240 + 32}, NEW_GAME, this->_window.getGuiEnv(), "NEW GAME"));
    this->_buttons.emplace_back(new Button({280, 350}, {20, 240, 110, 240 + 32}, LOAD_GAME, this->_window.getGuiEnv(), "LOAD GAME"));
    this->_buttons.emplace_back(new Button({280, 550}, {20, 240, 110, 240 + 32}, EXIT, this->_window.getGuiEnv(), "EXIT"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "BOMBERMAN", true, true, true));
    this->_textBoxes[0]->setBackgroundColor(irr::video::SColor(255, 255, 0, 0));
    this->_textBoxes[0]->setColorOfText(irr::video::SColor(255, 0, 0, 0));
}

bool Irrlicht::MainMenu::update()
{
    if (this->_clock >= FRAME_RATE * 40) {
        if (!this->_window.isValidGetterName("Demo"))
            this->_window.addGameSceneDemoMenu("Demo");
        changeCurrentGameScene("Demo");
        return (false);
    }
    this->_clock++;
    for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
	    this->_clock = 0;
            switch (i) {
                case NEW_GAME:
                    if (!this->_window.isValidGetterName("New Game Menu"))
                        this->_window.addGameSceneNewGameMenu("New Game Menu");
                    changeCurrentGameScene("New Game Menu");
                    return (true);
                case LOAD_GAME:
                    if (!this->_window.isValidGetterName("Load Game"))
                        this->_window.addGameSceneLoadGameMenu("Load Game");
                    changeCurrentGameScene("Load Game");
                    return (true);
                case EXIT:
                    this->_window.getDevice()->drop();
                    return (true);
                default:
                    break;
            }
        }
    }
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
    for (unsigned i = 0; i < this->_textBoxes.size(); i++)
        this->_textBoxes.at(i)->setVisible(true);
    return (true);
}
