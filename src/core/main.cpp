#include <iostream>
#include "irrlicht/Keycodes.h"
#include "../irrlicht/Irrlicht.hpp"
#include "../map/Map.hpp"
#include "../input/Keyboard.hpp"

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
			irr::KEY_SPACE,
			irr::KEY_KEY_A,
		})
	);
	ECS::Ressources	res{screen, inputs};
	Map::Map	map{res};

	map.generateMap({20, 20}, 70);
	while (!screen.isEnd()) {
		map.update();
		screen.display();
	}
	return EXIT_SUCCESS;
}