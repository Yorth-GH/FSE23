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
	public ref class ArticleOrderedItem : public System::Windows::Forms::UserControl
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

		int Amount;
		void setAmount(int arg) {
			Amount = arg;
		}
		int getAmount() {
			return Amount;
		}


		// Event to notify subscribers about the button click
		event System::EventHandler^ EditBtnClicked;


		ArticleOrderedItem(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ArticleOrderedItem(string name, int amountarg)
		{
			InitializeComponent();

			ArticleName = msclr::interop::marshal_as<String^>(name);
			articleNameLabel->Text = ArticleName;

			articleAmountLabel->Text = "x" + Convert::ToString(amountarg);
			setAmount(amountarg);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ArticleOrderedItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ articleNameLabel;
	private: System::Windows::Forms::Label^ articleAmountLabel;
	protected:
	protected:
	protected:
	protected:





	private: System::Windows::Forms::Label^ articleImagePathLabel;
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
			this->articleAmountLabel = (gcnew System::Windows::Forms::Label());
			this->articleImagePathLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// articleNameLabel
			// 
			this->articleNameLabel->AutoSize = true;
			this->articleNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articleNameLabel->Location = System::Drawing::Point(3, 18);
			this->articleNameLabel->Name = L"articleNameLabel";
			this->articleNameLabel->Size = System::Drawing::Size(144, 23);
			this->articleNameLabel->TabIndex = 2;
			this->articleNameLabel->Text = L"IME ARTIKLA";
			this->articleNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// articleAmountLabel
			// 
			this->articleAmountLabel->AutoSize = true;
			this->articleAmountLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleAmountLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articleAmountLabel->Location = System::Drawing::Point(415, 18);
			this->articleAmountLabel->Name = L"articleAmountLabel";
			this->articleAmountLabel->Size = System::Drawing::Size(35, 23);
			this->articleAmountLabel->TabIndex = 18;
			this->articleAmountLabel->Text = L"x0";
			this->articleAmountLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			// ArticleOrderedItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->Controls->Add(this->articleImagePathLabel);
			this->Controls->Add(this->articleAmountLabel);
			this->Controls->Add(this->articleNameLabel);
			this->Name = L"ArticleOrderedItem";
			this->Size = System::Drawing::Size(458, 54);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	};
}
