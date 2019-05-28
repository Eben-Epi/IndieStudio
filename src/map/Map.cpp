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

void setComponentPosition(ECS::Entity &entity, ECS::Point pos)
{
    reinterpret_cast<ECS::PositionComponent &>(entity.getComponentByName("Position")).pos = pos;
}

void generateRatioBricksAndWalls(std::vector<std::string> &entity)
{
    for (int i = 0; i < 3; ++i)
        entity.emplace_back("Wall");
    for (int i = 0; i < 5; ++i)
        entity.emplace_back("Brick");
}

void Map::Map::generateMap()
{
    std::vector<std::string> terrainByStr;
    std::vector<unsigned int> airBlocksPos = {0, 1, 18, 19, 20, 21, 38, 39, 360, 361, 378, 379, 380, 381};
    std::random_device rand_device;

    for (int i = 0; i < 398; ++i) {
        if (!airBlocksPos.empty() && airBlocksPos[0] == i)
            airBlocksPos.erase(airBlocksPos.begin());
        else
            setComponentPosition(this->_core.makeEntity(terrainByStr[rand_device() % 8]), {i / 20, i % 20});
    }
}