/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** UltShockWaveSystem.cpp
*/
#include "UltShockWaveSystem.hpp"
#include "../components/UltShockWaveComponent.hpp"
#include "../components/UltimeComponent.hpp"
#include "../components/ControllableComponent.hpp"
#include "../../config.hpp"
#include "../ECSCore.hpp"
#include "../components/PositionComponent.hpp"
#include "../entities/ExplosionFrame.hpp"
#include "../components/MovableComponent.hpp"
#include "../components/OnCollisionDamageDealerComponent.hpp"

ECS::UltShockWaveSystem::UltShockWaveSystem(ECS::ECSCore &core):
    System("UltShockWave", core)
{}

void ECS::UltShockWaveSystem::updateEntity(ECS::Entity &entity)
{
    auto &self = reinterpret_cast<UltShockWaveComponent &>(entity.getComponentByName("UltShockWave"));
    if (self.timer > 0) {
        if (self.timer > (2 * FRAME_RATE) && !(self.timer % (FRAME_RATE / 15))) {
            auto &exp = this->_core.makeEntity("ExplosionFrame");
            auto &explosion_position = reinterpret_cast<PositionComponent &>(exp.getComponentByName("Position"));
            auto &ddc = reinterpret_cast<OnCollisionDamageDealerComponent &>(exp.getComponentByName("OnCollisionDamageDealer"));

            self.waveCount++;
            ddc.ownerId = entity.getId();

            if (self.direction & 0b0001) {     // UP
                explosion_position.size = {TILESIZE * 3, TILESIZE};
                explosion_position.pos = {
                        static_cast<double>(self.origin.x - TILESIZE),
                        static_cast<double>(self.origin.y - TILESIZE * self.waveCount)};
            }
            else if (self.direction & 0b0010) { // LEFT
                explosion_position.size = {TILESIZE, TILESIZE * 3};
                explosion_position.pos = {
                        static_cast<double>(self.origin.x + TILESIZE * self.waveCount),
                        static_cast<double>(self.origin.y - TILESIZE)};
            }
            else if (self.direction & 0b0100) { // DOWN
                explosion_position.size = {TILESIZE * 3, TILESIZE};
                explosion_position.pos = {
                        static_cast<double>(self.origin.x - TILESIZE),
                        static_cast<double>(self.origin.y + TILESIZE * self.waveCount)};
            }
            else if (self.direction & 0b1000) { // RIGHT
                explosion_position.size = {TILESIZE, TILESIZE * 3};
                explosion_position.pos = {
                        static_cast<double>(self.origin.x - TILESIZE * self.waveCount),
                        static_cast<double>(self.origin.y - TILESIZE)};
            }
        }
        if (self.waveCount >= 20) {
            self.timer = 0;
            self.waveCount = 0;
        }
        else
            self.timer += 1;
    }

    auto &ult = reinterpret_cast<UltimeComponent &>(entity.getComponentByName("Ultime"));
    if (ult.castUlt && ult.ultimeIsReady()) {
        ult.resetUlt();
        auto &cc = reinterpret_cast<ControllableComponent &>(entity.getComponentByName("Controllable"));
        auto &pc = reinterpret_cast<PositionComponent &>(entity.getComponentByName("Position"));
        auto &mc = reinterpret_cast<MovableComponent &>(entity.getComponentByName("Movable"));

        cc.stun(3 * FRAME_RATE);
        self.timer = 1;
        self.origin.x = (static_cast<int>(pc.pos.x) + TILESIZE / 2) / TILESIZE * TILESIZE;
        self.origin.y = (static_cast<int>(pc.pos.y) + TILESIZE / 2) / TILESIZE * TILESIZE;
        pc.pos = {static_cast<double>(self.origin.x + 2), static_cast<double>(self.origin.y + 2)};
        self.direction = mc.dir;
    }
}