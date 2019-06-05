//
// Created by Eben on 05/06/2019.
//

#ifndef INDIE_IRRENTITY_HPP
#define INDIE_IRRENTITY_HPP

#include <string>
#include <irrlicht/irrlicht.h>
#include <iostream>
#include "../../Animations.hpp"
#include "../../../ecs/Entity.hpp"
#include "../../../ecs/data/Vector2.hpp"

namespace Irrlicht {
    class irrEntity {
    public:
        irrEntity(const std::string &name, irr::video::SColor defaultColor = irr::video::SColor(255, 255, 255, 255), std::string texturePath = nullptr);

        //PROPERTIES
        const std::string &_meshPath;
        // TODO unsigned _id;
        ECS::Point _pos;
        Animations _anim;
        ECS::Vector2<unsigned> _size;
        irr::video::SColor _defaultColor;
        irr::scene::IAnimatedMesh* _mesh;
        irr::scene::IAnimatedMeshSceneNode* _node;
        irr::scene::ISceneNode* _parent;
        std::string _texturePath;
    };
}


#endif //INDIE_IRRENTITY_HPP
