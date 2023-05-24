#pragma once

namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SnakeForm
	/// </summary>
	public ref class SnakeForm : public System::Windows::Forms::Form
	{
	public:
		SnakeForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SnakeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ settings;
	private: System::Windows::Forms::ToolStripMenuItem^ NewGameTool;

	private: System::Windows::Forms::ToolStripMenuItem^ PauseTool;
	private: System::Windows::Forms::Label^ scoreText;
	private: System::Windows::Forms::PictureBox^ upLine;
	private: System::Windows::Forms::PictureBox^ lLine;
	private: System::Windows::Forms::PictureBox^ botLine;
	private: System::Windows::Forms::PictureBox^ rLine;
	private: System::Windows::Forms::Timer^ timer;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->settings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->NewGameTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PauseTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->scoreText = (gcnew System::Windows::Forms::Label());
			this->upLine = (gcnew System::Windows::Forms::PictureBox());
			this->lLine = (gcnew System::Windows::Forms::PictureBox());
			this->botLine = (gcnew System::Windows::Forms::PictureBox());
			this->rLine = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upLine))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lLine))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->botLine))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rLine))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->settings });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(806, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// settings
			// 
			this->settings->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->NewGameTool,
					this->PauseTool
			});
			this->settings->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->settings->Name = L"settings";
			this->settings->Size = System::Drawing::Size(102, 24);
			this->settings->Text = L"Настройки";
			//this->settings->Click += gcnew System::EventHandler(this, &SnakeForm::settings_Click);
			// 
			// NewGameTool
			// 
			this->NewGameTool->Name = L"NewGameTool";
			this->NewGameTool->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::E));
			this->NewGameTool->Size = System::Drawing::Size(304, 26);
			this->NewGameTool->Text = L"Новая игра";
			this->NewGameTool->Click += gcnew System::EventHandler(this, &SnakeForm::NewGameTool_Click);
			// 
			// PauseTool
			// 
			this->PauseTool->Name = L"PauseTool";
			this->PauseTool->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Tab));
			this->PauseTool->Size = System::Drawing::Size(304, 26);
			this->PauseTool->Text = L"Пауза/продолжить";
			this->PauseTool->Click += gcnew System::EventHandler(this, &SnakeForm::PauseTool_Click);
			// 
			// scoreText
			// 
			this->scoreText->AutoSize = true;
			this->scoreText->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->scoreText->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->scoreText->ForeColor = System::Drawing::Color::White;
			this->scoreText->Location = System::Drawing::Point(12, 45);
			this->scoreText->Name = L"scoreText";
			this->scoreText->Size = System::Drawing::Size(73, 33);
			this->scoreText->TabIndex = 1;
			this->scoreText->Text = L"Счёт:";
			// 
			// upLine
			// 
			this->upLine->BackColor = System::Drawing::Color::Silver;
			this->upLine->Location = System::Drawing::Point(12, 94);
			this->upLine->Name = L"upLine";
			this->upLine->Size = System::Drawing::Size(778, 10);
			this->upLine->TabIndex = 2;
			this->upLine->TabStop = false;
			// 
			// lLine
			// 
			this->lLine->BackColor = System::Drawing::Color::Silver;
			this->lLine->Location = System::Drawing::Point(12, 94);
			this->lLine->Name = L"lLine";
			this->lLine->Size = System::Drawing::Size(10, 778);
			this->lLine->TabIndex = 3;
			this->lLine->TabStop = false;
			// 
			// botLine
			// 
			this->botLine->BackColor = System::Drawing::Color::Silver;
			this->botLine->Location = System::Drawing::Point(12, 862);
			this->botLine->Name = L"botLine";
			this->botLine->Size = System::Drawing::Size(778, 10);
			this->botLine->TabIndex = 4;
			this->botLine->TabStop = false;
			// 
			// rLine
			// 
			this->rLine->BackColor = System::Drawing::Color::Silver;
			this->rLine->Location = System::Drawing::Point(783, 94);
			this->rLine->Name = L"rLine";
			this->rLine->Size = System::Drawing::Size(10, 778);
			this->rLine->TabIndex = 5;
			this->rLine->TabStop = false;
			// 
			// timer
			// 
			this->timer->Interval = 300;
			this->timer->Tick += gcnew System::EventHandler(this, &SnakeForm::timer_Tick);
			// 
			// SnakeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(806, 877);
			this->Controls->Add(this->rLine);
			this->Controls->Add(this->botLine);
			this->Controls->Add(this->lLine);
			this->Controls->Add(this->upLine);
			this->Controls->Add(this->scoreText);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"SnakeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Игра Змейка";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &SnakeForm::SnakeForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &SnakeForm::SnakeForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SnakeForm::SnakeForm_KeyDown);

			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->upLine))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lLine))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->botLine))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rLine))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Глобальные переменные
  public: static int Timer1; // Время срабатывания таймера (в милисекундах), влияет на скорость
  public: static bool First = true; // Первый ли запуск игры
  public: static  bool lineOn = true; // Включены ли границы &&&&&&&&&&&&&

  public: static Color HeadColor = Color::Blue; // Цвет головы змейки
  public: static Color ElementsColor = Color::White; // Цвет хвоста змейки
  public: static Color foodColor = Color::Red; // Цвет еды

  private: Control^ Head; // Голова змейки
  private: PictureBox^ elem; // Один элемент змейки
  private: PictureBox^ line; // Один элемент стенки
  private: PictureBox^ food; // Еда

		 // Заголовки функций
  //private: void Status(); // Обновление строки состояния
  private: void NewGame(); // Перезапуск уровня
  private: void Pause(); // Пауза
  private: void GenerateFood(); // Генерация еды
  private: void GameOver(); //// Завершение игры
  //private: void Spawnline();


	private: System::Void SnakeForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SnakeForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);
//private: System::Void settings_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void NewGameTool_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void PauseTool_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SnakeForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);

};
}
