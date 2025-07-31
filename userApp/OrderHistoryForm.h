#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "OldOrderItem.h"
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
	public ref class OrderHistoryForm : public System::Windows::Forms::Form
	{
	public:

		Form^ previousForm;
		OrderHistoryForm(void)
		{
			InitializeComponent();
		}
		OrderHistoryForm(Form^ form)
		{
			InitializeComponent();
			vector<order> orderVector = getOrderHistVector(getActiveUser());

			ifstream file("dbase.json");

			json dbase;
			file >> dbase;
			for (order ordrr : orderVector) {
				peroArtikliConvertOrderToVec(ordrr);
				string restName = getRestName(ordrr.restName);
				
				OldOrderItem^ item = gcnew OldOrderItem(ordrr, restName, ordrr.comment, ordrr.timeOrd, ordrr.timeRec, ordrr.price);
				//item.name
				ordersLayoutTable->Controls->Add(item);
			}

			previousForm = form;
		}

	public:

	public:

	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ ordersLayoutTable;

	public:
	public: bool isExpand = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OrderHistoryForm()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OrderHistoryForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->ordersLayoutTable = (gcnew System::Windows::Forms::FlowLayoutPanel());
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
			this->label2->Location = System::Drawing::Point(240, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(586, 61);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ISTORIJA NARUDZBI";
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
			this->backBtn->Click += gcnew System::EventHandler(this, &OrderHistoryForm::backBtn_Click);
			// 
			// ordersLayoutTable
			// 
			this->ordersLayoutTable->AutoScroll = true;
			this->ordersLayoutTable->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->ordersLayoutTable->Location = System::Drawing::Point(60, 117);
			this->ordersLayoutTable->Name = L"ordersLayoutTable";
			this->ordersLayoutTable->Size = System::Drawing::Size(932, 590);
			this->ordersLayoutTable->TabIndex = 18;
			this->ordersLayoutTable->WrapContents = false;
			// 
			// OrderHistoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(1040, 733);
			this->Controls->Add(this->ordersLayoutTable);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1056, 772);
			this->MinimumSize = System::Drawing::Size(1056, 772);
			this->Name = L"OrderHistoryForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Korisnicka Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &OrderHistoryForm::RestaurantsForm_VisibleChanged);
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
			/*RestaurantItem^ item = gcnew RestaurantItem(rest.username, rest.name, rest.desc, rest.address, rest.imagePath, workTime, tags);
			for each (Control ^ control in restsFlowLayoutTable->Controls) {
				RestaurantItem^ existingItem = dynamic_cast<RestaurantItem^>(control);
				if ((existingItem->RestaurantName == item->RestaurantName)) {
					exists = true;
				}
			}
			if (exists == false) {
				restsFlowLayoutTable->Controls->Add(item);
			}
			exists = false;*/
		}

	}
	private: System::Void refreshBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
