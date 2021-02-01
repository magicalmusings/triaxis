#pragma once

# include "wx/wx.h"
# include "main.h"

class lichtGUIApp : public wxApp
{
public:
	lichtGUIApp();
	~lichtGUIApp();

private:
	main* m_frame1 = nullptr;

public:
	virtual bool OnInit();
}; 

