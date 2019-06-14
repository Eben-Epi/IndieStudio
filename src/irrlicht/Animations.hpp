/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Animations.hpp
*/

#ifndef BOMBERMAN_ANIMATIONS_HPP
#define BOMBERMAN_ANIMATIONS_HPP

#include "irrlicht/irrlicht.h"

namespace Irrlicht {
	enum Animations {
		IDLE = irr::scene::EMAT_STAND,
		DANCE = irr::scene::EMAT_SALUTE,
		DYING = irr::scene::EMAT_DEATH_FALLFORWARD,
		DEAD = irr::scene::EMAT_BOOM,
		RUN = irr::scene::EMAT_RUN,
		ULT_CAST = irr::scene::EMAT_ATTACK,
	};
}

#endif //BOMBERMAN_ANIMATIONS_HPP
