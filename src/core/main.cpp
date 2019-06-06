#include <iostream>
#include <fstream>
#include "irrlicht/Keycodes.h"
#include "../irrlicht/Screen/Screen.hpp"
#include "../map/Map.hpp"
#include "../irrlicht/GameEngine/Input/Keyboard.hpp"
#include "../ecs/Exceptions.hpp"

Map::Map *loadMap(const ECS::Ressources &res, std::string path)
{
	std::ifstream stream(path);

	try {
		if (stream.is_open())
			return new Map::Map{res, stream};
	} catch (ECS::InvalidSerializedStringException &e) {
		std::cerr << "The saved map is invalid " << e.what() << std::endl;
	}

	auto map = new Map::Map{res};

	map->generateMap({20, 20}, 70);
	return map;
}

int main()
{
//    AllocConsole();
//    freopen("CONOUT$", "w", stdout);
	Irrlicht::Screen screen(640, 480);
	Irrlicht::GameScene menu(screen);
	std::vector<std::unique_ptr<Input::Input>> inputs;
	inputs.emplace_back(
		new Irrlicht::Keyboard(menu, {
			irr::KEY_KEY_Z,
			irr::KEY_KEY_Q,
			irr::KEY_KEY_S,
			irr::KEY_KEY_D,
			irr::KEY_SPACE,
			irr::KEY_KEY_A,
		})
	);
	ECS::Ressources	res{menu, inputs};
	std::cout << "oui" << std::endl;
	Map::Map	*map = loadMap(res, "save.txt");
	std::cout << "non" << std::endl;

	while (!menu._window._device->run()) {
		map->update();
		menu.update();
	}
	std::ofstream	stream("save.txt");
	stream << *map << std::endl;
	delete map;
	return EXIT_SUCCESS;
}