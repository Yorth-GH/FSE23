#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
#include "MakeOrderArticleItem.h"
#include "MakeOrderArticleItem.h"
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
	public ref class SendOrderForm : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		SendOrderForm(void)
		{
			InitializeComponent();
		}
		SendOrderForm(Form^ form,vector<article> arg, vector<int> amarg, string restName, string restUsername)
		{

			InitializeComponent();
			previousForm = form;
			for (const auto& item : arg) {
				std::reverse(amarg.begin(), amarg.end());
				int am = amarg.back();
				amarg.pop_back();
				MakeOrderArticleItem^ artItem = gcnew MakeOrderArticleItem
					(item.name, item.desc, item.imagePath, item.tags, item.price,am);
				orderPriceLabel->Text = Convert::ToString((am*item.price) + Double::Parse(orderPriceLabel->Text));
				menuFlowLayoutPanel->Controls->Add(artItem);
			}
			restNameLabel->Text = marshal_as<String^>(restName);
			restUsernameLabel->Text = marshal_as<String^>(restUsername);
		}

	public:
	public:
	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::FlowLayoutPanel^ menuFlowLayoutPanel;



	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ orderPriceLabel;
	private: System::Windows::Forms::RichTextBox^ commentTextBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ restNameLabel;
	private: System::Windows::Forms::Label^ restUsernameLabel;











	public:
	public: bool isExpand = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SendOrderForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ headLabel;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SendOrderForm::typeid));
			this->headLabel = (gcnew System::Windows::Forms::Label());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->menuFlowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->orderPriceLabel = (gcnew System::Windows::Forms::Label());
			this->commentTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->restNameLabel = (gcnew System::Windows::Forms::Label());
			this->restUsernameLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// headLabel
			// 
			this->headLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->headLabel->AutoSize = true;
			this->headLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->headLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->headLabel->Location = System::Drawing::Point(163, 0);
			this->headLabel->Name = L"headLabel";
			this->headLabel->Size = System::Drawing::Size(445, 61);
			this->headLabel->TabIndex = 2;
			this->headLabel->Text = L"Vasa Narudzba";
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
			this->backBtn->Location = System::Drawing::Point(5, 7);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(111, 63);
			this->backBtn->TabIndex = 10;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &SendOrderForm::backBtn_Click);
			// 
			// menuFlowLayoutPanel
			// 
			this->menuFlowLayoutPanel->AutoScroll = true;
			this->menuFlowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->menuFlowLayoutPanel->Location = System::Drawing::Point(5, 85);
			this->menuFlowLayoutPanel->Name = L"menuFlowLayoutPanel";
			this->menuFlowLayoutPanel->Size = System::Drawing::Size(771, 413);
			this->menuFlowLayoutPanel->TabIndex = 18;
			this->menuFlowLayoutPanel->WrapContents = false;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(12, 751);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 45);
			this->label1->TabIndex = 27;
			this->label1->Text = L"Cena:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->button1->Location = System::Drawing::Point(586, 743);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 53);
			this->button1->TabIndex = 29;
			this->button1->Text = L"NARUCI";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &SendOrderForm::button1_Click);
			// 
			// orderPriceLabel
			// 
			this->orderPriceLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->orderPriceLabel->AutoSize = true;
			this->orderPriceLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->orderPriceLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->orderPriceLabel->Location = System::Drawing::Point(132, 753);
			this->orderPriceLabel->Name = L"orderPriceLabel";
			this->orderPriceLabel->Size = System::Drawing::Size(46, 45);
			this->orderPriceLabel->TabIndex = 30;
			this->orderPriceLabel->Text = L"0";
			// 
			// commentTextBox
			// 
			this->commentTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->commentTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->commentTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->commentTextBox->Location = System::Drawing::Point(12, 544);
			this->commentTextBox->Name = L"commentTextBox";
			this->commentTextBox->Size = System::Drawing::Size(369, 136);
			this->commentTextBox->TabIndex = 44;
			this->commentTextBox->Text = L"";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(6, 510);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 31);
			this->label2->TabIndex = 45;
			this->label2->Text = L"Komentar:";
			// 
			// restNameLabel
			// 
			this->restNameLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->restNameLabel->AutoSize = true;
			this->restNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 1, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->restNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->restNameLabel->Location = System::Drawing::Point(745, 510);
			this->restNameLabel->Name = L"restNameLabel";
			this->restNameLabel->Size = System::Drawing::Size(14, 2);
			this->restNameLabel->TabIndex = 46;
			this->restNameLabel->Text = L"Vasa Narudzba";
			this->restNameLabel->Visible = false;
			// 
			// restUsernameLabel
			// 
			this->restUsernameLabel->AutoSize = true;
			this->restUsernameLabel->Location = System::Drawing::Point(143, 29);
			this->restUsernameLabel->Name = L"restUsernameLabel";
			this->restUsernameLabel->Size = System::Drawing::Size(35, 13);
			this->restUsernameLabel->TabIndex = 47;
			this->restUsernameLabel->Text = L"label1";
			this->restUsernameLabel->Visible = false;
			// 
			// SendOrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(771, 807);
			this->Controls->Add(this->restUsernameLabel);
			this->Controls->Add(this->restNameLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->commentTextBox);
			this->Controls->Add(this->orderPriceLabel);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuFlowLayoutPanel);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->headLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SendOrderForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Korisnicka Aplikacija";
			this->VisibleChanged += gcnew System::EventHandler(this, &SendOrderForm::MyMenuForm_VisibleChanged);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void MyMenuForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {

		/*bool exists = false;
		vector<article> articles = parseArticlesFromRest(marshal_as<string>(restUsernameLabel->Text));
		for each (article art in articles) {
			String^ existingResName = marshal_as<String^>(art.name);
			MakeOrderArticleItem^ item = gcnew MakeOrderArticleItem(art.name, art.desc, art.imagePath, art.tags, art.price);
			for each (Control ^ control in menuFlowLayoutPanel->Controls) {
				MakeOrderArticleItem^ existingItem = dynamic_cast<MakeOrderArticleItem^>(control);
				if ((existingItem->ArticleName == item->ArticleName)) {
					exists = true;
				}
			}
			if (exists == false) {
				menuFlowLayoutPanel->Controls->Add(item);
			}
			exists = false;
		}*/

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (menuFlowLayoutPanel->Controls->Count == 0) {
			MessageBox::Show("Narduzba Vam je prazna.\n Vratite se na prethodni prozor.", "Prazna Narudzba", MessageBoxButtons::OK,
				MessageBoxIcon::Information);
		}
		else {

			order ord;
			ord.comment =marshal_as<string>(commentTextBox->Text);
			vector<string> artNames;
			double orderPrice = 0;
			ord.userUName = getActiveUser();
			ord.restName = marshal_as<string>(restUsernameLabel->Text);
			ord.timeOrd = marshal_as<string>(DateTime::Now.ToString());
			ord.timeRec = marshal_as<string>(DateTime::Now.AddMinutes(30).ToString());
			ord.processed = false;
			vector<unsigned int> ids;
			vector<article> articles = parseArticlesFromRest(marshal_as<string>(restUsernameLabel->Text));
			for each (article art in articles) {
				for each (Control ^ control in menuFlowLayoutPanel->Controls) {
					MakeOrderArticleItem^ item = dynamic_cast<MakeOrderArticleItem^>(control);
					if (item->ArticleName == marshal_as<String^>(art.name)) {
						for (int i = 0; i < item->getAmountOrd(); i++) {
							ids.push_back(art.id);
						}
					}
				}
			}
			ord.IDarticles = ids;
			for each (Control ^ control in menuFlowLayoutPanel->Controls) {
				MakeOrderArticleItem^ item = dynamic_cast<MakeOrderArticleItem^>(control);
				artNames.push_back(marshal_as<string>( item->ArticleName));
				orderPrice += item->getPrice()*item->getAmountOrd();
			}
			ord.artNames = artNames;
			ord.price = orderPrice;
			user temp = userGet(getActiveUser());
			if (temp.balance >= ord.price)
			{
				orderCreate(ord);
				MessageBox::Show("Uspesno ste napravili narudzbu.\nTrenutno se obradjuje", "Uspeh Kreiranja", MessageBoxButtons::OK,
					MessageBoxIcon::Information);
				this->Hide();
				previousForm->Show();
			}
			//if (userSubtractBalance(getActiveUser(), ord.price) == true) {
			//
			//}
			else {
				MessageBox::Show("Nemate dovoljno novca na racunu.\nAzurirajte stanje racuna u podesavanjima naloga.", "Nedostatak novca", MessageBoxButtons::OK,
					MessageBoxIcon::Information);
				this->Hide();
				previousForm->Show();
			}
		}
	}
};
}
