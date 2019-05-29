/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map.cpp
*/

#include <random>
#include "Map.hpp"
#include "../ecs/Components/PositionComponent.hpp"
#include "MapException.hpp"

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

    for (unsigned j = 0; j < maxSize; ++j) {
        if ((j / sizeMap.x) >= sizeMap.y / 2)
            yShift = true;
        if ((j % sizeMap.x) >= sizeMap.x / 2)
            xShift = true;
        if ((j / sizeMap.x + yShift) % 2 == 1 && (j % sizeMap.x + xShift) % 2 == 1)
            wallPos.push_back(j);
        yShift = false;
        xShift = false;
    }
    return (wallPos);
}

std::vector<unsigned> XImpairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        if ((j / sizeMap.x) % 2 == 1 && (j % sizeMap.x) % 2 == 1)
            wallPos.push_back(j);
    }
    return (wallPos);
}

std::vector<unsigned> XPairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool xShift = false;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        if ((j % sizeMap.x) >= sizeMap.x / 2)
            xShift = true;
        if ((j / sizeMap.x) % 2 == 1 && (j % sizeMap.x + xShift) % 2 == 1)
            wallPos.push_back(j);
        xShift = false;
    }
    return (wallPos);
}

std::vector<unsigned> XImpairYPairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool yShift = false;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        if ((j / sizeMap.x) >= sizeMap.y / 2)
            yShift = true;
        if ((j / sizeMap.x + yShift) % 2 == 1 && (j % sizeMap.x) % 2 == 1)
            wallPos.push_back(j);
        yShift = false;
    }
    return (wallPos);
}
std::vector<unsigned> generateWallBlocksPos(ECS::Vector2<unsigned> sizeMap)
{
    bool pairX = (sizeMap.x + 1) % 2;
    bool pairY = (sizeMap.y + 1) % 2;

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

    airPos = {0, 1, sizeMap.x - 2, sizeMap.x - 1, sizeMap.x, doubleSize - 1,
        maxSizeDM, maxSizeM - 1, maxSizeM, maxSizeM + 1, maxSize - 2, maxSize - 1};
    return (airPos);
}

void setEntityComponentPosition(ECS::Entity &entity, ECS::Point pos)
{
    reinterpret_cast<ECS::PositionComponent &>(entity.getComponentByName("Position")).pos = pos;
}

void Map::Map::generateMap(ECS::Vector2<unsigned> sizeMap, unsigned brickRatio)
{
    std::vector<unsigned> airBlocksPos = generateAirBlocksPos(sizeMap);
    std::vector<unsigned> wallBlocksPos = generateWallBlocksPos(sizeMap);
    std::random_device rand_device;
    unsigned int randNum;
    ECS::Point position;

    if (sizeMap.x < 4 || sizeMap.y < 4)
        throw MapException("Map is too small in x or in y (< 4).");
    setEntityComponentPosition(this->_core.makeEntity("Player"), {TILESIZE / 16., TILESIZE / 16.});
    //setWallArenaAround();
    for (int i = 0; i < sizeMap.x * sizeMap.y - 2; ++i) {
        if (!airBlocksPos.empty() && airBlocksPos[0] == i)
            airBlocksPos.erase(airBlocksPos.begin());
        else {
            position = {(double)((i % sizeMap.x) * TILESIZE), (double)((i / sizeMap.x) * TILESIZE)};
            if (!wallBlocksPos.empty() && wallBlocksPos[0] == i) {
                setEntityComponentPosition(this->_core.makeEntity("Wall"), position);
                wallBlocksPos.erase(wallBlocksPos.begin());
            } else {
                randNum = rand_device() % 100;
                if (randNum < brickRatio)
                    setEntityComponentPosition(this->_core.makeEntity("Brick"), position);
            }
        }
    }
}