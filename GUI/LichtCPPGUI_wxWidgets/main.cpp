# include "main.h"
# include "mainPanels.h"

main::main() : wxFrame(nullptr, 
	wxID_ANY, "Licht-cpp GUI - Version 0.1", wxPoint(30,30), wxSize(800, 600) )
{
	// centers the window on the screen.
	Centre();

	panel_parent = new wxPanel(this, wxID_ANY);

	hbox = new wxBoxSizer(wxHORIZONTAL);
	
	param_panel = new ParamPanel(panel_parent);
	graph_panel = new GraphPanel(panel_parent);

	hbox->Add(param_panel, 1, wxEXPAND | wxALL, 5);
	hbox->AddSpacer(10);
	hbox->Add(graph_panel, 1, 0.75, 5);
	hbox->AddSpacer(15);

	panel_parent->SetSizer(hbox);
}

main::~main()
{
	// wxWidgets automatically deallocates wx-related objects.
	//  - Any non wxWdigets memory allocated should be freed here
}
