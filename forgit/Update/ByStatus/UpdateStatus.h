#pragma once

namespace WindowProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;


	public ref class UpdateStatus : public System::Windows::Forms::Form
	{
	public:
		UpdateStatus(void)
		{
			InitializeComponent();

		}

	protected:

		~UpdateStatus()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 49);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(10, 177);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(251, 49);
			this->label2->TabIndex = 1;
			this->label2->Text = L"New Status:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(18, 109);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(289, 23);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(144, 313);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 87);
			this->button1->TabIndex = 4;
			this->button1->Text = L"EXIT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UpdateStatus::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(33, 244);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(74, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Done";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &UpdateStatus::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(129, 244);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(77, 23);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Not Done";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &UpdateStatus::button4_Click);
			// 
			// UpdateStatus
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(396, 412);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Rockwell", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"UpdateStatus";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"UpdateStatus";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->Owner != nullptr) {
				this->Owner->Visible = true;
				this->Owner->Activate();
			}
			this->Close();
		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			//func Done

			String^ Name = textBox1->Text;


			List<String^>^ data = gcnew List<String^>();
			StreamReader^ reader = gcnew StreamReader("data.txt");

			try {
				while (!reader->EndOfStream) {
					data->Add(reader->ReadLine());
				}
			}
			finally {
				reader->Close();
			}

			bool flg = false;

			for (int i = 0; i < data->Count; i++) {
				array<String^>^ parts = data[i]->Split('|');

				if (parts[0] == Name) {
					flg = true;
					parts[4] = "Done";
					data[i] = String::Join("|", parts);
				}
			}

			if (!flg) {
				MessageBox::Show("The task name not found", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			StreamWriter^ writer = gcnew StreamWriter("data.txt");

			try {
				for each (String ^ line in data) {
					writer->WriteLine(line);
				}
			}
			finally {
				writer->Close();
			}

			MessageBox::Show("The task status has been updating", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			if (this->Owner != nullptr) {
				this->Owner->Visible = true;
				this->Owner->Activate();
			}
			this->Close();
		}

		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			//func Not Done
			String^ Name = textBox1->Text;


			List<String^>^ data = gcnew List<String^>();
			StreamReader^ reader = gcnew StreamReader("data.txt");

			try {
				while (!reader->EndOfStream) {
					data->Add(reader->ReadLine());
				}
			}
			finally {
				reader->Close();
			}

			bool flg = false;

			for (int i = 0; i < data->Count; i++) {
				array<String^>^ parts = data[i]->Split('|');

				if (parts[0] == Name) {
					flg = true;
					parts[4] = "Not Done";
					data[i] = String::Join("|", parts);
				}
			}

			if (!flg) {
				MessageBox::Show("The task name not found", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			StreamWriter^ writer = gcnew StreamWriter("data.txt");

			try {
				for each (String ^ line in data) {
					writer->WriteLine(line);
				}
			}
			finally {
				writer->Close();
			}

			MessageBox::Show("The task status has been updating", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			if (this->Owner != nullptr) {
				this->Owner->Visible = true;
				this->Owner->Activate();
			}
			this->Close();
		}
	};
}
