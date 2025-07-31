#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "RestaurantItem.h"
namespace userApp {

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
	public ref class RestaurantsForm : public System::Windows::Forms::Form
	{
	public:

		Form^ previousForm;
		RestaurantsForm(void)
		{
			InitializeComponent();
		}
		RestaurantsForm(Form^ form)
		{
			InitializeComponent();
			previousForm = form;
		}

	public:

	public:

	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ restsFlowLayoutTable;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ searchTextBox;
	public:
	public: bool isExpand = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RestaurantsForm()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RestaurantsForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->restsFlowLayoutTable = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
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
			this->label2->Location = System::Drawing::Point(320, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(350, 61);
			this->label2->TabIndex = 2;
			this->label2->Text = L"RESTORANI";
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
			this->backBtn->Location = System::Drawing::Point(60, 18);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(109, 81);
			this->backBtn->TabIndex = 10;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &RestaurantsForm::backBtn_Click);
			// 
			// restsFlowLayoutTable
			// 
			this->restsFlowLayoutTable->AutoScroll = true;
			this->restsFlowLayoutTable->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->restsFlowLayoutTable->Location = System::Drawing::Point(60, 117);
			this->restsFlowLayoutTable->Name = L"restsFlowLayoutTable";
			this->restsFlowLayoutTable->Size = System::Drawing::Size(932, 590);
			this->restsFlowLayoutTable->TabIndex = 18;
			this->restsFlowLayoutTable->WrapContents = false;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(905, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 23);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Pretrazi";
			// 
			// searchTextBox
			// 
			this->searchTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->searchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->searchTextBox->Location = System::Drawing::Point(716, 81);
			this->searchTextBox->MaxLength = 20;
			this->searchTextBox->Name = L"searchTextBox";
			this->searchTextBox->Size = System::Drawing::Size(276, 30);
			this->searchTextBox->TabIndex = 35;
			this->searchTextBox->TextChanged += gcnew System::EventHandler(this, &RestaurantsForm::searchTextBox_TextChanged);
			// 
			// RestaurantsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(1040, 733);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->searchTextBox);
			this->Controls->Add(this->restsFlowLayoutTable);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1056, 772);
			this->MinimumSize = System::Drawing::Size(1056, 772);
			this->Name = L"RestaurantsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Korisnicka Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &RestaurantsForm::RestaurantsForm_VisibleChanged);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		previousForm->Show();
	}
	private: System::Void makeArticleBtn_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void RestaurantsForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		bool exists = false;
		vector<rest> rests = parseRestsFromDBase();
		for each (rest rest in rests) {
			String^ existingResName = marshal_as<String^>(rest.name);
			string workTime;
			workTime = rest.wt.timeOpen + "-" + rest.wt.timeClose;
			// Concatenate the strings in the vector into one string
			string tags;
			bool firstTag = true;
			for (const string& tag : rest.tags) {
				if (!(tag == "") && !(tag == " ")) {
					if (firstTag) {
						tags += tag;
						firstTag = false;
					}
					else {
						tags = tags + ", " + tag;
					}
				}
			}
			RestaurantItem^ item = gcnew RestaurantItem(rest.username, rest.name,rest.desc,rest.address, rest.imagePath, workTime, tags);
			for each (Control ^ control in restsFlowLayoutTable->Controls) {
				RestaurantItem^ existingItem = dynamic_cast<RestaurantItem^>(control);
				if ((existingItem->RestaurantName == item->RestaurantName)) {
					exists = true;
				}
			}
			if (exists == false) {
				restsFlowLayoutTable->Controls->Add(item);
			}
			exists = false;
		}

	}
	private: System::Void refreshBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void searchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		for each (Control ^ control in restsFlowLayoutTable->Controls) {
			RestaurantItem^ item = dynamic_cast<RestaurantItem^>(control);
			item->Visible = ((item->RestaurantName->ToLower()->Contains(searchTextBox->Text->ToLower())) ||
				(item->Tags->ToLower()->Contains(searchTextBox->Text->ToLower())));
		}
	}

};
}
