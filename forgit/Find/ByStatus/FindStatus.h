#pragma once

namespace WindowProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	public ref class FindStatus : public System::Windows::Forms::Form
	{
	public:
		FindStatus(void)
		{
			InitializeComponent();

		}

	protected:

		~FindStatus()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 49);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Status:";

			this->button1->Location = System::Drawing::Point(21, 122);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 75);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Done";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FindStatus::button1_Click);
			
			this->button2->Location = System::Drawing::Point(122, 122);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 75);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Not Done";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FindStatus::button2_Click);

			this->textBox2->Font = (gcnew System::Drawing::Font(L"Rockwell", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(245, 55);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(529, 347);
			this->textBox2->TabIndex = 7;

			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button3->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(338, 451);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(124, 97);
			this->button3->TabIndex = 8;
			this->button3->Text = L"EXIT";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FindStatus::button3_Click);

			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(828, 560);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Rockwell", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"FindStatus";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"FindStatus";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ filePath = "data.txt";

			try {
				array<String^>^ lines = File::ReadAllLines(filePath);

				this->textBox2->Clear();

				for each (String ^ line in lines) {
					array<String^>^ parts = line->Split('|');
					if (parts->Length > 0 && parts[4]->Equals("Done")) {
						this->textBox2->AppendText(line + Environment::NewLine);
					}
				}

				if (this->textBox2->Text->Length == 0) {
					MessageBox::Show("No entries found for the specified name.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error reading the file: " + ex->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ filePath = "data.txt";

			try {
				array<String^>^ lines = File::ReadAllLines(filePath);

				this->textBox2->Clear();

				for each (String ^ line in lines) {
					array<String^>^ parts = line->Split('|');
					if (parts->Length > 0 && parts[4]->Equals("Not Done")) {
						this->textBox2->AppendText(line + Environment::NewLine);
					}
				}

				if (this->textBox2->Text->Length == 0) {
					MessageBox::Show("No entries found for the specified name.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error reading the file: " + ex->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->Owner != nullptr) {
				this->Owner->Visible = true;
				this->Owner->Activate();
			}
			this->Close();
		}
	};
}
