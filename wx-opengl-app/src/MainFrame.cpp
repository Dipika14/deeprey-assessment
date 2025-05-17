#include "MainFrame.h"
#include "OpenGLCanvas.h"
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(900, 700))
{
    //Creating a control panel with a slider and a checkbox
    wxPanel* controlPanel = new wxPanel(this);
    wxSlider* slider = new wxSlider(controlPanel, wxID_ANY, 0, 0, 360, wxDefaultPosition, wxSize(200, -1));
    wxCheckBox* checkbox = new wxCheckBox(controlPanel, wxID_ANY, "Wireframe Mode");

    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(slider, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    panelSizer->Add(checkbox, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    controlPanel->SetSizer(panelSizer);

    OpenGLCanvas* canvas = new OpenGLCanvas(this);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(controlPanel, 0, wxEXPAND);
    mainSizer->Add(canvas, 1, wxEXPAND);

    SetSizer(mainSizer);
    Layout();

    // Pass controls to canvas for interaction
    canvas->SetSlider(slider);
    canvas->SetCheckBox(checkbox);
    canvas->SetControlPanel(controlPanel);
    controlPanel->Hide(); 
}