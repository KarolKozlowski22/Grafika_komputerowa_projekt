#pragma once
#include <wx/panel.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/sizer.h>
#include <wx/frame.h>

class MyFrame1 : public wxFrame
{
	protected:
		wxPanel* WxPanel;
		wxPanel* WxPanel1;
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;

		// Virtual event handlers, override them in your derived class
		virtual void MainFormClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void WxPanel_Repaint( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_button1_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button2_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button3_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button4_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_panel_2lclick( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_panel_1lclick( wxMouseEvent& event ) { event.Skip(); }

	public:
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Napisy na zdjeciach"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MyFrame1();
};