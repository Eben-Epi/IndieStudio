#include <iostream>
#include <fstream>
#include "irrlicht/Keycodes.h"
#include "../irrlicht/screen/Screen.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"
#include "../map/Map.hpp"
#include "../input/Keyboard.hpp"
#include "../input/Controller.hpp"
#include "../ecs/Exceptions.hpp"

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

	map->generateMap({20, 20}, 7000, {"Alphaone", "Xenotype"}, {
		{"Bonus", 40},
		{"DroppedBonusSpeed", 20},
		{"DroppedBonusBomb", 20},
		{"DroppedBonusKick", 5},
		{"DroppedBonusRange", 20},
		{"Skull", 10}
	});
	return map;
}

int main()
{
	try {
		Irrlicht::Screen screen(640, 640, 32, false, true);
		screen.addGameScene("Game");
		std::vector<std::unique_ptr<Input::Input>> inputs;
		if (!screen.setCurrentGameScene("Game"))
			return EXIT_FAILURE;

		irr::core::array<irr::SJoystickInfo> joystickInfos;
		if (screen.getDevice()->activateJoysticks(joystickInfos)) {
			std::cout << "Joystick support is enabled and " << joystickInfos.size() << " joystick(s) are present." << std::endl;

			inputs.emplace_back(
				new Input::Keyboard(screen.getCurrentGameScene(), {
					irr::KEY_KEY_Z,
					irr::KEY_KEY_D,
					irr::KEY_KEY_S,
					irr::KEY_KEY_Q,
					irr::KEY_SPACE,
					irr::KEY_KEY_A,
				})
			);
			inputs.emplace_back(
				new Input::Keyboard(screen.getCurrentGameScene(), {
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
						new Input::Controller(screen.getCurrentGameScene(), {
							Input::LEFT_JOYSTICK,
							Input::LT,
							Input::A,
						}, joystickInfos[joystick].Joystick)
					);
				}
			}
		}

		Sound::SoundSystem soundSystem;
		Map::Map *map = loadMap("save.txt", screen.getCurrentGameScene(), inputs, soundSystem);

		for (auto &sound_name : sound_to_load)
			soundSystem.loadSound(sound_name);

		bool justPaused = false;
		bool paused = false;

		while (screen.display()) {
			if (screen.getCurrentGameScene().isKeyPressed(irr::KEY_ESCAPE) && !justPaused) {
				justPaused = true;
				paused = !paused;
				if (paused)
					soundSystem.pauseBackgroundMusic();
				soundSystem.playSound("pause", 100);
				if (!paused)
					soundSystem.resumeBackgroundMusic();
			} else if (!screen.getCurrentGameScene().isKeyPressed(irr::KEY_ESCAPE))
				justPaused = false;
			if (!paused && !map->update()) {
				delete map;
				map = new Map::Map(screen.getCurrentGameScene(), inputs, soundSystem);
				map->generateMap({20, 20}, 7000, {"Alphaone", "Xenotype"}, {
					{"Bonus", 40},
					{"DroppedBonusSpeed", 20},
					{"DroppedBonusBomb", 20},
					{"DroppedBonusKick", 5},
					{"DroppedBonusRange", 20},
					{"Skull", 10}
				});
			}
		}

		std::ofstream stream("save.txt");

		stream << *map << std::endl;
		delete map;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}