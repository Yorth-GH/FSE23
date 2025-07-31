#pragma once
#include "ArticleItem.h"
#include "CreateArticleForm.h"
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
	/// Summary for MyMenuForm
	/// </summary>
	public ref class MyMenuForm : public System::Windows::Forms::Form
	{
	public:

		Form^ previousForm;
		MyMenuForm(void)
		{
			InitializeComponent();
		}
		MyMenuForm(Form^ form)
		{
			InitializeComponent();
			previousForm = form;
			rest thisRest = restGet(getActiveUser());
			if (thisRest.imagePath.empty() || (ifstream(thisRest.imagePath).fail())) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("restUser.png"));
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(thisRest.imagePath));
			}
		}
	private: System::Windows::Forms::Button^ makeArticleBtn;
	public:

	public:

	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ menuFlowLayoutPanel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ refreshBtn;






	public:
	public: bool isExpand = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyMenuForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->makeArticleBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->menuFlowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->refreshBtn = (gcnew System::Windows::Forms::Button());
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
			this->label2->Location = System::Drawing::Point(425, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 61);
			this->label2->TabIndex = 2;
			this->label2->Text = L"MENI";
			// 
			// makeArticleBtn
			// 
			this->makeArticleBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->makeArticleBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->makeArticleBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->makeArticleBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->makeArticleBtn->Location = System::Drawing::Point(876, 9);
			this->makeArticleBtn->Name = L"makeArticleBtn";
			this->makeArticleBtn->Size = System::Drawing::Size(122, 81);
			this->makeArticleBtn->TabIndex = 6;
			this->makeArticleBtn->Text = L"KREIRAJ ARTIKL";
			this->makeArticleBtn->UseVisualStyleBackColor = false;
			this->makeArticleBtn->Click += gcnew System::EventHandler(this, &MyMenuForm::makeArticleBtn_Click);
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
			this->backBtn->Location = System::Drawing::Point(12, 12);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(120, 81);
			this->backBtn->TabIndex = 10;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &MyMenuForm::backBtn_Click);
			// 
			// menuFlowLayoutPanel
			// 
			this->menuFlowLayoutPanel->AutoScroll = true;
			this->menuFlowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->menuFlowLayoutPanel->Location = System::Drawing::Point(60, 243);
			this->menuFlowLayoutPanel->Name = L"menuFlowLayoutPanel";
			this->menuFlowLayoutPanel->Size = System::Drawing::Size(932, 464);
			this->menuFlowLayoutPanel->TabIndex = 18;
			this->menuFlowLayoutPanel->WrapContents = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->pictureBox1->Location = System::Drawing::Point(152, 97);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(764, 140);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 20;
			this->pictureBox1->TabStop = false;
			// 
			// refreshBtn
			// 
			this->refreshBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->refreshBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->refreshBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->refreshBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->refreshBtn->Location = System::Drawing::Point(754, 10);
			this->refreshBtn->Name = L"refreshBtn";
			this->refreshBtn->Size = System::Drawing::Size(116, 81);
			this->refreshBtn->TabIndex = 21;
			this->refreshBtn->Text = L"OSVJEZI";
			this->refreshBtn->UseVisualStyleBackColor = false;
			this->refreshBtn->Click += gcnew System::EventHandler(this, &MyMenuForm::refreshBtn_Click);
			// 
			// MyMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(1040, 733);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->refreshBtn);
			this->Controls->Add(this->menuFlowLayoutPanel);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->makeArticleBtn);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1056, 772);
			this->MinimumSize = System::Drawing::Size(1056, 772);
			this->Name = L"MyMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &MyMenuForm::MyMenuForm_VisibleChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		previousForm->Show();
	}
	private: System::Void makeArticleBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateArticleForm^ createArticleForm = gcnew CreateArticleForm(this);
		createArticleForm->Show();
		this->Hide();
	}
	private: System::Void MyMenuForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		bool exists = false;
		vector<article> articles = parseArticlesFromRest(getActiveUser());
		for each (article art in articles) {
			String^ existingResName = marshal_as<String^>(art.name);
			ArticleItem^ item = gcnew ArticleItem(art.name,art.desc,art.imagePath,art.id, art.price);
			for each (Control ^ control in menuFlowLayoutPanel->Controls) {
				ArticleItem^ existingItem = dynamic_cast<ArticleItem^>(control);
				if ((existingItem->ArticleName == item->ArticleName)) {
					exists = true;
				}
			}
			if (exists == false) {
				menuFlowLayoutPanel->Controls->Add(item);
			}
			exists = false;
		}

		rest thisRest = restGet(getActiveUser());
		if (thisRest.imagePath.empty() || (ifstream(thisRest.imagePath).fail())) {
			pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("restUser.png"));
		}
		else {
			pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(thisRest.imagePath));
		}
	}
	private: System::Void refreshBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MyMenuForm^ myMenuForm = gcnew MyMenuForm(previousForm);
		myMenuForm->Show();
		this->Close();
	}
};
}
