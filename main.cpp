#include <iostream>
#include "Model.h"
#include "View.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp:public wxApp{
public:
    virtual bool OnInit();
};

wxBEGIN_EVENT_TABLE(View, wxFrame)
                EVT_MENU(wxID_EXIT,  View::OnExit)
                EVT_MENU(wxID_ABOUT, View::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    Model* myModel;
    myModel = new Model;

    myModel->addFile("/home/ren/CLionProjects/untitled/res/text1");
    myModel->addFile("/home/ren/CLionProjects/untitled/res/text1.1");

    View* frame = new View(myModel,("LA DIVINA COMMEDIA"), wxPoint(50,50), wxSize(950,650));
    myModel->loadFiles();
    frame->Show(true);
    return true;
}
