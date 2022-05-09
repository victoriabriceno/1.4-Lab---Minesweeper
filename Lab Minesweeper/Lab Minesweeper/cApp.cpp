#include "cApp.h"

wxIMPLEMENT_APP(cApp);
cApp::cApp() {

}

cApp::~cApp() {


}

bool cApp::OnInit() {

	mainWindow = new MainWindow();
	mainWindow->Show();
	return true;
}
