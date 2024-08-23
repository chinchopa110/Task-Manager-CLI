#pragma once
#include "Delete_by_name.h"

namespace WindowProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	public ref class Delete : public System::Windows::Forms::Form
	{
	public:
		Delete(void)
		{
			InitializeComponent();

		}

	protected:

		~Delete()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;

	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();


			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->button1->BackColor = System::Drawing::Color::DarkGray;
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(409, 61);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(228, 138);
			this->button1->TabIndex = 0;
			this->button1->Text = L"DELETE ALL";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Delete::button1_Click);


			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(45, 61);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(228, 138);
			this->button2->TabIndex = 1;
			this->button2->Text = L"DELETE TASK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Delete::button2_Click);


			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(717, 292);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Location = System::Drawing::Point(500, 500);
			this->Name = L"Delete";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Delete";
			this->ResumeLayout(false);

		}
#pragma endregion
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ filePath = "data.txt";

			try {
				StreamWriter^ writer = gcnew StreamWriter(filePath, false);
				writer->Close();
				MessageBox::Show("The tasks has been deleted", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error deleting the tasks: " + ex->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			if (this->Owner != nullptr) {
				this->Owner->Visible = true;
				this->Owner->Activate();
			}
			this->Close();
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			Delete_by_name^ del_by_name = gcnew Delete_by_name();

			del_by_name->ShowDialog();

			if (this->Owner != nullptr) {
				this->Owner->Visible = true;
				this->Owner->Activate();
			}
			this->Close();
		}
	};
}
