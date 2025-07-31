#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "MakeOrderArticleItem.h"
#include "SendOrderForm.h"
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
	public ref class MakeOrderForm : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		MakeOrderForm(void)
		{
			InitializeComponent();
		}
		MakeOrderForm(rest restt)
		{

			InitializeComponent();
			restUsernameLabel->Text = marshal_as<String^>(restt.username);
			restNameLabel->Text = marshal_as<String^>(restt.name);
			restDescriptionLabel->Text = marshal_as<String^>(restt.desc);
			if (restt.imagePath.empty()) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("User.png"));
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(restt.imagePath));
			}
			string workTime = restt.wt.timeOpen + "-" + restt.wt.timeClose;
			wtLabel->Text = marshal_as<String^>(workTime);
		}
		MakeOrderForm(rest restt, Form^ form)
		{

			InitializeComponent();
			previousForm = form;
			restUsernameLabel->Text = marshal_as<String^>(restt.username);
			restNameLabel->Text = marshal_as<String^>(restt.name);
			restDescriptionLabel->Text = marshal_as<String^>(restt.desc);
			if (restt.imagePath.empty()) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("User.png"));
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(restt.imagePath));
			}
			string workTime = restt.wt.timeOpen + "-" + restt.wt.timeClose;
			wtLabel->Text = marshal_as<String^>(workTime);
		}

	public:
	public:
	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ menuFlowLayoutPanel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ restDescriptionLabel;
	private: System::Windows::Forms::Label^ wtLabel;


	private: System::Windows::Forms::Button^ orderBtn;

	private: System::Windows::Forms::Label^ restUsernameLabel;
	private: System::Windows::Forms::TextBox^ searchTextBox;

	private: System::Windows::Forms::Label^ label2;



	public:
	public: bool isExpand = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MakeOrderForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ restNameLabel;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MakeOrderForm::typeid));
			this->restNameLabel = (gcnew System::Windows::Forms::Label());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->menuFlowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->restDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->wtLabel = (gcnew System::Windows::Forms::Label());
			this->orderBtn = (gcnew System::Windows::Forms::Button());
			this->restUsernameLabel = (gcnew System::Windows::Forms::Label());
			this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// restNameLabel
			// 
			this->restNameLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->restNameLabel->AutoSize = true;
			this->restNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->restNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->restNameLabel->Location = System::Drawing::Point(122, 9);
			this->restNameLabel->Name = L"restNameLabel";
			this->restNameLabel->Size = System::Drawing::Size(275, 61);
			this->restNameLabel->TabIndex = 2;
			this->restNameLabel->Text = L"Restoran";
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
			this->backBtn->Location = System::Drawing::Point(5, 7);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(111, 63);
			this->backBtn->TabIndex = 10;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &MakeOrderForm::backBtn_Click);
			// 
			// menuFlowLayoutPanel
			// 
			this->menuFlowLayoutPanel->AutoScroll = true;
			this->menuFlowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->menuFlowLayoutPanel->Location = System::Drawing::Point(1, 309);
			this->menuFlowLayoutPanel->Name = L"menuFlowLayoutPanel";
			this->menuFlowLayoutPanel->Size = System::Drawing::Size(783, 413);
			this->menuFlowLayoutPanel->TabIndex = 18;
			this->menuFlowLayoutPanel->WrapContents = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(1, 73);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(783, 160);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 24;
			this->pictureBox1->TabStop = false;
			// 
			// restDescriptionLabel
			// 
			this->restDescriptionLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->restDescriptionLabel->AutoSize = true;
			this->restDescriptionLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->restDescriptionLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->restDescriptionLabel->Location = System::Drawing::Point(4, 236);
			this->restDescriptionLabel->Name = L"restDescriptionLabel";
			this->restDescriptionLabel->Size = System::Drawing::Size(104, 23);
			this->restDescriptionLabel->TabIndex = 25;
			this->restDescriptionLabel->Text = L"Restoran";
			// 
			// wtLabel
			// 
			this->wtLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->wtLabel->AutoSize = true;
			this->wtLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wtLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->wtLabel->Location = System::Drawing::Point(632, 47);
			this->wtLabel->Name = L"wtLabel";
			this->wtLabel->Size = System::Drawing::Size(130, 23);
			this->wtLabel->TabIndex = 26;
			this->wtLabel->Text = L"00:00-00:00";
			// 
			// orderBtn
			// 
			this->orderBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->orderBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->orderBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->orderBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->orderBtn->Location = System::Drawing::Point(604, 742);
			this->orderBtn->Name = L"orderBtn";
			this->orderBtn->Size = System::Drawing::Size(158, 53);
			this->orderBtn->TabIndex = 29;
			this->orderBtn->Text = L"NARUCI";
			this->orderBtn->UseVisualStyleBackColor = false;
			this->orderBtn->Click += gcnew System::EventHandler(this, &MakeOrderForm::orderBtn_Click);
			// 
			// restUsernameLabel
			// 
			this->restUsernameLabel->AutoSize = true;
			this->restUsernameLabel->Location = System::Drawing::Point(122, 9);
			this->restUsernameLabel->Name = L"restUsernameLabel";
			this->restUsernameLabel->Size = System::Drawing::Size(35, 13);
			this->restUsernameLabel->TabIndex = 32;
			this->restUsernameLabel->Text = L"label1";
			this->restUsernameLabel->Visible = false;
			// 
			// searchTextBox
			// 
			this->searchTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->searchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->searchTextBox->Location = System::Drawing::Point(496, 273);
			this->searchTextBox->MaxLength = 20;
			this->searchTextBox->Name = L"searchTextBox";
			this->searchTextBox->Size = System::Drawing::Size(276, 30);
			this->searchTextBox->TabIndex = 33;
			this->searchTextBox->TextChanged += gcnew System::EventHandler(this, &MakeOrderForm::searchTextBox_TextChanged);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(682, 247);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 23);
			this->label2->TabIndex = 34;
			this->label2->Text = L"Pretrazi";
			// 
			// MakeOrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(777, 807);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->searchTextBox);
			this->Controls->Add(this->restUsernameLabel);
			this->Controls->Add(this->orderBtn);
			this->Controls->Add(this->wtLabel);
			this->Controls->Add(this->restDescriptionLabel);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuFlowLayoutPanel);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->restNameLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MakeOrderForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &MakeOrderForm::MyMenuForm_VisibleChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		previousForm->Show();
		this->Close();
	}

	private: System::Void MyMenuForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {

		bool exists = false;
		vector<article> articles = parseArticlesFromRestSpecial(marshal_as<string>(restUsernameLabel->Text));
		for each (article art in articles) {
			String^ existingResName = marshal_as<String^>(art.name);
			MakeOrderArticleItem^ item = gcnew MakeOrderArticleItem(art.name, art.desc, art.imagePath, art.tags, art.price, true);
			for each (Control ^ control in menuFlowLayoutPanel->Controls) {
				MakeOrderArticleItem^ existingItem = dynamic_cast<MakeOrderArticleItem^>(control);
				if ((existingItem->ArticleName == item->ArticleName)) {
					exists = true;
				}
			}
			if (exists == false) {
				menuFlowLayoutPanel->Controls->Add(item);
			}
			exists = false;
		}

	}
	private: System::Void searchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		for each (Control ^ control in menuFlowLayoutPanel->Controls) {
			MakeOrderArticleItem^ item = dynamic_cast<MakeOrderArticleItem^>(control);
			item->Visible = ((item->ArticleName->ToLower()->Contains(searchTextBox->Text->ToLower())) ||
				(item->ArticleTags->ToLower()->Contains(searchTextBox->Text->ToLower())));
		}
	}
	private: System::Void orderBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		vector <article> articles;
		vector <int> artOrdAmount;
		for each (Control ^ control in menuFlowLayoutPanel->Controls) {
			MakeOrderArticleItem^ item = dynamic_cast<MakeOrderArticleItem^>(control);
			if (item->getAmountOrd() != 0) {
				article art;
				art.name = marshal_as<string>(item->ArticleName);
				art.desc = marshal_as<string>(item->ArticleDestription);
				art.price = item->price;
				art.imagePath = marshal_as<string>(item->ArticleImagePath);
				// Convert String^ to std::string
				string textStdString = msclr::interop::marshal_as<std::string>(item->ArticleTags);

				// Split the std::string into words
				std::istringstream iss(textStdString);
				std::vector<std::string> tagVector(std::istream_iterator<std::string>{iss},
					std::istream_iterator<std::string>());
				art.tags = tagVector;
				articles.push_back(art);
				artOrdAmount.push_back(item->getAmountOrd());
			}
		}
		SendOrderForm^ sendOrderForm = gcnew SendOrderForm(this, articles, artOrdAmount, marshal_as<string>(restNameLabel->Text), marshal_as<string>(restUsernameLabel->Text));
		sendOrderForm->Show();
		this->Hide();
	}
	};
}
