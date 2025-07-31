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
	public ref class UsedResourceItem : public System::Windows::Forms::UserControl
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
		int amountUsed;
		void setAm(int arg) {
			amountUsed = arg;
		}
		int getAm() {
			return amountUsed;
		}
		UsedResourceItem(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		UsedResourceItem(string arg)
		{
			InitializeComponent();
			resNameLabel->Text = msclr::interop::marshal_as<String^>(arg);
			resAmountTextBox->Text = "0";
			setAm(0);
			ResourceName = msclr::interop::marshal_as<String^>(arg);
		}
		UsedResourceItem(string arg, int amrg)
		{
			InitializeComponent();
			resNameLabel->Text = msclr::interop::marshal_as<String^>(arg);
			setAm(amrg);
			resAmountTextBox->Text = "0";
			ResourceName = msclr::interop::marshal_as<String^>(arg);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UsedResourceItem()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	protected:

	private: System::Windows::Forms::Button^ sub10Btn;

	private: System::Windows::Forms::Button^ sub1Btn;

	private: System::Windows::Forms::Button^ add1Btn;





	private: System::Windows::Forms::TextBox^ resAmountTextBox;
	private: System::Windows::Forms::Label^ resNameLabel;
	private: System::Windows::Forms::Button^ add10Btn;






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
			this->sub10Btn = (gcnew System::Windows::Forms::Button());
			this->sub1Btn = (gcnew System::Windows::Forms::Button());
			this->add1Btn = (gcnew System::Windows::Forms::Button());
			this->resAmountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->resNameLabel = (gcnew System::Windows::Forms::Label());
			this->add10Btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// sub10Btn
			// 
			this->sub10Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->sub10Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sub10Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sub10Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->sub10Btn->Location = System::Drawing::Point(206, 13);
			this->sub10Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->sub10Btn->Name = L"sub10Btn";
			this->sub10Btn->Size = System::Drawing::Size(36, 27);
			this->sub10Btn->TabIndex = 11;
			this->sub10Btn->Text = L"-10";
			this->sub10Btn->UseVisualStyleBackColor = false;
			this->sub10Btn->Click += gcnew System::EventHandler(this, &UsedResourceItem::sub10Btn_Click);
			// 
			// sub1Btn
			// 
			this->sub1Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->sub1Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sub1Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sub1Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->sub1Btn->Location = System::Drawing::Point(245, 14);
			this->sub1Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->sub1Btn->Name = L"sub1Btn";
			this->sub1Btn->Size = System::Drawing::Size(30, 25);
			this->sub1Btn->TabIndex = 12;
			this->sub1Btn->Text = L"-1";
			this->sub1Btn->UseVisualStyleBackColor = false;
			this->sub1Btn->Click += gcnew System::EventHandler(this, &UsedResourceItem::sub1Btn_Click);
			// 
			// add1Btn
			// 
			this->add1Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->add1Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add1Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add1Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->add1Btn->Location = System::Drawing::Point(335, 14);
			this->add1Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->add1Btn->Name = L"add1Btn";
			this->add1Btn->Size = System::Drawing::Size(32, 25);
			this->add1Btn->TabIndex = 15;
			this->add1Btn->Text = L"+1";
			this->add1Btn->UseVisualStyleBackColor = false;
			this->add1Btn->Click += gcnew System::EventHandler(this, &UsedResourceItem::add1Btn_Click);
			// 
			// resAmountTextBox
			// 
			this->resAmountTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->resAmountTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resAmountTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->resAmountTextBox->Location = System::Drawing::Point(281, 17);
			this->resAmountTextBox->MaxLength = 20;
			this->resAmountTextBox->Name = L"resAmountTextBox";
			this->resAmountTextBox->Size = System::Drawing::Size(51, 19);
			this->resAmountTextBox->TabIndex = 17;
			this->resAmountTextBox->Text = L"0";
			this->resAmountTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->resAmountTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UsedResourceItem::resAmountTextBox_KeyPress);
			// 
			// resNameLabel
			// 
			this->resNameLabel->AutoSize = true;
			this->resNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->resNameLabel->Location = System::Drawing::Point(3, 18);
			this->resNameLabel->Name = L"resNameLabel";
			this->resNameLabel->Size = System::Drawing::Size(100, 16);
			this->resNameLabel->TabIndex = 2;
			this->resNameLabel->Text = L"KISELI KUPUS";
			this->resNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// add10Btn
			// 
			this->add10Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->add10Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add10Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add10Btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->add10Btn->Location = System::Drawing::Point(370, 13);
			this->add10Btn->Margin = System::Windows::Forms::Padding(0, 3, 3, 0);
			this->add10Btn->Name = L"add10Btn";
			this->add10Btn->Size = System::Drawing::Size(41, 27);
			this->add10Btn->TabIndex = 14;
			this->add10Btn->Text = L"+10";
			this->add10Btn->UseVisualStyleBackColor = false;
			this->add10Btn->Click += gcnew System::EventHandler(this, &UsedResourceItem::add10Btn_Click);
			// 
			// UsedResourceItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->Controls->Add(this->resAmountTextBox);
			this->Controls->Add(this->add1Btn);
			this->Controls->Add(this->add10Btn);
			this->Controls->Add(this->sub1Btn);
			this->Controls->Add(this->sub10Btn);
			this->Controls->Add(this->resNameLabel);
			this->Name = L"UsedResourceItem";
			this->Size = System::Drawing::Size(420, 50);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void add1Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) + 1).ToString();
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void add10Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) + 10).ToString();
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void sub1Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) - 1).ToString();
		if (Int32::Parse(resAmountTextBox->Text) < 0) {
			resAmountTextBox->Text = "0";
		}
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void sub10Btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resAmountTextBox->Text = (Int32::Parse(resAmountTextBox->Text) - 10).ToString();
		if (Int32::Parse(resAmountTextBox->Text) < 0) {
			resAmountTextBox->Text = "0";
		}
		setAm(Int32::Parse(resAmountTextBox->Text));
	}
	private: System::Void resAmountTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Check if the entered character is a digit or a control character
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {  // Allow digits and backspace
			e->Handled = true;
			setAm(Int32::Parse(resAmountTextBox->Text));
		}
	}
	};
}
