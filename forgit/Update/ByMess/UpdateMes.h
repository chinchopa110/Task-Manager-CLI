#pragma once

namespace WindowProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	public ref class UpdateMes : public System::Windows::Forms::Form
	{
	public:
		UpdateMes(void)
		{
			InitializeComponent();

		}

	protected:

		~UpdateMes()
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
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 25);
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
			this->label2->Location = System::Drawing::Point(12, 177);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(365, 49);
			this->label2->TabIndex = 1;
			this->label2->Text = L"New Description:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(21, 109);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(330, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(21, 258);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(330, 22);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(88, 313);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 87);
			this->button1->TabIndex = 4;
			this->button1->Text = L"EXIT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UpdateMes::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(241, 313);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 87);
			this->button2->TabIndex = 5;
			this->button2->Text = L"OK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UpdateMes::button2_Click);
			// 
			// UpdateName
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(453, 412);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"UpdateDescription";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"UpdateDescription";
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

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			//func

			String^ Name = textBox1->Text;
			String^ newmes = textBox2->Text;


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
					parts[1] = newmes;
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

			MessageBox::Show("The task description has been updating", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			if (this->Owner != nullptr) {
				this->Owner->Visible = true;
				this->Owner->Activate();
			}
			this->Close();
		}
	};
}
