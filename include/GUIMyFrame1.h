#pragma once
#include "GUI.h"
#include "TinyEXIF.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <wx/dcbuffer.h>
#include <wx/dir.h>
#include <wx/dirdlg.h>

class GUIMyFrame1 : public MyFrame1
{
	// wxBitmap variables hold the image and the exif data
	wxBitmap bitmapexif,bitmapphoto;
	// vector holds the exif data
	std::vector<wxImage> images;
	// s holds exif data, dire holds the path to the directory
	wxString s,dire;
	// path holds the path to the image
	std::vector<wxString> path;
	// bool variable checks if the image is full screen
	bool exp=false;
	
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
		// void method adds exif data
		void AddExif(wxString & filename);

    public:
    	GUIMyFrame1( wxWindow* parent );
    	~GUIMyFrame1();
};