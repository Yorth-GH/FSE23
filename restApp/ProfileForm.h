#pragma once
#include "DeleteProfileForm.h"
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
	public ref class ProfileForm : public System::Windows::Forms::Form
	{
	public:
		Form^ mainMenuForm;
		ProfileForm(void)
		{


			InitializeComponent();
			label6->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
		}
		ProfileForm(Form^ form)
		{
			//load rest settings
			InitializeComponent();
			rest thisRest = restGet(getActiveUser());
			label6->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			addressTextBox->Text = marshal_as<System::String^>(thisRest.address);
			wtOpenTextBox->Text = marshal_as<System::String^>(thisRest.wt.timeOpen);
			wtClosedTextBox->Text =marshal_as<System::String^>(thisRest.wt.timeClose);
			if (thisRest.imagePath.empty() || (ifstream(thisRest.imagePath).fail())) {
				pfpBox->Image = Image::FromFile(marshal_as<System::String^>("restUser.png"));
			}
			else {
				pfpBox->Image = Image::FromFile(marshal_as<System::String^>(thisRest.imagePath));
			}	
			descriptionTextBox->Text = marshal_as<System::String^>(thisRest.desc);
			string allTags;
			for (const std::string& str : thisRest.tags) {
				allTags += str + " ";
			}
			tagTextBox->Text = marshal_as<System::String^>(allTags);

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
	private: System::Windows::Forms::TextBox^ newAdminPassTextBox;

	private: System::Windows::Forms::TextBox^ wtOpenTextBox;








	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::Button^ confirmRegBtn;
	private: System::Windows::Forms::TextBox^ passTextBox;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ oldAdminPassTextBox;



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ addressTextBox;


	private: System::Windows::Forms::Label^ label7;


	private: System::Windows::Forms::Label^ exceptionLabel2;
	private: System::Windows::Forms::Label^ exceptionLabel1;
	private: System::Windows::Forms::Label^ exceptionLabel;
	private: System::Windows::Forms::Button^ deleteProfileBtn;
	private: System::Windows::Forms::Label^ exceptionLabel3;










	private: System::Windows::Forms::Button^ pfpButton;


	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::RichTextBox^ descriptionTextBox;
	private: System::Windows::Forms::RichTextBox^ tagTextBox;
	private: System::Windows::Forms::TextBox^ wtClosedTextBox;

	private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::PictureBox^ pfpBox;






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
			this->newAdminPassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->wtOpenTextBox = (gcnew System::Windows::Forms::TextBox());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->confirmRegBtn = (gcnew System::Windows::Forms::Button());
			this->passTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->oldAdminPassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->addressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel2 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel1 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel = (gcnew System::Windows::Forms::Label());
			this->deleteProfileBtn = (gcnew System::Windows::Forms::Button());
			this->exceptionLabel3 = (gcnew System::Windows::Forms::Label());
			this->pfpButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->descriptionTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->tagTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->wtClosedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pfpBox = (gcnew System::Windows::Forms::PictureBox());
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
			this->label2->Location = System::Drawing::Point(340, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(545, 61);
			this->label2->TabIndex = 1;
			this->label2->Text = L"RESTORAN PROFIL";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label3->Location = System::Drawing::Point(124, 590);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(282, 31);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Vrijeme Otvaranja:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label5->Location = System::Drawing::Point(124, 361);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(316, 31);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Nova Admin Lozinka:";
			// 
			// newAdminPassTextBox
			// 
			this->newAdminPassTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->newAdminPassTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->newAdminPassTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->newAdminPassTextBox->Location = System::Drawing::Point(130, 395);
			this->newAdminPassTextBox->MaxLength = 20;
			this->newAdminPassTextBox->Name = L"newAdminPassTextBox";
			this->newAdminPassTextBox->PasswordChar = '*';
			this->newAdminPassTextBox->Size = System::Drawing::Size(364, 30);
			this->newAdminPassTextBox->TabIndex = 6;
			this->newAdminPassTextBox->UseSystemPasswordChar = true;
			// 
			// wtOpenTextBox
			// 
			this->wtOpenTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->wtOpenTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wtOpenTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->wtOpenTextBox->Location = System::Drawing::Point(130, 624);
			this->wtOpenTextBox->MaxLength = 20;
			this->wtOpenTextBox->Name = L"wtOpenTextBox";
			this->wtOpenTextBox->Size = System::Drawing::Size(364, 30);
			this->wtOpenTextBox->TabIndex = 7;
			this->wtOpenTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProfileForm::wtOpenTextBox_KeyPress);
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
			this->backBtn->Location = System::Drawing::Point(35, 31);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(141, 75);
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
			this->confirmRegBtn->Location = System::Drawing::Point(481, 712);
			this->confirmRegBtn->Name = L"confirmRegBtn";
			this->confirmRegBtn->Size = System::Drawing::Size(198, 44);
			this->confirmRegBtn->TabIndex = 10;
			this->confirmRegBtn->Text = L"POTVRDI";
			this->confirmRegBtn->UseVisualStyleBackColor = false;
			this->confirmRegBtn->Click += gcnew System::EventHandler(this, &ProfileForm::confirmRegBtn_Click);
			// 
			// passTextBox
			// 
			this->passTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->passTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->passTextBox->Location = System::Drawing::Point(130, 319);
			this->passTextBox->MaxLength = 20;
			this->passTextBox->Name = L"passTextBox";
			this->passTextBox->PasswordChar = '*';
			this->passTextBox->Size = System::Drawing::Size(364, 30);
			this->passTextBox->TabIndex = 12;
			this->passTextBox->UseSystemPasswordChar = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label4->Location = System::Drawing::Point(124, 285);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(212, 31);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Nova Lozinka:";
			// 
			// oldAdminPassTextBox
			// 
			this->oldAdminPassTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->oldAdminPassTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->oldAdminPassTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->oldAdminPassTextBox->Location = System::Drawing::Point(130, 467);
			this->oldAdminPassTextBox->MaxLength = 20;
			this->oldAdminPassTextBox->Name = L"oldAdminPassTextBox";
			this->oldAdminPassTextBox->PasswordChar = '*';
			this->oldAdminPassTextBox->Size = System::Drawing::Size(364, 30);
			this->oldAdminPassTextBox->TabIndex = 14;
			this->oldAdminPassTextBox->UseSystemPasswordChar = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label6->Location = System::Drawing::Point(124, 433);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(377, 31);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Trenutna Admin Lozinka:";
			// 
			// addressTextBox
			// 
			this->addressTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->addressTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addressTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->addressTextBox->Location = System::Drawing::Point(130, 557);
			this->addressTextBox->MaxLength = 50;
			this->addressTextBox->Name = L"addressTextBox";
			this->addressTextBox->Size = System::Drawing::Size(364, 30);
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
			this->label7->Location = System::Drawing::Point(124, 523);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(119, 31);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Adresa:";
			// 
			// exceptionLabel2
			// 
			this->exceptionLabel2->AutoSize = true;
			this->exceptionLabel2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel2->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel2->Location = System::Drawing::Point(471, 681);
			this->exceptionLabel2->Name = L"exceptionLabel2";
			this->exceptionLabel2->Size = System::Drawing::Size(208, 18);
			this->exceptionLabel2->TabIndex = 25;
			this->exceptionLabel2->Text = L"Neispravno radno vreme";
			// 
			// exceptionLabel1
			// 
			this->exceptionLabel1->AutoSize = true;
			this->exceptionLabel1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel1->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel1->Location = System::Drawing::Point(526, 681);
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
			this->exceptionLabel->Location = System::Drawing::Point(425, 681);
			this->exceptionLabel->Name = L"exceptionLabel";
			this->exceptionLabel->Size = System::Drawing::Size(290, 18);
			this->exceptionLabel->TabIndex = 23;
			this->exceptionLabel->Text = L"Pogresna administratorska lozinka";
			// 
			// deleteProfileBtn
			// 
			this->deleteProfileBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)), static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->deleteProfileBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteProfileBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteProfileBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->deleteProfileBtn->Location = System::Drawing::Point(974, 18);
			this->deleteProfileBtn->Name = L"deleteProfileBtn";
			this->deleteProfileBtn->Size = System::Drawing::Size(198, 99);
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
			this->exceptionLabel3->Location = System::Drawing::Point(478, 681);
			this->exceptionLabel3->Name = L"exceptionLabel3";
			this->exceptionLabel3->Size = System::Drawing::Size(185, 18);
			this->exceptionLabel3->TabIndex = 27;
			this->exceptionLabel3->Text = L"Popunite prazna polja";
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
			this->pfpButton->Location = System::Drawing::Point(35, 149);
			this->pfpButton->Name = L"pfpButton";
			this->pfpButton->Size = System::Drawing::Size(141, 103);
			this->pfpButton->TabIndex = 38;
			this->pfpButton->Text = L"Izaberite Profilnu Sliku";
			this->pfpButton->UseVisualStyleBackColor = false;
			this->pfpButton->Click += gcnew System::EventHandler(this, &ProfileForm::pfpButton_Click);
			// 
			// label1
			// 
			this->label1->AutoEllipsis = true;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(673, 308);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(237, 31);
			this->label1->TabIndex = 39;
			this->label1->Text = L"Opis Restorana:";
			// 
			// label8
			// 
			this->label8->AutoEllipsis = true;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label8->Location = System::Drawing::Point(672, 495);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(374, 25);
			this->label8->TabIndex = 41;
			this->label8->Text = L"Tagovi (Odvojiti Sa Razmakom):";
			// 
			// descriptionTextBox
			// 
			this->descriptionTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->descriptionTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descriptionTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->descriptionTextBox->Location = System::Drawing::Point(678, 342);
			this->descriptionTextBox->Name = L"descriptionTextBox";
			this->descriptionTextBox->Size = System::Drawing::Size(369, 136);
			this->descriptionTextBox->TabIndex = 43;
			this->descriptionTextBox->Text = L"";
			// 
			// tagTextBox
			// 
			this->tagTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->tagTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tagTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->tagTextBox->Location = System::Drawing::Point(678, 523);
			this->tagTextBox->Name = L"tagTextBox";
			this->tagTextBox->Size = System::Drawing::Size(369, 54);
			this->tagTextBox->TabIndex = 44;
			this->tagTextBox->Text = L"";
			// 
			// wtClosedTextBox
			// 
			this->wtClosedTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->wtClosedTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wtClosedTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->wtClosedTextBox->Location = System::Drawing::Point(678, 624);
			this->wtClosedTextBox->MaxLength = 20;
			this->wtClosedTextBox->Name = L"wtClosedTextBox";
			this->wtClosedTextBox->Size = System::Drawing::Size(364, 30);
			this->wtClosedTextBox->TabIndex = 46;
			this->wtClosedTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ProfileForm::wtClosedTextBox_KeyPress);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label9->Location = System::Drawing::Point(672, 590);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(293, 31);
			this->label9->TabIndex = 45;
			this->label9->Text = L"Vrijeme Zatvaranja:";
			// 
			// pfpBox
			// 
			this->pfpBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pfpBox->Location = System::Drawing::Point(201, 123);
			this->pfpBox->Name = L"pfpBox";
			this->pfpBox->Size = System::Drawing::Size(764, 140);
			this->pfpBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pfpBox->TabIndex = 47;
			this->pfpBox->TabStop = false;
			// 
			// ProfileForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(1184, 792);
			this->Controls->Add(this->pfpBox);
			this->Controls->Add(this->wtClosedTextBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->tagTextBox);
			this->Controls->Add(this->descriptionTextBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pfpButton);
			this->Controls->Add(this->exceptionLabel3);
			this->Controls->Add(this->deleteProfileBtn);
			this->Controls->Add(this->exceptionLabel2);
			this->Controls->Add(this->exceptionLabel1);
			this->Controls->Add(this->exceptionLabel);
			this->Controls->Add(this->addressTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->oldAdminPassTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->passTextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->confirmRegBtn);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->wtOpenTextBox);
			this->Controls->Add(this->newAdminPassTextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(740, 684);
			this->Name = L"ProfileForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
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
		workTime wt;
		wt.timeOpen = marshal_as<std::string>(wtOpenTextBox->Text);
		wt.timeClose = marshal_as<std::string>(wtClosedTextBox->Text);

		// Convert System::String^ to std::string
		std::string stdText = marshal_as<std::string>(tagTextBox->Text);

		// Split the string into a vector of strings
		std::vector<std::string> tags;
		size_t pos = 0;
		std::string delimiter = " ";
		while ((pos = stdText.find(delimiter)) != std::string::npos)
		{
			tags.push_back(stdText.substr(0, pos));
			stdText.erase(0, pos + delimiter.length());
		}
		tags.push_back(stdText); // Add the last word
	
		switch (restUpdate(getActiveUser(),
			marshal_as<std::string>(addressTextBox->Text),
			marshal_as<std::string>(descriptionTextBox->Text),
			getProfileImagePath(),
			marshal_as<std::string>(passTextBox->Text),
			marshal_as<std::string>(newAdminPassTextBox->Text),
			marshal_as<std::string>(oldAdminPassTextBox->Text),tags,wt))
		{
		case 0:
			this->Hide();
			mainMenuForm->Show();
			exceptionLabel->Hide();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
			break;
		case 1:
			//admin sifra losa
			label3->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label6->ForeColor = System::Drawing::Color::Brown;
			label9->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			exceptionLabel->Show();
			exceptionLabel1->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
			break;
		case 2:
			//neispravan broj
			exceptionLabel->Hide();
			exceptionLabel1->Show();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
			break;
		case 4:
			//worktime ne uspesan
			label3->ForeColor = System::Drawing::Color::Brown;
			label6->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label9->ForeColor = System::Drawing::Color::Brown;
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
	private: System::Void wtOpenTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Check if the pressed key is a digit or a colon
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ':' && e->KeyChar != '\b') {
			// If it's not a digit, colon, or backspace, ignore the input
			e->Handled = true;
		}

		// If the pressed key is a digit, make sure it is in the correct position
		if (Char::IsDigit(e->KeyChar)) {
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			// If the length is already 5, ignore the input
			if (textBox != nullptr && marshal_as<std::string>(textBox->Text).length() == 5) {
				e->Handled = true;
			}
			// Check if the pressed key is a digit
			else if (Char::IsDigit(e->KeyChar)) {
				// If the first two characters are digits, insert a colon after the second character
				if (textBox != nullptr && marshal_as<std::string>(textBox->Text).length() == 2) {
					textBox->Text += ":";
					textBox->SelectionStart = marshal_as<std::string>(textBox->Text).length(); // Move the cursor to the end
				}
			}
			else if (e->KeyChar != '\b' && e->KeyChar != ':') {
				// If it's not a digit, backspace, or colon, ignore the input
				e->Handled = true;
			}
		}
	}
	private: System::Void wtClosedTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Check if the pressed key is a digit or a colon
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ':' && e->KeyChar != '\b') {
			// If it's not a digit, colon, or backspace, ignore the input
			e->Handled = true;
		}

		// If the pressed key is a digit, make sure it is in the correct position
		if (Char::IsDigit(e->KeyChar)) {
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			// If the length is already 5, ignore the input
			if (textBox != nullptr && marshal_as<std::string>(textBox->Text).length() == 5) {
				e->Handled = true;
			}
			// Check if the pressed key is a digit
			else if (Char::IsDigit(e->KeyChar)) {
				// If the first two characters are digits, insert a colon after the second character
				if (textBox != nullptr && marshal_as<std::string>(textBox->Text).length() == 2) {
					textBox->Text += ":";
					textBox->SelectionStart = marshal_as<std::string>(textBox->Text).length(); // Move the cursor to the end
				}
			}
			else if (e->KeyChar != '\b' && e->KeyChar != ':') {
				// If it's not a digit, backspace, or colon, ignore the input
				e->Handled = true;
			}
		}
	}
};
}
