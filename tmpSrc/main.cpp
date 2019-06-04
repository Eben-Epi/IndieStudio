#include <irrlicht/irrlicht.h>
#include <iostream>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class MyEventReceiver : public IEventReceiver
{
	public:

		MyEventReceiver()
		{
			KeyEvent = false;
			for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
				KeyIsDown[i] = false;
		}

		// This is the one method that we have to implement
		virtual bool OnEvent(const SEvent& event)
		{
			// Remember whether each key is down or up
			if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
				KeyEvent = true;
				KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
			} else
				KeyEvent = false;

			return false;
		}

		// This is used to check whether a key is being held down
		virtual bool IsKeyDown(EKEY_CODE keyCode) const
		{
			return KeyIsDown[keyCode];
		}

		// WARNING ! This function return the first occurence of true
		// so only one key pressed
		EMD2_ANIMATION_TYPE keyPressed() const
		{
			for (u32 i=0; i < KEY_KEY_CODES_COUNT; ++i) {
				if (KeyIsDown[i])
					return (EMD2_ANIMATION_TYPE)i;
			}
		}

		bool isKeyEvent() const
		{
			return KeyEvent;
		}

	private:
		// We use this array to store the current state of each key
		bool KeyIsDown[KEY_KEY_CODES_COUNT];
		bool KeyEvent;
};

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
	MyEventReceiver receiver;

	IrrlichtDevice *device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16, false, false, false, &receiver);

	if (!device)
		return 1;

//	device->setWindowCaption(L"Irrlicht Engine");

	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	
	guienv->addStaticText(L"Dab très fort sur l'Irrlicht Engine", rect<s32>(10,10,200,25), true);

	IAnimatedMesh *mesh = smgr->getMesh("media/sydney.md2");
	if (!mesh) {
		device->drop();
		return 1;
	}
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

	if (node) {
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture( 0, driver->getTexture("media/sydney.bmp") );
	}

	smgr->addCameraSceneNode(0, vector3df(0,60,-40), vector3df(0,15,0));

	EMD2_ANIMATION_TYPE tmp_anim = scene::EMAT_STAND;
	vector3df tmp_direction(0, 0, 0);

	bool anim_direction[] = {false, false, false, false, false, false};
	// {Up, Down, Left, Right, Dead, Bomb}
	bool isDead = false;
	unsigned int tmpCount = 0;
	bool isDroppingBomb = false;
	unsigned int timeBomb = 0;
	IAnimatedMeshSceneNode *bomb(smgr->addAnimatedMeshSceneNode(smgr->getMesh("/home/hstanislas/Desktop/sphere.dae"), nullptr, 0, vector3df(-100, 0, 0), vector3df(0, 0, 0), vector3df(3, 3, 3)));
	bomb->setMaterialTexture(0, driver->getTexture("/home/hstanislas/Desktop/orange.bmp"));

	while (device->run()) {
		driver->beginScene(true, true, SColor(255, 100, 101, 140));

		anim_direction[0] = receiver.IsKeyDown(irr::KEY_UP);
		anim_direction[1] = receiver.IsKeyDown(irr::KEY_DOWN);
		anim_direction[2] = receiver.IsKeyDown(irr::KEY_LEFT);
		anim_direction[3] = receiver.IsKeyDown(irr::KEY_RIGHT);
		anim_direction[4] = receiver.IsKeyDown(irr::KEY_KEY_D);
		anim_direction[5] = receiver.IsKeyDown(irr::KEY_KEY_B);

		if (isDroppingBomb && tmpCount == 0)
			isDroppingBomb = false;
		if (timeBomb == 0)
			bomb->setPosition(vector3df(-100, 0, 0));

		vector3df nodePos = node->getPosition();

		if (anim_direction[4] && tmpCount == 0) {
			if (isDead)
				isDead = false;
			else
				isDead = true;
			tmpCount = 30;
		} else if (anim_direction[5] && tmpCount == 0 && timeBomb == 0) {
				isDroppingBomb = true;
				tmpCount = 70;
				bomb->setPosition(vector3df(nodePos.X, -25, nodePos.Z));
				timeBomb = 250;
		} else if (tmpCount > 0)
			tmpCount--;
		if (timeBomb > 0)
			timeBomb--;

		if (isDead) {
			if (tmp_anim != scene::EMAT_BOOM) {
				node->setMD2Animation(scene::EMAT_BOOM);
				tmp_anim = scene::EMAT_BOOM;
			}
		} else if (isDroppingBomb) {
			if (tmp_anim != scene::EMAT_CROUCH_STAND) {
				node->setMD2Animation(scene::EMAT_CROUCH_STAND);
				tmp_anim = scene::EMAT_CROUCH_STAND;
			}
		} else {
			if(anim_direction[0]) {
				tmp_direction.Y = -90;
				nodePos.Z += 1;
			} else if(anim_direction[1]) {
				tmp_direction.Y = 90;
				nodePos.Z -= 1;
			} else if(anim_direction[2]) {
				tmp_direction.Y = 180;
				nodePos.X -= 1;
			} else if(anim_direction[3]) {
				tmp_direction.Y = 0;
				nodePos.X += 1;
			}

			node->setPosition(nodePos);
			node->setRotation(tmp_direction);

			if(anim_direction[0] || anim_direction[1] || anim_direction[2] || anim_direction[3]) {
				if(tmp_anim != scene::EMAT_RUN) {
					node->setMD2Animation(scene::EMAT_RUN);
					tmp_anim = scene::EMAT_RUN;
				}
			} else {
				if(tmp_anim != scene::EMAT_STAND) {
					node->setMD2Animation(scene::EMAT_STAND);
					tmp_anim = scene::EMAT_STAND;
				}
			}
			// if (new_user_anim != user_anim) {
			// 	node->setMD2Animation(new_user_anim);
			// 	user_anim = new_user_anim;
			// }
		}

			smgr->drawAll();
			guienv->drawAll();

			driver->endScene();
	}

	device->drop();
	return 0;
}