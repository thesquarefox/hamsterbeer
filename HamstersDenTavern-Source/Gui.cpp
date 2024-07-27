#include "GUI.h"

const int xOffset = 75;
const int yOffset = 75;

// Constructor
Hamster::CGUI::CGUI(irr::gui::IGUIEnvironment* guiEnvironment_, irr::video::IVideoDriver* videoDriver_)
: GUIEnvironment(guiEnvironment_)
{
	TextureBackground = videoDriver_->getTexture("Tavern.png");
	GUIEnvironment->getSkin()->setFont(GUIEnvironment->getFont("font.xml"));

	// change gui transparencies
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_3D_DARK_SHADOW, irr::video::SColor(255,0,0,0));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_3D_FACE, irr::video::SColor(255,200,120,10));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_3D_HIGH_LIGHT, irr::video::SColor(255,150,120,10));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_3D_LIGHT, irr::video::SColor(255,200,120,10));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_3D_SHADOW, irr::video::SColor(255,200,120,10));

	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_ACTIVE_BORDER, irr::video::SColor(255,0,0,255));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_ACTIVE_CAPTION, irr::video::SColor(255,180,120,10));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_APP_WORKSPACE, irr::video::SColor(255,0,0,255));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_COUNT, irr::video::SColor(255,0,0,0));

	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_GRAY_TEXT, irr::video::SColor(255,0,0,255));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_HIGH_LIGHT, irr::video::SColor(255,170,200,10));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_HIGH_LIGHT_TEXT, irr::video::SColor(255,0,0,0));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_ICON, irr::video::SColor(255,0,0,255));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_ICON_HIGH_LIGHT, irr::video::SColor(255,0,0,255));
													
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_INACTIVE_BORDER, irr::video::SColor(255,0,0,255));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_INACTIVE_CAPTION, irr::video::SColor(255,0,0,255));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_SCROLLBAR, irr::video::SColor(255,150,120,10));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_TOOLTIP, irr::video::SColor(255,0,0,255));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_TOOLTIP_BACKGROUND, irr::video::SColor(255,0,0,255));

	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_WINDOW, irr::video::SColor(255,0,0,255));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_WINDOW_SYMBOL, irr::video::SColor(255,0,0,0));

	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255,255,255,255));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_EDITABLE, irr::video::SColor(255,150,120,10));
	GUIEnvironment->getSkin()->setColor(irr::gui::EGDC_FOCUSED_EDITABLE, irr::video::SColor(255,150,120,10));
}

// create main menu
void Hamster::CGUI::CreateMenue()
{
	irr::gui::IGUIImage* background = GUIEnvironment->addImage(irr::core::rect<irr::s32>(0,0,1023,767), 0);
	background->setImage(TextureBackground);

	GUIEnvironment->addStaticText(L"You are in the tavern of the oupost Hamsters Den.", irr::core::rect<irr::s32>(xOffset, yOffset + 0, 999, 999), false, false, 0);
	GUIEnvironment->addStaticText(L"The barkeeper (a mutated hamster with big big teeth) says to you:", irr::core::rect<irr::s32>(xOffset, yOffset + 40, 999, 999), false, false, 0);
	GUIEnvironment->addStaticText(L"'Welcome my friend, stay a while and drink!'", irr::core::rect<irr::s32>(xOffset, yOffset + 80, 999, 999), false, false, 0);
	GUIEnvironment->addStaticText(L"He puts a precious beer onto the table in front of you.", irr::core::rect<irr::s32>(xOffset, yOffset + 120, 999, 999), false, false, 0);
	GUIEnvironment->addStaticText(L"The beer is called 'Rodents Special'.", irr::core::rect<irr::s32>(xOffset, yOffset + 160, 999, 999), false, false, 0);

	GUIEnvironment->addButton(irr::core::rect<irr::s32>(324,400,700,450), 0, EGuiId::BUTTON_DRINK_BEER, L"Drink the Beer!");
}

void Hamster::CGUI::Skal()
{
	GUIEnvironment->addStaticText(L"'Skal! For the hamsters!' you say.", irr::core::rect<irr::s32>(xOffset, yOffset + 500, 999, 999), false, false, 0);
	GUIEnvironment->addStaticText(L"The hamster bartender responds:", irr::core::rect<irr::s32>(xOffset, yOffset + 540, 999, 999), false, false, 0);
	GUIEnvironment->addStaticText(L"'You are now officially a friend of the hamsters!'", irr::core::rect<irr::s32>(xOffset, yOffset + 580, 999, 999), false, false, 0);
}
