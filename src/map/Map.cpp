/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map.cpp
*/

#include <random>
#include "Map.hpp"
#include "../ecs/Components/PositionComponent.hpp"

Map::Map::Map(const ECS::Ressources &ressources) : _core(ressources)
{

}

void Map::Map::update() {
    this->_core.update();
}

std::vector<unsigned> generateAirBlocksPos(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    unsigned maxSizeM = maxSize - sizeMap.x;
    unsigned doubleSize = sizeMap.x * 2;
    unsigned maxSizeDM = maxSize - doubleSize;
    std::vector<unsigned> airPos;

    airPos = {0, 1, sizeMap.x - 2, sizeMap.x - 1, sizeMap.x, sizeMap.x + 1, doubleSize - 2, doubleSize - 1,
        maxSizeDM, maxSizeDM + 1, maxSizeM - 2, maxSizeM - 1, maxSizeM, maxSizeM + 1, maxSize - 2, maxSize - 1};
    return (airPos);
}

void Map::Map::generateMap(ECS::Vector2<unsigned> sizeMap, unsigned brickRatio)
{
    std::vector<std::string> terrainByStr;
    std::vector<unsigned> airBlocksPos = generateAirBlocksPos(sizeMap);
    std::random_device rand_device;
    unsigned int randNum;

    for (int i = 0; i < sizeMap.x * sizeMap.y - 2; ++i) {
        if (!airBlocksPos.empty() && airBlocksPos[0] == i)
            airBlocksPos.erase(airBlocksPos.begin());
        else {
            randNum = rand_device() % 100;
            if (randNum < brickRatio)
                reinterpret_cast<ECS::PositionComponent &>(this->_core.makeEntity("Brick").getComponentByName("Position")).pos = {(double)(i / sizeMap.x), (double)(i % sizeMap.x)};
        }
    }
}