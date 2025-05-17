#ifndef APP_H
#define APP_H

#include <wx/wx.h>

class App : public wxApp
{
public:
    virtual bool OnInit();
    virtual int OnExit();
};

#endif // APP_H