//
// Created by eben_epitech on 6/15/19.
//

#include "LoadGameMenu.hpp"

Irrlicht::LoadGameMenu::LoadGameMenu(Screen &screen, const std::string &name, unsigned id) :
        GameScene(screen, name, id)
{
    this->_buttons.emplace_back(new Button({280, 100}, {20, 120, 110, 120 + 32}, SLOT_ONE, this->_window.getGuiEnv(), "SLOT ONE"));
    this->_buttons.emplace_back(new Button({280, 150}, {20, 120, 110, 120 + 32}, SLOT_TWO, this->_window.getGuiEnv(), "SLOT TWO"));
    this->_buttons.emplace_back(new Button({280, 200}, {20, 120, 110, 120 + 32}, SLOT_THREE, this->_window.getGuiEnv(), "SLOT THREE"));
    this->_buttons.emplace_back(new Button({280, 250}, {20, 120, 110, 120 + 32}, SLOT_FOUR, this->_window.getGuiEnv(), "SLOT FOUR"));
    this->_buttons.emplace_back(new Button({280, 300}, {20, 120, 110, 120 + 32}, SLOT_FIVE, this->_window.getGuiEnv(), "SLOT FIVE"));
    this->_buttons.emplace_back(new Button({280, 350}, {20, 120, 110, 120 + 32}, BACK_FROM_LOAD_GAME, this->_window.getGuiEnv(), "BACK"));
}

bool Irrlicht::LoadGameMenu::update()
{
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
    /*for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
            switch (i) {
                case NEW_GAME:
                    if (!this->_window.isValidGetterName("New Game Menu"))
                        this->_window.addGameSceneLoadGameMenu("New Game Menu");
                    changeCurrentGameScene("New Game Menu");
                    break;
                case LOAD_GAME:
                    if (!this->_window.isValidGetterName("Load Game Menu"))
                        this->_window.addGameSceneLoadGameMenu("Load Game Menu");
                    changeCurrentGameScene("Load Game Menu");
                    break;
                case EXIT:
                    this->_window.getDevice()->drop();
                    return (false);
                default:
                    break;
            }
        }
    }*/
    return (true);
}