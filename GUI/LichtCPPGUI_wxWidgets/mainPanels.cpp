
#include <wx/spinctrl.h>

#include "mainPanels.h"


wxBEGIN_EVENT_TABLE( ParamPanel, wxPanel)
	EVT_BUTTON(10001, OnHapkeParamButtonClicked)
wxEND_EVENT_TABLE()

ParamPanel::ParamPanel( wxPanel* parent ):
	wxPanel( parent, -1, wxPoint(-1,-1), wxSize(-1,-1), wxBORDER_NONE )
{
	// initialize components of the Parameter Panel 

	param_label = new wxStaticText(this, wxID_ANY, "Parameters:");
	param_hapke_frame_btn = new wxButton(this, 10001, "Hapke Parameters", 
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));
	param_phase_angle_frame_btn = new wxButton(this, 10002, "Phase Angle Function Parameters",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));
	param_ray_tracing_frame_btn = new wxButton(this, 10003, "Ray Tracing Parameters",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));
	param_shape_frame_btn = new wxButton(this, 10004, "Shape Parameters",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));
	param_spin_state_frame_btn = new wxButton(this, 10005, "Spin States",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));
	param_orbit_frame_btn = new wxButton(this, 10006, "Orbit Parameters",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));

	param_data_label = new wxStaticText(this, wxID_ANY, "Data");
	param_ephemeris_frame_btn = new wxButton(this, 10007, "Ephemeris Files",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));
	param_observed_data_frame_btn = new wxButton(this, 10008, "Observed Data Files",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));

	// Initialize BoxSizer for Parameter Buttons

	param_vbox = new wxBoxSizer(wxVERTICAL);

	// Add components to the BoxSizer for formatting

	param_vbox->Add(param_label, 0, 0, 0);
	param_vbox->AddSpacer(5);
	param_vbox->Add(param_hapke_frame_btn, 0, wxEXPAND | wxALL);
	param_vbox->Add(param_phase_angle_frame_btn, 0, wxEXPAND | wxALL);
	param_vbox->Add(param_ray_tracing_frame_btn, 0, wxEXPAND | wxALL);
	param_vbox->Add(param_shape_frame_btn, 0, wxEXPAND | wxALL);
	param_vbox->Add(param_spin_state_frame_btn, 0, wxEXPAND | wxALL);
	param_vbox->Add(param_orbit_frame_btn, 0, wxEXPAND | wxALL);
	param_vbox->AddSpacer(10);
	param_vbox->Add(param_data_label, 0, 0, 0, 0);
	param_vbox->AddSpacer(5);
	param_vbox->Add(param_ephemeris_frame_btn, 0, wxEXPAND | wxALL);
	param_vbox->Add(param_observed_data_frame_btn, 0, wxEXPAND | wxALL);

	// Set the panels' sizer to the BoxSizer

	this->SetSizer(param_vbox);

	// end of Parameter Panel Initialization
}

void ParamPanel::OnHapkeParamButtonClicked(wxCommandEvent& evt)
{

	hapke_frame = new HapkeFrame(20001);
	hapke_frame->Show();
	
	return;
}

ParamPanel::~ParamPanel()
{
	// wxWidgets automatically deallocates wx-related objects.
	//  - Any non wxWdigets memory allocated should be freed here
}

GraphPanel::GraphPanel(wxPanel* parent) :
	wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(270, 150), wxBORDER_NONE)
{
	// initializing components 

	graph_pane = new wxListBox(this, wxID_ANY, 
		wxDefaultPosition, wxSize( wxDefaultCoord, 800) );

	// Create sizer for GraphPanel

	graph_vbox = new wxBoxSizer(wxVERTICAL);
	graph_vbox->AddSpacer(25);
	graph_vbox->Add(graph_pane, 1, wxEXPAND | wxBOTTOM );
	graph_vbox->AddSpacer(15);
	graph_vbox->Layout();

	// Initialize BoxSizers and corresponding componenets

	button_hbox = initButtonHBox();

	tolerance_hbox = initToleranceVBox();
	
	iter_hbox = initIterCtrlVBox();

	// Add sub-BoxSizers and add them to main sizer

	graph_vbox->Add(button_hbox, 0);
	graph_vbox->AddSpacer(15);
	graph_vbox->Add(tolerance_hbox, 0);
	graph_vbox->AddSpacer(10);
	graph_vbox->Add(iter_hbox, 0);

	// set the graph panel's sizer to the main sizer

	this->SetSizer(graph_vbox);

	// End of GraphPanel initialization
}

wxBoxSizer* GraphPanel::initButtonHBox()
{
	// initialize componenents

	wxBoxSizer* button_hbox;

	graph_plot_btn = new wxButton(this, 10009, "Plot Graph",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));
	graph_cli_output_btn = new wxButton(this, 10010, "Output to CLI",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));
	graph_export_file_btn = new wxButton(this, 10011, "Export File",
		wxDefaultPosition, wxSize(wxDefaultCoord, wxDefaultCoord));

	// Create boxSizer to align components

	button_hbox = new wxBoxSizer(wxHORIZONTAL);

	// Add componenets to sizer

	button_hbox->AddSpacer(25);
	button_hbox->Add(graph_plot_btn, 1);
	button_hbox->AddSpacer(25);
	button_hbox->Add(graph_cli_output_btn, 1);
	button_hbox->AddSpacer(25);
	button_hbox->Add(graph_export_file_btn, 1);
	button_hbox->AddSpacer(25);

	// Return sizer to the user

	return button_hbox; // end of initButtonHBox()
}

wxBoxSizer* GraphPanel::initToleranceVBox()
{
	// initialize components

	wxBoxSizer* tolerance_hbox;

	graph_tolerance_label = new wxStaticText(this, wxID_ANY, "Minimizer Tolerance Level");
	graph_tolerance_spinbtn = new wxSpinCtrl(this, wxID_ANY, "1",
		wxDefaultPosition, wxSize(50, wxDefaultCoord), wxSP_ARROW_KEYS, 0, 10, 0, "tolerance_spinbtn");

	// create boxSizer to align componenets

	tolerance_hbox = new wxBoxSizer(wxHORIZONTAL);

	// Add componenents to the sizer

	tolerance_hbox->Add(graph_tolerance_label, 1, wxEXPAND | wxALL);
	tolerance_hbox->AddSpacer(88);
	tolerance_hbox->Add(graph_tolerance_spinbtn);

	// return the sizer to the user

	return tolerance_hbox; // end of initToleranceVBox()
}

wxBoxSizer* GraphPanel::initIterCtrlVBox()
{
	// initialize components 

	wxBoxSizer* iter_hbox;

	graph_iter_label = new wxStaticText(this, wxID_ANY, "Max Iterations");
	graph_iter_spinbtn = new wxSpinCtrl(this, wxID_ANY, "1",
		wxDefaultPosition, wxSize(50, wxDefaultCoord), wxSP_ARROW_KEYS, 1, 200, 10, "iter_spinbtn");

	// create boxSizer to align components

	iter_hbox = new wxBoxSizer(wxHORIZONTAL);

	// Add components to the sizer

	iter_hbox->Add(graph_iter_label, 1, wxEXPAND | wxALL);
	iter_hbox->AddSpacer(150);
	iter_hbox->Add(graph_iter_spinbtn);

	// return sizer to the user

	return iter_hbox; // end of initIterCtrlVBox()
}

GraphPanel::~GraphPanel()
{
	// wxWidgets automatically deallocates wx-related objects.
	//  - Any non wxWdigets memory allocated should be freed here
}
