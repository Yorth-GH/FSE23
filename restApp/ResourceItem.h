#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
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
	public ref class ResourceItem : public System::Windows::Forms::UserControl
	{
	public:
		property String^ ResourceName {
			String^ get() {
				return resNameLabel->Text;
			}
			void set(String^ value) {
				resNameLabel->Text = value;
			}
		}
		int am;
		void setAm(int arg) {
			am = arg;
		}
		int getAm() {
			return am;
		}
		ResourceItem(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ResourceItem(string arg)
		{
			InitializeComponent();
			resNameLabel->Text = msclr::interop::marshal_as<String^>(arg);
			ResourceName = msclr::interop::marshal_as<String^>(arg);
		}
		ResourceItem(string arg,int amrg)
		{
			InitializeComponent();
			if (getAuth() == false) {
				deleteResBtn->Visible=false;
			}
			else {
				deleteResBtn->Visible = true;
			}
			resNameLabel->Text = msclr::interop::marshal_as<String^>(arg);
			setAm(amrg);
			resAmountTextBox->Text = am.ToString();
			ResourceName = msclr::interop::marshal_as<String^>(arg);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ResourceItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ sub100Btn;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Button^ sub10Btn;

	private: System::Windows::Forms::Button^ sub1Btn;

	private: System::Windows::Forms::Button^ add1Btn;
	private: System::Windows::Forms::Button^ add10Btn;
	private: System::Windows::Forms::Button^ add100Btn;



	private: System::Windows::Forms::TextBox^ resAmountTextBox;
	private: System::Windows::Forms::Label^ resNameLabel;
	private: System::Windows::Forms::Button^ deleteResBtn;





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->sub100Btn = (gcnew System::Windows::Forms::Button());
			this->sub10Btn = (gcnew System::Windows::Forms::Button());
			this->sub1Btn = (gcnew System::Windows::Forms::Button());
			this->add1Btn = (gcnew System::Windows::Forms::Button());
			this->add10Btn = (gcnew System::Windows::Forms::Button());
			this->add100Btn = (gcnew System::Windows::Forms::Button());
			this->resAmountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->resNameLabel = (gcnew System::Windows::Forms::Label());
			this->deleteResBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// sub100Btn
			// 
			this->sub100Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->sub100Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sub100Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sub100Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->sub100Btn->Location = System::Drawing::Point(249, 11);
			this->sub100Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->sub100Btn->Name = L"sub100Btn";
			this->sub100Btn->Size = System::Drawing::Size(73, 38);
			this->sub100Btn->TabIndex = 10;
			this->sub100Btn->Text = L"-100";
			this->sub100Btn->UseVisualStyleBackColor = false;
			this->sub100Btn->Click += gcnew System::EventHandler(this, &ResourceItem::sub100Btn_Click);
			// 
			// sub10Btn
			// 
			this->sub10Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->sub10Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sub10Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sub10Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->sub10Btn->Location = System::Drawing::Point(325, 11);
			this->sub10Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->sub10Btn->Name = L"sub10Btn";
			this->sub10Btn->Size = System::Drawing::Size(56, 38);
			this->sub10Btn->TabIndex = 11;
			this->sub10Btn->Text = L"-10";
			this->sub10Btn->UseVisualStyleBackColor = false;
			this->sub10Btn->Click += gcnew System::EventHandler(this, &ResourceItem::sub10Btn_Click);
			// 
			// sub1Btn
			// 
			this->sub1Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->sub1Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sub1Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sub1Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->sub1Btn->Location = System::Drawing::Point(384, 11);
			this->sub1Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->sub1Btn->Name = L"sub1Btn";
			this->sub1Btn->Size = System::Drawing::Size(42, 38);
			this->sub1Btn->TabIndex = 12;
			this->sub1Btn->Text = L"-1";
			this->sub1Btn->UseVisualStyleBackColor = false;
			this->sub1Btn->Click += gcnew System::EventHandler(this, &ResourceItem::sub1Btn_Click);
			// 
			// add1Btn
			// 
			this->add1Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->add1Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add1Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add1Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->add1Btn->Location = System::Drawing::Point(541, 11);
			this->add1Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->add1Btn->Name = L"add1Btn";
			this->add1Btn->Size = System::Drawing::Size(50, 38);
			this->add1Btn->TabIndex = 15;
			this->add1Btn->Text = L"+1";
			this->add1Btn->UseVisualStyleBackColor = false;
			this->add1Btn->Click += gcnew System::EventHandler(this, &ResourceItem::add1Btn_Click);
			// 
			// add10Btn
			// 
			this->add10Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->add10Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add10Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add10Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->add10Btn->Location = System::Drawing::Point(594, 11);
			this->add10Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->add10Btn->Name = L"add10Btn";
			this->add10Btn->Size = System::Drawing::Size(67, 38);
			this->add10Btn->TabIndex = 14;
			this->add10Btn->Text = L"+10";
			this->add10Btn->UseVisualStyleBackColor = false;
			this->add10Btn->Click += gcnew System::EventHandler(this, &ResourceItem::add10Btn_Click);
			// 
			// add100Btn
			// 
			this->add100Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->add100Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add100Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add100Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->add100Btn->Location = System::Drawing::Point(664, 11);
			this->add100Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->add100Btn->Name = L"add100Btn";
			this->add100Btn->Size = System::Drawing::Size(73, 38);
			this->add100Btn->TabIndex = 13;
			this->add100Btn->Text = L"+100";
			this->add100Btn->UseVisualStyleBackColor = false;
			this->add100Btn->Click += gcnew System::EventHandler(this, &ResourceItem::add100Btn_Click);
			// 
			// resAmountTextBox
			// 
			this->resAmountTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->resAmountTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resAmountTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->resAmountTextBox->Location = System::Drawing::Point(432, 19);
			this->resAmountTextBox->MaxLength = 20;
			this->resAmountTextBox->Name = L"resAmountTextBox";
			this->resAmountTextBox->Size = System::Drawing::Size(96, 30);
			this->resAmountTextBox->TabIndex = 17;
			this->resAmountTextBox->Text = L"0";
			this->resAmountTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->resAmountTextBox->TextChanged += gcnew System::EventHandler(this, &ResourceItem::resAmountTextBox_TextChanged);
			this->resAmountTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ResourceItem::resAmountTextBox_KeyPress);
			// 
			// resNameLabel
			// 
			this->resNameLabel->AutoSize = true;
			this->resNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->resNameLabel->Location = System::Drawing::Point(4, 18);
			this->resNameLabel->Name = L"resNameLabel";
			this->resNameLabel->Size = System::Drawing::Size(203, 31);
			this->resNameLabel->TabIndex = 2;
			this->resNameLabel->Text = L"KISELI KUPUS";
			this->resNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// deleteResBtn
			// 
			this->deleteResBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->deleteResBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteResBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteResBtn->ForeColor = System::Drawing::Color::Red;
			this->deleteResBtn->Location = System::Drawing::Point(753, 11);
			this->deleteResBtn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->deleteResBtn->Name = L"deleteResBtn";
			this->deleteResBtn->Size = System::Drawing::Size(73, 38);
			this->deleteResBtn->TabIndex = 18;
			this->deleteResBtn->Text = L"OBRISI";
			this->deleteResBtn->UseVisualStyleBackColor = false;
			this->deleteResBtn->Click += gcnew System::EventHandler(this, &ResourceItem::deleteResBtn_Click);
			// 
			// ResourceItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->Controls->Add(this->deleteResBtn);
			this->Controls->Add(this->resAmountTextBox);
			this->Controls->Add(this->add1Btn);
			this->Controls->Add(this->add10Btn);
			this->Controls->Add(this->add100Btn);
			this->Controls->Add(this->sub1Btn);
			this->Controls->Add(this->sub10Btn);
			this->Controls->Add(this->sub100Btn);
			this->Controls->Add(this->resNameLabel);
			this->Name = L"ResourceItem";
			this->Size = System::Drawing::Size(883, 71);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void add1Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) + 1).ToString();
		resourceUpdate(getActiveUser(), marshal_as<std::string>(resNameLabel->Text), Int32::Parse(resAmountTextBox->Text));
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void add10Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) + 10).ToString();
		resourceUpdate(getActiveUser(), marshal_as<std::string>(resNameLabel->Text), Int32::Parse(resAmountTextBox->Text));
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void add100Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) + 100).ToString();
		resourceUpdate(getActiveUser(), marshal_as<std::string>(resNameLabel->Text), Int32::Parse(resAmountTextBox->Text));
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void sub1Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) - 1).ToString();
		if (Int32::Parse(resAmountTextBox->Text) < 0) {
			resAmountTextBox->Text = "0";
		}
		resourceUpdate(getActiveUser(), marshal_as<std::string>(resNameLabel->Text), Int32::Parse(resAmountTextBox->Text));
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void sub10Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) - 10).ToString();
		if (Int32::Parse(resAmountTextBox->Text) < 0) {
			resAmountTextBox->Text = "0";
		}
		resourceUpdate(getActiveUser(), marshal_as<std::string>(resNameLabel->Text), Int32::Parse(resAmountTextBox->Text));
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void sub100Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) - 100).ToString();
		if (Int32::Parse(resAmountTextBox->Text) < 0) {
			resAmountTextBox->Text = "0";
		}
		resourceUpdate(getActiveUser(), marshal_as<std::string>(resNameLabel->Text), Int32::Parse(resAmountTextBox->Text));
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void deleteResBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Assuming you want to show a message box with "Da" and "Ne" options
		System::Windows::Forms::DialogResult result = MessageBox::Show
		("Da li ste sigurni da zelite da obrisete ovaj resurs?", "Brisanje resursa", MessageBoxButtons::YesNo);
		// Check the result
		if (result == System::Windows::Forms::DialogResult::Yes) {
			if (resourceDelete(getActiveUser(), marshal_as<std::string>(resNameLabel->Text)) == 3)
				MessageBox::Show
				("Ovaj resurs se koristi u nekom artiklu i ne moze se obrisati.", "Brisanje resursa", MessageBoxButtons::OK);
			else
				delete this;
		}
		else {
			// User clicked "Ne" (No)
			// Your code here for "No" option
		}
	}
	private: System::Void resAmountTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Check if the entered character is a digit or a control character
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 ||marshal_as<std::string>(resAmountTextBox->Text).length() >= 6 && e->KeyChar != '\b') {  // Allow digits and backspace
			e->Handled = true; 
			setAm(Int32::Parse(resAmountTextBox->Text));
			resourceUpdate(getActiveUser(), marshal_as<std::string>(resNameLabel->Text), Int32::Parse(resAmountTextBox->Text));
		}
	}
	private: System::Void resAmountTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (marshal_as<std::string>(resAmountTextBox->Text).length() <= 6 && marshal_as<std::string>(resAmountTextBox->Text).length() > 0)  {  // Allow digits and backspace	
			resourceUpdate(getActiveUser(), marshal_as<std::string>(resNameLabel->Text), Int32::Parse(resAmountTextBox->Text));
		}
		else if (marshal_as<std::string>(resAmountTextBox->Text).length() == 0) {
			resAmountTextBox->Text = "0";
			resourceUpdate(getActiveUser(), marshal_as<std::string>(resNameLabel->Text), Int32::Parse(resAmountTextBox->Text));
		}
	}
};
}
