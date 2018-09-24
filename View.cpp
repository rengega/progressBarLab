//
// Created by ren on 24.9.2018.
//

#include "View.h"

View::View(Model *model, const wxString &title, const wxPoint &pos, const wxSize &size, long style)
        : wxFrame( NULL, wxID_ANY, title, pos, size, style ){
    myModel = model;
    myModel->addObserver(this);

    progressBar = new wxProgressDialog(wxT("Loading files"), wxT("Wait..."), myModel->getFilesSize(), this, wxPD_AUTO_HIDE | wxPD_APP_MODAL);



    wxMenu *menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "nel mezzo del camin di nostra vita..." );



    this->Centre(wxBOTH);
}

void View::update(int i) {
    wxString totSize = wxString::Format(wxT("%i"),myModel->getFilesSize());
    wxString loaded = wxString::Format(wxT("%i"),i);
    progressBar->Update(i, wxT("Loaded ") + loaded + wxT(" of ") + totSize + wxT(" bytes"));

}


void View::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void View::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Questa e' una parafrasi della divina commedia",
                 "Dante Alighieri", wxOK | wxICON_INFORMATION);

}