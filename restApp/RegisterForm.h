#pragma once
#include "LoginForm.h"
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
namespace restApp {
	using namespace msclr::interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	/// 
	/// // Forward declaration of the LoginForm class
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		Form^ mainForm;
		RegisterForm(void)
		{
			InitializeComponent();
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			label1->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label4->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
		}
		RegisterForm(Form^ form)
		{
			InitializeComponent();
			mainForm = form;
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			label1->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label4->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;



	private: System::Windows::Forms::TextBox^ passTextBox;

	private: System::Windows::Forms::TextBox^ userNameTextBox;

	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::Button^ confirmRegBtn;
	private: System::Windows::Forms::TextBox^ confirmPassTextBox;

	private: System::Windows::Forms::Label^ label4;



	private: System::Windows::Forms::TextBox^ addressTextBox;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ nameTextBox;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ adminPassTextBox;
	private: System::Windows::Forms::Label^ exceptionLabel;
	private: System::Windows::Forms::Label^ exceptionLabel1;
	private: System::Windows::Forms::Label^ exceptionLabel2;






	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->passTextBox = (gcnew System::Windows::Forms::TextBox());
			this->userNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->confirmRegBtn = (gcnew System::Windows::Forms::Button());
			this->confirmPassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->addressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->adminPassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->exceptionLabel = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel1 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(127, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(471, 61);
			this->label2->TabIndex = 1;
			this->label2->Text = L"KREIRAJ NALOG";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(199, 134);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(235, 31);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Korisnicko ime:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label3->Location = System::Drawing::Point(199, 210);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 31);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Lozinka:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label5->Location = System::Drawing::Point(199, 362);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(236, 31);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Admin Lozinka:";
			// 
			// passTextBox
			// 
			this->passTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->passTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->passTextBox->Location = System::Drawing::Point(205, 244);
			this->passTextBox->MaxLength = 20;
			this->passTextBox->Name = L"passTextBox";
			this->passTextBox->PasswordChar = '*';
			this->passTextBox->Size = System::Drawing::Size(276, 30);
			this->passTextBox->TabIndex = 7;
			this->passTextBox->UseSystemPasswordChar = true;
			// 
			// userNameTextBox
			// 
			this->userNameTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->userNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userNameTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->userNameTextBox->Location = System::Drawing::Point(205, 168);
			this->userNameTextBox->MaxLength = 20;
			this->userNameTextBox->Name = L"userNameTextBox";
			this->userNameTextBox->Size = System::Drawing::Size(276, 30);
			this->userNameTextBox->TabIndex = 8;
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
			this->backBtn->Location = System::Drawing::Point(12, 36);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(109, 55);
			this->backBtn->TabIndex = 9;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &RegisterForm::backBtn_Click);
			// 
			// confirmRegBtn
			// 
			this->confirmRegBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->confirmRegBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->confirmRegBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmRegBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->confirmRegBtn->Location = System::Drawing::Point(233, 670);
			this->confirmRegBtn->Name = L"confirmRegBtn";
			this->confirmRegBtn->Size = System::Drawing::Size(198, 44);
			this->confirmRegBtn->TabIndex = 10;
			this->confirmRegBtn->Text = L"POTVRDI";
			this->confirmRegBtn->UseVisualStyleBackColor = false;
			this->confirmRegBtn->Click += gcnew System::EventHandler(this, &RegisterForm::confirmRegBtn_Click);
			// 
			// confirmPassTextBox
			// 
			this->confirmPassTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->confirmPassTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmPassTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->confirmPassTextBox->Location = System::Drawing::Point(205, 320);
			this->confirmPassTextBox->MaxLength = 20;
			this->confirmPassTextBox->Name = L"confirmPassTextBox";
			this->confirmPassTextBox->PasswordChar = '*';
			this->confirmPassTextBox->Size = System::Drawing::Size(276, 30);
			this->confirmPassTextBox->TabIndex = 12;
			this->confirmPassTextBox->UseSystemPasswordChar = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label4->Location = System::Drawing::Point(199, 286);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(246, 31);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Potvrdi Lozinku:";
			// 
			// addressTextBox
			// 
			this->addressTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->addressTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addressTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->addressTextBox->Location = System::Drawing::Point(205, 561);
			this->addressTextBox->MaxLength = 50;
			this->addressTextBox->Name = L"addressTextBox";
			this->addressTextBox->Size = System::Drawing::Size(276, 30);
			this->addressTextBox->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoEllipsis = true;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label7->Location = System::Drawing::Point(199, 527);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(119, 31);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Adresa:";
			// 
			// nameTextBox
			// 
			this->nameTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->nameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->nameTextBox->Location = System::Drawing::Point(205, 481);
			this->nameTextBox->MaxLength = 20;
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(276, 30);
			this->nameTextBox->TabIndex = 18;
			// 
			// label6
			// 
			this->label6->AutoEllipsis = true;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label6->Location = System::Drawing::Point(199, 447);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(226, 31);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Ime Restorana:";
			// 
			// adminPassTextBox
			// 
			this->adminPassTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->adminPassTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adminPassTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->adminPassTextBox->Location = System::Drawing::Point(205, 396);
			this->adminPassTextBox->MaxLength = 20;
			this->adminPassTextBox->Name = L"adminPassTextBox";
			this->adminPassTextBox->PasswordChar = '*';
			this->adminPassTextBox->Size = System::Drawing::Size(276, 30);
			this->adminPassTextBox->TabIndex = 19;
			this->adminPassTextBox->UseSystemPasswordChar = true;
			// 
			// exceptionLabel
			// 
			this->exceptionLabel->AutoSize = true;
			this->exceptionLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel->Location = System::Drawing::Point(163, 625);
			this->exceptionLabel->Name = L"exceptionLabel";
			this->exceptionLabel->Size = System::Drawing::Size(345, 18);
			this->exceptionLabel->TabIndex = 20;
			this->exceptionLabel->Text = L"Korisnicko ime zauzeto, probajte ponovo";
			// 
			// exceptionLabel1
			// 
			this->exceptionLabel1->AutoSize = true;
			this->exceptionLabel1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel1->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel1->Location = System::Drawing::Point(163, 625);
			this->exceptionLabel1->Name = L"exceptionLabel1";
			this->exceptionLabel1->Size = System::Drawing::Size(351, 18);
			this->exceptionLabel1->TabIndex = 21;
			this->exceptionLabel1->Text = L"Lozinke se ne poklapaju, probajte ponovo";
			// 
			// exceptionLabel2
			// 
			this->exceptionLabel2->AutoSize = true;
			this->exceptionLabel2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel2->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel2->Location = System::Drawing::Point(240, 625);
			this->exceptionLabel2->Name = L"exceptionLabel2";
			this->exceptionLabel2->Size = System::Drawing::Size(185, 18);
			this->exceptionLabel2->TabIndex = 22;
			this->exceptionLabel2->Text = L"Popunite prazna polja";
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(724, 746);
			this->Controls->Add(this->exceptionLabel2);
			this->Controls->Add(this->exceptionLabel1);
			this->Controls->Add(this->exceptionLabel);
			this->Controls->Add(this->adminPassTextBox);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->addressTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->confirmPassTextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->confirmRegBtn);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->userNameTextBox);
			this->Controls->Add(this->passTextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(740, 684);
			this->Name = L"RegisterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		Application::Restart();
	}
	private: System::Void confirmRegBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrEmpty(userNameTextBox->Text) || String::IsNullOrEmpty(passTextBox->Text)
			|| String::IsNullOrEmpty(confirmPassTextBox->Text) || String::IsNullOrEmpty(adminPassTextBox->Text)
			|| String::IsNullOrEmpty(nameTextBox->Text) || String::IsNullOrEmpty(addressTextBox->Text)) {
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Show();
		}
		else {
			LoginForm^ loginForm = gcnew LoginForm(this);
			switch (restRegister(marshal_as<std::string>(userNameTextBox->Text),
				marshal_as<std::string>(passTextBox->Text),
				marshal_as<std::string>(confirmPassTextBox->Text),
				marshal_as<std::string>(adminPassTextBox->Text),
				marshal_as<std::string>(nameTextBox->Text),
				marshal_as<std::string>(addressTextBox->Text)))
			{
			case 0:
				loginForm->Show();
				this->Hide();
				userNameTextBox->Text = "";
				passTextBox->Text = "";
				confirmPassTextBox->Text = "";
				adminPassTextBox->Text = "";
				nameTextBox->Text = "";
				addressTextBox->Text = "";
				label1->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				label4->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				break;
			case 1:
				//korisnicko ime vec zauzeto
				exceptionLabel->Show();
				exceptionLabel1->Hide();
				exceptionLabel2->Hide();
				label1->ForeColor= System::Drawing::Color::Brown;
				label4->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				break;
			case 2:
				//lozinke se ne poklapaju
				exceptionLabel->Hide();
				exceptionLabel1->Show();
				exceptionLabel2->Hide();
				label1->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				label4->ForeColor= System::Drawing::Color::Brown;
				label3->ForeColor= System::Drawing::Color::Brown;
				break;
			default:
				break;
			}
			
		}
	}

};
}
