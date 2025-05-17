#include "OpenGLCanvas.h"
#include <wx/glcanvas.h>
#include <OpenGL/gl.h>
#include <wx/image.h>
#include <wx/dcclient.h>
#include <wx/msgdlg.h> 


OpenGLCanvas::OpenGLCanvas(wxWindow* parent)
    : wxGLCanvas(parent, wxID_ANY, nullptr, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
{
    m_context = new wxGLContext(this);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &OpenGLCanvas::OnPaint, this);
    Bind(wxEVT_SIZE, &OpenGLCanvas::OnResize, this);

    wxInitAllImageHandlers();
    wxBitmap bmp(wxT("../images/button.png"), wxBITMAP_TYPE_PNG);
    
    m_button = new wxBitmapButton(this, wxID_ANY, bmp, wxPoint(20, 20), wxSize(100, 100));
    m_button->Bind(wxEVT_BUTTON, &OpenGLCanvas::OnButtonClick, this);
}

void OpenGLCanvas::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    SetCurrent(*m_context);
    Render();
    SwapBuffers();
}

void OpenGLCanvas::OnResize(wxSizeEvent& event)
{
    SetCurrent(*m_context);
    glViewport(0, 0, GetSize().GetWidth(), GetSize().GetHeight());
    int w = GetSize().GetWidth();
    m_button->SetPosition(wxPoint(w - 120, 20));
    event.Skip();
}

void OpenGLCanvas::SetSlider(wxSlider* slider) {
    m_slider = slider;
    if (m_slider)
        m_slider->Bind(wxEVT_SLIDER, &OpenGLCanvas::OnSlider, this);
}

void OpenGLCanvas::SetCheckBox(wxCheckBox* checkbox) {
    m_checkbox = checkbox;
    if (m_checkbox)
        m_checkbox->Bind(wxEVT_CHECKBOX, &OpenGLCanvas::OnCheckBox, this);
}

void OpenGLCanvas::OnSlider(wxCommandEvent& event) {
    if (m_slider)
        m_angle = m_slider->GetValue();
    Refresh();
}

void OpenGLCanvas::OnCheckBox(wxCommandEvent& event) {
    if (m_checkbox)
        m_wireframe = m_checkbox->GetValue();
    Refresh();
}

void OpenGLCanvas::Render()
{
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = GetSize().GetWidth();
    int h = GetSize().GetHeight();
    glOrtho(0, w, h, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(w/2, h/2, 0);
    glRotatef(m_angle, 0, 0, 1);
    glTranslatef(-w/2, -h/2, 0);

    glPolygonMode(GL_FRONT_AND_BACK, m_wireframe ? GL_LINE : GL_FILL);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(w * 0.2f, h * 0.2f);
        glVertex2f(w * 0.8f, h * 0.2f);
        glVertex2f(w * 0.5f, h * 0.7f);
    glEnd();

    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void OpenGLCanvas::InitializeOpenGL() {
    
}

void OpenGLCanvas::OnButtonClick(wxCommandEvent& event)
{
    wxMessageBox("Button clicked! Toggling Panel", "Info", wxOK | wxICON_INFORMATION, this);
    if (m_controlPanel) {
        m_controlPanel->Show(!m_controlPanel->IsShown());
        m_controlPanel->GetParent()->Layout(); // Refresh layout
    }
}

OpenGLCanvas::~OpenGLCanvas() {
    if (m_context) {
        delete m_context;
        m_context = nullptr;
    }
}