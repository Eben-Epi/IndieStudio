/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BlockedSystem.hpp
*/
#ifndef BOMBERMAN_BlockedSystem_HPP
#define BOMBERMAN_BlockedSystem_HPP

#include "../System.hpp"

#define FIRST_QUARTILE(x, y) ((y - x) / 4 + x)
#define THIRD_QUARTILE(x, y) (y - FIRST_QUARTILE(x, y))
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)


namespace ECS {
    class BlockedSystem : public System {
    public:
        BlockedSystem(ECSCore &core);
        void updateEntity(Entity &entity) override;
    };
}


#endif //BOMBERMAN_BlockedSystem_HPP
