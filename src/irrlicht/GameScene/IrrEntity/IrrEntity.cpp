#include <utility>

//
// Created by Eben on 05/06/2019.
//

#include "IrrEntity.hpp"

Irrlicht::IrrEntity::IrrEntity(const std::string &filename, unsigned id, irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *driver,
        irr::video::SColor defaultColor, std::string texturePath) :
_meshPath("./media/models/" + filename + ".dae"), id(id), _defaultColor(defaultColor), _texturePath("./media/textures/" + filename + ".png"/*std::move(texturePath)*/), _mesh(nullptr), _node(nullptr), _parent(nullptr)
{
    this->_mesh = smgr->getMesh(this->_meshPath.c_str());

    if (!this->_mesh) {
        this->_loaded = false;
        std::cout << this->_meshPath << " failed to load" << std::endl;
        return;
    }
    this->_node = smgr->addAnimatedMeshSceneNode(this->_mesh);
    if (this->_node) {
        this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
//        std::cout << this->_texturePath << std::endl;
        this->_node->setMaterialTexture(0, driver->getTexture(this->_texturePath.c_str()));
        this->_node->setScale(irr::core::vector3df(4, 4, 4));
    } else
        this->_loaded = false;
    this->_loaded = true;
}



bool Irrlicht::IrrEntity::isEntityLoaded() {
    return this->_loaded;
}

void Irrlicht::IrrEntity::setPos(float x, float z) {
    if (this->_node)
        this->_node->setPosition(irr::core::vector3df(x, 0, z));
}
