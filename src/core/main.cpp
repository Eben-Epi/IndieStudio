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

void generateDefaultMap(Map::Map &map, const std::vector<Map::Map::PlayerConfig> &&players)
{
	map.generateMap(
		{20, 20},
		7000,
		std::move(players),
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

bool displayEndGameMenu(Map::Map &map, Irrlicht::Screen &screen, Sound::SoundSystem &sound)
{
	if (map.getPlayersAlive().empty()) {
		sound.playSound("announcer_draw");
	} else {
		sound.playSound("announcer_winner");
		std::this_thread::sleep_for(std::chrono::seconds(2));
		sound.playSound("announcer_" + reinterpret_cast<ECS::NameComponent &>(map.getPlayersAlive()[0]->getComponentByName("Name")).name);
	}
	screen.setCursorVisible(true);
	screen.setCurrentGameScene("MainMenu");
	while (screen.display() && screen.getCurrentGameScene().sceneName != "Game");
	if (screen.isGameClosed)
		exit(EXIT_SUCCESS);
	return true;
}

int main()
{
	try {
		Irrlicht::Screen screen(640, 640, 32, false, true);
		screen.addGameSceneMainMenu("MainMenu");
		std::vector<std::unique_ptr<Input::Input>> inputs;
		if (!screen.setCurrentGameScene("MainMenu"))
			return EXIT_FAILURE;

		irr::core::array<irr::SJoystickInfo> joystickInfos;

		while (screen.display() && screen.getCurrentGameScene().sceneName != "Game");

		inputs.emplace_back(
			new Input::Keyboard(screen.getGameSceneByName("Game"), {
				irr::KEY_KEY_Z,
				irr::KEY_KEY_D,
				irr::KEY_KEY_S,
				irr::KEY_KEY_Q,
				irr::KEY_SPACE,
				irr::KEY_KEY_A,
			})
		);
		inputs.emplace_back(
			new Input::Keyboard(screen.getGameSceneByName("Game"), {
				irr::KEY_UP,
				irr::KEY_RIGHT,
				irr::KEY_DOWN,
				irr::KEY_LEFT,
				irr::KEY_RSHIFT,
				irr::KEY_RETURN,
			})
		);

		if (screen.isGameClosed)
			return (EXIT_SUCCESS);
		if (!screen.isValidGetterName("Game"))
			return (EXIT_FAILURE);

		if (screen.getDevice()->activateJoysticks(joystickInfos)) {
			std::cout << "Joystick support is enabled and " << joystickInfos.size() << " joystick(s) are present." << std::endl;

			screen.setCursorVisible(false);
			screen.getGameSceneByName("Game").addCamera(320, 500, -320, 320, 0, -319);

			if (!joystickInfos.empty()) {
				for (irr::u32 joystick = 0; joystick < joystickInfos.size(); joystick++) {
					std::cout << "Joystick " << joystick << ":" << std::endl;
					std::cout << "\tName: '" << joystickInfos[joystick].Name.c_str() << "'" << std::endl;
					inputs.emplace_back(
						new Input::Controller(screen.getGameSceneByName("Game"), {
							Input::LEFT_JOYSTICK,
							Input::LT,
							Input::A,
						}, joystickInfos[joystick].Joystick)
					);
				}
			}
		}

		Sound::SoundSystem soundSystem;
		Map::Map *map = loadMap("save.txt", screen.getGameSceneByName("Game"), inputs, soundSystem);

		for (auto &sound_name : sound_to_load)
			soundSystem.loadSound(sound_name);

		bool justPaused = false;
		bool paused = false;

		while (screen.display()) {
			if (screen.getGameSceneByName("Game").isKeyPressed(irr::KEY_ESCAPE) && !justPaused) {
				justPaused = true;
				paused = !paused;
				if (paused)
					soundSystem.pauseBackgroundMusic();
				soundSystem.playSound("pause", 100);
				if (!paused)
					soundSystem.resumeBackgroundMusic();
			} else if (!screen.getCurrentGameScene().isKeyPressed(irr::KEY_ESCAPE))
				justPaused = false;
			if (!paused && !map->update() && displayEndGameMenu(*map, screen, soundSystem)) {
				delete map;
				map = new Map::Map(screen.getGameSceneByName("Game"), inputs, soundSystem);
				generateDefaultMap(*map, {
					{&*inputs[0], "Faerie", 0},
					{nullptr, "Xenotype", 1},
					{nullptr, "Alphaone", 2},
					{nullptr, "Sydney", 3},
				});
			}
		}

		map->save("save.txt");
		delete map;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}