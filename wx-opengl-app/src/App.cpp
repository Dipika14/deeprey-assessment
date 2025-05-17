#include "App.h"
#include "MainFrame.h"

bool App::OnInit() {
    MainFrame* frame = new MainFrame("wxWidgets OpenGL Application");
    frame->Show(true);
    return true;
}

int App::OnExit() {
    return 0;
}