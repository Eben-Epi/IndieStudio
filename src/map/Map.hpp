/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map.hpp
*/

#ifndef INDIESTUDIO_MAP_HPP
#define INDIESTUDIO_MAP_HPP


#include <iostream>
#include "../ecs/ECSCore.hpp"
#include "../ecs/data/Vector2.hpp"
#include "../config.hpp"

namespace Map {

    class Map {

    private:
        ECS::ECSCore _core;

    public:
        Map(const ECS::Ressources &ressources);
        ~Map() = default;
        void update();
        void generateMap(ECS::Vector2<unsigned> sizeMap, unsigned brickRatio);
	std::ostream &serialize(std::ostream &stream) const;
    };
}

std::ostream &operator<<(std::ostream &stream, const Map::Map &map);


#endif //INDIESTUDIO_MAP_HPP
