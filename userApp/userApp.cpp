#include "MainForm.h"
#include "RegisterForm.h"
#include "LoginForm.h"
#include <cstdlib>
#include "../src/include/datatypes.h"
#include "../src/include/dbase.h"
//TODO: Translate everything to serbian
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ argv)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and display the main form

    checkDBase();

    userApp::MainForm form;
    Application::Run(% form);

    
}