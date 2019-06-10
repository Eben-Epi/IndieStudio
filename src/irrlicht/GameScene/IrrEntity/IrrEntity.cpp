//
// Created by Eben on 05/06/2019.
//

#include <utility>
#include "IrrEntity.hpp"

Irrlicht::IrrEntity::IrrEntity(
    const std::string &filename,
    unsigned id,
    irr::scene::ISceneManager *smgr,
    irr::video::IVideoDriver *driver,
    irr::video::SColor defaultColor,
    std::string texturePath
) :
    id(id),
    anim(Animations::IDLE),
    _meshPath("./media/models/" + filename + ".dae"),
    _defaultColor(defaultColor),
    _texturePath("./media/textures/" + filename + ".png"),
    _smgr(smgr),
    _mesh(nullptr),
    _node(nullptr),
    _parent(nullptr)
{
    this->_mesh = smgr->getMesh(this->_meshPath.c_str());

    if (!this->_mesh) {
        this->_loaded = false;
        std::cerr << "Failed to load " << this->_meshPath << std::endl;
        return;
    }
    this->_node = smgr->addAnimatedMeshSceneNode(this->_mesh);
    if (this->_node) {
        this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        this->_node->setMaterialTexture(0, driver->getTexture(this->_texturePath.c_str()));
        this->_node->setScale(irr::core::vector3df(4, 4, 4));
        this->_loaded = true;
    } else
        this->_loaded = false;
}

Irrlicht::IrrEntity::~IrrEntity()
{
	this->_smgr->addToDeletionQueue(this->_node);
}

bool Irrlicht::IrrEntity::isEntityLoaded() {
    return this->_loaded;
}

void Irrlicht::IrrEntity::setPos(float x, float z) {
    if (this->_node)
        this->_node->setPosition(irr::core::vector3df(x / 4, 0, z / 4));
}
