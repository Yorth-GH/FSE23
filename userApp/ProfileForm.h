#pragma once
#include "DeleteProfileForm.h"
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "AddBalanceForm.h"
namespace userApp {
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
	public ref class ProfileForm : public System::Windows::Forms::Form
	{
	public:
		Form^ mainMenuForm;
		ProfileForm(void)
		{
			InitializeComponent();
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
		}
		ProfileForm(Form^ form)
		{
			InitializeComponent();
			user thisUser = userGet(getActiveUser());
			label4->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			addressTextBox->Text = marshal_as<System::String^>(thisUser.address);
			phoneTextBox->Text = marshal_as<System::String^>(thisUser.phone);
			nameTextBox->Text = marshal_as<System::String^>(thisUser.fullName);
			if (thisUser.imagePath.empty() || (ifstream(thisUser.imagePath).fail())) {
				pfpBox->Image = Image::FromFile(marshal_as<System::String^>("User.png"));
			}
			else {
				pfpBox->Image = Image::FromFile(marshal_as<System::String^>(thisUser.imagePath));
			}
			mainMenuForm = form;
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProfileForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ phoneTextBox;

	private: System::Windows::Forms::TextBox^ passTextBox;



	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::Button^ confirmRegBtn;
	private: System::Windows::Forms::TextBox^ confirmPassTextBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ nameTextBox;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ addressTextBox;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ balanceTextBox;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ exceptionLabel2;
	private: System::Windows::Forms::Label^ exceptionLabel1;
	private: System::Windows::Forms::Label^ exceptionLabel;
	private: System::Windows::Forms::Button^ deleteProfileBtn;
	private: System::Windows::Forms::Label^ exceptionLabel3;
	private: System::Windows::Forms::PictureBox^ pfpBox;
	private: System::Windows::Forms::Button^ pfpButton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProfileForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->phoneTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passTextBox = (gcnew System::Windows::Forms::TextBox());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->confirmRegBtn = (gcnew System::Windows::Forms::Button());
			this->confirmPassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->addressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->balanceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel2 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel1 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel = (gcnew System::Windows::Forms::Label());
			this->deleteProfileBtn = (gcnew System::Windows::Forms::Button());
			this->exceptionLabel3 = (gcnew System::Windows::Forms::Label());
			this->pfpBox = (gcnew System::Windows::Forms::PictureBox());
			this->pfpButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pfpBox))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(441, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(223, 61);
			this->label2->TabIndex = 1;
			this->label2->Text = L"PROFIL";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label3->Location = System::Drawing::Point(414, 308);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(212, 31);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Nova Lozinka:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label5->Location = System::Drawing::Point(414, 443);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(212, 31);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Broj Telefona:";
			// 
			// phoneTextBox
			// 
			this->phoneTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->phoneTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->phoneTextBox->Location = System::Drawing::Point(420, 477);
			this->phoneTextBox->MaxLength = 20;
			this->phoneTextBox->Name = L"phoneTextBox";
			this->phoneTextBox->Size = System::Drawing::Size(276, 30);
			this->phoneTextBox->TabIndex = 6;
			this->phoneTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProfileForm::phoneTextBox_KeyPress);
			// 
			// passTextBox
			// 
			this->passTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->passTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->passTextBox->Location = System::Drawing::Point(420, 342);
			this->passTextBox->MaxLength = 20;
			this->passTextBox->Name = L"passTextBox";
			this->passTextBox->PasswordChar = '*';
			this->passTextBox->Size = System::Drawing::Size(276, 30);
			this->passTextBox->TabIndex = 7;
			this->passTextBox->UseSystemPasswordChar = true;
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
			this->backBtn->Location = System::Drawing::Point(23, 18);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(109, 55);
			this->backBtn->TabIndex = 9;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &ProfileForm::backBtn_Click);
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
			this->confirmRegBtn->Location = System::Drawing::Point(442, 587);
			this->confirmRegBtn->Name = L"confirmRegBtn";
			this->confirmRegBtn->Size = System::Drawing::Size(198, 44);
			this->confirmRegBtn->TabIndex = 10;
			this->confirmRegBtn->Text = L"POTVRDI";
			this->confirmRegBtn->UseVisualStyleBackColor = false;
			this->confirmRegBtn->Click += gcnew System::EventHandler(this, &ProfileForm::confirmRegBtn_Click);
			// 
			// confirmPassTextBox
			// 
			this->confirmPassTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->confirmPassTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmPassTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->confirmPassTextBox->Location = System::Drawing::Point(420, 194);
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
			this->label4->Location = System::Drawing::Point(414, 160);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(273, 31);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Trenutna Lozinka:";
			// 
			// nameTextBox
			// 
			this->nameTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->nameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->nameTextBox->Location = System::Drawing::Point(80, 476);
			this->nameTextBox->MaxLength = 20;
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(276, 30);
			this->nameTextBox->TabIndex = 14;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label6->Location = System::Drawing::Point(74, 442);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(219, 31);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Ime i Prezime:";
			// 
			// addressTextBox
			// 
			this->addressTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->addressTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addressTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->addressTextBox->Location = System::Drawing::Point(743, 477);
			this->addressTextBox->MaxLength = 50;
			this->addressTextBox->Name = L"addressTextBox";
			this->addressTextBox->Size = System::Drawing::Size(253, 30);
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
			this->label7->Location = System::Drawing::Point(737, 443);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(119, 31);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Adresa:";
			// 
			// balanceTextBox
			// 
			this->balanceTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->balanceTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->balanceTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->balanceTextBox->Location = System::Drawing::Point(187, 342);
			this->balanceTextBox->MaxLength = 20;
			this->balanceTextBox->Name = L"balanceTextBox";
			this->balanceTextBox->ReadOnly = true;
			this->balanceTextBox->Size = System::Drawing::Size(141, 30);
			this->balanceTextBox->TabIndex = 18;
			this->balanceTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProfileForm::balanceTextBox_KeyPress);
			// 
			// label8
			// 
			this->label8->AutoEllipsis = true;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label8->Location = System::Drawing::Point(182, 313);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(148, 27);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Vas Novac:";
			// 
			// exceptionLabel2
			// 
			this->exceptionLabel2->AutoSize = true;
			this->exceptionLabel2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel2->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel2->Location = System::Drawing::Point(458, 544);
			this->exceptionLabel2->Name = L"exceptionLabel2";
			this->exceptionLabel2->Size = System::Drawing::Size(160, 18);
			this->exceptionLabel2->TabIndex = 25;
			this->exceptionLabel2->Text = L"Korisnik ne postoji";
			// 
			// exceptionLabel1
			// 
			this->exceptionLabel1->AutoSize = true;
			this->exceptionLabel1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel1->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel1->Location = System::Drawing::Point(481, 544);
			this->exceptionLabel1->Name = L"exceptionLabel1";
			this->exceptionLabel1->Size = System::Drawing::Size(137, 18);
			this->exceptionLabel1->TabIndex = 24;
			this->exceptionLabel1->Text = L"Neispravan Broj";
			// 
			// exceptionLabel
			// 
			this->exceptionLabel->AutoSize = true;
			this->exceptionLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel->Location = System::Drawing::Point(443, 544);
			this->exceptionLabel->Name = L"exceptionLabel";
			this->exceptionLabel->Size = System::Drawing::Size(195, 18);
			this->exceptionLabel->TabIndex = 23;
			this->exceptionLabel->Text = L"Pogresna stara lozinka";
			// 
			// deleteProfileBtn
			// 
			this->deleteProfileBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)), static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->deleteProfileBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteProfileBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteProfileBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->deleteProfileBtn->Location = System::Drawing::Point(853, 18);
			this->deleteProfileBtn->Name = L"deleteProfileBtn";
			this->deleteProfileBtn->Size = System::Drawing::Size(143, 99);
			this->deleteProfileBtn->TabIndex = 26;
			this->deleteProfileBtn->Text = L"OBRISI PROFIL";
			this->deleteProfileBtn->UseVisualStyleBackColor = false;
			this->deleteProfileBtn->Click += gcnew System::EventHandler(this, &ProfileForm::deleteProfileBtn_Click);
			// 
			// exceptionLabel3
			// 
			this->exceptionLabel3->AutoSize = true;
			this->exceptionLabel3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel3->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel3->Location = System::Drawing::Point(449, 544);
			this->exceptionLabel3->Name = L"exceptionLabel3";
			this->exceptionLabel3->Size = System::Drawing::Size(185, 18);
			this->exceptionLabel3->TabIndex = 27;
			this->exceptionLabel3->Text = L"Popunite prazna polja";
			// 
			// pfpBox
			// 
			this->pfpBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pfpBox->Location = System::Drawing::Point(215, 120);
			this->pfpBox->Name = L"pfpBox";
			this->pfpBox->Size = System::Drawing::Size(143, 103);
			this->pfpBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pfpBox->TabIndex = 49;
			this->pfpBox->TabStop = false;
			// 
			// pfpButton
			// 
			this->pfpButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->pfpButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->pfpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pfpButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->pfpButton->Location = System::Drawing::Point(23, 120);
			this->pfpButton->Name = L"pfpButton";
			this->pfpButton->Size = System::Drawing::Size(141, 103);
			this->pfpButton->TabIndex = 48;
			this->pfpButton->Text = L"Izaberite Profilnu Sliku";
			this->pfpButton->UseVisualStyleBackColor = false;
			this->pfpButton->Click += gcnew System::EventHandler(this, &ProfileForm::pfpButton_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->button1->Location = System::Drawing::Point(23, 270);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 103);
			this->button1->TabIndex = 50;
			this->button1->Text = L"Uplatite na racun";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ProfileForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(334, 340);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 31);
			this->label1->TabIndex = 51;
			this->label1->Text = L"KM";
			// 
			// ProfileForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(1031, 674);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pfpBox);
			this->Controls->Add(this->pfpButton);
			this->Controls->Add(this->exceptionLabel3);
			this->Controls->Add(this->deleteProfileBtn);
			this->Controls->Add(this->exceptionLabel2);
			this->Controls->Add(this->exceptionLabel1);
			this->Controls->Add(this->exceptionLabel);
			this->Controls->Add(this->balanceTextBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->addressTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->confirmPassTextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->confirmRegBtn);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->passTextBox);
			this->Controls->Add(this->phoneTextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(740, 684);
			this->Name = L"ProfileForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Korisnicka Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &ProfileForm::ProfileForm_VisibleChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pfpBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Hide();
		mainMenuForm->Show();
	}
	private: System::Void confirmRegBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{

		switch (userUpdate(getActiveUser(),
			marshal_as<std::string>(addressTextBox->Text),
			marshal_as<std::string>(nameTextBox->Text),
			marshal_as<std::string>(passTextBox->Text),
			marshal_as<std::string>(confirmPassTextBox->Text),
			marshal_as<std::string>(phoneTextBox->Text),
			getProfileImagePath()))
		{
		case 0:
			this->Hide();
			mainMenuForm->Show();
			break;
		case 1:
			//ne poklapaju se lozinke
			label4->ForeColor = System::Drawing::Color::Brown;
			exceptionLabel->Show();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
			break;
		case 2:
			//neispravan broj
			label4->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			exceptionLabel->Hide();
			exceptionLabel1->Show();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
			break;
		case 4:
			//korisnik ne postoji
			label4->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Show();
			exceptionLabel3->Hide();
			break;
		default:
			break;
		}


	}
	private: System::Void deleteProfileBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteProfileForm^ deleteProfileForm = gcnew DeleteProfileForm(this);
		deleteProfileForm->Show();
		this->Hide();
	}
	private: System::Void balanceTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Check if the entered character is a digit or a control character
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {  // Allow digits and backspace
			e->Handled = true;  // Mark the event as handled to prevent the character from being input
		}
	}
	private: System::Void phoneTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Check if the entered character is a digit or a control character
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {  // Allow digits and backspace
			e->Handled = true;  // Mark the event as handled to prevent the character from being input
		}
	}
	private: System::Void pfpButton_Click(System::Object^ sender, System::EventArgs^ e) {
		System::IO::Stream^ myStream;
		OpenFileDialog^ Dialog1 = gcnew OpenFileDialog;

		Dialog1->InitialDirectory = "C:\\";
		Dialog1->Filter = "PNG(*.png)|*.png|JPEG(*.jpeg)|*.jpeg|JPG(*.jpg)|*.jpg";
		Dialog1->FilterIndex = 1;
		Dialog1->RestoreDirectory = true;
		if (Dialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((myStream = Dialog1->OpenFile()) != nullptr) {
				pfpBox->Image = Image::FromStream(myStream);
				setProfileImagePath(marshal_as<std::string>(Dialog1->FileName));
				myStream->Close();
			}
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AddBalanceForm^ addBalanceForm = gcnew AddBalanceForm(this);
		addBalanceForm->Show();
		this->Hide();
	}
	private: System::Void ProfileForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		user thisUser = userGet(getActiveUser());
		nameTextBox->Text = marshal_as<String^>(thisUser.fullName);
		phoneTextBox->Text = marshal_as<String^>(thisUser.phone);
		addressTextBox->Text = marshal_as<String^>(thisUser.address);
		balanceTextBox->Text = Convert::ToString(thisUser.balance);
		if (thisUser.imagePath.empty() || (ifstream(thisUser.imagePath).fail())) {
			pfpBox->Image = Image::FromFile(marshal_as<System::String^>("User.png"));
		}
		else {
			pfpBox->Image = Image::FromFile(marshal_as<System::String^>(thisUser.imagePath));
		}
	}
};
}
