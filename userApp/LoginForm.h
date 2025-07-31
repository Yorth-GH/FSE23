#pragma once
#include "LoginForm.h"
#include "MainMenuForm.h"
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
namespace userApp {

	using namespace msclr::interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		Form^ mainForm;
		LoginForm(void)
		{
			InitializeComponent();
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			label2->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
		}
		LoginForm(Form^ form)
		{
			mainForm = form;
			InitializeComponent();
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			label2->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ usernameTextBox;
	private: System::Windows::Forms::TextBox^ passTextBox;


	private: System::Windows::Forms::Button^ confirmLoginBtn;

	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::Label^ exceptionLabel1;

	private: System::Windows::Forms::Label^ exceptionLabel2;
	private: System::Windows::Forms::Label^ exceptionLabel;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passTextBox = (gcnew System::Windows::Forms::TextBox());
			this->confirmLoginBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->exceptionLabel1 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel2 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(219, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(318, 61);
			this->label1->TabIndex = 1;
			this->label1->Text = L"PRIJAVI SE";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(239, 175);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(235, 31);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Korisnicko ime:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label3->Location = System::Drawing::Point(239, 254);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 31);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Lozinka";
			// 
			// usernameTextBox
			// 
			this->usernameTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->usernameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->usernameTextBox->Location = System::Drawing::Point(245, 209);
			this->usernameTextBox->MaxLength = 20;
			this->usernameTextBox->Name = L"usernameTextBox";
			this->usernameTextBox->Size = System::Drawing::Size(266, 30);
			this->usernameTextBox->TabIndex = 9;
			// 
			// passTextBox
			// 
			this->passTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->passTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->passTextBox->Location = System::Drawing::Point(245, 288);
			this->passTextBox->MaxLength = 20;
			this->passTextBox->Name = L"passTextBox";
			this->passTextBox->PasswordChar = '*';
			this->passTextBox->Size = System::Drawing::Size(266, 30);
			this->passTextBox->TabIndex = 10;
			this->passTextBox->UseSystemPasswordChar = true;
			// 
			// confirmLoginBtn
			// 
			this->confirmLoginBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->confirmLoginBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->confirmLoginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmLoginBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->confirmLoginBtn->Location = System::Drawing::Point(266, 351);
			this->confirmLoginBtn->Name = L"confirmLoginBtn";
			this->confirmLoginBtn->Size = System::Drawing::Size(203, 44);
			this->confirmLoginBtn->TabIndex = 11;
			this->confirmLoginBtn->Text = L"POTVRDI";
			this->confirmLoginBtn->UseVisualStyleBackColor = false;
			this->confirmLoginBtn->Click += gcnew System::EventHandler(this, &LoginForm::confirmLoginBtn_Click);
			// 
			// backBtn
			// 
			this->backBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->backBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->backBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->backBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->backBtn->Location = System::Drawing::Point(29, 54);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(108, 55);
			this->backBtn->TabIndex = 12;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &LoginForm::backBtn_Click);
			// 
			// exceptionLabel1
			// 
			this->exceptionLabel1->AutoSize = true;
			this->exceptionLabel1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel1->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel1->Location = System::Drawing::Point(242, 321);
			this->exceptionLabel1->Name = L"exceptionLabel1";
			this->exceptionLabel1->Size = System::Drawing::Size(274, 18);
			this->exceptionLabel1->TabIndex = 13;
			this->exceptionLabel1->Text = L"Pogresan unos, probajte ponovo";
			// 
			// exceptionLabel2
			// 
			this->exceptionLabel2->AutoSize = true;
			this->exceptionLabel2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel2->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel2->Location = System::Drawing::Point(272, 321);
			this->exceptionLabel2->Name = L"exceptionLabel2";
			this->exceptionLabel2->Size = System::Drawing::Size(185, 18);
			this->exceptionLabel2->TabIndex = 17;
			this->exceptionLabel2->Text = L"Popunite prazna polja";
			// 
			// exceptionLabel
			// 
			this->exceptionLabel->AutoSize = true;
			this->exceptionLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel->Location = System::Drawing::Point(234, 321);
			this->exceptionLabel->Name = L"exceptionLabel";
			this->exceptionLabel->Size = System::Drawing::Size(277, 18);
			this->exceptionLabel->TabIndex = 18;
			this->exceptionLabel->Text = L"Profil sa datim imenom ne postoji";
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(724, 591);
			this->Controls->Add(this->exceptionLabel);
			this->Controls->Add(this->exceptionLabel2);
			this->Controls->Add(this->exceptionLabel1);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->confirmLoginBtn);
			this->Controls->Add(this->passTextBox);
			this->Controls->Add(this->usernameTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(740, 630);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Korisnicka Aplikacija";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Restart();
	}
	private: System::Void confirmLoginBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrEmpty(usernameTextBox->Text) || String::IsNullOrEmpty(passTextBox->Text)) {
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Show();
		}
		else {
			bool loggedIn = false;
			switch (userLogin(marshal_as<std::string>(usernameTextBox->Text),
				marshal_as<std::string>(passTextBox->Text)))
			{
			case 0:
				setActiveUser(marshal_as<std::string>(usernameTextBox->Text));
				loggedIn = true;
				usernameTextBox->Text = "";
				passTextBox->Text = "";
				break;
			case 1:
				// 1 - racun ne postoji
				label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				label2->ForeColor = System::Drawing::Color::Brown;
				exceptionLabel->Show();
				exceptionLabel1->Hide();
				exceptionLabel2->Hide();
			case 2:
				// 2 - lozinka nije tacna
				label2->ForeColor = System::Drawing::Color::Brown;
				label3->ForeColor = System::Drawing::Color::Brown;
				exceptionLabel->Hide();
				exceptionLabel1->Show();
				exceptionLabel2->Hide();
			default:
				break;
			}
			if (loggedIn) {
				MainMenuForm^ mainMenuForm = gcnew MainMenuForm(this);
				mainMenuForm->Show();
				this->Hide();
			}
		}
	}
	};
}
