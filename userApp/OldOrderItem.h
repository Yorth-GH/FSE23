#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "OrderedArticleItem.h"
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
	public ref class OldOrderItem : public System::Windows::Forms::UserControl
	{
	public:

		property String^ RestName {
			String^ get() {
				return restNameLabel->Text;
			}
			void set(String^ value) {
				restNameLabel->Text = value;
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

		property String^ DeliverTime {
			String^ get() {
				return deliverTimeLabel->Text;
			}
			void set(String^ value) {
				deliverTimeLabel->Text = value;
			}
		}
		double price;
		void setPrice(double arg) {
			price = arg;
		}
		double getPrice() {
			return price;
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::FlowLayoutPanel^ restsFlowLayoutTable;
	private: System::Windows::Forms::Label^ restNameLabel;





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ orderTimeLabel;
	private: System::Windows::Forms::Label^ deliverTimeLabel;

	private: System::Windows::Forms::Label^ label4;




	public:

		int amountOrd;
		void setAmountOrd(int arg) {
			amountOrd = arg;
		}
		int getAmountOrd() {
			return amountOrd;
		}

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


		OldOrderItem(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		OldOrderItem(order& ordr, string name, string description, string OrderTimearg, string DeliverTimearg, double pricearg)
		{
			InitializeComponent();
			for (uiid a : ordr.IDarticles) {
				ordr.artNames.push_back(getArticleNameFromID(a));
			}
			restNameLabel->Text = marshal_as<String^>(name);
			RestName = restNameLabel->Text;

			orderDescLabel->Text = marshal_as<String^>(description);
			OrderDescription = orderDescLabel->Text;

			orderTimeLabel->Text = marshal_as<String^>(OrderTimearg);
			OrderTime = orderTimeLabel->Text;

			ifstream fileOrH("ordersHist.json");
			json ordersHist;
			fileOrH >> ordersHist;
			ordr.userUName = getActiveUser();
			string acc = ordersHist[getIDfromOrder(ordr)]["accepted"];
			if (acc == "0")
			{
				label4->Text = "Narudzba odbijena.";
				deliverTimeLabel->Hide();
			}
			else
			{
				label4->Text = "Dostavljeno:";
				deliverTimeLabel->Text = marshal_as<String^>(DeliverTimearg);
			}
			deliverTimeLabel->Text = marshal_as<String^>(DeliverTimearg);
			DeliverTime = deliverTimeLabel->Text;

			orderPriceLabel->Text = Convert::ToString(pricearg);
			TotalPrice = pricearg;


			vector<string> names = getPeroArtikliIme();
			vector<int> amounts = getPeroArtikliPuta();

			for (int i = 0; i < names.size(); i++) {
				OrderedArticleItem^ artItem = gcnew OrderedArticleItem(names.at(i), amounts.at(i));
				restsFlowLayoutTable->Controls->Add(artItem);
			}

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OldOrderItem()
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
			this->articleNameLabel = (gcnew System::Windows::Forms::Label());
			this->orderDescLabel = (gcnew System::Windows::Forms::Label());
			this->orderPriceLabel = (gcnew System::Windows::Forms::Label());
			this->articleImagePathLabel = (gcnew System::Windows::Forms::Label());
			this->imgPathLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->restsFlowLayoutTable = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->restNameLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->orderTimeLabel = (gcnew System::Windows::Forms::Label());
			this->deliverTimeLabel = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->articleNameLabel->Size = System::Drawing::Size(147, 31);
			this->articleNameLabel->TabIndex = 2;
			this->articleNameLabel->Text = L"Restoran:";
			this->articleNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// orderDescLabel
			// 
			this->orderDescLabel->AutoSize = true;
			this->orderDescLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->orderDescLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->orderDescLabel->Location = System::Drawing::Point(15, 231);
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
			this->orderPriceLabel->Location = System::Drawing::Point(751, 216);
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
			this->label2->Location = System::Drawing::Point(835, 216);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 31);
			this->label2->TabIndex = 33;
			this->label2->Text = L"KM";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// restsFlowLayoutTable
			// 
			this->restsFlowLayoutTable->AutoScroll = true;
			this->restsFlowLayoutTable->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->restsFlowLayoutTable->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->restsFlowLayoutTable->Location = System::Drawing::Point(18, 57);
			this->restsFlowLayoutTable->Name = L"restsFlowLayoutTable";
			this->restsFlowLayoutTable->Size = System::Drawing::Size(495, 171);
			this->restsFlowLayoutTable->TabIndex = 34;
			this->restsFlowLayoutTable->WrapContents = false;
			// 
			// restNameLabel
			// 
			this->restNameLabel->AutoSize = true;
			this->restNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->restNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->restNameLabel->Location = System::Drawing::Point(165, 23);
			this->restNameLabel->Name = L"restNameLabel";
			this->restNameLabel->Size = System::Drawing::Size(140, 31);
			this->restNameLabel->TabIndex = 36;
			this->restNameLabel->Text = L"Restoran";
			this->restNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(539, 56);
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
			this->orderTimeLabel->Location = System::Drawing::Point(625, 56);
			this->orderTimeLabel->MaximumSize = System::Drawing::Size(230, 50);
			this->orderTimeLabel->Name = L"orderTimeLabel";
			this->orderTimeLabel->Size = System::Drawing::Size(38, 16);
			this->orderTimeLabel->TabIndex = 38;
			this->orderTimeLabel->Text = L"7:01";
			this->orderTimeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// deliverTimeLabel
			// 
			this->deliverTimeLabel->AutoSize = true;
			this->deliverTimeLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deliverTimeLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->deliverTimeLabel->Location = System::Drawing::Point(625, 72);
			this->deliverTimeLabel->MaximumSize = System::Drawing::Size(230, 50);
			this->deliverTimeLabel->Name = L"deliverTimeLabel";
			this->deliverTimeLabel->Size = System::Drawing::Size(38, 16);
			this->deliverTimeLabel->TabIndex = 40;
			this->deliverTimeLabel->Text = L"7:01";
			this->deliverTimeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label4->Location = System::Drawing::Point(519, 72);
			this->label4->MaximumSize = System::Drawing::Size(230, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 16);
			this->label4->TabIndex = 39;
			this->label4->Text = L"Dostavljeno:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OldOrderItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->deliverTimeLabel);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->orderTimeLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->restNameLabel);
			this->Controls->Add(this->restsFlowLayoutTable);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->imgPathLabel);
			this->Controls->Add(this->articleImagePathLabel);
			this->Controls->Add(this->orderPriceLabel);
			this->Controls->Add(this->orderDescLabel);
			this->Controls->Add(this->articleNameLabel);
			this->Name = L"OldOrderItem";
			this->Size = System::Drawing::Size(899, 258);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	};
}
