#include <iostream>
#include <fstream>
#include <random>
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

void mainMenu(Irrlicht::Screen &screen, Sound::SoundSystem &soundSystem)
{
//	std::random_device _rand;
//	std::vector<std::unique_ptr<Input::Input>> inputs;
//	auto *map = new Map::Map{screen.getCurrentGameScene(), inputs, soundSystem};
//	std::vector<Map::Map::PlayerConfig> players;

//	for (unsigned i = 0; i < 4; i++)
//		players.push_back(Map::Map::PlayerConfig{nullptr, playerEntities[_rand() % playerEntities.size()], i});
//	generateDefaultMap(*map, players);
	while (screen.display() && screen.getCurrentGameScene().sceneName != "Game");
		//TODO: Clément fix ta merde
//		screen.getGameSceneByName("MainMenu").addCamera(320, 500, -320, 320, 0, -319);
//		if (!map->update()) {
//			if (map->getPlayersAlive().empty()) {
//				soundSystem.playSound("announcer_draw");
//			} else {
//				soundSystem.playSound("announcer_winner");
//				for (int i = 0; i < 120; i++)
//					screen.display();
//				soundSystem.playSound("announcer_" + reinterpret_cast<ECS::NameComponent &>(map->getPlayersAlive()[0]->getComponentByName("Name")).name);
//			}
//			for (int i = 0; i < 120; i++)
//				screen.display();
//			delete map;
//			map = new Map::Map{screen.getCurrentGameScene(), inputs, soundSystem};
//			players.clear();
//			for (unsigned i = 0; i < 4; i++)
//				players.push_back(Map::Map::PlayerConfig{nullptr, playerEntities[_rand() % playerEntities.size()], i});
//			generateDefaultMap(*map, players);
//		}
//	}
//	delete map;
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
	screen.setCurrentGameScene("Main Menu");

	mainMenu(screen, sound);
	if (screen.isGameClosed)
		exit(EXIT_SUCCESS);
	return true;
}

int main()
{
	try {
		Sound::SoundSystem soundSystem;
		Irrlicht::Screen screen(640, 640, 32, false, true);
        screen.addGameSceneMainMenu("Main Menu");
		std::vector<std::unique_ptr<Input::Input>> inputs;
		if (!screen.setCurrentGameScene("Main Menu"))
			return EXIT_FAILURE;

		for (auto &sound_name : sound_to_load)
			soundSystem.loadSound(sound_name);

		irr::core::array<irr::SJoystickInfo> joystickInfos;

		screen.getGameSceneByName("Main Menu").addCamera(320, 500, -320, 320, 0, -319);
		mainMenu(screen, soundSystem);

		if (screen.isGameClosed || !screen.getDevice()->isWindowActive())
			return (EXIT_SUCCESS);
		if (!screen.isValidGetterName("Game"))
			return (EXIT_FAILURE);

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


		if (screen.getDevice()->activateJoysticks(joystickInfos)) {
			std::cout << "Joystick support is enabled and " << joystickInfos.size() << " joystick(s) are present." << std::endl;

            screen.setCursorVisible(false);

            while (screen.display() && screen.getCurrentGameScene().sceneName != "Game");

            if (screen.isGameClosed)
                return (EXIT_SUCCESS);
            if (!screen.isValidGetterName("Game"))
                exit(EXIT_FAILURE); //TODO EXCEPTION
            else
                screen.cleanGameScenes();
            screen.setCursorVisible(false);
            screen.getGameSceneByName("Game").addCamera(320, 500, -320, 320, 0, -319);

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

		Map::Map *map = loadMap("save.txt", screen.getGameSceneByName("Game"), inputs, soundSystem);

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
			//TODO: Clément fix ta merde
			screen.getGameSceneByName("Game").addCamera(320, 500, -320, 320, 0, -319);
			if (!paused && !map->update() && displayEndGameMenu(map, screen, soundSystem)) {
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
