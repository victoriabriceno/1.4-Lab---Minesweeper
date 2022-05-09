#pragma once
#include "wx/wx.h"
class MainWindow : public wxFrame
{
public:
	MainWindow();
	~MainWindow();
public:
	int fieldWidth = 10;
	int fieldHeight = 10;
	wxButton** button1;
	int* field = nullptr;
	bool click1 = true;

	void ButtonClicked(wxCommandEvent &event);

	wxDECLARE_EVENT_TABLE();

};

