/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltStrikeSystem.cpp
*/

#include "UltStrikeSystem.hpp"
#include "../components/UltimeComponent.hpp"
#include "../components/UltShockWaveComponent.hpp"
#include "../ECSCore.hpp"
#include "../components/ControllableComponent.hpp"
#include "../components/CurseComponent.hpp"
#include "../../config.hpp"

ECS::UltStrikeSystem::UltStrikeSystem(ECS::ECSCore &core):
    System("UltStrike", core)
{}

void ECS::UltStrikeSystem::updateEntity(ECS::Entity &entity)
{
    auto &ult = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));

    if (ult.castUlt && ult.ultimeIsReady()) {
        ult.resetUlt();
        auto players = this->_core.getEntitiesByName("Player");
        for (auto &player : players) {
            if (player->getId() == entity.getId())
                continue;
            auto &pcontrol = reinterpret_cast<ControllableComponent &>(player->getComponentByName("Controllable"));
            auto &pcurse = reinterpret_cast<CurseComponent &>(player->getComponentByName("Curse"));

            pcontrol.stun(FRAME_RATE);
            pcurse.giveCurse(CurseComponent::CurseEffect::ULTRASLOW, static_cast<int>(6.5 * FRAME_RATE), true, false);
        }
        ult.soundSystem.playSoundOverBackgroundMusic("shock");
    }
}