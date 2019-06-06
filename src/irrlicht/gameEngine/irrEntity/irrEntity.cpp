//
// Created by Eben on 05/06/2019.
//

#include "IrrEntity.hpp"

Irrlicht::IrrEntity::IrrEntity(const std::string &name, unsigned id, irr::video::SColor defaultColor, std::string texturePath) :
_meshPath(name), _id(id), _defaultColor(defaultColor), _texturePath(texturePath), _mesh(nullptr), _node(nullptr), _parent(nullptr)
{
}
