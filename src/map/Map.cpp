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
#include "../ecs/Components/EntityDropperComponent.hpp"
#include "../ecs/Components/PowerUpComponent.hpp"

Map::Map::Map(ECS::Ressources &ressources) : _core(ressources)
{

}

Map::Map::Map(ECS::Ressources &ressources, std::istream &stream) :
    _core(ressources, stream)
{
}

void Map::Map::update() {
    this->_core.update();
}

std::vector<unsigned> XPairYPairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool yShift;
    bool xShift;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        yShift = (j / sizeMap.x) >= sizeMap.y / 2;
        xShift = (j % sizeMap.x) >= sizeMap.x / 2;
        if ((j / sizeMap.x + yShift) % 2 && (j % sizeMap.x + xShift) % 2)
            wallPos.push_back(j);
    }
    return (wallPos);
}

std::vector<unsigned> XImpairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        if ((j / sizeMap.x) % 2 && (j % sizeMap.x) % 2)
            wallPos.push_back(j);
    }
    return (wallPos);
}

std::vector<unsigned> XPairYImpairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool xShift;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        xShift = (j % sizeMap.x) >= sizeMap.x / 2;
        if ((j / sizeMap.x) % 2 && (j % sizeMap.x + xShift) % 2)
            wallPos.push_back(j);
    }
    return (wallPos);
}

std::vector<unsigned> XImpairYPairSidesWallGenerator(ECS::Vector2<unsigned> sizeMap)
{
    unsigned maxSize = sizeMap.x * sizeMap.y;
    bool yShift;
    std::vector<unsigned> wallPos;

    for (unsigned j = 0; j < maxSize; ++j) {
        yShift = (j / sizeMap.x) >= sizeMap.y / 2;
        if ((j / sizeMap.x + yShift) % 2 && (j % sizeMap.x) % 2)
            wallPos.push_back(j);
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
    ECS::PositionComponent &posComp = reinterpret_cast<ECS::PositionComponent &>(entity.getComponentByName("Position"));
    posComp.pos = pos;
}

void setEntityDropperComponentInBrick(ECS::Entity &brick, double randNum, double brickBonusRatio, std::map<std::string, ECS::NumericValue> &ratiosBonus)
{
    ECS::EntityDropperComponent &entityDropper = reinterpret_cast<ECS::EntityDropperComponent &>(brick.getComponentByName("EntityDropper"));
    double stacker = 0;
    double tmp = 0;

    if (randNum >= brickBonusRatio)
        return;
    tmp = (double)ratiosBonus["Health"] / 100. * brickBonusRatio;
    if (randNum < tmp + stacker) {
        entityDropper.items.emplace_back("DroppedBonusHealth");
        return;
    }
    stacker += tmp;
    tmp = (double)ratiosBonus["Speed"] / 100. * brickBonusRatio;
    if (randNum < tmp + stacker) {
        entityDropper.items.emplace_back("DroppedBonusSpeed");
        return;
    }
    stacker += tmp;
    tmp = (double)ratiosBonus["Bomb"] / 100. * brickBonusRatio;
    if (randNum < tmp + stacker) {
        entityDropper.items.emplace_back("DroppedBonusBomb");
        return;
    }
    stacker += tmp;
    tmp = (double)ratiosBonus["Kick"] / 100. * brickBonusRatio;
    if (randNum < tmp + stacker) {
        entityDropper.items.emplace_back("DroppedBonusKick");
        return;
    }
    stacker += tmp;
    tmp = (double)ratiosBonus["Hardness"] / 100. * brickBonusRatio;
    if (randNum < tmp + stacker) {
        entityDropper.items.emplace_back("DroppedBonusHardness");
        return;
    }
    stacker += tmp;
    tmp = (double)ratiosBonus["Range"] / 100. * brickBonusRatio;
    if (randNum < tmp + stacker) {
        entityDropper.items.emplace_back("DroppedBonusRange");
        return;
    }
}

void Map::Map::setArenaWallAround(ECS::Vector2<unsigned> sizeMap)
{
    for (int i = -1; i < (int)sizeMap.x + 1; ++i) {
        setEntityComponentPosition(this->_core.makeEntity("Bedrock"), {(double)(i * TILESIZE), -1 * TILESIZE});
        setEntityComponentPosition(this->_core.makeEntity("Bedrock"), {(double)(i * TILESIZE), (double)(sizeMap.y * TILESIZE)});
    }
    for (int i = 0; i < (int)sizeMap.y; ++i) {
        setEntityComponentPosition(this->_core.makeEntity("Bedrock"), {-1 * TILESIZE, (double)(i * TILESIZE)});
        setEntityComponentPosition(this->_core.makeEntity("Bedrock"), {(double)(sizeMap.x * TILESIZE), (double)(i * TILESIZE)});
    }
}

void Map::Map::generateMap(ECS::Vector2<unsigned> sizeMap, unsigned brickRatio, std::map<std::string, ECS::NumericValue> ratiosBonus)
{
    std::vector<unsigned> airBlocksPos = generateAirBlocksPos(sizeMap);
    std::vector<unsigned> wallBlocksPos = generateWallBlocksPos(sizeMap);
    std::random_device rand_device;
    double randNum;
    ECS::Point position;

    if (sizeMap.x < 4 || sizeMap.y < 4)
        throw MapTooSmallException("Map is too small in x or in y (< 4).");
    setEntityComponentPosition(this->_core.makeEntity("Player"), {TILESIZE / 16., TILESIZE / 16.});
    setEntityComponentPosition(this->_core.makeEntity("Bomb"), {(double)((sizeMap.x - 1) * TILESIZE) + TILESIZE / 16. , (double)((sizeMap.y - 1) * TILESIZE) + TILESIZE / 16.});
    setArenaWallAround(sizeMap);
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
                if (randNum < brickRatio) {
                    ECS::Entity &brick = this->_core.makeEntity("Brick");
                    setEntityComponentPosition(brick, position);
                    if (!ratiosBonus.empty() && (unsigned)ratiosBonus["Bonus"] > 0)
                        setEntityDropperComponentInBrick(brick, randNum, (double)(ratiosBonus["Bonus"]) / 100. * brickRatio, ratiosBonus);
                }
            }
        }
    }
}

std::ostream& Map::Map::serialize(std::ostream &stream) const
{
    return stream << this->_core;
}

std::ostream &operator<<(std::ostream &stream, const Map::Map &map)
{
    return map.serialize(stream);
}