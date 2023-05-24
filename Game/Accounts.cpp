#include "Accounts.h"
#include "iostream"
#include "MenuForm.h"

using namespace System;
using namespace System::IO;  // ������ � ������ ������
using namespace System::Windows::Forms;

bool isLogRegGame = true; // ����/ �����������


void Game::Accounts::Accounts_Load(System::Object^ sender, System::EventArgs^ e)  // ����� ������
{
	ReadUs();
}

void Game::Accounts::ReadUs()  // ������ � ������ � ������!!!!!!!!!
{
	DebugText->Text = ""; // ��� �� ���������� ��� ������������ �������������

	UsersAll->Clear; // � ��� ��� �������������
	usNum = 0;

	FileStream^ filestr = gcnew FileStream(fileName, FileMode::OpenOrCreate); //���� ��� ������ ��� ������
	BinaryReader^ binRead = gcnew BinaryReader(filestr);

	while (binRead->BaseStream->Position < binRead->BaseStream->Length) //���������� �� ����� �����
	{
		tempUser = gcnew User; //��������� ����������
		tempUser->log = binRead->ReadString();
		tempUser->password = binRead->ReadString();
		tempUser->ScoreBest = binRead->ReadInt32(); //��������� 4-������� �����
		for (int i = 0; i < 5; i++)
			tempUser->lastgame[i] = binRead->ReadInt32();

		usNum++; //����������� ����� ������������, �� ���� �� ��� ��������� � ������� ��� �� ������
		UsersAll->Resize(UsersAll, usNum); // �������� ������ �������
		UsersAll[usNum - 1] = tempUser;// ���������� ������������ � ������
	}

	filestr->Close();//��������� ����

	DebugText->Text = usNum + " user:   "; // ���������� �������������

	for (int i = 0; i < usNum; i++)
	{
		DebugText->Text += UsersAll[i]->log + " " + UsersAll[i]->ScoreBest; // ���������� �������������
		DebugText->Text += "| " + "\n";
	}
}

void Game::Accounts::EntryButton_Click(System::Object^ sender, System::EventArgs^ e)  // ����
{
	ErrorText->Text = "";

	if (isLogRegGame)
		LoginPl();
	else
		RegPl();
}

void Game::Accounts::LoginPl() {            // ���� ������������
	auto login = LoginBox->Text; // �����
	if (login->Length == 0)
		return;

	if (login[0] == ' ') {
		ErrorText->Text = "������������ \n �����";
		return;
	}
	bool isFound = false; // ���������� �� ������������

	for (int i = 0; i < usNum; i++) { //����� ���������������� ������������
		if (login == UsersAll[i]->log) {
			currUs = UsersAll[i];
			isFound = true;
			break;
		}
	}
	
	auto password = PasswordBox->Text; // ������
	bool accessHave = false; // �������� �� ������

	if (!isFound) {  // ������������ ���
		ErrorText->Text = "������\n ������������\n �� ����������";
		return;
	}
	
	accessHave = (password == currUs->password); // ������ ������������� ������ �������� ������������ ��/���

	if (!accessHave) {  // �������� ������ 
		ErrorText->Text = "�������� ������";
		return;
	}
	
	// ���� �� ��������� �� �������� ����������� ����
	this->Hide();     // �� �����. ������ "�����������"
	auto menuForm = gcnew Game::MenuForm;    // �������������� ����������
	menuForm->Show();    // ���������� ����
}

void Game::Accounts::RegPl() {    // �����������
	auto login = LoginBox->Text;
	auto password = PasswordBox->Text;

	if (login->Length == 0 || password->Length == 0) //�� ������������ ���� ��� ������ � ������
		return;

	if (login[0] == ' ') {  //�������� �� ����������� ������ (������ ������ �� ���������� �� ������)
		ErrorText->Text = "�����\n �����������\n(������)";
		return;
	}
	if (password[0] == ' ') { // ���� ����� � �������
		ErrorText->Text = "������ \n����������� \n(������)";
		return;
	}


	for (int i = 0; i < usNum; i++)  // ���������� ���� �������������
	{
		if (login == UsersAll[i]->log) {   //��������� ���� �� ��� ������������� � ����� �� �������
			ErrorText->Text = "������������\n � �����\n ������� ��� ����";
			return;
		}
	}

	// ������ ������ ������������ � ����
	FileStream^ filestr = gcnew FileStream(fileName, FileMode::OpenOrCreate); // ��������� ���������� 
	BinaryWriter^ writefl = gcnew BinaryWriter(filestr); //�������� ����

	writefl->BaseStream->Position = writefl->BaseStream->Length; // ������ � ����� �����

	currUs->log = login; // ������� �����. ����� �������� ������������ ��� ����� ������� �� ������� ������
	currUs->password = password;
	currUs->ScoreBest = 0; // ������ ���������

	writefl->Write(login); // ���������� �����
	writefl->Write(password);
	writefl->Write(0); // �� ����� ������������ � ���� ��� �����
	for (int i = 0; i < 5; i++) {
		writefl->Write(-1);
		currUs->lastgame[i] = -1;
	}

	filestr->Close(); // ������ ��������� ������� ��������� ��� ����

	ReadUs(); // �������������� � ������� ������

	currUs = UsersAll[usNum - 1]; // ������� ������������ - ���������

	this->Hide(); // �� �� �������� ������ ������������, ����� ��������� ����
	auto menuForm = gcnew Game::MenuForm; // ��������� ����
	menuForm->Show();
}




// ���������� "���������" ������������� �� ������������� ����� �� �������� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Game::Accounts::SortUs()
{
	for (int i = 0; i < usNum - 1; i++) {
		for (int j = 0; j < usNum - i - 1; j++) {
			if (UsersAll[j]->ScoreBest < UsersAll[j + 1]->ScoreBest) {
				// swap
				User^ temp = gcnew User;
				temp = UsersAll[i];
				UsersAll[i] = UsersAll[i + 1];
				UsersAll[i + 1] = temp;
			}
		}
	}
}

void Game::Accounts::SaveUsers() {   // ���������� �������������

	FileStream^ filestr = gcnew FileStream(fileName, FileMode::OpenOrCreate);
	BinaryWriter^ binWr = gcnew BinaryWriter(filestr);

	for (int i = 0; i < usNum; i++) //���������� �������������
	{
		binWr->Write(UsersAll[i]->log); // ���������� � ����
		binWr->Write(UsersAll[i]->password);


		binWr->Write(UsersAll[i]->ScoreBest);
		for (int j = 0; j < 5; j++)
			binWr->Write(UsersAll[i]->lastgame[j]);
	}

	filestr->Close(); // ���������
}


void Game::Accounts::AddResult(int result)// �������� ��������� � ��������� !!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	for (int i = 4; i > 0; i--) { 
		currUs->lastgame[i] = currUs->lastgame[i - 1]; //������ ��������� �����������
	}
	currUs->lastgame[0] = result; 

	if (result > currUs->ScoreBest)
		currUs->ScoreBest = result; //���������� ������ ���������

	SaveUsers();
}


void Game::Accounts::RegButton_Click(System::Object^ sender, System::EventArgs^ e)// ���� � �����������
{
	isLogRegGame = !isLogRegGame;// �����������

	// ��������� ������
	if (isLogRegGame) //���� �����
	{
		this->Text = "����";
		AccText->Text = "����";
		EntryButton->Text = "����� � �������";
		RegButton->Text = "�����������";
	}
	else //���� �����������
	{
		this->Text = "�����������";
		AccText->Text = "�����������";
		EntryButton->Text = "������������������";
		RegButton->Text = "����";
	}

	
	LoginBox->Clear();  // ����� ����� �����
	PasswordBox->Clear();

	
	ErrorText->Text = "";  // ����� ������
}


