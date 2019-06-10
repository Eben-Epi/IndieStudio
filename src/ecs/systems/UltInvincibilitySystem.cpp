/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltInvincibilitySystem.cpp
*/
#include "UltInvincibilitySystem.hpp"
#include "../components/UltimeComponent.hpp"
#include "../components/HealthComponent.hpp"
#include "../components/UltInvincibilityComponent.hpp"
#include "UltimeSystem.hpp"
#include "../components/CollisionComponent.hpp"

ECS::UltInvincibilitySystem::UltInvincibilitySystem(ECS::ECSCore &core):
    System("UltInvincibility", core)
{
    this->_dependencies = {"Ultime", "Collision", "Health"};
}

void ECS::UltInvincibilitySystem::updateEntity(ECS::Entity &entity)
{
    auto &uc = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));
    auto &self = reinterpret_cast<UltInvincibilityComponent &>(entity.getComponentByName("UltInvincibility"));

    if (self.isOnUse) {
        if (self.timeLeft == 0) {
            self.isOnUse = false;
            auto &mc = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
            mc.passThrough = self.oldPassThrough;
        }
        else {
            self.timeLeft -= 1;
            uc.charge -= ULTIME_POINT_PER_FRAME;
        }
    }

    if (uc.castUlt && uc.ultimeIsReady()) {
        auto &hc = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
        auto &mc = reinterpret_cast<CollisionComponent &>(entity.getComponentByName("Collision"));
        uc.charge = 0;

        uc.soundSystem.playSoundOverBackgroundMusic("starman", 100);
        hc.invunerabilityTimeLeft = 26 * FRAME_RATE;
        self.oldPassThrough = mc.passThrough;
        mc.passThrough = 2;
        self.isOnUse = true;
        self.timeLeft = 26 * FRAME_RATE;
    }
}