/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map.hpp
*/

#ifndef INDIESTUDIO_MAP_HPP
#define INDIESTUDIO_MAP_HPP

#include "../ecs/ECSCore.hpp"
#include "../ecs/data/Vector2.hpp"

namespace Map {

    class Map {

    private:
        ECS::ECSCore _core;

    public:
        Map(const ECS::Ressources &ressources);
        ~Map() = default;
        void update();
        void generateMap(ECS::Vector2<unsigned> sizeMap, unsigned brickRatio);

    };
}


#endif //INDIESTUDIO_MAP_HPP
