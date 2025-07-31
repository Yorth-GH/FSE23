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
	public ref class MakeOrderArticleItem : public System::Windows::Forms::UserControl
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

		property String^ ArticleDestription {
			String^ get() {
				return articleDescriptionLabel->Text;
			}
			void set(String^ value) {
				articleDescriptionLabel->Text = value;
			}
		}

		property String^ ArticleImagePath {
			String^ get() {
				return imgPathLabel->Text;
			}
			void set(String^ value) {
				imgPathLabel->Text = value;
			}
		}

		property String^ ArticleTags {
			String^ get() {
				return articleTagsLabel->Text;
			}
			void set(String^ value) {
				articleTagsLabel->Text = value;
			}
		}

		double price;
		void setPrice(double arg) {
			price = arg;
		}
		double getPrice() {
			return price;
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	public:

		int amountOrd;
		void setAmountOrd(int arg) {
			amountOrd = arg;
		}
		int getAmountOrd() {
			return amountOrd;
		}

		int totalPrice;
		void setTotalPrice(int arg) {
			totalPrice = arg;
		}
		int getTotalPrice() {
			return totalPrice;
		}

	private: System::Windows::Forms::Label^ imgPathLabel;
	public:

	public:


		// Event to notify subscribers about the button click
		event System::EventHandler^ EditBtnClicked;


		MakeOrderArticleItem(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MakeOrderArticleItem(string name, string description, string imagePatharg, vector<string> tags, double pricearg, bool showOrder)
		{
			InitializeComponent();
			ArticleName = msclr::interop::marshal_as<String^>(name);
			articleNameLabel->Text = ArticleName;

			ArticleDestription = msclr::interop::marshal_as<String^>(description);
			articleDescriptionLabel->Text = ArticleDestription;

			String^ result;
			if (tags.size() != 0) {

				result = gcnew String((tags[0]).c_str());
			}
			for (size_t i = 1; i < tags.size(); ++i) {
				result += " " + gcnew String((tags[i]).c_str());
			}
			ArticleTags = result;
			articleTagsLabel->Text = ArticleTags;

			if (imagePatharg.empty()) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("Food.png"));
				imgPathLabel->Text = marshal_as<System::String^>("Food.png");
				ArticleImagePath = imgPathLabel->Text;
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(imagePatharg));
				imgPathLabel->Text = marshal_as<System::String^>(imagePatharg);
				ArticleImagePath = imgPathLabel->Text;
			}
			articlePriceLabel->Text = System::Convert::ToString(pricearg);
			setPrice(pricearg);

			setTotalPrice(getPrice() * getAmountOrd());

			if (!showOrder)
			{
				removeArticleBtn->Hide();
				addArticleBtn->Hide();
				artAmountLabel->Hide();
			}
		}

		MakeOrderArticleItem(string name, string description, string imagePatharg, vector<string> tags, double pricearg, int amountarg)
		{
			InitializeComponent();
			ArticleName = msclr::interop::marshal_as<String^>(name);
			articleNameLabel->Text = ArticleName;



			ArticleDestription = msclr::interop::marshal_as<String^>(description);
			articleDescriptionLabel->Text = ArticleDestription;

			String^ result;
			if (tags.size() != 0) {

				result = gcnew String((tags[0]).c_str());
			}
			for (size_t i = 1; i < tags.size(); ++i) {
				result += " " + gcnew String((tags[i]).c_str());
			}
			ArticleTags = result;
			articleTagsLabel->Text = ArticleTags;

			if (imagePatharg.empty()) {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>("Food.png"));
				imgPathLabel->Text = marshal_as<System::String^>("Food.png");
				ArticleImagePath = imgPathLabel->Text;
			}
			else {
				pictureBox1->Image = Image::FromFile(marshal_as<System::String^>(imagePatharg));
				imgPathLabel->Text = marshal_as<System::String^>(imagePatharg);
				ArticleImagePath = imgPathLabel->Text;
			}
			articlePriceLabel->Text = System::Convert::ToString(pricearg);
			setPrice(pricearg);

			setAmountOrd(amountarg);
			artAmountLabel->Text = Convert::ToString(getAmountOrd());

			setTotalPrice(getPrice() * getAmountOrd());
			removeArticleBtn->Hide();
			addArticleBtn->Hide();
			label1->Show();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MakeOrderArticleItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ articleNameLabel;
	protected:
	protected:
	protected:
	protected:
	private: System::Windows::Forms::Label^ articleDescriptionLabel;
	private: System::Windows::Forms::Label^ articlePriceLabel;

	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ articleImagePathLabel;
	private: System::Windows::Forms::Label^ articleTagsLabel;
	private: System::Windows::Forms::PictureBox^ removeArticleBtn;


	private: System::Windows::Forms::Label^ artAmountLabel;
	private: System::Windows::Forms::PictureBox^ addArticleBtn;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MakeOrderArticleItem::typeid));
			this->articleNameLabel = (gcnew System::Windows::Forms::Label());
			this->articleDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->articlePriceLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->articleImagePathLabel = (gcnew System::Windows::Forms::Label());
			this->articleTagsLabel = (gcnew System::Windows::Forms::Label());
			this->removeArticleBtn = (gcnew System::Windows::Forms::PictureBox());
			this->artAmountLabel = (gcnew System::Windows::Forms::Label());
			this->addArticleBtn = (gcnew System::Windows::Forms::PictureBox());
			this->imgPathLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->removeArticleBtn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addArticleBtn))->BeginInit();
			this->SuspendLayout();
			// 
			// articleNameLabel
			// 
			this->articleNameLabel->AutoSize = true;
			this->articleNameLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articleNameLabel->Location = System::Drawing::Point(155, 10);
			this->articleNameLabel->Name = L"articleNameLabel";
			this->articleNameLabel->Size = System::Drawing::Size(199, 31);
			this->articleNameLabel->TabIndex = 2;
			this->articleNameLabel->Text = L"IME ARTIKLA";
			this->articleNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// articleDescriptionLabel
			// 
			this->articleDescriptionLabel->AutoSize = true;
			this->articleDescriptionLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleDescriptionLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articleDescriptionLabel->Location = System::Drawing::Point(158, 49);
			this->articleDescriptionLabel->MaximumSize = System::Drawing::Size(407, 50);
			this->articleDescriptionLabel->Name = L"articleDescriptionLabel";
			this->articleDescriptionLabel->Size = System::Drawing::Size(95, 16);
			this->articleDescriptionLabel->TabIndex = 18;
			this->articleDescriptionLabel->Text = L"Opis ARtikla";
			this->articleDescriptionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// articlePriceLabel
			// 
			this->articlePriceLabel->AutoSize = true;
			this->articlePriceLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articlePriceLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articlePriceLabel->Location = System::Drawing::Point(602, 10);
			this->articlePriceLabel->Name = L"articlePriceLabel";
			this->articlePriceLabel->Size = System::Drawing::Size(88, 31);
			this->articlePriceLabel->TabIndex = 20;
			this->articlePriceLabel->Text = L"00.00";
			this->articlePriceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(15, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(113, 102);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 23;
			this->pictureBox1->TabStop = false;
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
			// articleTagsLabel
			// 
			this->articleTagsLabel->AutoSize = true;
			this->articleTagsLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->articleTagsLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->articleTagsLabel->Location = System::Drawing::Point(158, 101);
			this->articleTagsLabel->Name = L"articleTagsLabel";
			this->articleTagsLabel->Size = System::Drawing::Size(123, 16);
			this->articleTagsLabel->TabIndex = 26;
			this->articleTagsLabel->Text = L"Tag1 Tag2 Tag3";
			this->articleTagsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// removeArticleBtn
			// 
			this->removeArticleBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->removeArticleBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"removeArticleBtn.Image")));
			this->removeArticleBtn->Location = System::Drawing::Point(608, 91);
			this->removeArticleBtn->Name = L"removeArticleBtn";
			this->removeArticleBtn->Size = System::Drawing::Size(36, 36);
			this->removeArticleBtn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->removeArticleBtn->TabIndex = 28;
			this->removeArticleBtn->TabStop = false;
			this->removeArticleBtn->Click += gcnew System::EventHandler(this, &MakeOrderArticleItem::removeArticleBtn_Click);
			// 
			// artAmountLabel
			// 
			this->artAmountLabel->AutoSize = true;
			this->artAmountLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->artAmountLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->artAmountLabel->Location = System::Drawing::Point(659, 95);
			this->artAmountLabel->Name = L"artAmountLabel";
			this->artAmountLabel->Size = System::Drawing::Size(31, 31);
			this->artAmountLabel->TabIndex = 29;
			this->artAmountLabel->Text = L"0";
			this->artAmountLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// addArticleBtn
			// 
			this->addArticleBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addArticleBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addArticleBtn.Image")));
			this->addArticleBtn->Location = System::Drawing::Point(706, 91);
			this->addArticleBtn->Name = L"addArticleBtn";
			this->addArticleBtn->Size = System::Drawing::Size(36, 36);
			this->addArticleBtn->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->addArticleBtn->TabIndex = 30;
			this->addArticleBtn->TabStop = false;
			this->addArticleBtn->Click += gcnew System::EventHandler(this, &MakeOrderArticleItem::addArticleBtn_Click);
			// 
			// imgPathLabel
			// 
			this->imgPathLabel->AutoSize = true;
			this->imgPathLabel->Location = System::Drawing::Point(286, 45);
			this->imgPathLabel->Name = L"imgPathLabel";
			this->imgPathLabel->Size = System::Drawing::Size(35, 13);
			this->imgPathLabel->TabIndex = 31;
			this->imgPathLabel->Text = L"label1";
			this->imgPathLabel->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(494, 96);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 31);
			this->label1->TabIndex = 32;
			this->label1->Text = L"KOLICINA:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(683, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 31);
			this->label2->TabIndex = 33;
			this->label2->Text = L"KM";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MakeOrderArticleItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->imgPathLabel);
			this->Controls->Add(this->addArticleBtn);
			this->Controls->Add(this->artAmountLabel);
			this->Controls->Add(this->removeArticleBtn);
			this->Controls->Add(this->articleTagsLabel);
			this->Controls->Add(this->articleImagePathLabel);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->articlePriceLabel);
			this->Controls->Add(this->articleDescriptionLabel);
			this->Controls->Add(this->articleNameLabel);
			this->Name = L"MakeOrderArticleItem";
			this->Size = System::Drawing::Size(756, 144);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->removeArticleBtn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addArticleBtn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void articleEditBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		//article artt;
		//rest thisRest = restGet(getActiveUser());

		//artt.name = marshal_as<string>(articleNameLabel->Text);
		//artt.desc = marshal_as<string>(articleDescriptionLabel->Text);
		//string priceString = marshal_as<string>(articlePriceLabel->Text);

		//if (priceString.length() >= 2) {
		//	// Subtract the last two characters
		//	string result = priceString.substr(0, priceString.length() - 2);
		//}
		//artt.price = stod(priceString);
		//ifstream file("dbase.json");
		//json dbase;
		//file >> dbase;
		//file.close();
		//string imagepath = dbase["RESTS"][thisRest.username]["articles"][artt.name]["imagePath"];

		//artt.imagePath = imagepath;

	}

	private: System::Void addArticleBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		int amount = Int32::Parse(artAmountLabel->Text);
		amount += 1;
		artAmountLabel->Text = Convert::ToString(amount);;
		amountOrd += 1;

		setTotalPrice(getPrice() * getAmountOrd());

	}
	private: System::Void removeArticleBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		int amount = Int32::Parse(artAmountLabel->Text);
		if (amount - 1 >= 0) {
			amount -= 1;
			artAmountLabel->Text = Convert::ToString(amount);;
			amountOrd -= 1;
			setTotalPrice(getPrice() * getAmountOrd());
		}
	}
	};
}
