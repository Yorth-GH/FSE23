#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
namespace restApp {

	using namespace System;
	using namespace msclr::interop;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AuthForm
	/// </summary>
	public ref class AuthForm : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		AuthForm(void)
		{
			InitializeComponent();
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
		}
		AuthForm(Form^ form)
		{
			previousForm = form;
			InitializeComponent();
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AuthForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ exceptionLabel3;
	protected:
	private: System::Windows::Forms::Label^ exceptionLabel2;
	private: System::Windows::Forms::Label^ exceptionLabel1;
	private: System::Windows::Forms::Label^ exceptionLabel;
	private: System::Windows::Forms::Button^ confirmAuthBtn;

	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::TextBox^ passTextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AuthForm::typeid));
			this->exceptionLabel3 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel2 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel1 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel = (gcnew System::Windows::Forms::Label());
			this->confirmAuthBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->passTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// exceptionLabel3
			// 
			this->exceptionLabel3->AutoSize = true;
			this->exceptionLabel3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel3->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel3->Location = System::Drawing::Point(273, 276);
			this->exceptionLabel3->Name = L"exceptionLabel3";
			this->exceptionLabel3->Size = System::Drawing::Size(185, 18);
			this->exceptionLabel3->TabIndex = 35;
			this->exceptionLabel3->Text = L"Popunite prazna polja";
			// 
			// exceptionLabel2
			// 
			this->exceptionLabel2->AutoSize = true;
			this->exceptionLabel2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel2->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel2->Location = System::Drawing::Point(298, 276);
			this->exceptionLabel2->Name = L"exceptionLabel2";
			this->exceptionLabel2->Size = System::Drawing::Size(132, 18);
			this->exceptionLabel2->TabIndex = 34;
			this->exceptionLabel2->Text = L"Pogresan Unos";
			// 
			// exceptionLabel1
			// 
			this->exceptionLabel1->AutoSize = true;
			this->exceptionLabel1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel1->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel1->Location = System::Drawing::Point(298, 276);
			this->exceptionLabel1->Name = L"exceptionLabel1";
			this->exceptionLabel1->Size = System::Drawing::Size(148, 18);
			this->exceptionLabel1->TabIndex = 33;
			this->exceptionLabel1->Text = L"Pogresna lozinka";
			// 
			// exceptionLabel
			// 
			this->exceptionLabel->AutoSize = true;
			this->exceptionLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel->Location = System::Drawing::Point(286, 276);
			this->exceptionLabel->Name = L"exceptionLabel";
			this->exceptionLabel->Size = System::Drawing::Size(160, 18);
			this->exceptionLabel->TabIndex = 32;
			this->exceptionLabel->Text = L"Korisnik ne postoji";
			// 
			// confirmAuthBtn
			// 
			this->confirmAuthBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->confirmAuthBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->confirmAuthBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmAuthBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->confirmAuthBtn->Location = System::Drawing::Point(276, 309);
			this->confirmAuthBtn->Name = L"confirmAuthBtn";
			this->confirmAuthBtn->Size = System::Drawing::Size(198, 44);
			this->confirmAuthBtn->TabIndex = 31;
			this->confirmAuthBtn->Text = L"POTVRDI";
			this->confirmAuthBtn->UseVisualStyleBackColor = false;
			this->confirmAuthBtn->Click += gcnew System::EventHandler(this, &AuthForm::confirmAuthBtn_Click);
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
			this->backBtn->Location = System::Drawing::Point(12, 18);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(109, 55);
			this->backBtn->TabIndex = 30;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &AuthForm::backBtn_Click);
			// 
			// passTextBox
			// 
			this->passTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->passTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->passTextBox->Location = System::Drawing::Point(245, 190);
			this->passTextBox->MaxLength = 20;
			this->passTextBox->Name = L"passTextBox";
			this->passTextBox->PasswordChar = '*';
			this->passTextBox->Size = System::Drawing::Size(276, 30);
			this->passTextBox->TabIndex = 29;
			this->passTextBox->UseSystemPasswordChar = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label3->Location = System::Drawing::Point(192, 156);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(390, 31);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Administratorska Lozinka:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(151, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(473, 61);
			this->label2->TabIndex = 36;
			this->label2->Text = L"AUTENTIKACIJA";
			// 
			// AuthForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(759, 422);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->exceptionLabel3);
			this->Controls->Add(this->exceptionLabel2);
			this->Controls->Add(this->exceptionLabel1);
			this->Controls->Add(this->exceptionLabel);
			this->Controls->Add(this->confirmAuthBtn);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->passTextBox);
			this->Controls->Add(this->label3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AuthForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void confirmAuthBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(passTextBox->Text)) {
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Show();
		}
		else {
			bool isAuth = false;
			isAuth = adminAuthentication(getActiveUser(), marshal_as<std::string>(passTextBox->Text));
			setAuth(isAuth);
			if (isAuth == true) {
				MessageBox::Show("Uspesno ste se autentifikovali", "Uspesno", MessageBoxButtons::OK,
					MessageBoxIcon::Information);
				passTextBox->Text = "";
				this->Hide();
			}
			else {
				exceptionLabel->Hide();
				exceptionLabel1->Hide();
				exceptionLabel2->Show();
				exceptionLabel3->Hide();
			}
		}
	}
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		previousForm->Show();
	}
	};
}
