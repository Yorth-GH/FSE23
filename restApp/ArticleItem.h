#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "EditArticleForm.h"
using namespace msclr::interop;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace restApp {

	/// <summary>
	/// Summary for ResourceItem
	/// </summary>
	public ref class ArticleItem : public System::Windows::Forms::UserControl
	{
	public:
		property String^ ArticleName {
			String^ get() {
				return articleNameLabel->Text;
			}
			void set(String^ value) {
				articleNameLabel->Text = value;
			}
		}

		property String^ ArticleID {
			String^ get() {
				return artIDLabel->Text;
			}
			void set(String^ value) {
				artIDLabel->Text = value;
			}
		}

		property String^ ArticleDestription {
			String^ get() {
				return articleDescriptionLabel->Text;
			}
			void set(String^ value) {
				articleDescriptionLabel->Text = value;
			}
		}

		int price;
		void setPrice(int arg) {
			price = arg;
		}
		int getPrice() {
			return price;
		}

		// Event to notify subscribers about the button click
		event System::EventHandler^ EditBtnClicked;

	
		ArticleItem(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ArticleItem(string name,string description,string imagePatharg, uiid ID ,double pricearg)
		{
			InitializeComponent();
			ArticleName = msclr::interop::marshal_as<String^>(name);
			articleNameLabel->Text = ArticleName;

			ArticleDestription = msclr::interop::marshal_as<String^>(description);
			articleDescriptionLabel->Text = ArticleDestription;

			if (imagePatharg.empty()) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("Food.png"));
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(imagePatharg));
			}
			articlePriceLabel->Text = System::Convert::ToString(pricearg)+" KM";;		
			setPrice(pricearg);

			ArticleID = Convert::ToString(ID);
			artIDLabel->Text = ArticleID;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ArticleItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ articleNameLabel;
	protected:
	protected:
	protected:
	protected:
	private: System::Windows::Forms::Label^ articleDescriptionLabel;
	private: System::Windows::Forms::Label^ articlePriceLabel;
	private: System::Windows::Forms::Button^ articleEditBtn;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ deleteResBtn;
	private: System::Windows::Forms::Label^ articleImagePathLabel;
	private: System::Windows::Forms::Label^ artIDLabel;

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
			this->articleNameLabel = (gcnew System::Windows::Forms::Label());
			this->articleDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->articlePriceLabel = (gcnew System::Windows::Forms::Label());
			this->articleEditBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->deleteResBtn = (gcnew System::Windows::Forms::Button());
			this->articleImagePathLabel = (gcnew System::Windows::Forms::Label());
			this->artIDLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// articleNameLabel
			// 
			this->articleNameLabel->AutoSize = true;
			this->articleNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articleNameLabel->Location = System::Drawing::Point(155, 10);
			this->articleNameLabel->Name = L"articleNameLabel";
			this->articleNameLabel->Size = System::Drawing::Size(199, 31);
			this->articleNameLabel->TabIndex = 2;
			this->articleNameLabel->Text = L"IME ARTIKLA";
			this->articleNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// articleDescriptionLabel
			// 
			this->articleDescriptionLabel->AutoSize = true;
			this->articleDescriptionLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleDescriptionLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articleDescriptionLabel->Location = System::Drawing::Point(158, 49);
			this->articleDescriptionLabel->Name = L"articleDescriptionLabel";
			this->articleDescriptionLabel->Size = System::Drawing::Size(103, 16);
			this->articleDescriptionLabel->TabIndex = 18;
			this->articleDescriptionLabel->Text = L"OPIS ARTIKLA";
			this->articleDescriptionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// articlePriceLabel
			// 
			this->articlePriceLabel->AutoSize = true;
			this->articlePriceLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articlePriceLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articlePriceLabel->Location = System::Drawing::Point(608, 10);
			this->articlePriceLabel->Name = L"articlePriceLabel";
			this->articlePriceLabel->Size = System::Drawing::Size(133, 31);
			this->articlePriceLabel->TabIndex = 20;
			this->articlePriceLabel->Text = L"00.00KM";
			this->articlePriceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// articleEditBtn
			// 
			this->articleEditBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->articleEditBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->articleEditBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleEditBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->articleEditBtn->Location = System::Drawing::Point(788, 10);
			this->articleEditBtn->Name = L"articleEditBtn";
			this->articleEditBtn->Size = System::Drawing::Size(98, 60);
			this->articleEditBtn->TabIndex = 21;
			this->articleEditBtn->Text = L"AZURIRAJ";
			this->articleEditBtn->UseVisualStyleBackColor = false;
			this->articleEditBtn->Click += gcnew System::EventHandler(this, &ArticleItem::articleEditBtn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(15, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(113, 102);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 23;
			this->pictureBox1->TabStop = false;
			// 
			// deleteResBtn
			// 
			this->deleteResBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->deleteResBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteResBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteResBtn->ForeColor = System::Drawing::Color::Red;
			this->deleteResBtn->Location = System::Drawing::Point(788, 76);
			this->deleteResBtn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->deleteResBtn->Name = L"deleteResBtn";
			this->deleteResBtn->Size = System::Drawing::Size(98, 60);
			this->deleteResBtn->TabIndex = 24;
			this->deleteResBtn->Text = L"OBRISI";
			this->deleteResBtn->UseVisualStyleBackColor = false;
			this->deleteResBtn->Click += gcnew System::EventHandler(this, &ArticleItem::deleteResBtn_Click);
			// 
			// articleImagePathLabel
			// 
			this->articleImagePathLabel->AutoSize = true;
			this->articleImagePathLabel->Location = System::Drawing::Point(15, 122);
			this->articleImagePathLabel->Name = L"articleImagePathLabel";
			this->articleImagePathLabel->Size = System::Drawing::Size(0, 13);
			this->articleImagePathLabel->TabIndex = 25;
			this->articleImagePathLabel->Visible = false;
			// 
			// artIDLabel
			// 
			this->artIDLabel->AutoSize = true;
			this->artIDLabel->Location = System::Drawing::Point(268, 45);
			this->artIDLabel->Name = L"artIDLabel";
			this->artIDLabel->Size = System::Drawing::Size(56, 13);
			this->artIDLabel->TabIndex = 26;
			this->artIDLabel->Text = L"artIDLabel";
			this->artIDLabel->Visible = false;
			// 
			// ArticleItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->Controls->Add(this->artIDLabel);
			this->Controls->Add(this->articleImagePathLabel);
			this->Controls->Add(this->deleteResBtn);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->articleEditBtn);
			this->Controls->Add(this->articlePriceLabel);
			this->Controls->Add(this->articleDescriptionLabel);
			this->Controls->Add(this->articleNameLabel);
			this->Name = L"ArticleItem";
			this->Size = System::Drawing::Size(901, 144);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void articleEditBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		article artt;
		rest thisRest = restGet(getActiveUser());

		artt.name =marshal_as<string>(articleNameLabel->Text);
		artt.desc =marshal_as<string>(articleDescriptionLabel->Text);
		string priceString = marshal_as<string>(articlePriceLabel->Text);
		
		if (priceString.length() >= 2) {
			// Subtract the last two characters
			string result = priceString.substr(0, priceString.length() - 2);
		}
		artt.price = stod(priceString);
		ifstream file("dbase.json");
		json dbase;
		file >> dbase;
		file.close();
		string imagepath = dbase["RESTS"][thisRest.username]["articles"][artt.name]["imagePath"];

		artt.imagePath = imagepath;

		EditArticleForm^ editArticleForm = gcnew EditArticleForm(artt);

		if (editArticleForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			
		}

	}
	private: System::Void deleteResBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Assuming you want to show a message box with "Da" and "Ne" options
		System::Windows::Forms::DialogResult result = MessageBox::Show
		("Da li ste sigurni da zeline da obrisete ovaj artikal", "Brisanje resursa", MessageBoxButtons::YesNo);
		// Check the result
		if (result == System::Windows::Forms::DialogResult::Yes) {
			articleDelete(getActiveUser(),marshal_as<std::string>(ArticleName));
			delete this;
		}
		else {
			// User clicked "Ne" (No)
			// Your code here for "No" option
		}
	}
	
};
}
