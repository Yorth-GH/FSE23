#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "MakeOrderForm.h"
using namespace msclr::interop;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace userApp {

	/// <summary>
	/// Summary for ResourceItem
	/// </summary>
	public ref class RestaurantItem : public System::Windows::Forms::UserControl
	{
	public:
		property String^ RestaurantUsername {
			String^ get() {
				return restUsernameLabel->Text;
			}
			void set(String^ value) {
				restUsernameLabel->Text = value;
			}
		}
		property String^ RestaurantName {
			String^ get() {
				return restNameLabel->Text;
			}
			void set(String^ value) {
				restNameLabel->Text = value;
			}
		}
		property String^ RestaurantDesc {
			String^ get() {
				return restDescriptonLabel->Text;
			}
			void set(String^ value) {
				restDescriptonLabel->Text = value;
			}
		}
		property String^ RestaurantAdress {
			String^ get() {
				return restAdressLabel->Text;
			}
			void set(String^ value) {
				restAdressLabel->Text = value;
			}
		}
		property String^ ImagePath {
			String^ get() {
				return restImagePath->Text;
			}
			void set(String^ value) {
				restImagePath->Text = value;
			}
		}
		property String^ WorkTime {
			String^ get() {
				return wtLabel->Text;
			}
			void set(String^ value) {
				wtLabel->Text = value;
			}
		}

		property String^ Tags {
			String^ get() {
				return tagLabel->Text;
			}
			void set(String^ value) {
				tagLabel->Text = value;
			}
		}

		// Event to notify subscribers about the button click
		event System::EventHandler^ EditBtnClicked;


		RestaurantItem(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		RestaurantItem(string username, string name, string description,
					   string adress, string imagePatharg, string wt , string tags)
		{
			InitializeComponent();

			RestaurantUsername = marshal_as<String^>(username);
			restUsernameLabel->Text = RestaurantUsername;

			RestaurantName = marshal_as<String^>(name);
			restNameLabel->Text = RestaurantName;

			RestaurantDesc = marshal_as<String^>(description);
			restDescriptonLabel->Text = RestaurantDesc;

			RestaurantAdress = marshal_as<String^>(adress);
			restAdressLabel->Text = RestaurantAdress;
			adressLabel->Text = RestaurantAdress;

			if (imagePatharg.empty()) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("User.png"));
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(imagePatharg));
			}
			restImagePath->Text =marshal_as<String^> (imagePatharg);

			WorkTime = marshal_as<String^>(wt);
			wtLabel->Text = WorkTime;

			Tags = marshal_as<String^>(tags);
			tagLabel->Text = Tags;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RestaurantItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ restNameLabel;

	protected:

	protected:
	protected:
	protected:
	protected:



	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ articleImagePathLabel;
	private: System::Windows::Forms::Label^ wtLabel;
	private: System::Windows::Forms::Label^ tagLabel;
	private: System::Windows::Forms::Label^ restDescriptonLabel;
private: System::Windows::Forms::Label^ restAdressLabel;
private: System::Windows::Forms::Label^ restImagePath;
private: System::Windows::Forms::Label^ restUsernameLabel;
private: System::Windows::Forms::Label^ adressLabel;


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
			this->restNameLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->articleImagePathLabel = (gcnew System::Windows::Forms::Label());
			this->wtLabel = (gcnew System::Windows::Forms::Label());
			this->tagLabel = (gcnew System::Windows::Forms::Label());
			this->restDescriptonLabel = (gcnew System::Windows::Forms::Label());
			this->restAdressLabel = (gcnew System::Windows::Forms::Label());
			this->restImagePath = (gcnew System::Windows::Forms::Label());
			this->restUsernameLabel = (gcnew System::Windows::Forms::Label());
			this->adressLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// restNameLabel
			// 
			this->restNameLabel->AutoSize = true;
			this->restNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->restNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->restNameLabel->Location = System::Drawing::Point(50, 17);
			this->restNameLabel->Name = L"restNameLabel";
			this->restNameLabel->Size = System::Drawing::Size(249, 31);
			this->restNameLabel->TabIndex = 2;
			this->restNameLabel->Text = L"IME RESTORANA";
			this->restNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(56, 51);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(771, 160);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 23;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &RestaurantItem::pictureBox1_Click);
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
			// wtLabel
			// 
			this->wtLabel->AutoSize = true;
			this->wtLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wtLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->wtLabel->Location = System::Drawing::Point(655, 214);
			this->wtLabel->Name = L"wtLabel";
			this->wtLabel->Size = System::Drawing::Size(172, 31);
			this->wtLabel->TabIndex = 26;
			this->wtLabel->Text = L"00:00-00:00";
			this->wtLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tagLabel
			// 
			this->tagLabel->AutoSize = true;
			this->tagLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tagLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->tagLabel->Location = System::Drawing::Point(50, 214);
			this->tagLabel->Name = L"tagLabel";
			this->tagLabel->Size = System::Drawing::Size(218, 31);
			this->tagLabel->TabIndex = 27;
			this->tagLabel->Text = L"tag1 tag2 tag3";
			this->tagLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// restDescriptonLabel
			// 
			this->restDescriptonLabel->AutoSize = true;
			this->restDescriptonLabel->Location = System::Drawing::Point(53, 35);
			this->restDescriptonLabel->Name = L"restDescriptonLabel";
			this->restDescriptonLabel->Size = System::Drawing::Size(35, 13);
			this->restDescriptonLabel->TabIndex = 28;
			this->restDescriptonLabel->Text = L"label1";
			this->restDescriptonLabel->Visible = false;
			// 
			// restAdressLabel
			// 
			this->restAdressLabel->AutoSize = true;
			this->restAdressLabel->Location = System::Drawing::Point(94, 31);
			this->restAdressLabel->Name = L"restAdressLabel";
			this->restAdressLabel->Size = System::Drawing::Size(35, 13);
			this->restAdressLabel->TabIndex = 29;
			this->restAdressLabel->Text = L"label1";
			this->restAdressLabel->Visible = false;
			// 
			// restImagePath
			// 
			this->restImagePath->AutoSize = true;
			this->restImagePath->Location = System::Drawing::Point(135, 31);
			this->restImagePath->Name = L"restImagePath";
			this->restImagePath->Size = System::Drawing::Size(35, 13);
			this->restImagePath->TabIndex = 30;
			this->restImagePath->Text = L"label1";
			this->restImagePath->Visible = false;
			// 
			// restUsernameLabel
			// 
			this->restUsernameLabel->AutoSize = true;
			this->restUsernameLabel->Location = System::Drawing::Point(176, 31);
			this->restUsernameLabel->Name = L"restUsernameLabel";
			this->restUsernameLabel->Size = System::Drawing::Size(35, 13);
			this->restUsernameLabel->TabIndex = 31;
			this->restUsernameLabel->Text = L"label1";
			this->restUsernameLabel->Visible = false;
			// 
			// adressLabel
			// 
			this->adressLabel->AutoSize = true;
			this->adressLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adressLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->adressLabel->Location = System::Drawing::Point(536, 17);
			this->adressLabel->Name = L"adressLabel";
			this->adressLabel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->adressLabel->Size = System::Drawing::Size(186, 31);
			this->adressLabel->TabIndex = 32;
			this->adressLabel->Text = L"ADRESAAAA";
			this->adressLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// RestaurantItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->Controls->Add(this->adressLabel);
			this->Controls->Add(this->restUsernameLabel);
			this->Controls->Add(this->restImagePath);
			this->Controls->Add(this->restAdressLabel);
			this->Controls->Add(this->restDescriptonLabel);
			this->Controls->Add(this->tagLabel);
			this->Controls->Add(this->wtLabel);
			this->Controls->Add(this->articleImagePathLabel);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->restNameLabel);
			this->Name = L"RestaurantItem";
			this->Size = System::Drawing::Size(904, 264);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		rest thisRest;
		thisRest.username = marshal_as<string>(RestaurantUsername);
		thisRest.name = marshal_as<string>(RestaurantName);
		thisRest.desc = marshal_as<string>(RestaurantDesc);
		thisRest.imagePath = marshal_as<string>(ImagePath);
		thisRest.address = marshal_as<string>(RestaurantAdress);
		workTime wt;

		// Find the position of the character "-"
		size_t position = marshal_as<string>(WorkTime).find('-');

		// Extract the substring until the position of "-"
		wt.timeOpen = marshal_as<string>(WorkTime).substr(0, position);

		// Extract the substring after the position of "-"
		wt.timeClose = marshal_as<string>(WorkTime).substr(position + 1);
		thisRest.wt = wt;
		
		MakeOrderForm^ makeOrderForm = gcnew MakeOrderForm(thisRest);
		makeOrderForm->Show();

		
	}
};
}
