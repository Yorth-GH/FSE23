#pragma once
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
	public ref class DeleteProfileForm : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		DeleteProfileForm(void)
		{
			InitializeComponent();
			label1->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
		}
		DeleteProfileForm(Form^ form)
		{
			InitializeComponent();
			label1->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			previousForm = form;
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DeleteProfileForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ adminPassTextBox;





	private: System::Windows::Forms::TextBox^ userNameTextBox;

	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::Button^ confirmRegBtn;












	private: System::Windows::Forms::Label^ exceptionLabel2;
	private: System::Windows::Forms::Label^ exceptionLabel1;
	private: System::Windows::Forms::Label^ exceptionLabel;

	private: System::Windows::Forms::Label^ exceptionLabel3;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeleteProfileForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->adminPassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->userNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->confirmRegBtn = (gcnew System::Windows::Forms::Button());
			this->exceptionLabel2 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel1 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(146, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(425, 61);
			this->label2->TabIndex = 1;
			this->label2->Text = L"OBRISI PROFIL";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(196, 174);
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
			this->label3->Location = System::Drawing::Point(196, 250);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(236, 31);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Admin Lozinka:";
			// 
			// adminPassTextBox
			// 
			this->adminPassTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->adminPassTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adminPassTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->adminPassTextBox->Location = System::Drawing::Point(202, 284);
			this->adminPassTextBox->MaxLength = 20;
			this->adminPassTextBox->Name = L"adminPassTextBox";
			this->adminPassTextBox->PasswordChar = '*';
			this->adminPassTextBox->Size = System::Drawing::Size(276, 30);
			this->adminPassTextBox->TabIndex = 7;
			this->adminPassTextBox->UseSystemPasswordChar = true;
			// 
			// userNameTextBox
			// 
			this->userNameTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->userNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userNameTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->userNameTextBox->Location = System::Drawing::Point(202, 208);
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
			this->backBtn->Click += gcnew System::EventHandler(this, &DeleteProfileForm::backBtn_Click);
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
			this->confirmRegBtn->Location = System::Drawing::Point(233, 402);
			this->confirmRegBtn->Name = L"confirmRegBtn";
			this->confirmRegBtn->Size = System::Drawing::Size(198, 44);
			this->confirmRegBtn->TabIndex = 10;
			this->confirmRegBtn->Text = L"POTVRDI";
			this->confirmRegBtn->UseVisualStyleBackColor = false;
			this->confirmRegBtn->Click += gcnew System::EventHandler(this, &DeleteProfileForm::confirmRegBtn_Click);
			// 
			// exceptionLabel2
			// 
			this->exceptionLabel2->AutoSize = true;
			this->exceptionLabel2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel2->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel2->Location = System::Drawing::Point(256, 366);
			this->exceptionLabel2->Name = L"exceptionLabel2";
			this->exceptionLabel2->Size = System::Drawing::Size(132, 18);
			this->exceptionLabel2->TabIndex = 25;
			this->exceptionLabel2->Text = L"Pogresan Unos";
			// 
			// exceptionLabel1
			// 
			this->exceptionLabel1->AutoSize = true;
			this->exceptionLabel1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel1->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel1->Location = System::Drawing::Point(256, 366);
			this->exceptionLabel1->Name = L"exceptionLabel1";
			this->exceptionLabel1->Size = System::Drawing::Size(148, 18);
			this->exceptionLabel1->TabIndex = 24;
			this->exceptionLabel1->Text = L"Pogresna lozinka";
			// 
			// exceptionLabel
			// 
			this->exceptionLabel->AutoSize = true;
			this->exceptionLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel->Location = System::Drawing::Point(241, 366);
			this->exceptionLabel->Name = L"exceptionLabel";
			this->exceptionLabel->Size = System::Drawing::Size(160, 18);
			this->exceptionLabel->TabIndex = 23;
			this->exceptionLabel->Text = L"Korisnik ne postoji";
			// 
			// exceptionLabel3
			// 
			this->exceptionLabel3->AutoSize = true;
			this->exceptionLabel3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel3->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel3->Location = System::Drawing::Point(230, 366);
			this->exceptionLabel3->Name = L"exceptionLabel3";
			this->exceptionLabel3->Size = System::Drawing::Size(185, 18);
			this->exceptionLabel3->TabIndex = 27;
			this->exceptionLabel3->Text = L"Popunite prazna polja";
			// 
			// DeleteProfileForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(724, 645);
			this->Controls->Add(this->exceptionLabel3);
			this->Controls->Add(this->exceptionLabel2);
			this->Controls->Add(this->exceptionLabel1);
			this->Controls->Add(this->exceptionLabel);
			this->Controls->Add(this->confirmRegBtn);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->userNameTextBox);
			this->Controls->Add(this->adminPassTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(740, 684);
			this->Name = L"DeleteProfileForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Hide();
		previousForm->Show();
	}
	private: System::Void confirmRegBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{

		if (String::IsNullOrEmpty(userNameTextBox->Text) || String::IsNullOrEmpty(adminPassTextBox->Text))
		{
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Show();
		}
		else {
			switch (restRemove(getActiveUser(), marshal_as<std::string>(userNameTextBox->Text),
				marshal_as<std::string>(adminPassTextBox->Text)))
			{
			case 0:
				Application::Restart();
				break;
			case 1:
				//korisnik ne postoji
				label1->ForeColor = System::Drawing::Color::Brown;
				label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				exceptionLabel->Show();
				exceptionLabel1->Hide();
				exceptionLabel2->Hide();
				exceptionLabel3->Hide();
				break;
			case 2:
				//pogresna lozinka
				label1->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				label3->ForeColor = System::Drawing::Color::Brown;
				exceptionLabel->Hide();
				exceptionLabel1->Show();
				exceptionLabel2->Hide();
				exceptionLabel3->Hide();
				break;
			case 3:
				//ne poklapaju se username i password
				label1->ForeColor = System::Drawing::Color::Brown;
				label3->ForeColor = System::Drawing::Color::Brown;
				exceptionLabel->Hide();
				exceptionLabel1->Hide();
				exceptionLabel2->Show();
				exceptionLabel3->Hide();
				break;
			default:
				break;
			}

		}
	}
	};
}
