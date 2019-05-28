/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map.hpp
*/

#ifndef INDIESTUDIO_MAP_HPP
#define INDIESTUDIO_MAP_HPP

#include "../ecs/ECSCore.hpp"

namespace Map {

    class Map {

    private:
        ECS::ECSCore _core;

    public:
        Map(const ECS::Ressources &ressources);
        ~Map() = default;
        void update();
        void generateMap(unsigned sizeMap, unsigned brickRatio);

    };
}


#endif //INDIESTUDIO_MAP_HPP
