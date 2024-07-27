
#include <iostream>
#include <irrlicht.h>
#include <steam_api.h>

#include "EventReceiver.h"
#include "Gui.h"

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "steam_api.lib")
#endif

int main(int argc, char* argv[])
{
	std::cout << "Welcome to Hamsters Den Tavern!" << std::endl;
	bool steamAvailable = SteamAPI_Init();
	std::cout << "Steam status: " << steamAvailable << std::endl;
	if (!steamAvailable)
	{
		std::cout << "Steam not available. Exiting." << std::endl;
		return 2;
	}

	// create Irrlicht device
	CEventReceiver eventReceiver;
	irr::SIrrlichtCreationParameters irrlichtParameter;
	irrlichtParameter.DriverType = irr::video::EDT_DIRECT3D9;
	irrlichtParameter.WindowSize = irr::core::dimension2du(1024, 768);
	irrlichtParameter.Bits = 32;
	irrlichtParameter.Fullscreen = false;
	irrlichtParameter.Stencilbuffer = false;
	irrlichtParameter.Vsync = false;
	irrlichtParameter.AntiAlias = false;
	irrlichtParameter.EventReceiver = &eventReceiver;

		irr::IrrlichtDevice* irrDevice = irr::createDeviceEx(irrlichtParameter);
	if (!irrDevice)
	{
		std::cout << "Could not create DirectX 9 Irrlicht device. Switching to OpenGL." << std::endl;
		irrlichtParameter.DriverType = irr::video::EDT_OPENGL;
		irrDevice = irr::createDeviceEx(irrlichtParameter);
	}

	if (!irrDevice)
	{
		std::cout << "Could not create OpenGL device. Exiting." << std::endl;
		return 1;
	}

	irr::scene::ISceneManager* sceneManager = irrDevice->getSceneManager();
	irr::video::IVideoDriver* videoDriver = irrDevice->getVideoDriver();
	irr::gui::IGUIEnvironment* guiEnvironment = irrDevice->getGUIEnvironment();

	Hamster::CGUI* gui = new Hamster::CGUI(guiEnvironment, videoDriver);
	eventReceiver.Initialize(gui, guiEnvironment);

	irrDevice->setWindowCaption(L"Hamsters Den Tavern");

	// as long as the engine is active:
	while (irrDevice->run() && videoDriver)
	{
		if (irrDevice->isWindowActive())
		{
			// draw everything
			videoDriver->beginScene(true, true, irr::video::SColor(255, 200, 215, 200));
			sceneManager->drawAll();
			guiEnvironment->drawAll();
			videoDriver->endScene();
		}
		else
			irrDevice->yield();
	}

	// destroy the engine
	delete gui;
	irrDevice->drop();

	return 0;
}
