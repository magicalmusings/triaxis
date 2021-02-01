#include "HapkeFrame.h"

int HAPKE_DEFAULT_SPINCTRL_SIZE = 100;

HapkeFrame::HapkeFrame( int id ) :
	wxFrame( nullptr, id, "Hapke Parameters - Licht-cpp GUI - Version 0.1", 
	wxPoint(30,30), wxSize(500, 600) )
{
	Centre();

	this->SetMinSize(wxSize(500, 600));
	this->SetMaxSize(wxSize(500, 600));

	wxPanel* parent = new wxPanel( this, wxID_ANY );
	wxBoxSizer* main_hbox = new wxBoxSizer(wxHORIZONTAL);

	HapkePanel* hapke_panel = new HapkePanel( parent );
	main_hbox->Add(hapke_panel);
}

HapkeFrame::~HapkeFrame()
{
	// wxWidgets automatically deallocates wx-related objects.
	//  - Any non wxWdigets memory allocated should be freed here
}

HapkePanel::HapkePanel( wxPanel* parent ) :
	wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_NONE )
{
	hapke_vbox = new wxBoxSizer(wxVERTICAL);
	
	hapke_scatter_albedo_p_hbox = initScatterAlbedoPrimaryHBox();
	hapke_scatter_albedo_s_hbox = initScatterAlbedoSecondaryHBox();

	hapke_amplitude_p_hbox = initAmplitudePrimaryHBox();
	hapke_amplitude_s_hbox = initAmplitudeSecondaryHBox();

	hapke_compaction_val_p_hbox = initCompactionValuePrimaryHBox();
	hapke_compaction_val_s_hbox = initCompactionValueSecondaryHBox();

	hapke_surface_rough_p_hbox = initSurfaceRoughPrimaryHBox();
	hapke_surface_rough_s_hbox = initSurfaceRoughSecondaryHBox();

	hapke_phase_angle_p_hbox = initPhaseAnglePrimaryHBox();
	hapke_phase_angle_s_hbox = initPhaseAngleSecondaryHBox();

	hapke_h93_p_hbox = initH93PrimaryHBox();
	hapke_h93_s_hbox = initH93SecondaryHBox();

	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_scatter_albedo_p_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_scatter_albedo_s_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_amplitude_p_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_amplitude_s_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_compaction_val_p_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_compaction_val_s_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_surface_rough_p_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_surface_rough_s_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_phase_angle_p_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_phase_angle_s_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_h93_p_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);
	hapke_vbox->Add(hapke_h93_s_hbox, 1, wxEXPAND | wxALL);
	hapke_vbox->AddSpacer(15);

	this->SetSizerAndFit(hapke_vbox);
}

HapkePanel::~HapkePanel()
{
	// wxWidgets automatically deallocates wx-related objects.
	//  - Any non wxWdigets memory allocated should be freed here
}

wxBoxSizer* HapkePanel::initScatterAlbedoPrimaryHBox()
{
	hapke_scatter_albedo_p_label = new wxStaticText(
		this, wxID_ANY, "Scattering Albedo (Primary)");
	hapke_scatter_albedo_p_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "0.9", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 10, 0, "scatter_albedo_p_spinbtn");
	hapke_scatter_albedo_p_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_scatter_albedo_p_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_scatter_albedo_p_hbox->AddSpacer(15);
	hapke_scatter_albedo_p_hbox->Add(hapke_scatter_albedo_p_label, 0, wxEXPAND | wxALL, 0);
	hapke_scatter_albedo_p_hbox->AddSpacer(160);
	hapke_scatter_albedo_p_hbox->Add(hapke_scatter_albedo_p_spinbtn, 1, wxEXPAND | wxALL);
	hapke_scatter_albedo_p_hbox->AddSpacer(15);
	hapke_scatter_albedo_p_hbox->Add(hapke_scatter_albedo_p_fitcheck, 1, wxEXPAND | wxALL);
	hapke_scatter_albedo_p_hbox->AddSpacer(5);

	return hapke_scatter_albedo_p_hbox;
}

wxBoxSizer* HapkePanel::initScatterAlbedoSecondaryHBox()
{
	hapke_scatter_albedo_s_label = new wxStaticText(
		this, wxID_ANY, "Scattering Albedo (Secondary)");
	hapke_scatter_albedo_s_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "0.9", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 10, 0, "scatter_albedo_s_spinbtn");
	hapke_scatter_albedo_s_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_scatter_albedo_s_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_scatter_albedo_s_hbox->AddSpacer(15);
	hapke_scatter_albedo_s_hbox->Add(hapke_scatter_albedo_s_label, 0, wxEXPAND | wxALL, 0);
	hapke_scatter_albedo_s_hbox->AddSpacer(146);
	hapke_scatter_albedo_s_hbox->Add(hapke_scatter_albedo_s_spinbtn, 1, wxEXPAND | wxALL);
	hapke_scatter_albedo_s_hbox->AddSpacer(15);
	hapke_scatter_albedo_s_hbox->Add(hapke_scatter_albedo_s_fitcheck, 1, wxEXPAND | wxALL);
	hapke_scatter_albedo_s_hbox->AddSpacer(5);

	return hapke_scatter_albedo_s_hbox;
}

wxBoxSizer* HapkePanel::initAmplitudePrimaryHBox()
{
	hapke_amplitude_p_label = new wxStaticText(
		this, wxID_ANY, "Amplitude of Opposition Surge (Primary)");
	hapke_amplitude_p_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "0.0", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 10, 0, "amplitude_p_spinbtn");
	hapke_amplitude_p_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_amplitude_p_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_amplitude_p_hbox->AddSpacer(15);
	hapke_amplitude_p_hbox->Add(hapke_amplitude_p_label, 0, wxEXPAND | wxALL, 0);
	hapke_amplitude_p_hbox->AddSpacer(89);
	hapke_amplitude_p_hbox->Add(hapke_amplitude_p_spinbtn, 1, wxEXPAND | wxALL);
	hapke_amplitude_p_hbox->AddSpacer(15);
	hapke_amplitude_p_hbox->Add(hapke_amplitude_p_fitcheck, 1, wxEXPAND | wxALL);
	hapke_amplitude_p_hbox->AddSpacer(5);

	return hapke_amplitude_p_hbox;
}

wxBoxSizer* HapkePanel::initAmplitudeSecondaryHBox()
{
	hapke_amplitude_s_label = new wxStaticText(
		this, wxID_ANY, "Amplitude of Opposition Surge (Secondary)");
	hapke_amplitude_s_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "0.0", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 10, 0, "amplitude_s_spinbtn");
	hapke_amplitude_s_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_amplitude_s_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_amplitude_s_hbox->AddSpacer(15);
	hapke_amplitude_s_hbox->Add(hapke_amplitude_s_label, 0, wxEXPAND | wxALL, 0);
	hapke_amplitude_s_hbox->AddSpacer(75);
	hapke_amplitude_s_hbox->Add(hapke_amplitude_s_spinbtn, 1, wxEXPAND | wxALL);
	hapke_amplitude_s_hbox->AddSpacer(15);
	hapke_amplitude_s_hbox->Add(hapke_amplitude_s_fitcheck, 1, wxEXPAND | wxALL);
	hapke_amplitude_s_hbox->AddSpacer(5);

	return hapke_amplitude_s_hbox;
}

wxBoxSizer* HapkePanel::initCompactionValuePrimaryHBox()
{
	hapke_compaction_val_p_label = new wxStaticText(
		this, wxID_ANY, "Compaction Value (Primary)");
	hapke_compaction_val_p_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "0", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 10, 0, "compaction_val_p_spinbtn");
	hapke_compaction_val_p_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_compaction_val_p_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_compaction_val_p_hbox->AddSpacer(15);
	hapke_compaction_val_p_hbox->Add(hapke_compaction_val_p_label, 0, wxEXPAND | wxALL, 0);
	hapke_compaction_val_p_hbox->AddSpacer(156);
	hapke_compaction_val_p_hbox->Add(hapke_compaction_val_p_spinbtn, 1, wxEXPAND | wxALL);
	hapke_compaction_val_p_hbox->AddSpacer(15);
	hapke_compaction_val_p_hbox->Add(hapke_compaction_val_p_fitcheck, 1, wxEXPAND | wxALL);
	hapke_compaction_val_p_hbox->AddSpacer(5);

	return hapke_compaction_val_p_hbox;
}

wxBoxSizer* HapkePanel::initCompactionValueSecondaryHBox()
{
	hapke_compaction_val_s_label = new wxStaticText(
		this, wxID_ANY, "Compaction Value (Secondary)");
	hapke_compaction_val_s_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "0", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 10, 0, "compaction_val_s_spinbtn");
	hapke_compaction_val_s_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_compaction_val_s_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_compaction_val_s_hbox->AddSpacer(15);
	hapke_compaction_val_s_hbox->Add(hapke_compaction_val_s_label, 0, wxEXPAND | wxALL, 0);
	hapke_compaction_val_s_hbox->AddSpacer(142);
	hapke_compaction_val_s_hbox->Add(hapke_compaction_val_s_spinbtn, 1, wxEXPAND | wxALL);
	hapke_compaction_val_s_hbox->AddSpacer(15);
	hapke_compaction_val_s_hbox->Add(hapke_compaction_val_s_fitcheck, 1, wxEXPAND | wxALL);
	hapke_compaction_val_s_hbox->AddSpacer(5);

	return hapke_compaction_val_s_hbox;
}

wxBoxSizer* HapkePanel::initSurfaceRoughPrimaryHBox()
{
	hapke_surface_rough_p_label = new wxStaticText(
		this, wxID_ANY, "Surface Roughness (Primary)");
	hapke_surface_rough_p_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "20", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 100, 0, "surface_rough_p_spinbtn");
	hapke_surface_rough_p_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_surface_rough_p_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_surface_rough_p_hbox->AddSpacer(15);
	hapke_surface_rough_p_hbox->Add(hapke_surface_rough_p_label, 0, wxEXPAND | wxALL, 0);
	hapke_surface_rough_p_hbox->AddSpacer(154);
	hapke_surface_rough_p_hbox->Add(hapke_surface_rough_p_spinbtn, 1, wxEXPAND | wxALL);
	hapke_surface_rough_p_hbox->AddSpacer(15);
	hapke_surface_rough_p_hbox->Add(hapke_surface_rough_p_fitcheck, 1, wxEXPAND | wxALL);
	hapke_surface_rough_p_hbox->AddSpacer(5);

	return hapke_surface_rough_p_hbox;
}

wxBoxSizer* HapkePanel::initSurfaceRoughSecondaryHBox()
{
	hapke_surface_rough_s_label = new wxStaticText(
		this, wxID_ANY, "Surface Roughness (Secondary)");
	hapke_surface_rough_s_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "20", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 100, 0, "surface_rough_s_spinbtn");
	hapke_surface_rough_s_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_surface_rough_s_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_surface_rough_s_hbox->AddSpacer(15);
	hapke_surface_rough_s_hbox->Add(hapke_surface_rough_s_label, 0, wxEXPAND | wxALL, 0);
	hapke_surface_rough_s_hbox->AddSpacer(140);
	hapke_surface_rough_s_hbox->Add(hapke_surface_rough_s_spinbtn, 1, wxEXPAND | wxALL);
	hapke_surface_rough_s_hbox->AddSpacer(15);
	hapke_surface_rough_s_hbox->Add(hapke_surface_rough_s_fitcheck, 1, wxEXPAND | wxALL);
	hapke_surface_rough_s_hbox->AddSpacer(5);

	return hapke_surface_rough_s_hbox;
}

wxBoxSizer* HapkePanel::initPhaseAnglePrimaryHBox()
{
	hapke_phase_angle_p_label = new wxStaticText(
		this, wxID_ANY, "Phase Angle (Primary)");
	hapke_phase_angle_p_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "0", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 10, 0, "phase_angle_p_spinbtn");
	hapke_phase_angle_p_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_phase_angle_p_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_phase_angle_p_hbox->AddSpacer(15);
	hapke_phase_angle_p_hbox->Add(hapke_phase_angle_p_label, 0, wxEXPAND | wxALL, 0);
	hapke_phase_angle_p_hbox->AddSpacer(188);
	hapke_phase_angle_p_hbox->Add(hapke_phase_angle_p_spinbtn, 1, wxEXPAND | wxALL);
	hapke_phase_angle_p_hbox->AddSpacer(15);
	hapke_phase_angle_p_hbox->Add(hapke_phase_angle_p_fitcheck, 1, wxEXPAND | wxALL);
	hapke_phase_angle_p_hbox->AddSpacer(5);

	return hapke_phase_angle_p_hbox;
}

wxBoxSizer* HapkePanel::initPhaseAngleSecondaryHBox()
{
	hapke_phase_angle_s_label = new wxStaticText(
		this, wxID_ANY, "Phase Angle (Secondary)");
	hapke_phase_angle_s_spinbtn = new wxSpinCtrl(
		this, wxID_ANY, "0", wxDefaultPosition, wxSize(HAPKE_DEFAULT_SPINCTRL_SIZE, wxDefaultCoord),
		wxSP_ARROW_KEYS, 0, 10, 0, "phase_angle_s_spinbtn");
	hapke_phase_angle_s_fitcheck = new wxCheckBox(
		this, wxID_ANY, "Fit?", wxDefaultPosition);

	hapke_phase_angle_s_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_phase_angle_s_hbox->AddSpacer(15);
	hapke_phase_angle_s_hbox->Add(hapke_phase_angle_s_label, 0, wxEXPAND | wxALL, 0);
	hapke_phase_angle_s_hbox->AddSpacer(173);
	hapke_phase_angle_s_hbox->Add(hapke_phase_angle_s_spinbtn, 1, wxEXPAND | wxALL);
	hapke_phase_angle_s_hbox->AddSpacer(15);
	hapke_phase_angle_s_hbox->Add(hapke_phase_angle_s_fitcheck, 1, wxEXPAND | wxALL);
	hapke_phase_angle_s_hbox->AddSpacer(5);

	return hapke_phase_angle_s_hbox;
}

wxBoxSizer* HapkePanel::initH93PrimaryHBox()
{
	hapke_h93_p_label = new wxStaticText(
		this, wxID_ANY, "h93 (Primary)");
	hapke_h93_p_combobox = new wxComboBox(this, wxID_ANY, "True", wxDefaultPosition, wxDefaultSize);
	hapke_h93_p_combobox->Append("True");
	hapke_h93_p_combobox->Append("False");
	hapke_h93_p_combobox->SetMaxSize(wxSize(100, wxDefaultCoord));

	hapke_h93_p_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_h93_p_hbox->AddSpacer(15);
	hapke_h93_p_hbox->Add(hapke_h93_p_label, 0, wxEXPAND | wxALL, 0);
	hapke_h93_p_hbox->AddSpacer(233);
	hapke_h93_p_hbox->Add(hapke_h93_p_combobox, 1, wxEXPAND | wxALL);

	return hapke_h93_p_hbox;
}

wxBoxSizer* HapkePanel::initH93SecondaryHBox()
{
	hapke_h93_s_label = new wxStaticText(
		this, wxID_ANY, "h93 (Secondary)");
	hapke_h93_s_combobox = new wxComboBox(this, wxID_ANY, "True", wxDefaultPosition, wxDefaultSize);
	hapke_h93_s_combobox->Append("True");
	hapke_h93_s_combobox->Append("False");
	hapke_h93_s_combobox->SetMaxSize(wxSize(100, wxDefaultCoord));

	hapke_h93_s_hbox = new wxBoxSizer(wxHORIZONTAL);
	hapke_h93_s_hbox->AddSpacer(15);
	hapke_h93_s_hbox->Add(hapke_h93_s_label, 0, wxEXPAND | wxALL, 0);
	hapke_h93_s_hbox->AddSpacer(220);
	hapke_h93_s_hbox->Add(hapke_h93_s_combobox, 1, wxEXPAND | wxALL);
	
	return hapke_h93_s_hbox;
}
