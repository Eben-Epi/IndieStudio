/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** HowToPlayMenu.cpp
*/

#include "HowToPlayMenu.hpp"

Irrlicht::HowToPlayMenu::HowToPlayMenu(Screen &screen, const std::string &name, unsigned id) :
    GameScene(screen, name, id)
{
	this->_buttons.emplace_back(new Button({280, 550}, {20, 240, 110, 240 + 32},HTP_GAME_BACK, this->_window.getGuiEnv(), "BACK"));

    this->_textBoxes.emplace_back(new TextBox({280, 25}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "HOW TO PLAY", true, true, true));

    std::string text = "\n\n \
                        You can choose the number of players and the number of AI.\n\n \
                        The number max of players is 4 and the minimum is 2.\n\n \
                        For example, you can play with 2 players and 2 AI, but can't play with 3 players and 2 AI.\n\n\n \
                        Commands for each player are defined when you create a new game.\n\n\n \
                        There are ultimates that you need to charge to use them.\n\n \
                        Sydney : Became invincible and get a boost of movement speed.\n\n \
                        AlphaOne : Throw a chock wave in column or in rows. It destructs everything on its way.\n\n \
                        Lonie : Stun all enemies for a few seconds, then slow them a lot.\n\n \
                        Gunguy : Thorw bombs on feets of his enemies.\n\n\n \
                        There are bonuses and penalties that can be dropped when you destruct a brick wall.\n\n \
                        - Bonuses :\n \
                            \tDark green : more bombs.\n \
                            \tBlue : give kick bombs ability.\n \
                            \tLight blue : Wall Pass.\n \
                            \tRed : increase range of bombs.\n \
                            \tYellow : increase speed.\n\n \
                        - Penalties :\n \
                            \tSkull : random among :\n \
                                \t\tUltra Speed,\n \
                                \t\tUltra slow,\n \
                                \t\tReverse Control,\n \
                                \t\tNo drop,\n \
                                \t\tAuto drop\n";

    this->_textBoxes.emplace_back(new TextBox({50, 100}, {0, 150, 550, 550}, 0, this->_window.getGuiEnv(), text, true, true, true, irr::gui::EGUIA_UPPERLEFT, irr::gui::EGUIA_UPPERLEFT));
}

bool Irrlicht::HowToPlayMenu::update()
{
	for (unsigned i = 0; i < this->_buttons.size(); i++) {
        if (this->isGuiButtonPressed(i)) {
            switch (i) {
                case HTP_GAME_BACK:
                    if (!this->_window.isValidGetterName("Main Menu"))
                        this->_window.addGameSceneMainMenu("Main Menu");
                    changeCurrentGameScene("Main Menu");
                    return (true);
                default:
                    break;
            }
            this->_window.resetButtonsStates();
        }
    }
    for (unsigned i = 0; i < this->_buttons.size(); i++)
        this->_buttons.at(i)->setVisible(true);
    for (unsigned i = 0; i < this->_textBoxes.size(); i++)
        this->_textBoxes.at(i)->setVisible(true);
    return (true);
}
