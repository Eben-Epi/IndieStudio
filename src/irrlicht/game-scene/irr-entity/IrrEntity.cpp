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
    _loaded(false),
    _smgr(smgr),
    _mesh(nullptr),
    _node(nullptr),
    _parent(nullptr)
{
    this->_mesh = smgr->getMesh(this->_meshPath.c_str());

    if (!this->_mesh) {
        std::cerr << "Failed to load " << this->_meshPath << std::endl;
        return;
    }
    this->_node = smgr->addAnimatedMeshSceneNode(this->_mesh);
    if (this->_node) {
        this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        this->_node->setMaterialTexture(0, driver->getTexture(this->_texturePath.c_str()));
        this->_node->setScale(irr::core::vector3df(4, 4, 4));
        this->_loaded = true;
    }
}

Irrlicht::IrrEntity::~IrrEntity()
{
    this->_smgr->addToDeletionQueue(this->_node);
}

bool Irrlicht::IrrEntity::isEntityLoaded() {
    return this->_loaded;
}

void Irrlicht::IrrEntity::setPos(float x, float z) {
    if (this->_node && (this->_pos.x != x || this->_pos.y != z)) {
        this->_pos = {x, z};
        x = x + this->_size.x / 2;
        z = z - this->_size.y / 2;
        this->_node->setPosition(irr::core::vector3df(x, 0, z));
    }
}

void Irrlicht::IrrEntity::setScale(float x, float z, float y) {
    if (this->_node && (this->_scale.x != x || this->_scale.y != z)) {
        irr::core::vector3d<irr::f32> factorEscalate(
            x,
            y < 0 ? (z > x ? x : z) : 1,
            z
        );

        this->_node->setScale(factorEscalate);
    }
}

ECS::Vector2<float> Irrlicht::IrrEntity::getSize() {
    irr::core::aabbox3d<float> bounding_box = this->_node->getBoundingBox();

    return ECS::Vector2<float>{bounding_box.MaxEdge.X - bounding_box.MinEdge.X, bounding_box.MaxEdge.Z - bounding_box.MinEdge.Z};
}

void Irrlicht::IrrEntity::setSize(float x, float z)
{
    if (this->_node && (this->_size.x != x || this->_size.y != z)) {
        irr::f32 width;
        irr::f32 depth;
        if (_size.x == -1 && _size.y == -1) {
            auto *edges = new irr::core::vector3d<irr::f32>[8];
            irr::core::aabbox3d<irr::f32> boundingbox = this->_node->getBoundingBox();

            boundingbox.getEdges(edges);
            width = edges[5].X - edges[1].X;
            depth = edges[2].Z - edges[0].Z;
        } else {
            width = _size.x;
            depth = _size.y;
        }

        irr::f32 factorX = x / width;
        irr::f32 factorZ = z / depth;
        irr::core::vector3d<irr::f32> factorEscalate(
            factorX,
            factorZ > factorX ? factorX : factorZ,
            factorZ
        );
        this->_size = {x, z};
        this->_scale = {factorX, factorZ};
        this->_node->setScale(factorEscalate);
    }
}