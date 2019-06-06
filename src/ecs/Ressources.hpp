/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Ressources.hpp
*/

#ifndef BOMBERMAN_RESSOURCES_HPP
#define BOMBERMAN_RESSOURCES_HPP


#include "../input/Input.hpp"
#include "../irrlicht/Irrlicht.hpp"
#include "../sound/SoundSystem.hpp"

namespace ECS
{
	struct Ressources {
		Sound::SoundSystem                         &soundSystem;
		Irrlicht::Irrlicht                         &screen;
		std::vector<std::unique_ptr<Input::Input>> &inputs;
	};
}


#endif //BOMBERMAN_RESSOURCES_HPP
