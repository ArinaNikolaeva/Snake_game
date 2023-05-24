#include "SplashScreen.h"
#include "SnakeForm.h"
#include "Accounts.h"
#include "MenuForm.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

void main() {
	// Базовые настройки для запуска формы
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Game::SplashScreen splashscreen;

	Application::Run(% splashscreen);


}