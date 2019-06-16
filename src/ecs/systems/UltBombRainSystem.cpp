/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltBombRainSystem.cpp
*/

#include "UltBombRainSystem.hpp"
#include "../components/UltBombRainComponent.hpp"
#include "../components/UltimeComponent.hpp"
#include "../../config.hpp"
#include "../ECSCore.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/OwnerComponent.hpp"
#include "../components/BlockedComponent.hpp"

ECS::UltBombRainSystem::UltBombRainSystem(ECS::ECSCore &core):
    System("UltBombRain", core)
{}

void ECS::UltBombRainSystem::updateEntity(ECS::Entity &entity)
{
    auto &self = reinterpret_cast<UltBombRainComponent &>(entity.getComponentByName("UltBombRain"));

    if (self.timer > 0) {
        if (self.timer % (FRAME_RATE * 4) == 1) {
            dprintf(2, "timer is %d\n", self.timer);
            auto players = this->_core.getEntitiesByName("Player");
            for (auto &player : players) {
                auto &pp = reinterpret_cast<PositionComponent &>(player->getComponentByName("Position"));

                auto &new_bomb = this->_core.makeEntity("Bomb");
                for (auto &p : players) {
                    auto &bc = reinterpret_cast<BlockedComponent &>(p->getComponentByName("Blocked"));
                    bc.whitelistId.push_back(&new_bomb);
                }
                auto &nb_pos = reinterpret_cast<PositionComponent &>(new_bomb.getComponentByName("Position"));
                auto &nb_owner = reinterpret_cast<OwnerComponent &>(new_bomb.getComponentByName("Owner"));
                nb_pos.pos.x = (static_cast<int>(pp.pos.x) + TILESIZE / 2) / TILESIZE * TILESIZE + 2;
                nb_pos.pos.y = (static_cast<int>(pp.pos.y) + TILESIZE / 2) / TILESIZE * TILESIZE + 2;
                nb_owner.ownerId = entity.getId();
            }
            self.bombCount += 1;
            if (self.bombCount >= 3) { // reset
                self.timer = 0;
                self.bombCount = 0;
                return;
            }
        }
        self.timer += 1;
    }

    auto &ult = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));
    if (ult.castUlt && ult.ultimeIsReady()) {
        dprintf(2, "ULT PRESSED\n");
        ult.resetUlt();
        self.timer = 1;
    }
}