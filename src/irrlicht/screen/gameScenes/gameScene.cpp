//
// Created by Eben on 05/06/2019.
//

#include "gameScene.hpp"

Irrlicht::gameScene::gameScene(screen window) : _window(window) {
    this->_guienv = nullptr;
    this->_smgr = nullptr;
}

void Irrlicht::gameScene::update() {
    this->_window.display(this->_smgr, this->_guienv);
}

void Irrlicht::gameScene::addSmgr() {
    this->_smgr = this->_window._device->getSceneManager();
}

void Irrlicht::gameScene::addGuiENV() {
    this->_guienv = this->_window._device->getGUIEnvironment();
}
