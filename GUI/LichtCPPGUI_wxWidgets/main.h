#pragma once

# include <wx/wxprec.h>

# ifndef WXPRECOMP
# include <wx/wx.h>
# endif 

# include "mainPanels.h"

class main : public wxFrame
{
public:
	main();
	~main();

public:
	// Panels for organizing content
	wxPanel* panel_parent;
	ParamPanel* param_panel;
	GraphPanel* graph_panel;

	wxBoxSizer* hbox;

	// Graph Panel Objects
};

