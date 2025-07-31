#pragma once
#include <msclr/marshal_cppstd.h>
#include "../src/include/dbase.h"
namespace userApp {
	using namespace msclr::interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	/// 
	/// // Forward declaration of the LoginForm class
	public ref class AddBalanceForm : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		AddBalanceForm(void)
		{
			InitializeComponent();
			exceptionLabel->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
		}
		AddBalanceForm(Form^ form)
		{
			InitializeComponent();
			user thisUser = userGet(getActiveUser());
			label4->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
			previousForm = form;
			exceptionLabel->Hide();
			exceptionLabel2->Hide();
			exceptionLabel3->Hide();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddBalanceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ monthTextbox;









	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::Button^ confirmRegBtn;












	private: System::Windows::Forms::Label^ exceptionLabel2;

	private: System::Windows::Forms::Label^ exceptionLabel;

	private: System::Windows::Forms::Label^ exceptionLabel3;
	private: System::Windows::Forms::TextBox^ yearTextbox;

	private: System::Windows::Forms::TextBox^ cvvTextBox;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ nameTextBox;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ cardNumTextbox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ sumTextbox;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label8;







	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddBalanceForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->monthTextbox = (gcnew System::Windows::Forms::TextBox());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->confirmRegBtn = (gcnew System::Windows::Forms::Button());
			this->exceptionLabel2 = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel = (gcnew System::Windows::Forms::Label());
			this->exceptionLabel3 = (gcnew System::Windows::Forms::Label());
			this->yearTextbox = (gcnew System::Windows::Forms::TextBox());
			this->cvvTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cardNumTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->sumTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label2->Location = System::Drawing::Point(201, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(250, 61);
			this->label2->TabIndex = 1;
			this->label2->Text = L"UPLATA";
			// 
			// monthTextbox
			// 
			this->monthTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->monthTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->monthTextbox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->monthTextbox->Location = System::Drawing::Point(219, 356);
			this->monthTextbox->MaxLength = 20;
			this->monthTextbox->Name = L"monthTextbox";
			this->monthTextbox->Size = System::Drawing::Size(102, 30);
			this->monthTextbox->TabIndex = 6;
			this->monthTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AddBalanceForm::monthTextbox_KeyDown);
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
			this->backBtn->Location = System::Drawing::Point(23, 18);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(109, 55);
			this->backBtn->TabIndex = 9;
			this->backBtn->Text = L"Nazad";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &AddBalanceForm::backBtn_Click);
			// 
			// confirmRegBtn
			// 
			this->confirmRegBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->confirmRegBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->confirmRegBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmRegBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)));
			this->confirmRegBtn->Location = System::Drawing::Point(238, 534);
			this->confirmRegBtn->Name = L"confirmRegBtn";
			this->confirmRegBtn->Size = System::Drawing::Size(198, 44);
			this->confirmRegBtn->TabIndex = 10;
			this->confirmRegBtn->Text = L"POTVRDI";
			this->confirmRegBtn->UseVisualStyleBackColor = false;
			this->confirmRegBtn->Click += gcnew System::EventHandler(this, &AddBalanceForm::confirmRegBtn_Click);
			// 
			// exceptionLabel2
			// 
			this->exceptionLabel2->AutoSize = true;
			this->exceptionLabel2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel2->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel2->Location = System::Drawing::Point(229, 504);
			this->exceptionLabel2->Name = L"exceptionLabel2";
			this->exceptionLabel2->Size = System::Drawing::Size(185, 18);
			this->exceptionLabel2->TabIndex = 25;
			this->exceptionLabel2->Text = L"Popunite prazna polja";
			// 
			// exceptionLabel
			// 
			this->exceptionLabel->AutoSize = true;
			this->exceptionLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel->Location = System::Drawing::Point(234, 504);
			this->exceptionLabel->Name = L"exceptionLabel";
			this->exceptionLabel->Size = System::Drawing::Size(197, 18);
			this->exceptionLabel->TabIndex = 23;
			this->exceptionLabel->Text = L"Broj kartice nije validan";
			// 
			// exceptionLabel3
			// 
			this->exceptionLabel3->AutoSize = true;
			this->exceptionLabel3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exceptionLabel3->ForeColor = System::Drawing::Color::Brown;
			this->exceptionLabel3->Location = System::Drawing::Point(229, 504);
			this->exceptionLabel3->Name = L"exceptionLabel3";
			this->exceptionLabel3->Size = System::Drawing::Size(213, 18);
			this->exceptionLabel3->TabIndex = 27;
			this->exceptionLabel3->Text = L"Datum isteka nije validan";
			// 
			// yearTextbox
			// 
			this->yearTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->yearTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yearTextbox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->yearTextbox->Location = System::Drawing::Point(361, 356);
			this->yearTextbox->MaxLength = 20;
			this->yearTextbox->Name = L"yearTextbox";
			this->yearTextbox->Size = System::Drawing::Size(102, 30);
			this->yearTextbox->TabIndex = 29;
			this->yearTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AddBalanceForm::yearTextbox_KeyDown);
			// 
			// cvvTextBox
			// 
			this->cvvTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->cvvTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cvvTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->cvvTextBox->Location = System::Drawing::Point(514, 257);
			this->cvvTextBox->MaxLength = 20;
			this->cvvTextBox->Name = L"cvvTextBox";
			this->cvvTextBox->Size = System::Drawing::Size(134, 30);
			this->cvvTextBox->TabIndex = 31;
			this->cvvTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AddBalanceForm::cvvTextBox_KeyDown);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label3->Location = System::Drawing::Point(508, 223);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(140, 31);
			this->label3->TabIndex = 30;
			this->label3->Text = L"CSC/CVV";
			// 
			// nameTextBox
			// 
			this->nameTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->nameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameTextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->nameTextBox->Location = System::Drawing::Point(212, 164);
			this->nameTextBox->MaxLength = 20;
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(276, 30);
			this->nameTextBox->TabIndex = 33;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label6->Location = System::Drawing::Point(206, 130);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(219, 31);
			this->label6->TabIndex = 32;
			this->label6->Text = L"Ime i Prezime:";
			// 
			// cardNumTextbox
			// 
			this->cardNumTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->cardNumTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cardNumTextbox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->cardNumTextbox->Location = System::Drawing::Point(212, 257);
			this->cardNumTextbox->MaxLength = 20;
			this->cardNumTextbox->Name = L"cardNumTextbox";
			this->cardNumTextbox->Size = System::Drawing::Size(276, 30);
			this->cardNumTextbox->TabIndex = 35;
			this->cardNumTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AddBalanceForm::cardNumTextbox_KeyDown);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label4->Location = System::Drawing::Point(206, 223);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(186, 31);
			this->label4->TabIndex = 34;
			this->label4->Text = L"Broj Kartice:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label7->Location = System::Drawing::Point(232, 322);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(210, 31);
			this->label7->TabIndex = 36;
			this->label7->Text = L"Datum Isteka:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label1->Location = System::Drawing::Point(327, 354);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 31);
			this->label1->TabIndex = 37;
			this->label1->Text = L"/";
			// 
			// sumTextbox
			// 
			this->sumTextbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->sumTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sumTextbox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->sumTextbox->Location = System::Drawing::Point(255, 438);
			this->sumTextbox->MaxLength = 20;
			this->sumTextbox->Name = L"sumTextbox";
			this->sumTextbox->Size = System::Drawing::Size(148, 30);
			this->sumTextbox->TabIndex = 39;
			this->sumTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AddBalanceForm::sumTextbox_KeyDown);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label5->Location = System::Drawing::Point(281, 404);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 31);
			this->label5->TabIndex = 38;
			this->label5->Text = L"Suma:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->label8->Location = System::Drawing::Point(409, 436);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 31);
			this->label8->TabIndex = 40;
			this->label8->Text = L"KM";
			// 
			// AddBalanceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(724, 645);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->sumTextbox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->cardNumTextbox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->cvvTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->yearTextbox);
			this->Controls->Add(this->exceptionLabel3);
			this->Controls->Add(this->exceptionLabel2);
			this->Controls->Add(this->exceptionLabel);
			this->Controls->Add(this->confirmRegBtn);
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->monthTextbox);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(740, 684);
			this->Name = L"AddBalanceForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FFDM Korisnicka Aplikacija";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void backBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Hide();
		previousForm->Show();
	}
	private: System::Void confirmRegBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrEmpty(nameTextBox->Text) || String::IsNullOrEmpty(cardNumTextbox->Text) ||
			String::IsNullOrEmpty(cvvTextBox->Text) || String::IsNullOrEmpty(monthTextbox->Text) ||
			String::IsNullOrEmpty(yearTextbox->Text) || String::IsNullOrEmpty(sumTextbox->Text)) {
			exceptionLabel->Hide();
			exceptionLabel2->Show();
			exceptionLabel3->Hide();
		}
		else {
			float money;
			Single::TryParse(sumTextbox->Text, money);
			switch (addMoney(getActiveUser(), marshal_as<string>(cardNumTextbox->Text), marshal_as<string>(monthTextbox->Text),
				marshal_as<string>(yearTextbox->Text), money)) {

			case 0:
				MessageBox::Show("Uspesno ste dodali novac.\n Vratite se na prethodni prozor.", "Uspeh Kreiranja", MessageBoxButtons::OK,
					MessageBoxIcon::Information);
				this->Hide();
				previousForm->Show();
				break;
			case 1:
				exceptionLabel->Show();
				exceptionLabel2->Hide();
				exceptionLabel3->Hide();
				label7->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				label4->ForeColor = System::Drawing::Color::Brown;
				break;
			case 2:
				label4->ForeColor = System::Drawing::Color::FromArgb(231, 224, 139);
				label7->ForeColor = System::Drawing::Color::Brown;
				exceptionLabel->Hide();
				exceptionLabel2->Hide();
				exceptionLabel3->Show();
				break;
			}

		}

	}


	private: System::Void monthTextbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Check if the pressed key is a digit
		if (Char::IsDigit(e->KeyChar)) {
			// Check if the total length is less than 16 or Backspace key is pressed
			if (marshal_as<string>( monthTextbox->Text).length() < 2 && e->KeyChar != '\b') {
				// Allow the key
				e->Handled = false;
			}
			else {
				// Suppress the key if the limit is reached
				e->Handled = true;
			}
		}
		else {
			// Suppress the key if it's not a digit
			e->Handled = true;
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void cardNumTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Check if the pressed key is a digit and the total length is less than 16
		if (Char::IsDigit(static_cast<wchar_t>(e->KeyValue)) && marshal_as<string>(cardNumTextbox->Text).length() < 16) {
			// Allow the key
			e->SuppressKeyPress = false;
		}
		else if (e->KeyValue == 8) {  // Check for Backspace key
			// Allow the Backspace key even if the TextBox is full
			e->SuppressKeyPress = false;
		}
		else {
			// Suppress the key if it's not a digit or Backspace
			e->SuppressKeyPress = true;
		}
	}
	private: System::Void cvvTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Check if the pressed key is a digit and the total length is less than 16
		if (Char::IsDigit(static_cast<wchar_t>(e->KeyValue)) && marshal_as<string>(cvvTextBox->Text).length() < 3) {
			// Allow the key
			e->SuppressKeyPress = false;
		}
		else if (e->KeyValue == 8) {  // Check for Backspace key
			// Allow the Backspace key even if the TextBox is full
			e->SuppressKeyPress = false;
		}
		else {
			// Suppress the key if it's not a digit or Backspace
			e->SuppressKeyPress = true;
		}
	}
	private: System::Void monthTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Check if the pressed key is a digit and the total length is less than 16
		if (Char::IsDigit(static_cast<wchar_t>(e->KeyValue)) && marshal_as<string>(monthTextbox->Text).length() < 2) {
			// Allow the key
			e->SuppressKeyPress = false;
		}
		else if (e->KeyValue == 8) {  // Check for Backspace key
			// Allow the Backspace key even if the TextBox is full
			e->SuppressKeyPress = false;
		}
		else {
			// Suppress the key if it's not a digit or Backspace
			e->SuppressKeyPress = true;
		}
	}
	private: System::Void yearTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Check if the pressed key is a digit and the total length is less than 16
		if (Char::IsDigit(static_cast<wchar_t>(e->KeyValue)) && marshal_as<string>(yearTextbox->Text).length() < 4) {
			// Allow the key
			e->SuppressKeyPress = false;
		}
		else if (e->KeyValue == 8) {  // Check for Backspace key
			// Allow the Backspace key even if the TextBox is full
			e->SuppressKeyPress = false;
		}
		else {
			// Suppress the key if it's not a digit or Backspace
			e->SuppressKeyPress = true;
		}
	}
	private: System::Void sumTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Check if the pressed key is a digit and the total length is less than 16
		if (Char::IsDigit(static_cast<wchar_t>(e->KeyValue)) && marshal_as<string>(sumTextbox->Text).length() < 6) {
			// Allow the key
			e->SuppressKeyPress = false;
		}
		else if (e->KeyValue == 8) {  // Check for Backspace key
			// Allow the Backspace key even if the TextBox is full
			e->SuppressKeyPress = false;
		}
		else {
			// Suppress the key if it's not a digit or Backspace
			e->SuppressKeyPress = true;
		}
	}
};
}
