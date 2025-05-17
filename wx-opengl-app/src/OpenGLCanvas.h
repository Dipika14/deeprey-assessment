#include <wx/glcanvas.h>
#include <wx/bmpbuttn.h>
#include <wx/slider.h>
#include <wx/checkbox.h>

class OpenGLCanvas : public wxGLCanvas {
public:
    OpenGLCanvas(wxWindow* parent);
    ~OpenGLCanvas();
    void InitializeOpenGL();
    void Render();

    void SetSlider(wxSlider* slider);
    void SetCheckBox(wxCheckBox* checkbox);
    void SetControlPanel(wxWindow* panel) { m_controlPanel = panel; }

protected:
    void OnPaint(wxPaintEvent& event);
    void OnResize(wxSizeEvent& event);
    void OnButtonClick(wxCommandEvent& event);
    void OnSlider(wxCommandEvent& event);
    void OnCheckBox(wxCommandEvent& event);

private:
    wxGLContext* m_context;
    wxBitmapButton* m_button;
    wxSlider* m_slider = nullptr;
    wxCheckBox* m_checkbox = nullptr;
    wxWindow* m_controlPanel = nullptr; 
    float m_angle = 0.0f;
    bool m_wireframe = false;
};