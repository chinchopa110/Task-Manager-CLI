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

	public ref class Delete_by_name : public System::Windows::Forms::Form
	{
	public:
		Delete_by_name(void)
		{
			InitializeComponent();
		}

	protected:
		~Delete_by_name()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;

	protected:

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(39, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 49);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name:";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(48, 108);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(386, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(275, 230);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 97);
			this->button2->TabIndex = 3;
			this->button2->Text = L"OK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Delete_by_name::button2_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(48, 230);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 97);
			this->button1->TabIndex = 2;
			this->button1->Text = L"EXIT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Delete_by_name::button1_Click);
			// 
			// Delete_by_name
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(475, 339);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Delete_by_name";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Delete_by_name";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			if (this->Owner != nullptr) {
				this->Owner->Visible = true;
				this->Owner->Activate();
			}
			this->Close();
		}



		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

			String^ name = this->textBox1->Text;
			String^ filePath = "data.txt";

			try {
				array<String^>^ lines = File::ReadAllLines(filePath);
				List<String^>^ updatedLines = gcnew List<String^>();

				for each (String ^ line in lines) {
					array<String^>^ parts = line->Split('|');
					if (parts->Length > 0 && !parts[0]->Equals(name)) {
						updatedLines->Add(line);
					}
				}
				File::WriteAllLines(filePath, updatedLines->ToArray());

				MessageBox::Show("The task has been deleted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error deleting the task: " + ex->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			if (this->Owner != nullptr) {
				this->Owner->Visible = true;
				this->Owner->Activate();
			}
			this->Close();
		}
	};
}
