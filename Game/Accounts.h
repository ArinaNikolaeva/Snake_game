#pragma once

namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Accounts
	/// </summary>
	public ref class Accounts : public System::Windows::Forms::Form
	{
	public:
		Accounts(void)
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
		~Accounts()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ AccText;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ LoginBox;
	private: System::Windows::Forms::TextBox^ PasswordBox;
	private: System::Windows::Forms::Button^ EntryButton;
	private: System::Windows::Forms::Button^ RegButton;

	private: System::Windows::Forms::Label^ ErrorText;
	private: System::Windows::Forms::Label^ DebugText;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->AccText = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->LoginBox = (gcnew System::Windows::Forms::TextBox());
			this->PasswordBox = (gcnew System::Windows::Forms::TextBox());
			this->EntryButton = (gcnew System::Windows::Forms::Button());
			this->RegButton = (gcnew System::Windows::Forms::Button());
			this->ErrorText = (gcnew System::Windows::Forms::Label());
			this->DebugText = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// AccText
			// 
			this->AccText->AutoSize = true;
			this->AccText->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AccText->ForeColor = System::Drawing::Color::White;
			this->AccText->Location = System::Drawing::Point(302, 9);
			this->AccText->Name = L"AccText";
			this->AccText->Size = System::Drawing::Size(263, 84);
			this->AccText->TabIndex = 0;
			this->AccText->Text = L"Аккаунт";
			this->AccText->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 22.2F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(57, 138);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 52);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Логин:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 22.2F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(31, 236);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(170, 52);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Пароль:";
			// 
			// LoginBox
			// 
			this->LoginBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LoginBox->Location = System::Drawing::Point(227, 140);
			this->LoginBox->Name = L"LoginBox";
			this->LoginBox->Size = System::Drawing::Size(563, 49);
			this->LoginBox->TabIndex = 2;
			this->LoginBox->TextChanged += gcnew System::EventHandler(this, &Accounts::LoginTextBox_TextChanged);
			// 
			// PasswordBox
			// 
			this->PasswordBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PasswordBox->Location = System::Drawing::Point(227, 236);
			this->PasswordBox->Name = L"PasswordBox";
			this->PasswordBox->Size = System::Drawing::Size(563, 49);
			this->PasswordBox->TabIndex = 4;
			this->PasswordBox->UseSystemPasswordChar = true;
			this->PasswordBox->TextChanged += gcnew System::EventHandler(this, &Accounts::PasswordTextBox_TextChanged);
			// 
			// EntryButton
			// 
			this->EntryButton->BackColor = System::Drawing::Color::White;
			this->EntryButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EntryButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->EntryButton->Location = System::Drawing::Point(198, 323);
			this->EntryButton->Name = L"EntryButton";
			this->EntryButton->Size = System::Drawing::Size(473, 77);
			this->EntryButton->TabIndex = 1;
			this->EntryButton->Text = L"Вход";
			this->EntryButton->UseVisualStyleBackColor = true;
			this->EntryButton->Click += gcnew System::EventHandler(this, &Accounts::EntryButton_Click);
			// 
			// RegButton
			// 
			this->RegButton->BackColor = System::Drawing::Color::White;
			this->RegButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RegButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->RegButton->Location = System::Drawing::Point(316, 406);
			this->RegButton->Name = L"RegButton";
			this->RegButton->Size = System::Drawing::Size(250, 48);
			this->RegButton->TabIndex = 5;
			this->RegButton->Text = L"Регистрация";
			this->RegButton->UseVisualStyleBackColor = true;
			this->RegButton->Click += gcnew System::EventHandler(this, &Accounts::RegButton_Click);
			// 
			// ErrorText
			// 
			this->ErrorText->AutoSize = true;
			this->ErrorText->BackColor = System::Drawing::Color::Teal;
			this->ErrorText->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ErrorText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ErrorText->Location = System::Drawing::Point(27, 347);
			this->ErrorText->Name = L"ErrorText";
			this->ErrorText->Size = System::Drawing::Size(55, 24);
			this->ErrorText->TabIndex = 6;
			this->ErrorText->Text = L"Error";
			// 
			// DebugText
			// 
			this->DebugText->AutoSize = true;
			this->DebugText->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DebugText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->DebugText->Location = System::Drawing::Point(707, 347);
			this->DebugText->Name = L"DebugText";
			this->DebugText->Size = System::Drawing::Size(58, 24);
			this->DebugText->TabIndex = 7;
			this->DebugText->Text = L"debug";
			// 
			// Accounts
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Teal;
			this->ClientSize = System::Drawing::Size(865, 468);
			this->Controls->Add(this->DebugText);
			this->Controls->Add(this->ErrorText);
			this->Controls->Add(this->RegButton);
			this->Controls->Add(this->EntryButton);
			this->Controls->Add(this->PasswordBox);
			this->Controls->Add(this->LoginBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->AccText);
			this->MaximizeBox = false;
			this->Name = L"Accounts";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Аккаунт";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Accounts::Accounts_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Accounts::Accounts_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: static String^ fileName = "users.bin";//бинарный файл
  public: ref struct User //данные пользователя
  {
			String^ log;
			String^ password;


	  //РЕКОРД???
	  int ScoreBest;
	  array<int>^ lastgame = gcnew array<int>(5);
  };
	public: static array<User^>^ UsersAll;//все пользователи
	public: static User^ currUs = gcnew User;//текущий пользователь
	public: static int usNum = 0;//номер пользователя
	public: User^ tempUser;

		// Заголовки функций
  public: static void AddResult(int res);//сохранение результата
  public: static void SortUs();//сортировка пользователей
  private: static void SaveUsers();//сохранение пользователей
  public: void ReadUs();//чтение пользователей
  private: void LoginPl();//вход
  private: void RegPl();//регистрация

  private: System::Void EntryButton_Click(System::Object^ sender, System::EventArgs^ e);//кнопка вход
  private: System::Void RegButton_Click(System::Object^ sender, System::EventArgs^ e);//кнопка регистрация
  private: System::Void Accounts_Load(System::Object^ sender, System::EventArgs^ e);//окно авторизации
		   private: System::Void Accounts_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {//кнопка крестика на форме
	  Application::OpenForms[0]->Close(); // закрыть игру
  }
  private: System::Void LoginTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	  ErrorText->Text = "";
  }
  private: System::Void PasswordTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	  ErrorText->Text = "";
  }

};
}
