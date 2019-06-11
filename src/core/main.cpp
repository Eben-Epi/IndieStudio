#include <iostream>
#include <fstream>
#include "irrlicht/Keycodes.h"
#include "../irrlicht/screen/Screen.hpp"
#include "../irrlicht/game-scene/GameScene.hpp"
#include "../map/Map.hpp"
#include "../input/Keyboard.hpp"
#include "../input/Controller.hpp"
#include "../ecs/Exceptions.hpp"

Map::Map *loadMap(ECS::Ressources &res, std::string path)
{
	std::ifstream stream(path);

	try {
		if (stream.is_open())
			return new Map::Map{res, stream};
	} catch (std::exception &e) {
		std::cerr << "The saved map is invalid " << e.what() << std::endl;
	}

	auto map = new Map::Map{res};

	map->generateMap({20, 20}, 70);
	return map;
}

int main()
{
	try {
		Irrlicht::Screen screen(640, 640, 32, false, false);
		screen.addGameScene("Game");
		std::vector<std::unique_ptr<Input::Input>> inputs;
		if (!screen.setCurrentGameScene("Game"))
			return EXIT_FAILURE;
		inputs.emplace_back(
			new Input::Controller(screen.getCurrentGameScene(), {
/*				irr::KEY_KEY_Z,
				irr::KEY_KEY_Q,
				irr::KEY_KEY_S,
				irr::KEY_KEY_D,
				irr::KEY_SPACE,
				irr::KEY_KEY_A,
*/				1,
				2,
				3,
				4,
				5,
				6,
				7,
				8,
				9,
				10,
				11,
				12,
				13,
				14,
				15,
				16,
				17,
				18,
				19,
				20,
				21,
				22,
				23,
				24,
				25,
				26,
				27,
				28,
				29,
				30,
				31,
				32
			},
			0)
		);

		ECS::Ressources res{screen.getCurrentGameScene(), inputs};
		Map::Map *map = loadMap(res, "save.txt");

		for (auto &sound_name : sound_to_load)
			res.soundSystem.loadSound(sound_name);

		irr::core::array<irr::SJoystickInfo> joystickInfo;
		if (screen.getDevice()->activateJoysticks(joystickInfo))
		{
			std::cout << "Joystick support is enabled and " << joystickInfo.size() << " joystick(s) are present." << std::endl;

			for (irr::u32 joystick = 0; joystick < joystickInfo.size(); ++joystick)
			{
				std::cout << "Joystick " << joystick << ":" << std::endl;
				std::cout << "\tName: '" << joystickInfo[joystick].Name.c_str() << "'" << std::endl;
				std::cout << "\tAxes: " << joystickInfo[joystick].Axes << std::endl;
				std::cout << "\tButtons: " << joystickInfo[joystick].Buttons << std::endl;

				std::cout << "\tHat is: ";

				switch (joystickInfo[joystick].PovHat)
				{
				case irr::SJoystickInfo::POV_HAT_PRESENT:
					std::cout << "present" << std::endl;
					break;

				case irr::SJoystickInfo::POV_HAT_ABSENT:
					std::cout << "absent" << std::endl;
					break;

				case irr::SJoystickInfo::POV_HAT_UNKNOWN:
				default:
					std::cout << "unknown" << std::endl;
					break;
				}
			}
		}
		else
		{
			std::cout << "Joystick support is not enabled." << std::endl;
		}
		res.soundSystem.setBackgroundMusic("battle_music", 50); // tmp
		while (screen.display())
			map->update();

		std::ofstream stream("save.txt");

		stream << *map << std::endl;
		delete map;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}