/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include <fstream>
#include "../../../config.hpp"
#include "../../../ecs/components/NameComponent.hpp"

Irrlicht::Game::Game(Screen &screen, const std::string &name, unsigned id, std::vector<std::unique_ptr<Input::Input>> &inputs, std::ifstream &file) :
	GameScene(screen, name, id),
	_map(new Map::Map{*this, inputs, screen.soundSystem, file})
{
}

Irrlicht::Game::Game(Screen &screen, const std::string &name, unsigned id, std::vector<Map::Map::PlayerConfig> configs) :
        GameScene(screen, name, id),
        _map(new Map::Map{*this, this->_ais, screen.soundSystem})
{
    this->_map->generateMap({20, 20}, 7000, configs,
                            {
                                    {"Bonus", 40},
                                    {"DroppedBonusSpeed", 20},
                                    {"DroppedBonusBomb", 20},
                                    {"DroppedBonusKick", 5},
                                    {"DroppedBonusRange", 20},
                                    {"DroppedBonusGhost", 1},
                                    {"Skull", 10}
                            });
}

bool Irrlicht::Game::update()
{
    if (this->_window.getCurrentGameScene().isKeyPressed(irr::KEY_ESCAPE)) {
    	if (!this->_hasPaused) {
		this->_hasPaused = true;
		if (!this->_paused) {
			this->_map->save("save.txt");
			this->_window.soundSystem.playSound("pause");
			this->_window.soundSystem.pauseBackgroundMusic();
		} else
			this->_window.soundSystem.resumeBackgroundMusic();
		this->_paused = !this->_paused;
	}
    } else
        this->_hasPaused = false;
    if (this->_paused)
    	return true;
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
