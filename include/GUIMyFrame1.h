#pragma once
#include "GUI.h"
#include "TinyEXIF.h"
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <wx/dir.h>
#include <wx/msgdlg.h>
#include <wx/numdlg.h>
#include <wx/pen.h>
#include <wx/brush.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/dc.h>
#include <wx/dcgraph.h>
#include <wx/dcmirror.h>
#include <wx/dcscreen.h>
#include <wx/dcsvg.h>
#include <wx/dcprint.h>

class GUIMyFrame1 : public MyFrame1
{
	protected:
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;

		// Virtual event handlers, override them in your derived class
		virtual void MainFormClose( wxCloseEvent& event );
		virtual void WxPanel_Repaint( wxUpdateUIEvent& event );
		virtual void m_button1_click( wxCommandEvent& event );
		virtual void m_button2_click( wxCommandEvent& event );
		virtual void m_button3_click( wxCommandEvent& event );
		virtual void m_button4_click( wxCommandEvent& event );
		void DrawExif(wxDC& dc);
		void DrawBitmap(wxDC& dc);
		void Repaint();
    public:
    GUIMyFrame1( wxWindow* parent );
    ~GUIMyFrame1();
	wxBitmap bitmapexif;
	wxBitmap bitmapphoto;
	std::vector<wxImage> images;
	wxString s;
	wxString path;
	wxString dire;
	bool exp=false;
};


