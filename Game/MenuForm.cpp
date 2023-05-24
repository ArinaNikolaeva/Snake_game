#include "MenuForm.h"
#include "Accounts.h"
#include "SnakeForm.h"

using namespace System;
using namespace System::Windows::Forms;


void Game::MenuForm::MenuForm_Load(System::Object^ sender, System::EventArgs^ e)// ��� ������������ � �����������
{
    toolStripLabel->Text = "������, \"" + Accounts::currUs->log + "\"! ������� ����!";
}


void Game::MenuForm::StartButton_Click(System::Object^ sender, System::EventArgs^ e) // ������ "������"
{
    SnakeForm::Timer1 = 150;
    SnakeForm::First = true;

    auto gameForm = gcnew Game::SnakeForm();
    gameForm->ShowDialog();//��������� ���� ������ ����
    
}

void Game::MenuForm::info_Click(System::Object^ sender, System::EventArgs^ e)  // ������ "�������"
{
    Diagnostics::Process::Start("info.txt"); // ������� ���� �������
}

void Game::MenuForm::exitBut_Click(System::Object^ sender, System::EventArgs^ e) // ������ "�����"
{
    String^ caption = "�����";// �� ����������� ���� ����� � �������� �����
    String^ message = "�� ������ �����?\n ������ ����� �������..."; //� � ���� ���������
    MessageBoxButtons buttons = MessageBoxButtons::YesNo; // �� ������ ������ �� � ��� �����
    System::Windows::Forms::DialogResult result = MessageBox::Show(message, caption, buttons); // ���������� �� ���

    if (result == ::DialogResult::Yes) { // ���� ����� �� �����
        Application::OpenForms[0]->Close(); // ���������
    }
}

void Game::MenuForm::oProgBut_Click(System::Object^ sender, System::EventArgs^ e)// ������ "� ���������"
{
    String^ caption = "� ���������";//� ���������
    String^ message = "���� \"������\"\n�����������: ��������� ����� ����-22-1\n������: 2.0";// ���������
    MessageBox::Show(message, caption);//����������
}

void Game::MenuForm::MenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ cross) { // ����� ��������� ���� (������� �� �������)

    String^ caption = "�����";
    String^ message = "�� ������ �����?\n ������ ����� �������...";
    MessageBoxButtons buttons = MessageBoxButtons::YesNo;
    System::Windows::Forms::DialogResult result = MessageBox::Show(message, caption, buttons);

    if (result == ::DialogResult::Yes) { //���� ��
        Application::OpenForms[0]->Close(); // ���������
    }
    else
        cross->Cancel = true; //��������
}
