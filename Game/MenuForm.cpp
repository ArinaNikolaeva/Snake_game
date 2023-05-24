#include "MenuForm.h"
#include "Accounts.h"
#include "SnakeForm.h"

using namespace System;
using namespace System::Windows::Forms;


void Game::MenuForm::MenuForm_Load(System::Object^ sender, System::EventArgs^ e)// имя пользователя и приветствие
{
    toolStripLabel->Text = "Привет, \"" + Accounts::currUs->log + "\"! Хорошей игры!";
}


void Game::MenuForm::StartButton_Click(System::Object^ sender, System::EventArgs^ e) // Кнопка "Играть"
{
    SnakeForm::Timer1 = 150;
    SnakeForm::First = true;

    auto gameForm = gcnew Game::SnakeForm();
    gameForm->ShowDialog();//открываем игру поверх меню
    
}

void Game::MenuForm::info_Click(System::Object^ sender, System::EventArgs^ e)  // Кнопка "Справка"
{
    Diagnostics::Process::Start("info.txt"); // Открыть окно справки
}

void Game::MenuForm::exitBut_Click(System::Object^ sender, System::EventArgs^ e) // Кнопка "Выход"
{
    String^ caption = "Выход";// на появившемся окне пишем в названии выход
    String^ message = "Вы хотите выйти?\n Змейка будет скучать..."; //а в окне сообщение
    MessageBoxButtons buttons = MessageBoxButtons::YesNo; // из кнопок только да и нет будет
    System::Windows::Forms::DialogResult result = MessageBox::Show(message, caption, buttons); // показываем всё это

    if (result == ::DialogResult::Yes) { // если будет да выйти
        Application::OpenForms[0]->Close(); // закрываем
    }
}

void Game::MenuForm::oProgBut_Click(System::Object^ sender, System::EventArgs^ e)// Кнопка "О программе"
{
    String^ caption = "О программе";//в заголовке
    String^ message = "Игра \"Змейка\"\nРазработчик: Николаева Арина ИСТб-22-1\nВерсия: 2.0";// сообщение
    MessageBox::Show(message, caption);//показываем
}

void Game::MenuForm::MenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ cross) { // Перед закрытием окна (нажатие на крестик)

    String^ caption = "Выход";
    String^ message = "Вы хотите выйти?\n Змейка будет скучать...";
    MessageBoxButtons buttons = MessageBoxButtons::YesNo;
    System::Windows::Forms::DialogResult result = MessageBox::Show(message, caption, buttons);

    if (result == ::DialogResult::Yes) { //если да
        Application::OpenForms[0]->Close(); // закрываем
    }
    else
        cross->Cancel = true; //отменяем
}
