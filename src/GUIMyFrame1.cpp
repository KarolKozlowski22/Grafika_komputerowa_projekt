#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent ): MyFrame1( parent ){}

GUIMyFrame1::~GUIMyFrame1() {}

void GUIMyFrame1::Repaint() {
    wxClientDC dc1(WxPanel);
    wxClientDC dc2(WxPanel1);
    wxBufferedDC bdc1(&dc1);
    wxBufferedDC bdc2(&dc2);
    bdc1.Clear();
    bdc2.Clear();
    DrawBitmap(bdc1);
    DrawExif(bdc2);
}

void GUIMyFrame1::DrawExif(wxDC& dc) {
    dc.DrawBitmap(bitmapexif, 0, 0, true);
}

void GUIMyFrame1::DrawBitmap(wxDC& dc) {
    dc.DrawBitmap(bitmapphoto, 0, 0, true);
}

void GUIMyFrame1::MainFormClose( wxCloseEvent& event ) { Destroy(); }
void GUIMyFrame1::WxPanel_Repaint( wxUpdateUIEvent& event ) { Repaint(); }
void GUIMyFrame1::m_button1_click( wxCommandEvent& event ) {
    wxFileDialog WxOpenFileDialog(this, _("Choose a file"), _(""), _(""), _("jpg files (*.jpg)|*.jpg"), wxFD_OPEN);
    WxOpenFileDialog.ShowModal();
    std::cout<<WxOpenFileDialog.GetDirectory()<<std::endl;
    std::ifstream file(WxOpenFileDialog.GetPath().mb_str(), std::ios::binary);
    TinyEXIF::EXIFInfo imageEXIF(file);  
    if (imageEXIF.Fields)
        std::cout
            << "Image Description " << imageEXIF.ImageDescription << "\n"
            << "Image Resolution " << imageEXIF.ImageWidth << "x" << imageEXIF.ImageHeight << " pixels\n"
            << "Camera Model " << imageEXIF.Make << " - " << imageEXIF.Model << "\n"
            << "Focal Length " << imageEXIF.FocalLength << " mm" << std::endl
            << "Aperture " << imageEXIF.ApertureValue << std::endl
            << "Exposure Time " << imageEXIF.ExposureTime << std::endl
            << "ISO " << imageEXIF.ISOSpeedRatings << std::endl
            << "Date Taken " << imageEXIF.DateTimeOriginal << std::endl
            << "Software " << imageEXIF.Software << std::endl
            << "Bits Per Sample " << imageEXIF.BitsPerSample << std::endl
            << "Exposure Bias " << imageEXIF.ExposureBiasValue << std::endl
            << "Flash " << imageEXIF.Flash << std::endl
            << "Metering Mode " << imageEXIF.MeteringMode << std::endl
            << "X Resolution " << imageEXIF.XResolution << std::endl
            << "Y Resolution " << imageEXIF.YResolution << std::endl
            << "Orientation " << imageEXIF.Orientation << std::endl;
    else
        std::cout << "No EXIF information in this image." << std::endl;
    file.close();
}
void GUIMyFrame1::m_button2_click( wxCommandEvent& event ) { Repaint(); }
void GUIMyFrame1::m_button3_click( wxCommandEvent& event ) { Repaint(); }