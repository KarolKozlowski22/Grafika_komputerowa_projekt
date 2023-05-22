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
		// void method destroys all the objects in the vector
		void MainFormClose( wxCloseEvent& event );
		// void method repaints the panel
		void WxPanel_Repaint( wxUpdateUIEvent& event );
		// void method loads the image
		void m_button1_click( wxCommandEvent& event );
		// void method saves the image
		void m_button2_click( wxCommandEvent& event );
		// void method loads the exif data
		void m_button3_click( wxCommandEvent& event );
		// void method loads the comments
		void m_button4_click( wxCommandEvent& event );
		// void method makes image full screen
		void m_panel_2lclick( wxMouseEvent& event );
		// void method makes image back to normal size
		void m_panel_1lclick( wxMouseEvent& event );
		// void method draws the exif data
		void DrawExif(wxDC& dc);
		// void method draws the image
		void DrawBitmap(wxDC& dc);
		// void method repaints
		void Repaint();

    public:

    	GUIMyFrame1( wxWindow* parent );
    	~GUIMyFrame1();

		wxBitmap bitmapexif,bitmapphoto;
		std::vector<wxImage> images;
		wxString s,path,dire;
		bool exp=false;
};


