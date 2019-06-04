//
// Created by Eben on 27/05/2019.
//

#include <iostream>
#include <irrlicht/irrlicht.h>
#include <irrlicht/driverChoice.h>


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include "screen.hpp"

Irrlicht::screen::screen(int width, int height, int colorDepth) { //TODO FULLSCREEN, SET WINDOW SIZE AND TYPE, ENABLE VSYNC
    this->_driverType = EDT_OPENGL;
    this->_device = createDevice(_driverType, dimension2d<u32>(width, height), colorDepth,
                                 false, false, false, nullptr);
    this->_smgr = _device->getSceneManager();
    this->_driver = _device->getVideoDriver();
}


int Irrlicht::screen::display () { //TODO COLOR SCENE
    int lastFPS = -1;
    while(this->_device->run()) {
        if (this->_device->isWindowActive())
        {
            this->_driver->beginScene(true, true, video::SColor(255,200,200,200));
            this->_smgr->drawAll();
            this->_driver->endScene();

            int fps = this->_driver->getFPS();

            if (lastFPS != fps)
            {
                core::stringw str = "Indie Studio [";
                str += this->_driver->getName();
                str += "] FPS:";
                str += fps;

                this->_device->setWindowCaption(str.c_str());
                lastFPS = fps;
            }
        } else
            this->_device->yield();
    }
    this->_device->drop();
    return (0);
}