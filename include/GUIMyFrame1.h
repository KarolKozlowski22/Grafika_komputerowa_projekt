#pragma once
#include "GUI.h"
#include "TinyEXIF.h"
#include <iostream>
#include <fstream>
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
		void Repaint();
    public:
    GUIMyFrame1( wxWindow* parent );
    ~GUIMyFrame1();
	std::vector<TinyEXIF::EXIFInfo> exif;
};


