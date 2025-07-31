#pragma once
#include "ProfileForm.h"
#include "RestaurantsForm.h"
#include "OrderHistoryForm.h"
namespace userApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MainMenuForm
	/// </summary>
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		Form^ loginForm;
		MainMenuForm(void)
		{
			InitializeComponent();
			container->Controls->Add(profileBtn);
			container->Controls->Add(logoutBtn);
		}
		MainMenuForm(Form^ form)
		{		
			InitializeComponent();
			user thisUser = userGet(getActiveUser());
			if (thisUser.imagePath.empty() || (ifstream(thisUser.imagePath).fail())) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("User.png"));
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(thisUser.imagePath));
			}
			loginForm = form;
			container->Controls->Add(profileBtn);
			container->Controls->Add(logoutBtn);
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ restoraniBtn;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button3;

	public:
	public: bool isExpand = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::FlowLayoutPanel^ container;



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ profileBtn;
	private: System::Windows::Forms::Button^ logoutBtn;
	private: System::ComponentModel::IContainer^ components;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainMenuForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->container = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->profileBtn = (gcnew System::Windows::Forms::Button());
			this->logoutBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->restoraniBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->container->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(260, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 61);
			this->label2->TabIndex = 2;
			this->label2->Text = L"FFDM";
			// 
			// container
			// 
			this->container->Controls->Add(this->profileBtn);
			this->container->Controls->Add(this->logoutBtn);
			this->container->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->container->Location = System::Drawing::Point(25, 117);
			this->container->MaximumSize = System::Drawing::Size(133, 200);
			this->container->Name = L"container";
			this->container->Size = System::Drawing::Size(133, 0);
			this->container->TabIndex = 4;
			// 
			// profileBtn
			// 
			this->profileBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->profileBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->profileBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->profileBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->profileBtn->Location = System::Drawing::Point(3, 0);
			this->profileBtn->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->profileBtn->Name = L"profileBtn";
			this->profileBtn->Size = System::Drawing::Size(129, 55);
			this->profileBtn->TabIndex = 6;
			this->profileBtn->Text = L"PROFIL";
			this->profileBtn->UseVisualStyleBackColor = false;
			this->profileBtn->Click += gcnew System::EventHandler(this, &MainMenuForm::profileBtn_Click);
			// 
			// logoutBtn
			// 
			this->logoutBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->logoutBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->logoutBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logoutBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->logoutBtn->Location = System::Drawing::Point(138, 0);
			this->logoutBtn->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->logoutBtn->Name = L"logoutBtn";
			this->logoutBtn->Size = System::Drawing::Size(129, 55);
			this->logoutBtn->TabIndex = 7;
			this->logoutBtn->Text = L"ODJAVA";
			this->logoutBtn->UseVisualStyleBackColor = false;
			this->logoutBtn->Click += gcnew System::EventHandler(this, &MainMenuForm::logoutBtn_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(15, 14);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 103);
			this->button1->TabIndex = 3;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainMenuForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainMenuForm::timer1_Tick_1);
			// 
			// restoraniBtn
			// 
			this->restoraniBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->restoraniBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->restoraniBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->restoraniBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->restoraniBtn->Location = System::Drawing::Point(211, 222);
			this->restoraniBtn->Name = L"restoraniBtn";
			this->restoraniBtn->Size = System::Drawing::Size(261, 84);
			this->restoraniBtn->TabIndex = 5;
			this->restoraniBtn->Text = L"RESTORANI";
			this->restoraniBtn->UseVisualStyleBackColor = false;
			this->restoraniBtn->Click += gcnew System::EventHandler(this, &MainMenuForm::restoraniBtn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Location = System::Drawing::Point(15, 14);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(143, 103);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainMenuForm::pictureBox1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->button3->Location = System::Drawing::Point(211, 357);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(261, 84);
			this->button3->TabIndex = 9;
			this->button3->Text = L"ISTORIJA NARUDZBI";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainMenuForm::button3_Click);
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(724, 591);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->restoraniBtn);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->container);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(740, 630);
			this->Name = L"MainMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Korisnicka Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_VisibleChanged);
			this->container->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		if (isExpand == false) {
			container->Height += 10;
			if (container->Height >= container->MaximumSize.Height) {
				isExpand = true;
				timer1->Stop();
			}
		}
		else {
			container->Height -= 10;
			if (container->Height <= container->MinimumSize.Height) {
				isExpand = false;
				timer1->Stop();
			}
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();
	}
	private: System::Void profileBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		
		ProfileForm^ profileForm = gcnew ProfileForm(this);
		profileForm->Show();
		this->Hide();
	}
	private: System::Void logoutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		loginForm->Show();
	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		button1_Click(sender, e);
	}
	private: System::Void MainMenuForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		user thisUser = userGet(getActiveUser());
		if (thisUser.imagePath.empty() || (ifstream(thisUser.imagePath).fail())) {
			pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("User.png"));
		}
		else {
			pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(thisUser.imagePath));
		}
	}
	private: System::Void restoraniBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		RestaurantsForm^ restaurantsForm = gcnew RestaurantsForm(this);
		restaurantsForm->Show();
		this->Hide();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		OrderHistoryForm^ orderHistoryForm = gcnew OrderHistoryForm(this);
		orderHistoryForm->Show();
		this->Hide();
	}
};
}
