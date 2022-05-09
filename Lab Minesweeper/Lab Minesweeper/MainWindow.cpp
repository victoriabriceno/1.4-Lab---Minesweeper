#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)

wxEND_EVENT_TABLE()
MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(30, 30), wxSize(800, 600)) {

	button1 = new wxButton * [fieldWidth * fieldHeight];
	wxGridSizer* gridSize = new wxGridSizer(fieldWidth, fieldHeight, 0, 0);

	field = new int[fieldWidth * fieldHeight];
	wxFont font(24,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);

	for (int x = 0; x < fieldWidth; x++)
	{
		for (int y = 0; y < fieldHeight; y++)
		{
			button1[y * fieldWidth + x] = new wxButton(this, 10000 + (y * fieldWidth + x));
			button1[y * fieldWidth + x]->SetFont(font);
			gridSize->Add(button1[y * fieldWidth + x], 1, wxEXPAND | wxALL);

			button1[y * fieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainWindow::ButtonClicked, this);
			field[y * fieldWidth + x] = 0;
		}
	}
	this->SetSizer(gridSize);
	gridSize->Layout();

}

MainWindow::~MainWindow() {
	delete[]button1;
}

void MainWindow::ButtonClicked(wxCommandEvent& event) {


	//Get coordinate of button in field array
	int x = (event.GetId() - 10000) % fieldWidth;
	int y = (event.GetId() - 10000) / fieldWidth;

	if (click1)
	{
		int mines = 30;

		while (mines)
		{
			int rx = rand() % fieldWidth;
			int ry = rand() % fieldHeight;

			if (field[ry * fieldWidth + rx] == 0 && rx != x && ry != y)
			{
				field[ry * fieldWidth + rx] = -1;
				mines--;
			}
		}
		click1 = false;
	}
	//Disable Button , preventing it being pressed again

	button1[y * fieldWidth + x]->Enable(false);

	//Check if player hit mine

	if (field[y * fieldWidth + x] == -1)
	{
		wxMessageBox("BOOM!! - You Lost! : (");

		//Reset Game 

		click1 = true;
		for (int x = 0; x < fieldWidth; x++)
		{
			for (int y = 0; y < fieldHeight; y++)
			{
				field[y * fieldWidth + x] = 0;
				button1[y * fieldWidth + x]->SetLabel("");
				button1[y * fieldWidth + x]->Enable(true);
			}
		}
	}
	else
	{
		//Count neighbouring mines

		int mineCount = 0;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < fieldWidth && y + j >= 0 && y + j < fieldHeight)
				{
					if (field[(y + j) * fieldWidth + (x + i)] == -1)
					{
						mineCount++;
					}
				}
			}
		}
		if (mineCount > 0 )
		{
			button1[y * fieldWidth + x]->SetLabel(std::to_string(mineCount));
		}
	}
	event.Skip();

}