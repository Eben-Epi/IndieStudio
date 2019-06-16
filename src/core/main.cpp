#include <iostream>
#include <fstream>
#include "irrlicht/Keycodes.h"
#include "../irrlicht/screen/Screen.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"
#include "../map/Map.hpp"
#include "../input/Keyboard.hpp"
#include "../input/Controller.hpp"
#include "../ecs/Exceptions.hpp"
#include "../ecs/components/NameComponent.hpp"

void generateDefaultMap(Map::Map &map, const std::vector<Map::Map::PlayerConfig> &players)
{
	map.generateMap(
		{20, 20},
		7000,
		players,
		{
			{"Bonus", 40},
			{"DroppedBonusSpeed", 20},
			{"DroppedBonusBomb", 20},
			{"DroppedBonusKick", 5},
			{"DroppedBonusRange", 20},
			{"DroppedBonusGhost", 1},
			{"Skull", 10}
		}
	);
}

Map::Map *loadMap(std::string path, Irrlicht::GameScene &gameScene, std::vector<std::unique_ptr<Input::Input>> &inputs, Sound::SoundSystem &soundSystem)
{
	std::ifstream stream(path);

	try {
		if (stream.is_open())
			return new Map::Map{gameScene, inputs, soundSystem, stream};
	} catch (std::exception &e) {
		std::cerr << "The saved map is invalid " << e.what() << std::endl;
	}

	auto map = new Map::Map{gameScene, inputs, soundSystem};

	generateDefaultMap(*map, {
		{nullptr, "Faerie", 0},
		{nullptr, "Xenotype", 1},
		{nullptr, "Alphaone", 2},
		{nullptr, "Sydney", 3},
	});
	return map;
}

bool displayEndGameMenu(Map::Map *map, Irrlicht::Screen &screen, Sound::SoundSystem &sound)
{
	if (map->getPlayersAlive().empty()) {
		sound.playSound("announcer_draw");
	} else {
		sound.playSound("announcer_winner");
		for (int i = 0; i < 120; i++)
			screen.display();
		sound.playSound("announcer_" + reinterpret_cast<ECS::NameComponent &>(map->getPlayersAlive()[0]->getComponentByName("Name")).name);
	}
	std::this_thread::sleep_for(std::chrono::seconds(2));
	delete map;
	screen.setCursorVisible(true);
	if (!screen.isValidGetterName("Main Menu"))
		screen.addGameSceneMainMenu("Main Menu");
	screen.setCurrentGameScene("Main Menu");

	if (screen.isGameClosed)
		exit(EXIT_SUCCESS);
	return true;
}

int main()
{
	srand(time(NULL));
	try {
		Irrlicht::Screen screen(640, 640, 32, false, true);
		screen.addGameSceneMainMenu("Main Menu");

		if (!screen.setCurrentGameScene("Main Menu"))
			return EXIT_FAILURE;
		screen.getGameSceneByName("Main Menu").addCamera(320, 500, -320, 320, 0, -319);
		while (screen.display());
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
