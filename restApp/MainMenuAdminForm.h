#pragma once
#include "ProfileForm.h"
#include "ResourcesForm.h"
#include "MyMenuForm.h"
#include "RestaurantAdminView.h"
namespace restApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MainMenuForm
	/// </summary>
	public ref class MainMenuAdminForm : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		MainMenuAdminForm(void)
		{
			InitializeComponent();
			container->Controls->Add(logoutBtn);
			container->Controls->Add(deAuthBtn);
		}
		MainMenuAdminForm(Form^ form)
		{
			InitializeComponent();
			rest thisRest = restGet(getActiveUser());
			if (thisRest.imagePath.empty() || (ifstream(thisRest.imagePath).fail())) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("restUser.png"));
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(thisRest.imagePath));
			}
			previousForm = form;
			container->Controls->Add(logoutBtn);
			container->Controls->Add(deAuthBtn);
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ myMenuBtn;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ deAuthBtn;

	private: System::Windows::Forms::Button^ profileBtn;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button3;

	public:
	public: bool isExpand = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainMenuAdminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::FlowLayoutPanel^ container;



	private: System::Windows::Forms::Button^ button1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainMenuAdminForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->container = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->deAuthBtn = (gcnew System::Windows::Forms::Button());
			this->profileBtn = (gcnew System::Windows::Forms::Button());
			this->logoutBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->myMenuBtn = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->container->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->label2->Location = System::Drawing::Point(294, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(392, 61);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ADMIN FFDM";
			// 
			// container
			// 
			this->container->Controls->Add(this->deAuthBtn);
			this->container->Controls->Add(this->profileBtn);
			this->container->Controls->Add(this->logoutBtn);
			this->container->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->container->Location = System::Drawing::Point(9, 127);
			this->container->MaximumSize = System::Drawing::Size(150, 200);
			this->container->Name = L"container";
			this->container->Size = System::Drawing::Size(150, 0);
			this->container->TabIndex = 4;
			// 
			// deAuthBtn
			// 
			this->deAuthBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->deAuthBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deAuthBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deAuthBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->deAuthBtn->Location = System::Drawing::Point(3, 0);
			this->deAuthBtn->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->deAuthBtn->Name = L"deAuthBtn";
			this->deAuthBtn->Size = System::Drawing::Size(147, 55);
			this->deAuthBtn->TabIndex = 8;
			this->deAuthBtn->Text = L"NAZAD";
			this->deAuthBtn->UseVisualStyleBackColor = false;
			this->deAuthBtn->Click += gcnew System::EventHandler(this, &MainMenuAdminForm::deAuthBtn_Click);
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
			this->profileBtn->Location = System::Drawing::Point(156, 0);
			this->profileBtn->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->profileBtn->Name = L"profileBtn";
			this->profileBtn->Size = System::Drawing::Size(147, 55);
			this->profileBtn->TabIndex = 9;
			this->profileBtn->Text = L"PROFIL";
			this->profileBtn->UseVisualStyleBackColor = false;
			this->profileBtn->Click += gcnew System::EventHandler(this, &MainMenuAdminForm::profileBtn_Click);
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
			this->logoutBtn->Location = System::Drawing::Point(309, 0);
			this->logoutBtn->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->logoutBtn->Name = L"logoutBtn";
			this->logoutBtn->Size = System::Drawing::Size(147, 55);
			this->logoutBtn->TabIndex = 7;
			this->logoutBtn->Text = L"ODJAVA";
			this->logoutBtn->UseVisualStyleBackColor = false;
			this->logoutBtn->Click += gcnew System::EventHandler(this, &MainMenuAdminForm::logoutBtn_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(9, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 103);
			this->button1->TabIndex = 3;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainMenuAdminForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainMenuAdminForm::timer1_Tick_1);
			// 
			// myMenuBtn
			// 
			this->myMenuBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->myMenuBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->myMenuBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->myMenuBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->myMenuBtn->Location = System::Drawing::Point(318, 291);
			this->myMenuBtn->Name = L"myMenuBtn";
			this->myMenuBtn->Size = System::Drawing::Size(261, 84);
			this->myMenuBtn->TabIndex = 5;
			this->myMenuBtn->Text = L"KREIRAJ MENI";
			this->myMenuBtn->UseVisualStyleBackColor = false;
			this->myMenuBtn->Click += gcnew System::EventHandler(this, &MainMenuAdminForm::myMenuBtn_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->button2->Location = System::Drawing::Point(318, 405);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(261, 84);
			this->button2->TabIndex = 6;
			this->button2->Text = L"RESURSI";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainMenuAdminForm::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->pictureBox1->Location = System::Drawing::Point(165, 143);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(645, 103);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainMenuAdminForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.InitialImage")));
			this->pictureBox2->Location = System::Drawing::Point(12, 24);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(150, 103);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 8;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MainMenuAdminForm::pictureBox2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->button3->Location = System::Drawing::Point(318, 521);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(261, 84);
			this->button3->TabIndex = 9;
			this->button3->Text = L"PREGLED RESTORANA";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainMenuAdminForm::button3_Click);
			// 
			// MainMenuAdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(961, 674);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->myMenuBtn);
			this->Controls->Add(this->container);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(977, 630);
			this->Name = L"MainMenuAdminForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &MainMenuAdminForm::MainMenuAdminForm_VisibleChanged);
			this->container->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
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
	private: System::Void logoutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Restart();
	}

	private: System::Void deAuthBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		setAuth(false);
		this->Hide();
		previousForm->Show();
	}

	private: System::Void profileBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ProfileForm^ profileForm = gcnew ProfileForm(this);
		profileForm->Show();
		this->Hide();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		ResourcesForm^ resForm = gcnew ResourcesForm(this);
		resForm->Show();
		this->Hide();
	}
	private: System::Void myMenuBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MyMenuForm^ myMenuForm = gcnew MyMenuForm(this);
		myMenuForm->Show();
		this->Hide();
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		button1_Click(sender, e);
	}
	private: System::Void MainMenuAdminForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		rest thisRest = restGet(getActiveUser());
		if (thisRest.imagePath.empty() || (ifstream(thisRest.imagePath).fail())) {
			pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("restUser.png"));
		}
		else {
			pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(thisRest.imagePath));
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		rest thisrest = restGet(getActiveUser());
		RestaurantAdminView^ restAdminView = gcnew RestaurantAdminView(thisrest,this);
		restAdminView->Show();
		this->Hide();
	}
};
}
