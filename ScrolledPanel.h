//
// Created by ren on 25.9.2018.
//

#ifndef PROGRESSBARLAB_SCROLLEDPANEL_H
#define PROGRESSBARLAB_SCROLLEDPANEL_H


#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/stattext.h>

class ScrolledPanel: public wxScrolledWindow{
public:
    ScrolledPanel(wxWindow* parent, wxWindowID id) : wxScrolledWindow(parent, id)
    {
        // the sizer will take care of determining the needed scroll size
        // (if you don't use sizers you will need to manually set the viewport size)
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        // add a series of widgets
        textBox = new wxStaticText(this, wxID_ANY, wxT(""), wxPoint(10,10));
        sizer->Add(textBox, 1, wxALIGN_CENTER_HORIZONTAL, wxALL);

        this->SetSizer(sizer);

        // this part makes the scrollbars show up
        this->FitInside(); // ask the sizer about the needed size
        this->SetScrollRate(5, 5);
    }

    void changeLabel(wxString label){
        textBox->SetLabel(label);

    }
private:
    wxStaticText* textBox;
};

#endif //PROGRESSBARLAB_SCROLLEDPANEL_H
