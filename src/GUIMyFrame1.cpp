#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent ): MyFrame1( parent ){wxInitAllImageHandlers();}

GUIMyFrame1::~GUIMyFrame1() {}

void GUIMyFrame1::MainFormClose( wxCloseEvent& event ) { Destroy(); }

void GUIMyFrame1::WxPanel_Repaint( wxUpdateUIEvent& event ) { Repaint(); }

void GUIMyFrame1::Repaint() {
    wxClientDC dc1(WxPanel);
    wxClientDC dc2(WxPanel1);
    wxBufferedDC bdc1(&dc1);
    wxBufferedDC bdc2(&dc2);
    bdc1.Clear();
    bdc2.Clear();
    DrawBitmap(bdc1);
    DrawExifAndIptc(bdc2);
}

void GUIMyFrame1::DrawExifAndIptc(wxDC& dc) {
    bitmapexif.Create(this->WxPanel1->GetSize().GetWidth(), this->WxPanel1->GetSize().GetHeight());
    wxMemoryDC dc1(bitmapexif);
    dc1.SetBackground(*wxWHITE_BRUSH);
    dc1.Clear();
    dc1.SetTextForeground(*wxBLACK);
    dc1.DrawText(s, 0, 0);
    dc1.SelectObject(wxNullBitmap);
    dc.DrawBitmap(bitmapexif, 0, 0, true);
}

void GUIMyFrame1::DrawBitmap(wxDC& dc) {
    bitmapphoto.Create(this->WxPanel->GetSize().GetWidth(), this->WxPanel->GetSize().GetHeight());
    wxMemoryDC dc1(bitmapphoto);
    dc1.SetBackground(*wxWHITE_BRUSH);
    dc1.Clear();
    if (exp==false) {
        int i = 0, j = 0;
        for (const auto& img : images) {
            wxBitmap bitmap(img);
            wxMemoryDC dc1(bitmapphoto);
            dc1.DrawBitmap(bitmap, i,j, true);
            dc1.SelectObject(wxNullBitmap);
            dc1.DrawBitmap(bitmapphoto, i, j, true);
            if (i + 2*bitmap.GetWidth() > this->WxPanel->GetSize().GetWidth()) {
                i = 0;
                j += bitmap.GetHeight();
            }
            else {
                i += bitmap.GetWidth();
            }
        }
    }
    else {
        wxBitmap bitmap(images.back());
        wxMemoryDC dc1(bitmapphoto);
        dc1.DrawBitmap(bitmap, 0, 0, true);
    }
    dc1.SelectObject(wxNullBitmap);
    dc.DrawBitmap(bitmapphoto, 0, 0, true);
}

void GUIMyFrame1::AddExif(wxString & filename){
    std::ifstream file2(filename.mb_str(), std::ios::binary);
    std::stringstream ss;
    TinyEXIF::EXIFInfo imageEXIF(file2);
    if (imageEXIF.Fields) {
        ss << "Date Taken " << imageEXIF.DateTimeOriginal << std::endl
        << "Camera Model " << imageEXIF.Make << " - " << imageEXIF.Model << std::endl
        << "Focal Length " << imageEXIF.FocalLength << " mm" << std::endl
        << "Aperture " << imageEXIF.ApertureValue << std::endl
        << "Exposure Time " << imageEXIF.ExposureTime << std::endl
        << "ISO " << imageEXIF.ISOSpeedRatings << std::endl
        << "Software " << imageEXIF.Software << std::endl
        << "Bits Per Sample " << imageEXIF.BitsPerSample << std::endl
        << "Exposure Bias " << imageEXIF.ExposureBiasValue << std::endl
        << "Flash " << imageEXIF.Flash << std::endl
        << "Metering Mode " << imageEXIF.MeteringMode << std::endl
        << "X Resolution " << imageEXIF.XResolution << std::endl
        << "Y Resolution " << imageEXIF.YResolution << std::endl
        << "Orientation " << imageEXIF.Orientation << std::endl
        << "Exposure Program " << imageEXIF.ExposureProgram << std::endl
        << "Light Source " << imageEXIF.LightSource << std::endl
        << "GPS Latitude " << imageEXIF.GeoLocation.Latitude << std::endl
        << "GPS Longitude " << imageEXIF.GeoLocation.Longitude << std::endl
        << "GPS Altitude " << imageEXIF.GeoLocation.Altitude << std::endl;
    }
    else
        ss << "No EXIF information in this image." << std::endl;
    file2.close();
    s=wxString(ss.str());
}

void GUIMyFrame1::m_button1_click( wxCommandEvent& event ) {

    images.clear();
    wxDirDialog dir_path(this,"Choose directory", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
    dir_path.ShowModal();
    
    wxDir dir(dir_path.GetPath().mb_str());
    dire = dir_path.GetPath().mb_str();
    if (!dir.IsOpened()) {
        std::cout << "Cannot open the directory!" << std::endl;
        return;
    }
    wxString filename;
    bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);

    while (cont) {
        wxImage image(dir_path.GetPath() + "\\" + filename,wxBITMAP_TYPE_JPEG);
        path.push_back(dir_path.GetPath() + "\\" + filename);
        image.Rescale(100,100);
        images.push_back(image);
        cont = dir.GetNext(&filename);
    }
    Repaint();
}

void GUIMyFrame1::m_button2_click( wxCommandEvent& event ) { 
    if (images.size() > 0) {
        std::ofstream file("exif.txt", std::ios::binary);   
        std::stringstream ss;
        wxDir dir(dire);
        wxString filename;
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);
        while (cont) {
            std::string command = "iptcprint.exe " + std::string((dire + "\\" + filename).ToUTF8().data()) + " >> iptc.txt";
            //std::cout << command;
            system(command.c_str());
            std::ifstream file2((dire + "\\" + filename).mb_str(), std::ios::binary);
            TinyEXIF::EXIFInfo imageEXIF(file2);
            if (imageEXIF.Fields) {
                ss << "Image Description " << imageEXIF.ImageDescription << std::endl
                    << "Image Resolution " << imageEXIF.ImageWidth << "x" << imageEXIF.ImageHeight << " pixels" << std::endl
                    << "Date Taken " << imageEXIF.DateTimeOriginal << std::endl
                    << "Camera Model " << imageEXIF.Make << " - " << imageEXIF.Model << std::endl
                    << "Focal Length " << imageEXIF.FocalLength << " mm" << std::endl
                    << "Aperture " << imageEXIF.ApertureValue << std::endl
                    << "Exposure Time " << imageEXIF.ExposureTime << std::endl
                    << "ISO " << imageEXIF.ISOSpeedRatings << std::endl
                    << "Software " << imageEXIF.Software << std::endl
                    << "Bits Per Sample " << imageEXIF.BitsPerSample << std::endl
                    << "Exposure Bias " << imageEXIF.ExposureBiasValue << std::endl
                    << "Flash " << imageEXIF.Flash << std::endl
                    << "Metering Mode " << imageEXIF.MeteringMode << std::endl
                    << "X Resolution " << imageEXIF.XResolution << std::endl
                    << "Y Resolution " << imageEXIF.YResolution << std::endl
                    << "Orientation " << imageEXIF.Orientation << std::endl
                    << "Exposure Program " << imageEXIF.ExposureProgram << std::endl
                    << "Light Source " << imageEXIF.LightSource << std::endl
                    << "GPS Latitude " << imageEXIF.GeoLocation.Latitude << std::endl
                    << "GPS Longitude " << imageEXIF.GeoLocation.Longitude << std::endl
                    << "GPS Altitude " << imageEXIF.GeoLocation.Altitude << std::endl;
            }
            else
                ss << "No EXIF and IPTC information in this image." << std::endl;

            file2.close();

            file << filename.mb_str() << std::endl << ss.str() << std::endl;

            ss.str("");
            ss.clear();
            cont = dir.GetNext(&filename);
        }
        file.close();
    }
}

void GUIMyFrame1::m_button3_click( wxCommandEvent& event ) {
    if (images.size() > 0) {
        wxDir dir(dire);
        wxString filename;
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);
        while (cont) {
            std::ifstream file2((dire + "\\" + filename).mb_str(), std::ios::binary);
            TinyEXIF::EXIFInfo imageEXIF(file2);
            std::stringstream ss;
            wxString nazwachanged = filename;
            nazwachanged.Replace(".jpg", "changed.jpg");
            if (imageEXIF.Fields) {
                ss << "Date Taken " << imageEXIF.DateTimeOriginal << std::endl
                << "Camera Model " << imageEXIF.Make << " - " << imageEXIF.Model << "\n";
            }
            else {
                ss << "No EXIF information in this image." << std::endl;
            }
            wxImage image(dire + "\\" + filename, wxBITMAP_TYPE_JPEG);
            wxBitmap bitmap(image);
            wxMemoryDC dc(bitmap);
            dc.SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
            dc.SetTextForeground(*wxWHITE);
            dc.DrawText(ss.str(), 0, 0);
            image = bitmap.ConvertToImage();
            image.SaveFile(dire + nazwachanged);
            file2.close();
            cont = dir.GetNext(&filename);
        }
    }
}

void GUIMyFrame1::m_button4_click( wxCommandEvent& event ) {
    if (images.size() > 0) {
        std::ifstream file("loader.txt", std::ios::binary);
        std::stringstream ss;
        std::string line;
        std::string comment;
        std::string name;
        wxDir dir(dire);
        wxString filename;
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);
        while (cont) {
            std::getline(file, line);
            name = line;
            std::getline(file, line);
            comment = line;
            std::getline(file, line);
            wxImage image(dire + "\\" + filename, wxBITMAP_TYPE_JPEG);
            wxBitmap bitmap(image);
            wxMemoryDC dc(bitmap);
            dc.SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
            dc.SetTextForeground(*wxWHITE);
            dc.DrawText(name, 0, 0);
            dc.DrawText(comment, 0, 20);
            image = bitmap.ConvertToImage();
            name = name.substr(0, name.size() - 4);
            name += "comment.jpg";
            image.SaveFile(dire + name);
            cont = dir.GetNext(&filename);
        }
        Repaint();
    }
}

void GUIMyFrame1::m_panel_2lclick( wxMouseEvent& event ) {
    if (images.size() > 0) {
        if (exp == false) {
            exp = true;
            wxPoint pos=event.GetPosition();
            size_t final_index=0;
            int x_coord=pos.x/100;
            int y_coord=pos.y/100;
            for(unsigned i=0;i<=this->WxPanel->GetSize().GetWidth()/100;i++){
                for(unsigned j=0;j<=this->WxPanel->GetSize().GetHeight()/100;j++){
                    if(i==x_coord && j==y_coord){
                        final_index=i+j*(this->WxPanel->GetSize().GetWidth()/100);
                        break;
                    }
                }
            }
           
            wxImage image(path[final_index], wxBITMAP_TYPE_JPEG);
            image.Rescale(this->WxPanel->GetSize().GetWidth(), this->WxPanel->GetSize().GetHeight());
            images.push_back(image);
            AddExifAndIptc(path[final_index]);
        }
        Repaint();
    }
}

void GUIMyFrame1::m_panel_1lclick( wxMouseEvent& event ) {
    if (images.size() > 0) {
        if (exp == true) {
            exp = false;
            images.pop_back();
        }
        Repaint();
    }
}

void GUIMyFrame1::AddExifAndIptc(wxString & filename){
    std::string command = "iptcprint.exe " + std::string(filename.ToUTF8().data()) + " >> iptcinfo.txt";
    system(command.c_str());
    std::ifstream file2(filename.mb_str(), std::ios::binary);
    std::stringstream ss;
    TinyEXIF::EXIFInfo imageEXIF(file2);
    if (imageEXIF.Fields) {
        ss << "EXIF metadata" << "\n";
        ss << "Date Taken " << imageEXIF.DateTimeOriginal << std::endl
        << "Camera Model " << imageEXIF.Make << " - " << imageEXIF.Model << std::endl
        << "Focal Length " << imageEXIF.FocalLength << " mm" << std::endl
        << "Aperture " << imageEXIF.ApertureValue << std::endl
        << "Exposure Time " << imageEXIF.ExposureTime << std::endl
        << "ISO " << imageEXIF.ISOSpeedRatings << std::endl
        << "Software " << imageEXIF.Software << std::endl
        << "Bits Per Sample " << imageEXIF.BitsPerSample << std::endl
        << "Exposure Bias " << imageEXIF.ExposureBiasValue << std::endl
        << "Flash " << imageEXIF.Flash << std::endl
        << "Metering Mode " << imageEXIF.MeteringMode << std::endl
        << "X Resolution " << imageEXIF.XResolution << std::endl
        << "Y Resolution " << imageEXIF.YResolution << std::endl
        << "Orientation " << imageEXIF.Orientation << std::endl
        << "Exposure Program " << imageEXIF.ExposureProgram << std::endl
        << "Light Source " << imageEXIF.LightSource << std::endl
        << "GPS Latitude " << imageEXIF.GeoLocation.Latitude << std::endl
        << "GPS Longitude " << imageEXIF.GeoLocation.Longitude << std::endl
        << "GPS Altitude " << imageEXIF.GeoLocation.Altitude << std::endl;
    }
    else
        ss << "No EXIF information in this image." << std::endl;
    file2.close();
    std::string str = "Caught";
    int count=0;
    std::ifstream file3("iptcinfo.txt");
    if(file3.is_open()){
        int x=0;
        std::string line;
        while(std::getline(file3,line)){

            for(unsigned i=0;i<str.length();i++){

                if (str[i]!=line[i]){
                    count=1;
                    break;
                }
            }
            if(count==0){
                ss << "No IPTC metada found in the picture\n";
                break;
            }
            else{
                if(x==0){
                    ss << "IPTC metadata" << "\n";
                    x=1;
                }
                
                for(unsigned i=18;i<40;i++){
                    ss << line[i];
                }
                for(unsigned i=67;i<line.length();i++){
                    ss << line[i];
                }
                    ss << "\n";   
            }
            
        }
           
    }
    else
        ss << "Cannot open file" << "\n";
    file3.close();
    system("del iptcinfo.txt");
    s=wxString(ss.str());
}

