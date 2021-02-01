#pragma once

# include <wx/wx.h>
# include <wx/panel.h>

# include "HapkeFrame.h"

class ParamPanel : public wxPanel
{
public:
	ParamPanel(wxPanel* parent);
	~ParamPanel();

	// Event Handlers
	void OnHapkeParamButtonClicked(wxCommandEvent& evt);

public:
	// Frames for additional parameters

	HapkeFrame* hapke_frame;

	// Parameter Panel Objects
	wxBoxSizer* param_vbox;

	wxButton* param_ephemeris_frame_btn;
	wxButton* param_observed_data_frame_btn;
	wxButton* param_hapke_frame_btn;
	wxButton* param_phase_angle_frame_btn;
	wxButton* param_ray_tracing_frame_btn;
	wxButton* param_shape_frame_btn;
	wxButton* param_spin_state_frame_btn;
	wxButton* param_orbit_frame_btn;
	
	wxStaticText* param_data_label;
	wxStaticText* param_label;
	
	// Prepares the panel to handle events 
	wxDECLARE_EVENT_TABLE();
};

class GraphPanel : public wxPanel
{
public:
	GraphPanel(wxPanel* parent);
	~GraphPanel();

private:
	wxBoxSizer* initButtonHBox();
	wxBoxSizer* initToleranceVBox();
	wxBoxSizer* initIterCtrlVBox();

public:
	wxBoxSizer* graph_vbox;
	wxBoxSizer* button_hbox;
	wxBoxSizer* tolerance_hbox;
	wxBoxSizer* iter_hbox;

	wxButton* graph_plot_btn;
	wxButton* graph_cli_output_btn;
	wxButton* graph_export_file_btn;

	wxListBox* graph_pane;
	
	wxStaticText* graph_tolerance_label;
	wxStaticText* graph_iter_label;

	wxSpinCtrl* graph_tolerance_spinbtn;
	wxSpinCtrl* graph_iter_spinbtn;

};

