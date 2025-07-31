#pragma once
#include "AuthForm.h"
#include "WorkerResourcesForm.h"
#include "MainMenuAdminForm.h"
#include "OrdersForm.h"
#include "MakeOrderForm.h"
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
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		Form^ loginForm;
		MainMenuForm(void)
		{
			InitializeComponent();
			container->Controls->Add(logoutBtn);
			container->Controls->Add(authBtn);
		}
		MainMenuForm(Form^ form)
		{
			InitializeComponent();
			loginForm = form;
			rest thisRest = restGet(getActiveUser());
			if (thisRest.imagePath.empty() || (ifstream(thisRest.imagePath).fail())) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("restUser.png"));
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(thisRest.imagePath));
			}
			container->Controls->Add(logoutBtn);
			container->Controls->Add(authBtn);
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ authBtn;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ orderBtn;

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
			this->authBtn = (gcnew System::Windows::Forms::Button());
			this->logoutBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->orderBtn = (gcnew System::Windows::Forms::Button());
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
			this->label2->Location = System::Drawing::Point(380, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 61);
			this->label2->TabIndex = 2;
			this->label2->Text = L"FFDM";
			// 
			// container
			// 
			this->container->Controls->Add(this->authBtn);
			this->container->Controls->Add(this->logoutBtn);
			this->container->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->container->Location = System::Drawing::Point(17, 115);
			this->container->MaximumSize = System::Drawing::Size(150, 130);
			this->container->Name = L"container";
			this->container->Size = System::Drawing::Size(150, 0);
			this->container->TabIndex = 4;
			// 
			// authBtn
			// 
			this->authBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->authBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->authBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->authBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->authBtn->Location = System::Drawing::Point(3, 0);
			this->authBtn->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->authBtn->Name = L"authBtn";
			this->authBtn->Size = System::Drawing::Size(147, 62);
			this->authBtn->TabIndex = 8;
			this->authBtn->Text = L"AUTENTIKACIJA";
			this->authBtn->UseVisualStyleBackColor = false;
			this->authBtn->Click += gcnew System::EventHandler(this, &MainMenuForm::authBtn_Click);
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
			this->logoutBtn->Location = System::Drawing::Point(156, 0);
			this->logoutBtn->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->logoutBtn->Name = L"logoutBtn";
			this->logoutBtn->Size = System::Drawing::Size(147, 55);
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
			this->button1->Location = System::Drawing::Point(24, 12);
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
			// loginBtn
			// 
			this->loginBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->loginBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->loginBtn->Location = System::Drawing::Point(329, 378);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(261, 84);
			this->loginBtn->TabIndex = 5;
			this->loginBtn->Text = L"NARUDZBE";
			this->loginBtn->UseVisualStyleBackColor = false;
			this->loginBtn->Click += gcnew System::EventHandler(this, &MainMenuForm::loginBtn_Click);
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
			this->button2->Location = System::Drawing::Point(329, 486);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(261, 84);
			this->button2->TabIndex = 6;
			this->button2->Text = L"RESURSI";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainMenuForm::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->pictureBox1->Location = System::Drawing::Point(173, 131);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(645, 103);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainMenuForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.InitialImage")));
			this->pictureBox2->Location = System::Drawing::Point(20, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(150, 103);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MainMenuForm::pictureBox2_Click);
			// 
			// orderBtn
			// 
			this->orderBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->orderBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->orderBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->orderBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->orderBtn->Location = System::Drawing::Point(329, 265);
			this->orderBtn->Name = L"orderBtn";
			this->orderBtn->Size = System::Drawing::Size(261, 84);
			this->orderBtn->TabIndex = 10;
			this->orderBtn->Text = L"NARUCI";
			this->orderBtn->UseVisualStyleBackColor = false;
			this->orderBtn->Click += gcnew System::EventHandler(this, &MainMenuForm::orderBtn_Click);
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(961, 651);
			this->Controls->Add(this->orderBtn);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->container);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(740, 630);
			this->Name = L"MainMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_VisibleChanged);
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
		this->Hide();
		loginForm->Show();
	}

	private: System::Void authBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		AuthForm^ authForm = gcnew AuthForm(this);
		this->Hide();
		authForm->ShowDialog();
		if (getAuth() == true) {
			MainMenuAdminForm^ mainMenuAdminForm = gcnew MainMenuAdminForm(this);
			mainMenuAdminForm->Show();
		}
		else {
			this->Show();
		}

	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		button1_Click(sender, e);
	}
	private: System::Void MainMenuForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		rest thisRest = restGet(getActiveUser());
		if (thisRest.imagePath.empty() || (ifstream(thisRest.imagePath).fail())) {
			pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("restUser.png"));
		}
		else {
			pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(thisRest.imagePath));
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		WorkerResourcesForm^ workerResourcesForm = gcnew WorkerResourcesForm(this);
		workerResourcesForm->Show();
		this->Hide();
	}
	private: System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		OrdersForm^ ordersForm = gcnew OrdersForm(this);
		ordersForm->Show();
		this->Hide();
	}
	private: System::Void orderBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		rest thisRest = restGet(getActiveUser());
		MakeOrderForm^ makeOrderForm = gcnew MakeOrderForm(thisRest,this);
		makeOrderForm->Show();
	}
};
}
