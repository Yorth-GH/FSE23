#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "ReceiptForm.h"
#include "ArticleOrderedItem.h"
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
	public ref class OrderItem : public System::Windows::Forms::UserControl
	{
	public:

		property String^ UserName {
			String^ get() {
				return userUsernameLabel->Text;
			}
			void set(String^ value) {
				userUsernameLabel->Text = value;
			}
		}
		property String^ OrderName {
			String^ get() {
				return orderNameLabel->Text;
			}
			void set(String^ value) {
				orderNameLabel->Text = value;
			}
		}
		property String^ OrderDescription {
			String^ get() {
				return orderDescLabel->Text;
			}
			void set(String^ value) {
				orderDescLabel->Text = value;
			}
		}

		property String^ OrderTime {
			String^ get() {
				return orderTimeLabel->Text;
			}
			void set(String^ value) {
				orderTimeLabel->Text = value;
			}
		}

		property String^ Receipt {
			String^ get() {
				return receiptLabel->Text;
			}
			void set(String^ value) {
				receiptLabel->Text = value;
			}
		}

		double Price;
		void setPrice(double arg) {
			Price = arg;
		}
		double getPrice() {
			return Price;
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::FlowLayoutPanel^ articleNamesTable;

	private: System::Windows::Forms::Button^ printRecBtn;
	private: System::Windows::Forms::Label^ userUsernameLabel;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ orderTimeLabel;
	private: System::Windows::Forms::PictureBox^ accOrderBtn;
	private: System::Windows::Forms::PictureBox^ decOrderBtn;
	private: System::Windows::Forms::Label^ receiptLabel;
	private: System::Windows::Forms::Label^ orderNameLabel;

	public:

		int TotalPrice;
		void setTotalPrice(int arg) {
			TotalPrice = arg;
		}
		int getTotalPrice() {
			return TotalPrice;
		}

	private: System::Windows::Forms::Label^ imgPathLabel;
	public:

	public:
		// Event to notify subscribers about the button click
		event System::EventHandler^ EditBtnClicked;


		OrderItem(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		OrderItem(order& ordr,string name, string description,string OrderTimearg, double pricearg)
		{
			InitializeComponent();
			for (uiid a : ordr.IDarticles) {
				ordr.artNames.push_back(getArticleNameFromID(a));
			}
			orderNameLabel->Text =marshal_as<String^>(getIDfromOrder(ordr));
			OrderName = orderNameLabel->Text;
			receiptLabel->Text = marshal_as<String^>(receipt(ordr));
			Receipt = receiptLabel->Text;

			string restoranNarucio = "RESTORAN";
			if (name == "")
				userUsernameLabel->Text = marshal_as<String^>(restoranNarucio);
			else
				userUsernameLabel->Text = marshal_as<String^>(name);

			UserName = userUsernameLabel->Text;

			orderDescLabel->Text = marshal_as<String^>(description);
			OrderDescription = orderDescLabel->Text;

			orderTimeLabel->Text = marshal_as<String^>(OrderTimearg);
			OrderTime = orderTimeLabel->Text;

			orderPriceLabel->Text =  Convert::ToString(pricearg);
			TotalPrice = pricearg;


			vector<string> names = getPeroArtikliIme();
			vector<int> amounts = getPeroArtikliPuta();
			
			for (int i = 0; i < names.size(); i++) {
				ArticleOrderedItem^ artItem = gcnew ArticleOrderedItem(names.at(i), amounts.at(i));
				articleNamesTable->Controls->Add(artItem);
			}

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OrderItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ articleNameLabel;
	private: System::Windows::Forms::Label^ orderDescLabel;
	private: System::Windows::Forms::Label^ orderPriceLabel;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OrderItem::typeid));
			this->articleNameLabel = (gcnew System::Windows::Forms::Label());
			this->orderDescLabel = (gcnew System::Windows::Forms::Label());
			this->orderPriceLabel = (gcnew System::Windows::Forms::Label());
			this->articleImagePathLabel = (gcnew System::Windows::Forms::Label());
			this->imgPathLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->articleNamesTable = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->printRecBtn = (gcnew System::Windows::Forms::Button());
			this->userUsernameLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->orderTimeLabel = (gcnew System::Windows::Forms::Label());
			this->accOrderBtn = (gcnew System::Windows::Forms::PictureBox());
			this->decOrderBtn = (gcnew System::Windows::Forms::PictureBox());
			this->receiptLabel = (gcnew System::Windows::Forms::Label());
			this->orderNameLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->accOrderBtn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->decOrderBtn))->BeginInit();
			this->SuspendLayout();
			// 
			// articleNameLabel
			// 
			this->articleNameLabel->AutoSize = true;
			this->articleNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articleNameLabel->Location = System::Drawing::Point(12, 23);
			this->articleNameLabel->Name = L"articleNameLabel";
			this->articleNameLabel->Size = System::Drawing::Size(132, 31);
			this->articleNameLabel->TabIndex = 2;
			this->articleNameLabel->Text = L"Narucio:";
			this->articleNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// orderDescLabel
			// 
			this->orderDescLabel->AutoSize = true;
			this->orderDescLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->orderDescLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->orderDescLabel->Location = System::Drawing::Point(15, 252);
			this->orderDescLabel->MaximumSize = System::Drawing::Size(400, 50);
			this->orderDescLabel->Name = L"orderDescLabel";
			this->orderDescLabel->Size = System::Drawing::Size(77, 16);
			this->orderDescLabel->TabIndex = 18;
			this->orderDescLabel->Text = L"Komentar";
			this->orderDescLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// orderPriceLabel
			// 
			this->orderPriceLabel->AutoSize = true;
			this->orderPriceLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->orderPriceLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->orderPriceLabel->Location = System::Drawing::Point(745, 23);
			this->orderPriceLabel->Name = L"orderPriceLabel";
			this->orderPriceLabel->Size = System::Drawing::Size(88, 31);
			this->orderPriceLabel->TabIndex = 20;
			this->orderPriceLabel->Text = L"00.00";
			this->orderPriceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			// imgPathLabel
			// 
			this->imgPathLabel->AutoSize = true;
			this->imgPathLabel->Location = System::Drawing::Point(15, 54);
			this->imgPathLabel->Name = L"imgPathLabel";
			this->imgPathLabel->Size = System::Drawing::Size(35, 13);
			this->imgPathLabel->TabIndex = 31;
			this->imgPathLabel->Text = L"label1";
			this->imgPathLabel->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(829, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 31);
			this->label2->TabIndex = 33;
			this->label2->Text = L"KM";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// articleNamesTable
			// 
			this->articleNamesTable->AutoScroll = true;
			this->articleNamesTable->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->articleNamesTable->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->articleNamesTable->Location = System::Drawing::Point(18, 57);
			this->articleNamesTable->Name = L"articleNamesTable";
			this->articleNamesTable->Size = System::Drawing::Size(495, 192);
			this->articleNamesTable->TabIndex = 34;
			this->articleNamesTable->WrapContents = false;
			// 
			// printRecBtn
			// 
			this->printRecBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->printRecBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->printRecBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printRecBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->printRecBtn->Location = System::Drawing::Point(767, 211);
			this->printRecBtn->Name = L"printRecBtn";
			this->printRecBtn->Size = System::Drawing::Size(121, 66);
			this->printRecBtn->TabIndex = 35;
			this->printRecBtn->Text = L"Stampaj Racun";
			this->printRecBtn->UseVisualStyleBackColor = false;
			this->printRecBtn->Visible = false;
			this->printRecBtn->Click += gcnew System::EventHandler(this, &OrderItem::printRecBtn_Click);
			// 
			// userUsernameLabel
			// 
			this->userUsernameLabel->AutoSize = true;
			this->userUsernameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userUsernameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->userUsernameLabel->Location = System::Drawing::Point(139, 23);
			this->userUsernameLabel->Name = L"userUsernameLabel";
			this->userUsernameLabel->Size = System::Drawing::Size(71, 31);
			this->userUsernameLabel->TabIndex = 36;
			this->userUsernameLabel->Text = L"huh";
			this->userUsernameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(519, 57);
			this->label1->MaximumSize = System::Drawing::Size(230, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 16);
			this->label1->TabIndex = 37;
			this->label1->Text = L"Naruceno:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// orderTimeLabel
			// 
			this->orderTimeLabel->AutoSize = true;
			this->orderTimeLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->orderTimeLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->orderTimeLabel->Location = System::Drawing::Point(605, 57);
			this->orderTimeLabel->MaximumSize = System::Drawing::Size(230, 50);
			this->orderTimeLabel->Name = L"orderTimeLabel";
			this->orderTimeLabel->Size = System::Drawing::Size(38, 16);
			this->orderTimeLabel->TabIndex = 38;
			this->orderTimeLabel->Text = L"7:01";
			this->orderTimeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// accOrderBtn
			// 
			this->accOrderBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->accOrderBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"accOrderBtn.Image")));
			this->accOrderBtn->Location = System::Drawing::Point(767, 241);
			this->accOrderBtn->Name = L"accOrderBtn";
			this->accOrderBtn->Size = System::Drawing::Size(36, 36);
			this->accOrderBtn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->accOrderBtn->TabIndex = 39;
			this->accOrderBtn->TabStop = false;
			this->accOrderBtn->Click += gcnew System::EventHandler(this, &OrderItem::accOrderBtn_Click);
			// 
			// decOrderBtn
			// 
			this->decOrderBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->decOrderBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"decOrderBtn.Image")));
			this->decOrderBtn->Location = System::Drawing::Point(852, 241);
			this->decOrderBtn->Name = L"decOrderBtn";
			this->decOrderBtn->Size = System::Drawing::Size(36, 36);
			this->decOrderBtn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->decOrderBtn->TabIndex = 40;
			this->decOrderBtn->TabStop = false;
			this->decOrderBtn->Click += gcnew System::EventHandler(this, &OrderItem::decOrderBtn_Click);
			// 
			// receiptLabel
			// 
			this->receiptLabel->AutoSize = true;
			this->receiptLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->receiptLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->receiptLabel->Location = System::Drawing::Point(574, 11);
			this->receiptLabel->Name = L"receiptLabel";
			this->receiptLabel->Size = System::Drawing::Size(71, 31);
			this->receiptLabel->TabIndex = 41;
			this->receiptLabel->Text = L"huh";
			this->receiptLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->receiptLabel->Visible = false;
			// 
			// orderNameLabel
			// 
			this->orderNameLabel->AutoSize = true;
			this->orderNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->orderNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->orderNameLabel->Location = System::Drawing::Point(574, 11);
			this->orderNameLabel->Name = L"orderNameLabel";
			this->orderNameLabel->Size = System::Drawing::Size(71, 31);
			this->orderNameLabel->TabIndex = 42;
			this->orderNameLabel->Text = L"huh";
			this->orderNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->orderNameLabel->Visible = false;
			// 
			// OrderItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->orderNameLabel);
			this->Controls->Add(this->receiptLabel);
			this->Controls->Add(this->decOrderBtn);
			this->Controls->Add(this->accOrderBtn);
			this->Controls->Add(this->orderTimeLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->userUsernameLabel);
			this->Controls->Add(this->printRecBtn);
			this->Controls->Add(this->articleNamesTable);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->imgPathLabel);
			this->Controls->Add(this->articleImagePathLabel);
			this->Controls->Add(this->orderPriceLabel);
			this->Controls->Add(this->orderDescLabel);
			this->Controls->Add(this->articleNameLabel);
			this->Name = L"OrderItem";
			this->Size = System::Drawing::Size(899, 286);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->accOrderBtn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->decOrderBtn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void printRecBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		
		ReceiptForm^ recForm = gcnew ReceiptForm(Receipt);
		recForm->ShowDialog();
		delete(this);

	}
	private: System::Void decOrderBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		bool lowRes = false;
		order ord = getOrderFromID(marshal_as<string>(OrderName));
		processOrder(ord,"0", lowRes);
		
		delete(this);

	}
	private: System::Void accOrderBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		bool lowRes = false;

		order ord = getOrderFromID(marshal_as<string>(OrderName));
		for (uiid a : ord.IDarticles) {
			ord.artNames.push_back(getArticleNameFromID(a));
		}
		switch (processOrder(ord, "1", lowRes))
		{
		case 0:
			if (ord.userUName != "")
				userSubtractBalance(ord.userUName, ord.price);
			printRecBtn->Show();
			accOrderBtn->Hide();
			decOrderBtn->Hide();
			break;
		case 1:
			MessageBox::Show("Narudzba je vec obradjena.", "Greska u obradi", MessageBoxButtons::OK,
				MessageBoxIcon::Information);
			delete(this);
			break;
		case 2:
			MessageBox::Show("Nemate dovoljno resursa za ovu narudzbu.", "Nedostatak resursa", MessageBoxButtons::OK,
				MessageBoxIcon::Information);
			break;
		}
		if (lowRes == true) {
			MessageBox::Show("Imate malo resursa.\n Molimo proverite inventar.", "Upozorenje o resursima", MessageBoxButtons::OK,
				MessageBoxIcon::Information);
		}
	}
};
}
