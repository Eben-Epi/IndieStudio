/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** KeyManagingMenu.cpp
*/

#include "DemoMenu.hpp"
#include "../../../config.hpp"
#include "../../../ecs/components/NameComponent.hpp"

Irrlicht::DemoMenu::DemoMenu(Screen &screen, const std::string &name, unsigned id) :
	GameScene(screen, name, id),
	_map(new Map::Map{*this, this->_ais, screen.soundSystem})
{
	this->_map->generateMap({20, 20}, 7000, {
		{nullptr, playerEntities[rand() % playerEntities.size()], 0},
		{nullptr, playerEntities[rand() % playerEntities.size()], 1},
		{nullptr, playerEntities[rand() % playerEntities.size()], 2},
		{nullptr, playerEntities[rand() % playerEntities.size()], 3},
	},
	{
		{"Bonus", 40},
		{"DroppedBonusSpeed", 20},
		{"DroppedBonusBomb", 20},
		{"DroppedBonusKick", 5},
		{"DroppedBonusRange", 20},
		{"DroppedBonusGhost", 1},
		{"Skull", 10}
	});
	this->_buttons.emplace_back(new Button({10, 600}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "BACK"));
	this->_textBoxes.emplace_back(new TextBox({0, 0}, {20, 240, 110, 240 + 32}, 0, this->_window.getGuiEnv(), "DEMO", true, true, true));
}

bool Irrlicht::DemoMenu::update()
{
	this->_textBoxes[0]->setVisible(this->_clock < FRAME_RATE / 2);
	if (this->_clock++ >= FRAME_RATE)
		this->_clock = 0;
	if (this->_buttons[0]->isPressed()) {
		if (!this->_window.isValidGetterName("Main Menu"))
			this->_window.addGameSceneMainMenu("Main Menu");
		this->changeCurrentGameScene("Main Menu");
		return (false);
	}
	if (this->_gameClock)
		this->_gameClock++;
	if (this->_gameClock == 0 && !this->_map->update()) {
		if (this->_map->getPlayersAlive().empty())
			this->_window.soundSystem.playSound("announcer_draw");
		else
			this->_window.soundSystem.playSound("announcer_winner");
		this->_gameClock++;
	}
	if (this->_gameClock == FRAME_RATE * 2) {
		if (this->_map->getPlayersAlive().empty())
			this->_gameClock = FRAME_RATE * 4;
		else
			this->_window.soundSystem.playSound("announcer_" + reinterpret_cast<ECS::NameComponent &>(this->_map->getPlayersAlive()[0]->getComponentByName("Name")).name);
	}
	if (this->_gameClock >= FRAME_RATE * 4) {
		if (!this->_window.isValidGetterName("Main Menu"))
			this->_window.addGameSceneMainMenu("Main Menu");
		this->changeCurrentGameScene("Main Menu");
		return (false);
	}
	return (true);
}
