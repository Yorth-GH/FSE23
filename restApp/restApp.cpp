
#include "MainForm.h"
#include "RegisterForm.h"
#include "LoginForm.h"
#include <cstdlib>
#include <thread>
#include <windows.h>
#include "../src/include/datatypes.h"
#include "../src/include/dbase.h"
//TODO: Translate everything to serbian
using namespace System;
using namespace System::Windows::Forms;

void t1()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and display the main form

    checkDBase();

    restApp::MainForm form;
    Application::Run(% form);
}

void t2()
{
    while (getActiveUser() == "")
        Sleep(100);

    if (getRestOrders(getActiveUser()) != 0)
        MessageBox::Show("Imate neobradjene narudzbe!\nMolimo provjerite narudzbe.", "Narudzba", MessageBoxButtons::OK, MessageBoxIcon::Information);

    int orders = getRestOrders(getActiveUser());

    while (true)
    {
        if (getRestOrders(getActiveUser()) > orders)
        {
            MessageBox::Show("Imate novu narudzbu!\nMolimo provjerite narudzbe.", "Narudzba", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        orders = getRestOrders(getActiveUser());
        
        Sleep(100);
    }
}

[STAThreadAttribute]
void main(array<String^>^ argv)
{
    std::thread thread1(t1);
    std::thread thread2(t2);

    thread1.join();
    thread2.join();
}