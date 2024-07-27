#ifndef EVENTRECEIVER_H
#define EVENTRECEIVER_H

#include <irrlicht.h>
#include <string>

namespace Hamster
{
	class CGUI;
}

class CEventReceiver : public irr::IEventReceiver
{
public:
	/// Constructor.
	CEventReceiver();

	/// Destructor.
	~CEventReceiver();

	/// Initialize the object.
	void Initialize(Hamster::CGUI* gui_, irr::gui::IGUIEnvironment* guiEnvironment_);

	/// What to do on an event?
	virtual bool OnEvent(const irr::SEvent& event_);

private:
	irr::gui::IGUIEnvironment* GuiEnvironment;	///< The irrlicht gui environment.
	Hamster::CGUI* Gui;							///< The GUI for creating menu elements.
};

#endif