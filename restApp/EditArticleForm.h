#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "UsedResourceItem.h"
#include "ResourcesForm.h"
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
	public ref class EditArticleForm : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		EditArticleForm(void)
		{
			InitializeComponent();
			rest thisRest = restGet(getActiveUser());

			for each (ingr ing in thisRest.inventory) {
				String^ existingResName = marshal_as<String^>(ing.name);
				UsedResourceItem^ item = gcnew UsedResourceItem(marshal_as<std::string>(existingResName), 0);
				resLayoutTable->Controls->Add(item);
			}

			for (const auto& str : getArticleTags()) {
				tagCheckListBox->Items->Add(gcnew System::String(str.c_str()));
			}

		}
		EditArticleForm(article artt)
		{
			InitializeComponent();
			articleNameTextBox->Text = marshal_as<System::String^>(artt.name);
			priceTextBox->Text = artt.price.ToString();
			descriptionTextBox->Text = marshal_as<System::String^>(artt.desc);	
			if (!artt.imagePath.empty()) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(artt.imagePath));
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("Food.png"));
			}
			
			//TODO: tagove i resurse prikazati u trenutnom stanju
			rest thisRest = restGet(getActiveUser());

			for each (ingr ing in thisRest.inventory) {
				String^ existingResName = marshal_as<String^>(ing.name);
				UsedResourceItem^ item = gcnew UsedResourceItem(marshal_as<std::string>(existingResName), 0);
				resLayoutTable->Controls->Add(item);
			}

			for (const auto& str : getArticleTags()) {
				tagCheckListBox->Items->Add(gcnew System::String(str.c_str()));
			}
			backBtn->Click += gcnew System::EventHandler(this, &EditArticleForm::backBtn_Click);
		}
		EditArticleForm(Form^ form, article artt)
		{
			InitializeComponent();
			articleNameTextBox->Text =marshal_as<System::String^>(artt.name);
			priceTextBox->Text =marshal_as<System::String^>(artt.name);
			descriptionTextBox->Text =marshal_as<System::String^>(artt.name);
			pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(artt.imagePath));
			//TODO: tagove i resurse prikazati u trenutnom stanju
			rest thisRest = restGet(getActiveUser());

			for each (ingr ing in thisRest.inventory) {
				String^ existingResName = marshal_as<String^>(ing.name);
				UsedResourceItem^ item = gcnew UsedResourceItem(marshal_as<std::string>(existingResName), 0);
				resLayoutTable->Controls->Add(item);
			}

			for (const auto& str : getArticleTags()) {
				tagCheckListBox->Items->Add(gcnew System::String(str.c_str()));
			}

			previousForm = form;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditArticleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::Button^ confirmRegBtn;
	private: System::Windows::Forms::TextBox^ articleNameTextBox;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ pfpButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::RichTextBox^ descriptionTextBox;

	private: System::Windows::Forms::Label^ label3;



	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::CheckedListBox^ tagCheckListBox;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::FlowLayoutPanel^ resLayoutTable;
	private: System::Windows::Forms::TextBox^ priceTextBox;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditArticleForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->confirmRegBtn = (gcnew System::Windows::Forms::Button());
			this->articleNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pfpButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->descriptionTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tagCheckListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->resLayoutTable = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->priceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(321, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(554, 61);
			this->label2->TabIndex = 1;
			this->label2->Text = L"AZURIRAJ ARTIKLE";
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
			this->backBtn->Location = System::Drawing::Point(67, 31);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(109, 75);
			this->backBtn->TabIndex = 9;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &EditArticleForm::backBtn_Click);
			// 
			// confirmRegBtn
			// 
			this->confirmRegBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->confirmRegBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->confirmRegBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmRegBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->confirmRegBtn->Location = System::Drawing::Point(496, 736);
			this->confirmRegBtn->Name = L"confirmRegBtn";
			this->confirmRegBtn->Size = System::Drawing::Size(198, 52);
			this->confirmRegBtn->TabIndex = 10;
			this->confirmRegBtn->Text = L"AZURIRAJ";
			this->confirmRegBtn->UseVisualStyleBackColor = false;
			this->confirmRegBtn->Click += gcnew System::EventHandler(this, &EditArticleForm::confirmRegBtn_Click);
			// 
			// articleNameTextBox
			// 
			this->articleNameTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->articleNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleNameTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articleNameTextBox->Location = System::Drawing::Point(149, 179);
			this->articleNameTextBox->MaxLength = 20;
			this->articleNameTextBox->Name = L"articleNameTextBox";
			this->articleNameTextBox->ReadOnly = true;
			this->articleNameTextBox->Size = System::Drawing::Size(369, 30);
			this->articleNameTextBox->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoEllipsis = true;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label7->Location = System::Drawing::Point(234, 145);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(174, 31);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Ime Artikla";
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
			this->pfpButton->Location = System::Drawing::Point(667, 179);
			this->pfpButton->Name = L"pfpButton";
			this->pfpButton->Size = System::Drawing::Size(143, 103);
			this->pfpButton->TabIndex = 38;
			this->pfpButton->Text = L"Slika Artikla";
			this->pfpButton->UseVisualStyleBackColor = false;
			this->pfpButton->Click += gcnew System::EventHandler(this, &EditArticleForm::pfpButton_Click);
			// 
			// label1
			// 
			this->label1->AutoEllipsis = true;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(234, 299);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 31);
			this->label1->TabIndex = 39;
			this->label1->Text = L"Opis Artikla:";
			// 
			// label8
			// 
			this->label8->AutoEllipsis = true;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label8->Location = System::Drawing::Point(257, 468);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(139, 39);
			this->label8->TabIndex = 41;
			this->label8->Text = L"Tagovi";
			// 
			// descriptionTextBox
			// 
			this->descriptionTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->descriptionTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descriptionTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->descriptionTextBox->Location = System::Drawing::Point(149, 333);
			this->descriptionTextBox->Name = L"descriptionTextBox";
			this->descriptionTextBox->Size = System::Drawing::Size(369, 136);
			this->descriptionTextBox->TabIndex = 43;
			this->descriptionTextBox->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoEllipsis = true;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label3->Location = System::Drawing::Point(271, 230);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 31);
			this->label3->TabIndex = 46;
			this->label3->Text = L"Cijena";
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
			this->button2->Location = System::Drawing::Point(918, 31);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(192, 84);
			this->button2->TabIndex = 50;
			this->button2->Text = L"RESURSI";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &EditArticleForm::button2_Click);
			// 
			// tagCheckListBox
			// 
			this->tagCheckListBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->tagCheckListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tagCheckListBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->tagCheckListBox->FormattingEnabled = true;
			this->tagCheckListBox->Location = System::Drawing::Point(149, 510);
			this->tagCheckListBox->Name = L"tagCheckListBox";
			this->tagCheckListBox->Size = System::Drawing::Size(369, 202);
			this->tagCheckListBox->TabIndex = 51;
			// 
			// label5
			// 
			this->label5->AutoEllipsis = true;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label5->Location = System::Drawing::Point(661, 316);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(394, 31);
			this->label5->TabIndex = 53;
			this->label5->Text = L"Potrebna Kolicina Resursa:";
			// 
			// resLayoutTable
			// 
			this->resLayoutTable->AutoScroll = true;
			this->resLayoutTable->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->resLayoutTable->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->resLayoutTable->Location = System::Drawing::Point(667, 350);
			this->resLayoutTable->Name = L"resLayoutTable";
			this->resLayoutTable->Size = System::Drawing::Size(443, 362);
			this->resLayoutTable->TabIndex = 54;
			this->resLayoutTable->WrapContents = false;
			// 
			// priceTextBox
			// 
			this->priceTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->priceTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->priceTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->priceTextBox->Location = System::Drawing::Point(149, 266);
			this->priceTextBox->MaxLength = 20;
			this->priceTextBox->Name = L"priceTextBox";
			this->priceTextBox->Size = System::Drawing::Size(369, 30);
			this->priceTextBox->TabIndex = 55;
			this->priceTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditArticleForm::priceTextBox_KeyPress);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Location = System::Drawing::Point(844, 179);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(143, 103);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 56;
			this->pictureBox1->TabStop = false;
			// 
			// EditArticleForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(1168, 800);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->priceTextBox);
			this->Controls->Add(this->resLayoutTable);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tagCheckListBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->descriptionTextBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pfpButton);
			this->Controls->Add(this->articleNameTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->confirmRegBtn);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(740, 684);
			this->Name = L"EditArticleForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &EditArticleForm::EditArticleForm_VisibleChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Hide();
		//previousForm->Show();
	}
	private: System::Void confirmRegBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		article newArt;
		newArt.name = marshal_as<std::string>(articleNameTextBox->Text);
		newArt.desc = marshal_as<std::string>(descriptionTextBox->Text);
		if (String::IsNullOrEmpty(priceTextBox->Text)) {
			priceTextBox->Text = "0";
			newArt.price = 0;
		}
		else {
			newArt.price = Convert::ToDouble(priceTextBox->Text);
		}
		newArt.imagePath = getProfileImagePath();
		vector<ingr> resVector;
		for each (Control ^ control in resLayoutTable->Controls) {
			UsedResourceItem^ usedRes = dynamic_cast<UsedResourceItem^>(control);	
				ingr ingredient;
				ingredient.name = marshal_as<std::string>(usedRes->ResourceName);
				ingredient.amnt = usedRes->amountUsed;
				resVector.push_back(ingredient);
		}
		newArt.ingredients = resVector;
		vector<string> tagVector;
		for each (auto itemChecked in tagCheckListBox->CheckedItems)
		{
			string selection = marshal_as<std::string>(itemChecked->ToString());
			tagVector.push_back(selection);
		}
		newArt.tags = tagVector;
		switch (articleUpdate(getActiveUser(), newArt)) {
		case 0:
			articleNameTextBox->Text = "";
			priceTextBox->Text = "";
			descriptionTextBox->Text = "";
			for each (int index in tagCheckListBox->CheckedIndices) {
				tagCheckListBox->SetItemChecked(index, false);
			}
			for each (Control ^ control in resLayoutTable->Controls) {
				UsedResourceItem^ usedRes = dynamic_cast<UsedResourceItem^>(control);
				usedRes->amountUsed = 0;
			}
			pictureBox1->Image = nullptr;
			MessageBox::Show("Uspesno ste azurirali artikal.\n Osvezite prethodni prozor da vidite promene.", "Uspeh Azuriranja", MessageBoxButtons::OK,
				MessageBoxIcon::Information);
			// Set DialogResult to OK to indicate success
			this->DialogResult = System::Windows::Forms::DialogResult::OK;

			// Close the form
			this->Close();
			break;
		case 3:
			label5->ForeColor = System::Drawing::Color::Brown;
			label8->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			MessageBox::Show("Niste podesili sastojke artikla.", "Greska u Azuriranju", MessageBoxButtons::OK,
				MessageBoxIcon::Information);
			break;
		case 4:
			label5->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			label8->ForeColor = System::Drawing::Color::Brown;
			MessageBox::Show("Niste podesili tagove artikla.", "Greska u Azuriranju", MessageBoxButtons::OK,
				MessageBoxIcon::Information);
			break;
		}

	}
	private: System::Void deleteProfileBtn_Click(System::Object^ sender, System::EventArgs^ e) {
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
				pictureBox1->Image = Image::FromStream(myStream);
				setProfileImagePath(marshal_as<std::string>(Dialog1->FileName));
				myStream->Close();
			}
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		ResourcesForm^ resourcesForm = gcnew ResourcesForm(this);
		resourcesForm->Show();
		this->Hide();
	}
	private: System::Void EditArticleForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		bool exists = false;
		rest thisRest = restGet(getActiveUser());
		for each (ingr ing in thisRest.inventory) {
			String^ existingResName = marshal_as<String^>(ing.name);
			UsedResourceItem^ item = gcnew UsedResourceItem(marshal_as<std::string>(existingResName), ing.amnt);
			for each (Control ^ control in resLayoutTable->Controls) {
				UsedResourceItem^ existingItem = dynamic_cast<UsedResourceItem^>(control);
				if ((existingItem->ResourceName == item->ResourceName)) {
					exists = true;
				}
			}
			if (exists == false) {
				resLayoutTable->Controls->Add(item);
			}
			exists = false;
		}
	}

	private: System::Void priceTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);

		// Check if the pressed key is a digit or a dot
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '.' && e->KeyChar != '\b') {
			// If it's not a digit, dot, or backspace, ignore the input
			e->Handled = true;
		}

		// If the pressed key is a digit, check the position of the dot and limit decimal places
		if (Char::IsDigit(e->KeyChar) && textBox != nullptr) {
			std::string text = marshal_as<std::string>(textBox->Text);

			// Find the position of the dot
			size_t dotPosition = text.find('.');

			// If the dot is not present or if there are less than 2 decimal places after the dot
			if (dotPosition == std::string::npos || text.length() - dotPosition <= 2) {
				// Allow the input
				e->Handled = false;
			}
			else {
				// Ignore the input if more than 2 decimal places are present
				e->Handled = true;
			}
		}
	}
	};
}
