#pragma once

# include <wx/wxprec.h>
# include <wx/spinctrl.h>

# ifndef WXPRECOMP
# include <wx/wx.h>
# endif 

class HapkeFrame : public wxFrame
{
public:
	HapkeFrame( int id );
	~HapkeFrame();

};

class HapkePanel : public wxPanel
{
public:
	HapkePanel( wxPanel* parent );
	~HapkePanel();
	wxBoxSizer* initScatterAlbedoPrimaryHBox();
	wxBoxSizer* initScatterAlbedoSecondaryHBox();
	wxBoxSizer* initAmplitudePrimaryHBox();
	wxBoxSizer* initAmplitudeSecondaryHBox();
	wxBoxSizer* initCompactionValuePrimaryHBox();
	wxBoxSizer* initCompactionValueSecondaryHBox();
	wxBoxSizer* initSurfaceRoughPrimaryHBox();
	wxBoxSizer* initSurfaceRoughSecondaryHBox();
	wxBoxSizer* initPhaseAnglePrimaryHBox();
	wxBoxSizer* initPhaseAngleSecondaryHBox();
	wxBoxSizer* initH93PrimaryHBox();
	wxBoxSizer* initH93SecondaryHBox();

public:
	wxBoxSizer* hapke_vbox;
	wxBoxSizer* hapke_scatter_albedo_p_hbox;
	wxBoxSizer* hapke_scatter_albedo_s_hbox;
	wxBoxSizer* hapke_amplitude_p_hbox;
	wxBoxSizer* hapke_amplitude_s_hbox;
	wxBoxSizer* hapke_compaction_val_p_hbox;
	wxBoxSizer* hapke_compaction_val_s_hbox;
	wxBoxSizer* hapke_surface_rough_p_hbox;
	wxBoxSizer* hapke_surface_rough_s_hbox;
	wxBoxSizer* hapke_phase_angle_p_hbox;
	wxBoxSizer* hapke_phase_angle_s_hbox;
	wxBoxSizer* hapke_h93_p_hbox;
	wxBoxSizer* hapke_h93_s_hbox;

	wxCheckBox* hapke_scatter_albedo_p_fitcheck;
	wxCheckBox* hapke_scatter_albedo_s_fitcheck;
	wxCheckBox* hapke_amplitude_p_fitcheck;
	wxCheckBox* hapke_amplitude_s_fitcheck;
	wxCheckBox* hapke_compaction_val_p_fitcheck;
	wxCheckBox* hapke_compaction_val_s_fitcheck;
	wxCheckBox* hapke_surface_rough_p_fitcheck;
	wxCheckBox* hapke_surface_rough_s_fitcheck;
	wxCheckBox* hapke_phase_angle_p_fitcheck;
	wxCheckBox* hapke_phase_angle_s_fitcheck;

	wxComboBox* hapke_h93_p_combobox;
	wxComboBox* hapke_h93_s_combobox;

	wxSpinCtrl* hapke_scatter_albedo_p_spinbtn;
	wxSpinCtrl* hapke_scatter_albedo_s_spinbtn;
	wxSpinCtrl* hapke_amplitude_p_spinbtn;
	wxSpinCtrl* hapke_amplitude_s_spinbtn;
	wxSpinCtrl* hapke_compaction_val_p_spinbtn;
	wxSpinCtrl* hapke_compaction_val_s_spinbtn;
	wxSpinCtrl* hapke_surface_rough_p_spinbtn;
	wxSpinCtrl* hapke_surface_rough_s_spinbtn;
	wxSpinCtrl* hapke_phase_angle_p_spinbtn;
	wxSpinCtrl* hapke_phase_angle_s_spinbtn;

	wxStaticText* hapke_scatter_albedo_p_label;
	wxStaticText* hapke_scatter_albedo_s_label;
	wxStaticText* hapke_amplitude_p_label;
	wxStaticText* hapke_amplitude_s_label;
	wxStaticText* hapke_compaction_val_p_label;
	wxStaticText* hapke_compaction_val_s_label;
	wxStaticText* hapke_surface_rough_p_label;
	wxStaticText* hapke_surface_rough_s_label;
	wxStaticText* hapke_phase_angle_p_label;
	wxStaticText* hapke_phase_angle_s_label;
	wxStaticText* hapke_h93_p_label;
	wxStaticText* hapke_h93_s_label;
};

