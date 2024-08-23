#pragma once
#include "Add.h"
#include "Delete.h"
#include "Find.h"
#include "Update.h"
#include "DisplayForPeriod.h"
#include "Sort.h"


namespace WindowProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Button^ button1;
	private:
		System::Windows::Forms::Button^ button2;
	private: 
		System::Windows::Forms::Button^ button3;
	private: 
		System::Windows::Forms::Button^ button4;
	private: 
		System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(158, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(721, 376);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 394);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 140);
			this->button1->TabIndex = 1;
			this->button1->Text = L"DISPLAY";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(158, 394);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 140);
			this->button2->TabIndex = 2;
			this->button2->Text = L"ADD";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button3->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(304, 394);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(130, 140);
			this->button3->TabIndex = 3;
			this->button3->Text = L"DELETE";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button4->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(452, 394);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(130, 140);
			this->button4->TabIndex = 4;
			this->button4->Text = L"FIND";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button5->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(600, 394);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(130, 140);
			this->button5->TabIndex = 5;
			this->button5->Text = L"UPDATE";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button6->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(749, 394);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(130, 140);
			this->button6->TabIndex = 6;
			this->button6->Text = L"DISPLAY\r\nFOR PERIOD\r\n";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button7->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(901, 394);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(130, 140);
			this->button7->TabIndex = 7;
			this->button7->Text = L"SORT";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1043, 546);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void display_all() {
			try {
				this->textBox1->Clear();
				StreamReader^ sr = gcnew StreamReader("data.txt");
				String^ content = sr->ReadToEnd();
				textBox1->Text = content;
				sr->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error reading file: " + ex->Message);
			}
		}

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			display_all();
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			Add^ add = gcnew Add();
			add->ShowDialog();

			display_all();
		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			Delete^ del = gcnew Delete();
			del->ShowDialog();

			display_all();
		}

		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			Find^ find = gcnew Find();
			find->ShowDialog();

			display_all();
		}

		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
			Update1^ update = gcnew Update1();
			update->ShowDialog();

			display_all();
		}

		System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
			DisplayForPeriod^ period = gcnew DisplayForPeriod();
			period->ShowDialog();
		}

		System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
			Sort^ sort = gcnew Sort();
			sort->ShowDialog();
		}
	};
}
