#include "SplashScreen.h"
#include "SnakeForm.h"
#include "Accounts.h"
#include "MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;

int a = 0;


void Game::SplashScreen::SplashScreen_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { // ������� ��������
	if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Space)
		a = 2;
}
void Game::SplashScreen::timer_Tick(System::Object^ sender, System::EventArgs^ e) //����� ������� ����� ������������ ����
{
	if (a == 2) {
		// C�������� �����
		auto accounts = gcnew Game::Accounts;
		accounts->Show(); //���������� �����������
		this->Hide(); //������

		timer->Stop();

	}
	a++;
}



