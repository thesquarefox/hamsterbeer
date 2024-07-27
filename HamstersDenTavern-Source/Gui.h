#ifndef GUI_H
#define GUI_H

#include <irrlicht.h>

namespace Hamster
{
	// GUI class
	class CGUI
	{
	public:
		struct EGuiId
		{
			enum Enum
			{
				BUTTON_DRINK_BEER
			};
		};

	public:
		CGUI(irr::gui::IGUIEnvironment* guiEnvironment_, irr::video::IVideoDriver* videoDriver_);

		void CreateMenue();

		void Skal();

	private:
		// GUI Environment
		irr::gui::IGUIEnvironment* GUIEnvironment;
		irr::video::ITexture* TextureBackground;
	};
	
} // END NAMESPACE DunGen

#endif