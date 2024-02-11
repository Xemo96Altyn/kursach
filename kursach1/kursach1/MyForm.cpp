#include "MyForm.h"

using namespace System::Collections::Generic;
using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::SetUnhandledExceptionMode(UnhandledExceptionMode::CatchException);
	kursach1::MyForm form;

	Application::Run(% form);
}