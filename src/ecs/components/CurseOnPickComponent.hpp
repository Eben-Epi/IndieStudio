/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseOnPickComponent.hpp
*/

#ifndef BOMBERMAN_CURSEONPICKCOMPONENT_HPP
#define BOMBERMAN_CURSEONPICKCOMPONENT_HPP

#include "../Component.hpp"
#include "../Ressources.hpp"

namespace ECS
{
    class CurseOnPickComponent : public Component {
    public:
        Sound::SoundSystem &soundSystem;

        CurseOnPickComponent(Sound::SoundSystem &soundSystem);
        CurseOnPickComponent(unsigned id, Ressources &ressources, std::istream &stream);
        std::ostream& serialize(std::ostream &stream) const;
    };
}


#endif //BOMBERMAN_CURSEONPICKCOMPONENT_HPP
