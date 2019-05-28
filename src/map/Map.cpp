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

std::vector<unsigned> XPairYPairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool yShift = false;
    bool xShift = false;
    std::vector<unsigned> wallPos;

    for (unsigned i = 0; i < maxSize; ++i) {
        if ((maxSize / sizeMap.x) < sizeMap.y / 2)
            yShift = true;
        if ((maxSize % sizeMap.x) < sizeMap.x / 2)
            xShift = true;
        if ((maxSize / sizeMap.x + yShift) % 2 == 1 && (maxSize % sizeMap.x + xShift) % 2 == 1)
            wallPos.push_back(i);
        yShift = false;
        xShift = false;
    }
    return (wallPos);
}

std::vector<unsigned> XImpairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    std::vector<unsigned> wallPos;

    for (unsigned i = 0; i < maxSize; ++i) {
        if ((maxSize / sizeMap.x) % 2 == 1 && (maxSize % sizeMap.x) % 2 == 1)
            wallPos.push_back(i);
    }
    return (wallPos);
}

std::vector<unsigned> XPairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool xShift = false;
    std::vector<unsigned> wallPos;

    for (unsigned i = 0; i < maxSize; ++i) {
        if ((maxSize % sizeMap.x) < sizeMap.x / 2)
            xShift = true;
        if ((maxSize / sizeMap.x) % 2 == 1 && (maxSize % sizeMap.x + xShift) % 2 == 1)
            wallPos.push_back(i);
        xShift = false;
    }
    return (wallPos);
}

std::vector<unsigned> XImpairYPairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool yShift = false;
    std::vector<unsigned> wallPos;

    for (unsigned i = 0; i < maxSize; ++i) {
        if ((maxSize / sizeMap.x) < sizeMap.y / 2)
            yShift = true;
        if ((maxSize / sizeMap.x + yShift) % 2 == 1 && (maxSize % sizeMap.x) % 2 == 1)
            wallPos.push_back(i);
        yShift = false;
    }
    return (wallPos);
}
std::vector<unsigned> generateWallBlocksPos(ECS::Vector2<unsigned> sizeMap)
{
    bool pairX = sizeMap.x + 1 % 2;
    bool pairY = sizeMap.y + 1 % 2;

    switch (pairX + (pairY * 2)) {
        case 1:
            return (XPairYImpairSidesWallGenerator(sizeMap));
        case 2:
            return (XImpairYPairSidesWallGenerator(sizeMap));
        case 3:
            return (XPairYPairSidesWallGenerator(sizeMap));
        default:
            return (XImpairYImpairSidesWallGenerator(sizeMap));
    }

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
                reinterpret_cast<ECS::PositionComponent &>(this->_core.makeEntity("Brick").getComponentByName("Position")).pos = {(double)((i % sizeMap.x) * TILESIZE), (double)((i / sizeMap.x) * TILESIZE)};
        }
    }
}