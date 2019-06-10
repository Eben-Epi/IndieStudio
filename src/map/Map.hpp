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
#include "../ecs/data/NumericValue.hpp"


namespace Map {

    class Map {

    private:
        ECS::ECSCore _core;

    public:
        Map(ECS::Ressources &ressources);
        Map(ECS::Ressources &ressources, std::istream &stream);
        ~Map() = default;
        void update();
        void generateMap(ECS::Vector2<unsigned> sizeMap, unsigned brickRatio, std::map<std::string, ECS::NumericValue> ratiosBonus = {{"Bonus", 0}});
        std::ostream &serialize(std::ostream &stream) const;
        void setArenaWallAround(ECS::Vector2<unsigned> sizeMap);
    };
}

std::ostream &operator<<(std::ostream &stream, const Map::Map &map);


#endif //INDIESTUDIO_MAP_HPP
