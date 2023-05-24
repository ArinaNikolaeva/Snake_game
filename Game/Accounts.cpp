#include "Accounts.h"
#include "iostream"
#include "MenuForm.h"

using namespace System;
using namespace System::IO;  // чтение и запись файлов
using namespace System::Windows::Forms;

bool isLogRegGame = true; // Вход/ регистрации


void Game::Accounts::Accounts_Load(System::Object^ sender, System::EventArgs^ e)  // сразу читаем
{
	ReadUs();
}

void Game::Accounts::ReadUs()  // чтение и запись в массив!!!!!!!!!
{
	DebugText->Text = ""; // тут мы показываем уже существующих пользователей

	UsersAll->Clear; // у нас нет пользователей
	usNum = 0;

	FileStream^ filestr = gcnew FileStream(fileName, FileMode::OpenOrCreate); //тоже что делали при записи
	BinaryReader^ binRead = gcnew BinaryReader(filestr);

	while (binRead->BaseStream->Position < binRead->BaseStream->Length) //проходимся по всему файлу
	{
		tempUser = gcnew User; //временная переменная
		tempUser->log = binRead->ReadString();
		tempUser->password = binRead->ReadString();
		tempUser->ScoreBest = binRead->ReadInt32(); //считываем 4-байтное число
		for (int i = 0; i < 5; i++)
			tempUser->lastgame[i] = binRead->ReadInt32();

		usNum++; //увеличиваем номер пользователя, то есть мы его прочитали и говорим что он первый
		UsersAll->Resize(UsersAll, usNum); // изменяем размер вектора
		UsersAll[usNum - 1] = tempUser;// записываем пользователя в массив
	}

	filestr->Close();//закрываем файл

	DebugText->Text = usNum + " user:   "; // показываем пользователей

	for (int i = 0; i < usNum; i++)
	{
		DebugText->Text += UsersAll[i]->log + " " + UsersAll[i]->ScoreBest; // перебираем пользователей
		DebugText->Text += "| " + "\n";
	}
}

void Game::Accounts::EntryButton_Click(System::Object^ sender, System::EventArgs^ e)  // Вход
{
	ErrorText->Text = "";

	if (isLogRegGame)
		LoginPl();
	else
		RegPl();
}

void Game::Accounts::LoginPl() {            // Вход пользователя
	auto login = LoginBox->Text; // логин
	if (login->Length == 0)
		return;

	if (login[0] == ' ') {
		ErrorText->Text = "Неправильный \n логин";
		return;
	}
	bool isFound = false; // Существует ли пользователь

	for (int i = 0; i < usNum; i++) { //поиск соответствующего пользователя
		if (login == UsersAll[i]->log) {
			currUs = UsersAll[i];
			isFound = true;
			break;
		}
	}
	
	auto password = PasswordBox->Text; // пароль
	bool accessHave = false; // Разрешён ли доступ

	if (!isFound) {  // пользователя нет
		ErrorText->Text = "Такого\n пользователя\n не существует";
		return;
	}
	
	accessHave = (password == currUs->password); // пароль соответствует паролю текущего пользователя да/нет

	if (!accessHave) {  // Неверный пароль 
		ErrorText->Text = "Неверный пароль";
		return;
	}
	
	// если всё нормально то спокойно переключаем окна
	this->Hide();     // Мы вошли. прячем "авторизацию"
	auto menuForm = gcnew Game::MenuForm;    // переопределяем переменную
	menuForm->Show();    // показываем меню
}

void Game::Accounts::RegPl() {    // Регистрация
	auto login = LoginBox->Text;
	auto password = PasswordBox->Text;

	if (login->Length == 0 || password->Length == 0) //не регистрируем если нет пароля и логина
		return;

	if (login[0] == ' ') {  //проверка на корректость логина (первый символ не начинается на пробел)
		ErrorText->Text = "Логин\n некорректен\n(пробел)";
		return;
	}
	if (password[0] == ' ') { // тоже самое с паролем
		ErrorText->Text = "Пароль \nнекорректен \n(пробел)";
		return;
	}


	for (int i = 0; i < usNum; i++)  // перебираем всех пользователей
	{
		if (login == UsersAll[i]->log) {   //проверяем есть ли уже пользователей с таким же логином
			ErrorText->Text = "Пользователь\n с таким\n логином уже есть";
			return;
		}
	}

	// Запись нового пользователя в файл
	FileStream^ filestr = gcnew FileStream(fileName, FileMode::OpenOrCreate); // переопред переменную 
	BinaryWriter^ writefl = gcnew BinaryWriter(filestr); //бинарный файл

	writefl->BaseStream->Position = writefl->BaseStream->Length; // Запись в конец файла

	currUs->log = login; // создаем связь. логин текущего пользователя это логин который мы запишем дальше
	currUs->password = password;
	currUs->ScoreBest = 0; // лучший результат

	writefl->Write(login); // записываем логин
	writefl->Write(password);
	writefl->Write(0); // тк новый пользователь у него нет счёта
	for (int i = 0; i < 5; i++) {
		writefl->Write(-1);
		currUs->lastgame[i] = -1;
	}

	filestr->Close(); // запись закончена поэтому закрываем бин файл

	ReadUs(); // перенаправляем в функцию чтения

	currUs = UsersAll[usNum - 1]; // текущий пользователь - последний

	this->Hide(); // всё мы записали нового пользователя, поэто закрываем окно
	auto menuForm = gcnew Game::MenuForm; // открываем меню
	menuForm->Show();
}




// Сортировка "пузырьком" пользователей по максимальному счёту по убыванию !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

void Game::Accounts::SaveUsers() {   // Сохранение пользователей

	FileStream^ filestr = gcnew FileStream(fileName, FileMode::OpenOrCreate);
	BinaryWriter^ binWr = gcnew BinaryWriter(filestr);

	for (int i = 0; i < usNum; i++) //перебираем пользователей
	{
		binWr->Write(UsersAll[i]->log); // записываем в файл
		binWr->Write(UsersAll[i]->password);


		binWr->Write(UsersAll[i]->ScoreBest);
		for (int j = 0; j < 5; j++)
			binWr->Write(UsersAll[i]->lastgame[j]);
	}

	filestr->Close(); // закрываем
}


void Game::Accounts::AddResult(int result)// Добавить результат и сохранить !!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	for (int i = 4; i > 0; i--) { 
		currUs->lastgame[i] = currUs->lastgame[i - 1]; //запись последних результатов
	}
	currUs->lastgame[0] = result; 

	if (result > currUs->ScoreBest)
		currUs->ScoreBest = result; //записываем лучший результат

	SaveUsers();
}


void Game::Accounts::RegButton_Click(System::Object^ sender, System::EventArgs^ e)// Вход и регистрации
{
	isLogRegGame = !isLogRegGame;// регистрация

	// Изменение текста
	if (isLogRegGame) //окно входа
	{
		this->Text = "Вход";
		AccText->Text = "Вход";
		EntryButton->Text = "Войти в профиль";
		RegButton->Text = "Регистрация";
	}
	else //окно регистрации
	{
		this->Text = "Регистрация";
		AccText->Text = "Регистрация";
		EntryButton->Text = "Зарегистрироваться";
		RegButton->Text = "Вход";
	}

	
	LoginBox->Clear();  // Сброс полей ввода
	PasswordBox->Clear();

	
	ErrorText->Text = "";  // Сброс текста
}


