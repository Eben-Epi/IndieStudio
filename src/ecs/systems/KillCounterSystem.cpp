/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KillCounterSystem.cpp
*/

#include <algorithm>
#include "KillCounterSystem.hpp"
#include "../components/KillCounterComponent.hpp"
#include "../components/UltimeComponent.hpp"
#include "../../config.hpp"

ECS::KillCounterSystem::KillCounterSystem(ECS::ECSCore &core):
    System("KillCounter", core)
{}

void ECS::KillCounterSystem::updateEntity(ECS::Entity &entity)
{
    auto &self = reinterpret_cast<KillCounterComponent &>(entity.getComponentByName("KillCounter"));
    auto &ult = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));

    if (self.multikillTimer > 0)
        self.multikillTimer -= 1;
    if (self.multikillTimer == 0)
        self.multikillCount = 0;

    for (auto &kill : self.killQueue) {
        if (kill.id == entity.getId() ||
                std::find(self.killedId.begin(), self.killedId.end(), kill.id) != self.killedId.end())
            continue;
        self.killedId.push_back(kill.id);
        try {
            ult.charge += kill_value.at(kill.name);
        }
        catch (std::out_of_range &) {
            continue;
        }
        if (kill.name == "Player") {
            self.multikillCount += 1;
            self.multikillTimer = 7 * FRAME_RATE;
            if (self.multikillCount == 2)
                self.soundSystem.playSound("announcer_doublekill");
            if (self.multikillCount == 3)
                self.soundSystem.playSound("announcer_triplekill");
        }
    }
    self.killQueue = {};
}