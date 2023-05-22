///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-282-g1fa54006)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 600,400 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	WxPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	WxPanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	bSizer1->Add( WxPanel, 1, wxEXPAND | wxALL, 5 );

	WxPanel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	WxPanel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	bSizer1->Add( WxPanel1, 1, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_button1 = new wxButton( this, wxID_ANY, _("Wybierz folder"), wxDefaultPosition, wxDefaultSize, 0 );
	//bSizer9->Add( m_button1, 0, wxALL, 5 );

	bSizer2->Add( m_button1, 1, wxEXPAND, 5 );//

	m_button2 = new wxButton( this, wxID_ANY, _("Zapisz dane exif"), wxDefaultPosition, wxDefaultSize, 0 );
	//bSizer9->Add( m_button2, 0, wxALL, 5 );

	bSizer2->Add( m_button2, 1, wxEXPAND, 5 );//

	bSizer2->Add( bSizer9, 1, wxALIGN_CENTER|wxALL, 5 );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxHORIZONTAL );

	m_button3 = new wxButton( this, wxID_ANY, _("Wczytaj dane na zdjecie"), wxDefaultPosition, wxDefaultSize, 0 );
	//bSizer91->Add( m_button3, 0, wxALL, 10 );

	bSizer2->Add( m_button3, 1, wxEXPAND, 5 );//

	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxHORIZONTAL );

	m_button4 = new wxButton( this, wxID_ANY, _("Wczytaj komentarze na zdjecia"), wxDefaultPosition, wxDefaultSize, 0 );
	//bSizer92->Add( m_button4, 0, wxALL, 10 );

	bSizer2->Add( m_button4, 1, wxEXPAND, 5 );//

	bSizer2->Add( bSizer91, 1, wxEXPAND, 5 );

	bSizer2->Add( bSizer92, 1, wxEXPAND, 5 );

	bSizer1->Add( bSizer2, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::MainFormClose ) );
	WxPanel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	WxPanel1->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button1_click ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button2_click ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button3_click ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button4_click ), NULL, this );
	WxPanel->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame1::m_panel_2lclick ), NULL, this );
	WxPanel->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame1::m_panel_1lclick ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::MainFormClose ) );
	WxPanel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	WxPanel1->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button1_click ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button2_click ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button3_click ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button4_click ), NULL, this );
	WxPanel->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame1::m_panel_2lclick ), NULL, this );
	WxPanel->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame1::m_panel_1lclick ), NULL, this );
}
