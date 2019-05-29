#include <iostream>
#include "../irrlicht/Irrlicht.hpp"
#include "../map/Map.hpp"

int main()
{
	Irrlicht::Irrlicht	screen;
	ECS::Ressources		res{screen};
	Map::Map		map{res};

	map.generateMap({20, 20}, 70);
	while (!screen.isEnd()) {
		map.update();
		screen.display();
	}
	return EXIT_SUCCESS;
}