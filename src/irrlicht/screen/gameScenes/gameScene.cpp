//
// Created by Eben on 05/06/2019.
//

#include "GameScene.hpp"
#include "../Screen.hpp"

Irrlicht::GameScene::GameScene(Screen &window) : _window(window) {
    this->_guienv = nullptr;
    this->_smgr = nullptr;
}

void Irrlicht::GameScene::update() {
    this->_window.display(this->_smgr, this->_guienv);
}

void Irrlicht::GameScene::addSmgr() {
    this->_smgr = this->_window._device->getSceneManager();
}

void Irrlicht::GameScene::addGuiENV() {
    this->_guienv = this->_window._device->getGUIEnvironment();
}
