#include <steam_api.h>
#include "EventReceiver.h"
#include "Gui.h"

const std::string HAMSTERS_FRIEND = "ACH_21";

CEventReceiver::CEventReceiver()
{
}

CEventReceiver::~CEventReceiver()
{
}

void CEventReceiver::Initialize(Hamster::CGUI* gui_,  irr::gui::IGUIEnvironment* guiEnvironment_)
{
	Gui = gui_;
	GuiEnvironment = guiEnvironment_;
	Gui->CreateMenue();
}

bool CEventReceiver::OnEvent(const irr::SEvent& event_)
{
	if (event_.EventType == irr::EET_GUI_EVENT)
	{		
		// get id of element
		irr::s32 id = event_.GUIEvent.Caller->getID();

		// type of element
		switch(event_.GUIEvent.EventType)
		{
		// button clicked
		case irr::gui::EGET_BUTTON_CLICKED:
			switch(id)
			{
			// buttons
			case Hamster::CGUI::EGuiId::BUTTON_DRINK_BEER:
				SteamUserStats()->SetAchievement(HAMSTERS_FRIEND.c_str());
				Gui->Skal();
				break;
			}
			break;
		}
	}
	return false;
}

