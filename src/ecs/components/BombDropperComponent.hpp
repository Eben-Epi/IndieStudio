/*
** EPITECH PROJECT, 2019
** ECS
** File description:
** BombDropperComponent.hpp
*/

#ifndef BOMBDROPpERCOMPONENT_HPP
#define BOMBDROPpERCOMPONENT_HPP

#include <vector>
#include "../Component.hpp"
#include "../Entity.hpp"
#include "../Ressources.hpp"

namespace ECS
{
	class BombDropperComponent : public Component {
	public:
		Sound::SoundSystem &soundSystem;
		std::vector<unsigned> bombs;
		unsigned int max;
		float timeToExplode;
		unsigned int range;
		bool dropBomb;

		explicit BombDropperComponent(Sound::SoundSystem &system, unsigned max = 1, float timeToExplode = 5, unsigned range = 1);
		BombDropperComponent(unsigned id, Ressources &ressources, std::istream &stream);
		std::ostream &serialize(std::ostream &stream) const override;
	};
} // namespace ECS

#endif