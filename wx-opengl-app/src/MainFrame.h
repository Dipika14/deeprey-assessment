#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/glcanvas.h>

class OpenGLCanvas; // Forward declaration

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

private:
    void CreateOpenGLCanvas();
    void OnClose(wxCloseEvent& event);

    OpenGLCanvas* m_canvas;
};

#endif // MAINFRAME_H