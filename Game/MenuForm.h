#pragma once

namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
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
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ menuText;
	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::Button^ info;
	private: System::Windows::Forms::Button^ exitBut;
	private: System::Windows::Forms::Button^ oProgBut;
	private: System::Windows::Forms::HelpProvider^ helpProvider;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

	protected:


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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuText = (gcnew System::Windows::Forms::Label());
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->info = (gcnew System::Windows::Forms::Button());
			this->exitBut = (gcnew System::Windows::Forms::Button());
			this->oProgBut = (gcnew System::Windows::Forms::Button());
			this->helpProvider = (gcnew System::Windows::Forms::HelpProvider());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel = (gcnew System::Windows::Forms::ToolStripLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 22.2F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(25, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(224, 52);
			this->label3->TabIndex = 3;
			this->label3->Text = L" Змейка 🐍";
			// 
			// menuText
			// 
			this->menuText->AutoSize = true;
			this->menuText->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuText->ForeColor = System::Drawing::Color::White;
			this->menuText->Location = System::Drawing::Point(328, 47);
			this->menuText->Name = L"menuText";
			this->menuText->Size = System::Drawing::Size(163, 60);
			this->menuText->TabIndex = 3;
			this->menuText->Text = L" Меню";
			this->menuText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// StartButton
			// 
			this->StartButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->StartButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->StartButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StartButton->ForeColor = System::Drawing::Color::White;
			this->StartButton->Location = System::Drawing::Point(256, 149);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(348, 106);
			this->StartButton->TabIndex = 0;
			this->StartButton->Text = L"ИГРАТЬ !";
			this->StartButton->UseVisualStyleBackColor = false;
			this->StartButton->Click += gcnew System::EventHandler(this, &MenuForm::StartButton_Click);
			// 
			// info
			// 
			this->info->BackColor = System::Drawing::Color::White;
			this->info->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->info->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->info->Location = System::Drawing::Point(460, 309);
			this->info->Name = L"info";
			this->info->Size = System::Drawing::Size(144, 45);
			this->info->TabIndex = 4;
			this->info->Text = L"Справка";
			this->info->UseVisualStyleBackColor = false;
			this->info->Click += gcnew System::EventHandler(this, &MenuForm::info_Click);
			// 
			// exitBut
			// 
			this->exitBut->BackColor = System::Drawing::Color::White;
			this->exitBut->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exitBut->ForeColor = System::Drawing::Color::Maroon;
			this->exitBut->Location = System::Drawing::Point(256, 309);
			this->exitBut->Name = L"exitBut";
			this->exitBut->Size = System::Drawing::Size(144, 45);
			this->exitBut->TabIndex = 5;
			this->exitBut->Text = L"Выход";
			this->exitBut->UseVisualStyleBackColor = false;
			this->exitBut->Click += gcnew System::EventHandler(this, &MenuForm::exitBut_Click);
			// 
			// oProgBut
			// 
			this->oProgBut->BackColor = System::Drawing::Color::White;
			this->oProgBut->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->oProgBut->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->oProgBut->Location = System::Drawing::Point(316, 382);
			this->oProgBut->Name = L"oProgBut";
			this->oProgBut->Size = System::Drawing::Size(233, 43);
			this->oProgBut->TabIndex = 6;
			this->oProgBut->Text = L"О программе";
			this->oProgBut->UseVisualStyleBackColor = false;
			this->oProgBut->Click += gcnew System::EventHandler(this, &MenuForm::oProgBut_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripLabel });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(836, 25);
			this->toolStrip1->TabIndex = 8;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripLabel
			// 
			this->toolStripLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->toolStripLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->toolStripLabel->Name = L"toolStripLabel";
			this->toolStripLabel->Size = System::Drawing::Size(84, 22);
			this->toolStripLabel->Text = L"Привет, \"\"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(683, 155);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 51);
			this->label1->TabIndex = 9;
			this->label1->Text = L"👾";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(556, 434);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 51);
			this->label2->TabIndex = 10;
			this->label2->Text = L"😵";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(591, 47);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 51);
			this->label4->TabIndex = 11;
			this->label4->Text = L"🎧";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(54, 406);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 51);
			this->label5->TabIndex = 12;
			this->label5->Text = L" 🍀";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(144, 268);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(79, 51);
			this->label6->TabIndex = 13;
			this->label6->Text = L" 🍎";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(43, 149);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 51);
			this->label7->TabIndex = 14;
			this->label7->Text = L"☠";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(734, 391);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(70, 51);
			this->label8->TabIndex = 15;
			this->label8->Text = L"🎮";
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Teal;
			this->ClientSize = System::Drawing::Size(836, 494);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->oProgBut);
			this->Controls->Add(this->exitBut);
			this->Controls->Add(this->info);
			this->Controls->Add(this->StartButton);
			this->Controls->Add(this->menuText);
			this->Controls->Add(this->label3);
			this->MaximizeBox = false;
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Меню";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MenuForm::MenuForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void MenuForm_Load(System::Object^ sender, System::EventArgs^ e); //форма
private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e); //играть
private: System::Void exitBut_Click(System::Object^ sender, System::EventArgs^ e);//выход
private: System::Void info_Click(System::Object^ sender, System::EventArgs^ e);//справка
private: System::Void oProgBut_Click(System::Object^ sender, System::EventArgs^ e);//о программе
private: System::Void MenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);//крестик на окне

};
}
