//
// Created by Eben on 05/06/2019.
//

#include "irrEntity.hpp"

Irrlicht::irrEntity::irrEntity(const std::string &name, unsigned id, irr::video::SColor defaultColor, std::string texturePath) :
_meshPath(name), _id(id), _defaultColor(defaultColor), _texturePath(texturePath)
{

}
