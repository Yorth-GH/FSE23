#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "ArticleOrderedItem.h"

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
	public ref class StatisticsForm : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		StatisticsForm(void)
		{
			InitializeComponent();
		}

		StatisticsForm(Form^ form)
		{

			InitializeComponent();
			stats stats = getRestStats(getActiveUser());
			for (auto it = stats.rbegin(); it != stats.rend(); it++) {
				ArticleOrderedItem^ item = gcnew ArticleOrderedItem((*it).first, (*it).second);
				statsTable->Controls->Add(item);
			}

			previousForm = form;
	
		}

	public:
	public:
	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ statsTable;

	public:
	public: bool isExpand = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StatisticsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Label;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StatisticsForm::typeid));
			this->Label = (gcnew System::Windows::Forms::Label());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->statsTable = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// Label
			// 
			this->Label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Label->AutoSize = true;
			this->Label->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->Label->Location = System::Drawing::Point(202, 55);
			this->Label->Name = L"Label";
			this->Label->Size = System::Drawing::Size(383, 39);
			this->Label->TabIndex = 2;
			this->Label->Text = L"Korisnicka Statistika";
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
			this->backBtn->Location = System::Drawing::Point(12, 31);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(111, 63);
			this->backBtn->TabIndex = 10;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &StatisticsForm::backBtn_Click);
			// 
			// statsTable
			// 
			this->statsTable->AutoScroll = true;
			this->statsTable->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->statsTable->Location = System::Drawing::Point(17, 145);
			this->statsTable->Name = L"statsTable";
			this->statsTable->Size = System::Drawing::Size(748, 413);
			this->statsTable->TabIndex = 19;
			this->statsTable->WrapContents = false;
			// 
			// StatisticsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(777, 648);
			this->Controls->Add(this->statsTable);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->Label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"StatisticsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &StatisticsForm::MyMenuForm_VisibleChanged);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		previousForm->Show();
		this->Close();
	}

	private: System::Void MyMenuForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {

		

	}


	};
}
