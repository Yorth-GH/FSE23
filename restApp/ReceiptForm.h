#pragma once
namespace restApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ReceiptForm
	/// </summary>
	public ref class ReceiptForm : public System::Windows::Forms::Form
	{
	public:
		ReceiptForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ReceiptForm(String^ arg)
		{
			InitializeComponent();
			receiptLabel->Text = arg;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ReceiptForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ receiptLabel;
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ReceiptForm::typeid));
			this->receiptLabel = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// receiptLabel
			// 
			this->receiptLabel->AutoSize = true;
			this->receiptLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->receiptLabel->Location = System::Drawing::Point(3, 0);
			this->receiptLabel->Name = L"receiptLabel";
			this->receiptLabel->Size = System::Drawing::Size(64, 25);
			this->receiptLabel->TabIndex = 0;
			this->receiptLabel->Text = L"label1";
			this->receiptLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->receiptLabel);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(534, 522);
			this->panel1->TabIndex = 1;
			// 
			// ReceiptForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 546);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ReceiptForm";
			this->Text = L"FFDM Restoranska Aplikacija";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
