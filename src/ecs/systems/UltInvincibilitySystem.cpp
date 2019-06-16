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
#include "../components/MovableComponent.hpp"

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
            auto &mc = reinterpret_cast<MovableComponent&>(entity.getComponentByName("Movable"));

            self.isOnUse = false;
            mc.maxSpeed -= 2.5;
        }
        else {
            self.timeLeft -= 1;
            uc.charge -= ULTIME_POINT_PER_FRAME;
        }
    }

    if (uc.castUlt && uc.ultimeIsReady()) {
        auto &hc = reinterpret_cast<HealthComponent &>(entity.getComponentByName("Health"));
        auto &mc = reinterpret_cast<MovableComponent&>(entity.getComponentByName("Movable"));

        uc.resetUlt();
        uc.soundSystem.playSoundOverBackgroundMusic("starman", 100);
        hc.invunerabilityTimeLeft = 25 * FRAME_RATE;
        mc.maxSpeed += 2.5;
        self.isOnUse = true;

        self.timeLeft = 25 * FRAME_RATE;
    }
}