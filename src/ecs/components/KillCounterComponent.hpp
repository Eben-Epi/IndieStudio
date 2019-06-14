/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KillCounterComponent.hpp
*/
#ifndef BOMBERMAN_KILLCOUNTERCOMPONENT_HPP
#define BOMBERMAN_KILLCOUNTERCOMPONENT_HPP


#include "../Ressources.hpp"

static const std::map<std::string, int> kill_value = {
        {"Player", 2000},
        {"Brick", 75}
    };

namespace ECS {
    struct Kill {
        unsigned id;
        std::string name;
    };

    class KillCounterComponent : public Component {
    public:
        std::vector<Kill> killQueue;
        std::vector<unsigned> killedId = {};
        unsigned multikillCount;
        unsigned multikillTimer;
        Sound::SoundSystem &soundSystem;

        KillCounterComponent(Sound::SoundSystem &soundSystem);
        KillCounterComponent(Ressources &ressources, std::istream &stream);
        std::ostream &serialize(std::ostream &stream) const override;
    };
}


#endif //BOMBERMAN_KILLCOUNTERCOMPONENT_HPP
