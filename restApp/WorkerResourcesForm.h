#pragma once
#include "ResourceItem.h"
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
	/// Summary for MainMenuForm
	/// </summary>
	public ref class WorkerResourcesForm : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		WorkerResourcesForm(void)
		{
			InitializeComponent();
		}
		WorkerResourcesForm(Form^ form)
		{
			InitializeComponent();
			previousForm = form;
			rest thisRest = restGet(getActiveUser());

			for each (ingr ing in thisRest.inventory) {
				String^ existingResName = marshal_as<String^>(ing.name);
				ResourceItem^ item = gcnew ResourceItem(marshal_as<std::string>(existingResName), ing.amnt);
				item->am = ing.amnt;
				flowLayoutPanel1->Controls->Add(item);
			}


		}

	public:
	private: System::Windows::Forms::Button^ backBtn;


	private: System::Windows::Forms::Button^ applyChanges;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;

	public:
	public: bool isExpand = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WorkerResourcesForm()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WorkerResourcesForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->applyChanges = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
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
			this->label2->Location = System::Drawing::Point(413, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(260, 61);
			this->label2->TabIndex = 2;
			this->label2->Text = L"RESURSI";
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
			this->backBtn->Size = System::Drawing::Size(109, 55);
			this->backBtn->TabIndex = 10;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &WorkerResourcesForm::backBtn_Click);
			// 
			// applyChanges
			// 
			this->applyChanges->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->applyChanges->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->applyChanges->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->applyChanges->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->applyChanges->Location = System::Drawing::Point(436, 645);
			this->applyChanges->Name = L"applyChanges";
			this->applyChanges->Size = System::Drawing::Size(198, 55);
			this->applyChanges->TabIndex = 20;
			this->applyChanges->Text = L"AZURIRAJ";
			this->applyChanges->UseVisualStyleBackColor = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(60, 85);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(932, 522);
			this->flowLayoutPanel1->TabIndex = 18;
			this->flowLayoutPanel1->WrapContents = false;
			// 
			// WorkerResourcesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(1040, 733);
			this->Controls->Add(this->applyChanges);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1056, 772);
			this->MinimumSize = System::Drawing::Size(1056, 772);
			this->Name = L"WorkerResourcesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Restoranska Aplikacija";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		previousForm->Show();
		// Iterate through each item and make changes
		for each (ResourceItem ^ resourceItem in flowLayoutPanel1->Controls)
		{
			resourceUpdate(getActiveUser(), marshal_as<std::string>(resourceItem->ResourceName), resourceItem->getAm());
		}

	}
	
	private: System::Void applyChanges_Click(System::Object^ sender, System::EventArgs^ e) {
		// Iterate through each item and make changes
		for each (ResourceItem ^ resourceItem in flowLayoutPanel1->Controls)
		{
			resourceUpdate(getActiveUser(), marshal_as<std::string>(resourceItem->ResourceName), resourceItem->getAm());
		}
	}
	};
}
