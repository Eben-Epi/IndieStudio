#include <utility>

//
// Created by Eben on 05/06/2019.
//

#include "IrrEntity.hpp"

Irrlicht::IrrEntity::IrrEntity(const std::string &filename, unsigned id, irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *driver,
        irr::video::SColor defaultColor, std::string texturePath) :
_meshPath("./media/mesh/" + filename + ".dae"), id(id), _defaultColor(defaultColor), _texturePath(std::move(texturePath)), _mesh(nullptr), _node(nullptr), _parent(nullptr)
{
    this->_mesh = smgr->getMesh(this->_meshPath.c_str());

    if (!this->_mesh) {
        this->_loaded = false;
        return;
    }
    this->_node = smgr->addAnimatedMeshSceneNode(this->_mesh);
    if (this->_node) {
        this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        this->_node->setMaterialTexture(0, driver->getTexture(this->_texturePath.c_str()));
    } else
        this->_loaded = false;
    this->_loaded = true;
}

bool Irrlicht::IrrEntity::isEntityLoaded() {
    return this->_loaded;
}
