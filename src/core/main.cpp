#include <iostream>
#include "../irrlicht/Irrlicht.hpp"
#include "../map/Map.hpp"

int main()
{
	Irrlicht::Irrlicht	screen;
	ECS::Ressources		res;
	Map::Map		map{res};

	map.generateMap(10, 70);
	while (!screen.isEnd()) {
		map.update();
		screen.display();
	}
	return EXIT_FAILURE;
}