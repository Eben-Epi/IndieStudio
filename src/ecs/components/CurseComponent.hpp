/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** CurseComponent.hpp
*/
#ifndef BOMBERMAN_CURSECOMPONENT_HPP
#define BOMBERMAN_CURSECOMPONENT_HPP

#include "../Ressources.hpp"
#include "../Component.hpp"

#define IS_CURSED(entity, curse) (entity.hasComponent("Curse") && reinterpret_cast<CurseComponent &>(entity.getComponentByName("Curse")).effect == curse)

namespace ECS {
    class CurseComponent : public Component {
    public:
        enum CurseEffect {
            NONE = 0,
            ULTRASPEED,
            ULTRASLOW,
            REVERSECONTROL,
            AUTODROP,
            NODROP,
            _NUMBER_OF_CURSE
        };

        Sound::SoundSystem &soundSystem;
        CurseEffect effect;
        int timeLeft;
        CurseComponent(Sound::SoundSystem &soundSystem);
        CurseComponent(unsigned id, Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;

        bool giveCurse(CurseEffect effect, int time, bool force=false, bool playSound=true);
    };
}


#endif //BOMBERMAN_CURSECOMPONENT_HPP
