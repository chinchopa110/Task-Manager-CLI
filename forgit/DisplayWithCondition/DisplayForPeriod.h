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



	public ref class DisplayForPeriod : public System::Windows::Forms::Form
	{
	public:
		DisplayForPeriod(void)
		{
			InitializeComponent();
		}

	protected:
		~DisplayForPeriod()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(70, 24);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(721, 376);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(70, 427);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 82);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Day";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DisplayForPeriod::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(250, 427);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(174, 82);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Week";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &DisplayForPeriod::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Rockwell", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(430, 427);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(174, 82);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Month";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &DisplayForPeriod::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Rockwell", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(610, 427);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(174, 82);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Year";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &DisplayForPeriod::button4_Click);
			// 
			// DisplayForPeriod
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(861, 536);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"DisplayForPeriod";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"DisplayForPeriod";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		String^ GetCurrentDate() {
			DateTime now = DateTime::Now; 
			return String::Format("{0:D2}-{1:D2}-{2}", now.Day, now.Month, now.Year);
		}

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			StreamReader^ reader = gcnew StreamReader("data.txt");
			List<String^>^ linesList = gcnew List<String^>();

			while (!reader->EndOfStream) {
				String^ line = reader->ReadLine();
				linesList->Add(line);
			}
			reader->Close();

			array<String^>^ linesArray = linesList->ToArray();

			String^ currenrdate = GetCurrentDate();

			this->textBox1->Clear();
			for each (String ^ line in linesArray) {
				array<String^>^ parts = line->Split('|');
				if (currenrdate == parts[2]) {
					this->textBox1->AppendText(line + Environment::NewLine);
				}
			}
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			StreamReader^ reader = gcnew StreamReader("data.txt");
			List<String^>^ linesList = gcnew List<String^>();

			while (!reader->EndOfStream) {
				String^ line = reader->ReadLine();
				linesList->Add(line);
			}
			reader->Close();

			array<String^>^ linesArray = linesList->ToArray();

			String^ currenrdate = GetCurrentDate();

			this->textBox1->Clear();
			for each (String ^ line in linesArray) {
				array<String^>^ parts = line->Split('|');

				array<String^>^ date1 = currenrdate->Split('-');
				array<String^>^ date2 = parts[2]->Split('-');

				int day1 = Int32::Parse(date1[0]->Trim());
				int month1 = Int32::Parse(date1[1]->Trim());
				int year1 = Int32::Parse(date1[2]->Trim());

				int day2 = Int32::Parse(date2[0]->Trim());
				int month2 = Int32::Parse(date2[1]->Trim());
				int year2 = Int32::Parse(date2[2]->Trim());

				if (day2 - day1 >= 0 && day1 - day2 < 7 && month1 == month2 && year1 == year2) {
					this->textBox1->AppendText(line + Environment::NewLine);
				}
			}
		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			StreamReader^ reader = gcnew StreamReader("data.txt");
			List<String^>^ linesList = gcnew List<String^>();

			while (!reader->EndOfStream) {
				String^ line = reader->ReadLine();
				linesList->Add(line);
			}
			reader->Close();

			array<String^>^ linesArray = linesList->ToArray();

			String^ currenrdate = GetCurrentDate();

			this->textBox1->Clear();
			for each (String ^ line in linesArray) {
				array<String^>^ parts = line->Split('|');

				array<String^>^ date1 = currenrdate->Split('-');
				array<String^>^ date2 = parts[2]->Split('-');

				int month1 = Int32::Parse(date1[1]->Trim());
				int year1 = Int32::Parse(date1[2]->Trim());

				int month2 = Int32::Parse(date2[1]->Trim());
				int year2 = Int32::Parse(date2[2]->Trim());

				if (month1 == month2 && year1 == year2) {
					this->textBox1->AppendText(line + Environment::NewLine);
				}
			}
		}

		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			StreamReader^ reader = gcnew StreamReader("data.txt");
			List<String^>^ linesList = gcnew List<String^>();

			while (!reader->EndOfStream) {
				String^ line = reader->ReadLine();
				linesList->Add(line);
			}
			reader->Close();

			array<String^>^ linesArray = linesList->ToArray();

			String^ currenrdate = GetCurrentDate();

			this->textBox1->Clear();
			for each (String ^ line in linesArray) {
				array<String^>^ parts = line->Split('|');

				array<String^>^ date1 = currenrdate->Split('-');
				array<String^>^ date2 = parts[2]->Split('-');

				int year1 = Int32::Parse(date1[2]->Trim());

				int year2 = Int32::Parse(date2[2]->Trim());

				if (year1 == year2) {
					this->textBox1->AppendText(line + Environment::NewLine);
				}
			}
		}
	};
}
