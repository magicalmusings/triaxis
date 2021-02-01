#include "lichtGUIApp.h"

// Implement the main application
wxIMPLEMENT_APP(lichtGUIApp); 

lichtGUIApp::lichtGUIApp()
{
	// end of lichtGUIApp initialization
}

lichtGUIApp::~lichtGUIApp()
{
	// wxWidgets automatically deallocates wx-related objects.
	//  - Any non wxWdigets memory allocated should be freed here
}

bool lichtGUIApp::OnInit()
{
	if (!wxApp::OnInit())
	{
		return false;
	}

	// create the main frame and show to the user
	m_frame1 = new main();
	m_frame1->Show();

	return true;
}
