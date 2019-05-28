#include <iostream>
#include "../irrlicht/Irrlicht.hpp"

int main()
{
	Irrlicht::Irrlicht screen;

	while (!screen.isEnd())
		screen.display();
	return EXIT_FAILURE;
}