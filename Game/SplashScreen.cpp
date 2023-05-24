#include "SplashScreen.h"
#include "SnakeForm.h"
#include "Accounts.h"
#include "MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;

int a = 0;


void Game::SplashScreen::SplashScreen_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { // Пропуск заставки
	if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Space)
		a = 2;
}
void Game::SplashScreen::timer_Tick(System::Object^ sender, System::EventArgs^ e) //время которое будет показываться игра
{
	if (a == 2) {
		// Cледующей формы
		auto accounts = gcnew Game::Accounts;
		accounts->Show(); //показываем авторизацию
		this->Hide(); //прячем

		timer->Stop();

	}
	a++;
}



