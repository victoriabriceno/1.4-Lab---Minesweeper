#pragma once
#include "wx/wx.h"
#include "MainWindow.h"
class cApp:public wxApp
{
public:	
	cApp();
	~cApp();
private:
	MainWindow* mainWindow = nullptr;

public:
	virtual bool OnInit();
};

