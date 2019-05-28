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

std::vector<unsigned> generateAirBlocksPos(unsigned sizeMap)
{
    unsigned maxSize = sizeMap * sizeMap;
    unsigned maxSizeM = maxSize - sizeMap;
    unsigned doubleSize = sizeMap * 2;
    unsigned maxSizeDM = maxSize - doubleSize;
    std::vector<unsigned> airPos;

    airPos = {0, 1, sizeMap - 2, sizeMap - 1, sizeMap, sizeMap + 1, doubleSize - 2, doubleSize - 1,
        maxSizeDM, maxSizeDM + 1, maxSizeM - 2, maxSizeM - 1, maxSizeM, maxSizeM + 1, maxSize - 2, maxSize - 1};
    return (airPos);
}

void Map::Map::generateMap(unsigned sizeMap, unsigned brickRatio)
{
    std::vector<std::string> terrainByStr;
    std::vector<unsigned> airBlocksPos = generateAirBlocksPos(sizeMap);
    std::random_device rand_device;
    unsigned int randNum;

    for (int i = 0; i < 398; ++i) {
        if (!airBlocksPos.empty() && airBlocksPos[0] == i)
            airBlocksPos.erase(airBlocksPos.begin());
        else {
            randNum = rand_device() % 100;
            if (randNum < brickRatio)
                reinterpret_cast<ECS::PositionComponent &>(this->_core.makeEntity("Brick").getComponentByName("Position")).pos = {i / 20, i % 20};
        }
    }
}