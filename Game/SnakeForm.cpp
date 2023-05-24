#include "SnakeForm.h"
#include "iostream"
#include "Accounts.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


struct Vector2 { // двухмерное пространство
    int x, y;
};

const int step = 30; // шаг
const int ElementSize = 30; // размер элемента змейки

Vector2 direction; // направление движения
Vector2 currPos; // текущая позиция
int score = 0; // Счёт
int length = 1; // длина змейки
bool moveMent = true; // движение, для завершения игры
bool ispause = false; // пауза
bool closeForm = true; // Нужно ли диалоговое окно при закрытии формы

void Game::SnakeForm::SnakeForm_Load(System::Object^ sender, System::EventArgs^ e) { //окно игры
    srand(time(NULL));//случ числа на основе времени
    NewGame();
}

void Game::SnakeForm::NewGame() // новая игра
{
    
    if (!First) { // удаляем фрукты
        Controls->Remove(food);
        auto snakeElements = Controls->Find("Snake", false);//указываем что новая переменная это элемент змейки
        for (int i = 0; i < length; i++) { //перебираем элементы змейки и удаляем
            Controls->Remove(snakeElements[i]);
        }
    }

    First = false;//не первый запуск
    // Установка начальных параметров
    direction = { 1, 0 };//направление змейки
    currPos = { 250, 420 };//откуда начинаем движение
    length = 1;//длина змеи
    score = 0;//счёт
    moveMent = true;//начали движение
    ispause = false;//паузы нет
    closeForm = true;//не закрыли окно
    timer->Interval = Timer1;//время идет
    timer->Start();

    elem = gcnew PictureBox();// голова
    elem->Location = Point(currPos.x, currPos.y);//на той позиции которую прописали
    elem->BackColor = HeadColor;//цвет
    elem->Width = ElementSize;//ширина
    elem->Height = ElementSize;//высота
    elem->Name = "Snake";//название
    Controls->Add(elem); // добавляем

    food = gcnew PictureBox();//создаем фрукты
    food->BackColor = foodColor; //цвет
    food->Width = ElementSize;//ширина
    food->Height = ElementSize;//высота
    Controls->Add(food); // добавляем

    Head = Controls->Find("Snake", false)[0]; // Инициализация переменной, отвечающей за голову змейки
    PauseTool->Checked = ispause;

    GenerateFood();//генерируем фрукт
}

void Game::SnakeForm::Pause() { // Пауза
    ispause = !ispause;
    if (ispause) { //если пауза то останавливаем таймер
        timer->Stop();
    }
    else { //время идёт
        timer->Start();
    }
    PauseTool->Checked = ispause;
}

void Game::SnakeForm::GenerateFood() { //создаем еду
    Vector2 FoodPos;

    
    bool insnake = false;// еда не в змейке
    do {
        insnake = false;
        FoodPos.x = 30 * (rand() % 20) + 10;
        FoodPos.y = 30 * (rand() % 10) + 90;

        auto snakeElements = Controls->Find("Snake", false);//элемент змейки
        for (int i = 0; i < length; i++) { //проходимся по длине
            if (FoodPos.x == snakeElements[i]->Location.X && FoodPos.y == snakeElements[i]->Location.Y) //если совпадает расположение змеи и фрукта
                insnake = true;//фрукт в змейке
        }
    } while (insnake);

    food->Location = Point(FoodPos.x, FoodPos.y);//ставим фрукт по координатам
}

void Game::SnakeForm::GameOver()// Проигрыш
{
    moveMent = false;// нет движения

    if (score > 0)// записываем результат
        Accounts::AddResult(score);

    String^ caption = "Проигрыш";//окно проигрыша
    String^ message = "Конец игры!\nСчёт: " + score + "\nПопробуешь ещё раз?";
    MessageBoxButtons buttons = MessageBoxButtons::YesNo;
    System::Windows::Forms::DialogResult result = MessageBox::Show(message, caption, buttons);

    if (result == ::DialogResult::Yes) {
        NewGame();
    }
    if (result == ::DialogResult::No) {
        closeForm = false;
        timer->Stop();
        this->Close();
    }
}

void Game::SnakeForm::timer_Tick(System::Object^ sender, System::EventArgs^ e) { // основные моменты
    if (moveMent) //если есть движ
    {
        auto snakeElements = Controls->Find("Snake", false);//элемент змейкм

        currPos.x += direction.x * step;
        currPos.y += direction.y * step;
       
            // переход между линиями
            if (currPos.x <= lLine->Location.X)
                currPos.x += rLine->Location.X - lLine->Location.X;

            if (currPos.x >= rLine->Location.X)
                currPos.x -= rLine->Location.X - lLine->Location.X;

            if (currPos.y <= upLine->Location.Y)
                currPos.y += botLine->Location.Y - upLine->Location.Y;

            if (currPos.y >= botLine->Location.Y)
                currPos.y -= botLine->Location.Y - upLine->Location.Y;
        
        for (int i = 0; i < length; i++) { 
            if (currPos.x == snakeElements[i]->Location.X && currPos.y == snakeElements[i]->Location.Y) //если голова в змее
                GameOver();
        }

        if (moveMent) // движение змеи
        {
            for (int i = length - 1; i > 0; i--) {
                snakeElements[i]->Location = snakeElements[i - 1]->Location;
            }
            Head->Location = Point(currPos.x, currPos.y);
        }

        if (Head->Location == food->Location)//если голова и фрукт на одном месте 
        {
            score++;// +1
            length++;// +1

            elem = gcnew PictureBox();//увеличиваем змею
            elem->Location = Point(currPos.x, currPos.y);
            elem->BackColor = ElementsColor;
            elem->Width = ElementSize;
            elem->Height = ElementSize;
            elem->Name = "Snake";
            Controls->Add(elem);

            GenerateFood();//новый фрукт
        }
    }
    scoreText->Text = "Счёт: " + score;
}

void Game::SnakeForm::SnakeForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //управление
    if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up) { // ↑
        if (direction.y != 1)
            direction = { 0, -1 };
    }

    if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down) { // ↓ 
        if (direction.y != -1)
            direction = { 0, 1 };
    }

    if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right) { // →
        if (direction.x != -1)
            direction = { 1, 0 };
    }

    if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left) { // ←
        if (direction.x != 1)
            direction = { -1, 0 };
    }
}

void Game::SnakeForm::PauseTool_Click(System::Object^ sender, System::EventArgs^ e)// Пауза
{
    Pause();
}

void Game::SnakeForm::NewGameTool_Click(System::Object^ sender, System::EventArgs^ e)//новая игра
{
    NewGame();
}

void Game::SnakeForm::SnakeForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) { // закрываем 
    if (closeForm) {
        if (!ispause)
            Pause();

        String^ caption = "Закрыть игру";
        String^ message = "Игра будет окончена!!\nРезультат будет потерян(";
        MessageBoxButtons buttons = MessageBoxButtons::OKCancel;
        System::Windows::Forms::DialogResult result = MessageBox::Show(message, caption, buttons);

        if (result == ::DialogResult::OK) {
            timer->Stop();
        }
        if (result == ::DialogResult::Cancel) {
            e->Cancel = true;
            if (ispause)
                Pause();
        }
    }
}


