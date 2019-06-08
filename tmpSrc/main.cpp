#include <irrlicht/irrlicht.h>
#include <iostream>
#include <vector>

class MyEventReceiver : public irr::IEventReceiver
{
	public:

		MyEventReceiver()
		{
			KeyEvent = false;
			for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
				KeyIsDown[i] = false;
		}

		// This is the one method that we have to implement
		virtual bool OnEvent(const irr::SEvent &event)
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
		virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
		{
			return KeyIsDown[keyCode];
		}

		// WARNING ! This function return the first occurence of true
		// so only one key pressed
		irr::scene::EMD2_ANIMATION_TYPE keyPressed() const
		{
			for (irr::u32 i=0; i < irr::KEY_KEY_CODES_COUNT; ++i)
				if (KeyIsDown[i])
					return (irr::scene::EMD2_ANIMATION_TYPE)i;
		}

		bool isKeyEvent() const
		{
			return KeyEvent;
		}

	private:
		// We use this array to store the current state of each key
		bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
		bool KeyEvent;
};

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
	MyEventReceiver receiver;
	irr::scene::EMD2_ANIMATION_TYPE user_anim = irr::scene::EMAT_STAND;
	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, &receiver);

	if (!device)
		return 1;

	device->setWindowCaption(L"Irrlicht Engine");

	irr::video::IVideoDriver *driver = device->getVideoDriver();
	irr::scene::ISceneManager *smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"Dab très fort sur l'Irrlicht Engine", irr::core::rect<irr::s32>(10, 10, 200, 25), true);

	irr::scene::IAnimatedMesh *mesh = smgr->getMesh("media/Audience.DAE");
	if (!mesh) {
		device->drop();
		return 1;
	}
	irr::scene::IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);

	if (node) {
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setMD2Animation(irr::scene::EMAT_STAND);
		node->setMaterialTexture( 0, driver->getTexture("media/Audience2_TEXT.png") );
	}

	smgr->addCameraSceneNode(0, irr::core::vector3df(0, 60, -40), irr::core::vector3df(0, 15, 0));

	irr::scene::EMD2_ANIMATION_TYPE tmp_anim = irr::scene::EMAT_STAND;
	irr::core::vector3df tmp_direction(0, 0, 0);

	std::vector<bool> anim_direction = {false, false, false, false, false, false};
	// {Up, Down, Left, Right, Dead, Bomb}
	std::vector<irr::EKEY_CODE> keys = {irr::KEY_UP, irr::KEY_DOWN, irr::KEY_LEFT, irr::KEY_RIGHT, irr::KEY_KEY_D, irr::KEY_KEY_B};
	bool isDead = false;
	unsigned int tmpCount = 0;
	bool isDroppingBomb = false;
	unsigned int timeBomb = 0;
	irr::scene::IAnimatedMeshSceneNode *bomb(smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/skull.dae"), nullptr, 0, irr::core::vector3df(-100, 0, 0), irr::core::vector3df(0, 0, 0), irr::core::vector3df(5, 5, 5)));
	bomb->setMaterialTexture(0, driver->getTexture("./media/orange.bmp"));

	while (device->run()) {
		driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));

		for (unsigned int i = 0; i < anim_direction.size(); i++)
			anim_direction[i] = receiver.IsKeyDown(keys[i]);

		if (isDroppingBomb && tmpCount == 0)
			isDroppingBomb = false;
		if (timeBomb == 0)
			bomb->setPosition(irr::core::vector3df(-100, 0, 0));

		irr::core::vector3df nodePos = node->getPosition();

		if (anim_direction[4] && tmpCount == 0) {
			if (isDead)
				isDead = false;
			else
				isDead = true;
			tmpCount = 30;
		} else if (anim_direction[5] && tmpCount == 0 && timeBomb == 0 && !isDead) {
				isDroppingBomb = true;
				tmpCount = 70;
				bomb->setPosition(irr::core::vector3df(nodePos.X, -25, nodePos.Z));
				timeBomb = 250;
		} else if (tmpCount > 0)
			tmpCount--;
		if (timeBomb > 0)
			timeBomb--;

		if (isDead) {
			if (tmp_anim != irr::scene::EMAT_BOOM) {
				node->setMD2Animation(irr::scene::EMAT_BOOM);
				tmp_anim = irr::scene::EMAT_BOOM;
			}
		} else if (isDroppingBomb) {
			if (tmp_anim != irr::scene::EMAT_CROUCH_STAND) {
				node->setMD2Animation(irr::scene::EMAT_CROUCH_STAND);
				tmp_anim = irr::scene::EMAT_CROUCH_STAND;
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
				if(tmp_anim != irr::scene::EMAT_RUN) {
					node->setMD2Animation(irr::scene::EMAT_RUN);
					tmp_anim = irr::scene::EMAT_RUN;
				}
			} else {
				if(tmp_anim != irr::scene::EMAT_STAND) {
					node->setMD2Animation(irr::scene::EMAT_STAND);
					tmp_anim = irr::scene::EMAT_STAND;
				}
			}
		}

			smgr->drawAll();
			guienv->drawAll();
			driver->endScene();
	}
	device->drop();
	return 0;
}