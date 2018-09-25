//
// Created by ren on 24.9.2018.
//

#ifndef PROGRESSBARLAB_VIEW_H
#define PROGRESSBARLAB_VIEW_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/progdlg.h>
#include "Observer.h"
#include "Model.h"
#include "ScrolledPanel.h"
#endif

class View: public Observer, public wxFrame {
public:
    View(Model* model, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    ~View(){
        delete[] myModel;
        delete[] progressBar;
    }
    virtual void update(int i) override;
    void readFiles();
private:
    Model* myModel;
    wxProgressDialog* progressBar;
    ScrolledPanel* leftText;
    ScrolledPanel* rightText;
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};


#endif //PROGRESSBARLAB_VIEW_H
