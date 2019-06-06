#include <iostream>
#include <fstream>
#include "irrlicht/Keycodes.h"
#include "../irrlicht/Irrlicht.hpp"
#include "../map/Map.hpp"
#include "../input/Keyboard.hpp"
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
	Irrlicht::Irrlicht			   screen;
	std::vector<std::unique_ptr<Input::Input>> inputs;
	inputs.emplace_back(
		new Input::Keyboard(screen, {
			irr::KEY_KEY_Z,
			irr::KEY_KEY_Q,
			irr::KEY_KEY_S,
			irr::KEY_KEY_D,
			irr::KEY_KEY_M,
			irr::KEY_KEY_A,
		})
	);
	ECS::Ressources	res{screen, inputs};
	Map::Map	*map = loadMap(res, "save.txt");

	while (!screen.isEnd()) {
		map->update();
		screen.display();
	}
	std::ofstream	stream("save.txt");
	stream << *map << std::endl;
	delete map;
	return EXIT_SUCCESS;
}