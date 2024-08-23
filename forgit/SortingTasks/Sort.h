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


	public ref class Sort : public System::Windows::Forms::Form
	{
	public:
		Sort(void)
		{
			InitializeComponent();
		}

	protected:
		~Sort()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(70, 27);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(721, 376);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(70, 433);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(354, 82);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Prioritet";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Sort::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(437, 433);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(354, 82);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Date";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Sort::button2_Click);
			// 
			// Sort
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(861, 536);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Sort";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Sort";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void BubbleSort1(array<String^>^ lines) {
			int n = lines->Length;
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {

					array<String^>^ parts1 = lines[j]->Split('|');
					array<String^>^ parts2 = lines[j + 1]->Split('|');
					if (parts1->Length > 3 && parts2->Length > 3) {

						int prior1 = Int32::Parse(parts1[3]->Trim());
						int prior2 = Int32::Parse(parts2[3]->Trim());
						if (prior1 > prior2) {
							String^ temp = lines[j];
							lines[j] = lines[j + 1];
							lines[j + 1] = temp;
						}
					}
				}
			}
		}

		void BubbleSort2(array<String^>^ lines) {
			int n = lines->Length;
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					array<String^>^ parts1 = lines[j]->Split('|');
					array<String^>^ parts2 = lines[j + 1]->Split('|');

					if (parts1->Length > 3 && parts2->Length > 3) {
						array<String^>^ date1 = parts1[2]->Split('-');
						array<String^>^ date2 = parts2[2]->Split('-');

						int day1 = Int32::Parse(date1[0]->Trim());
						int month1 = Int32::Parse(date1[1]->Trim());
						int year1 = Int32::Parse(date1[2]->Trim());

						int day2 = Int32::Parse(date2[0]->Trim());
						int month2 = Int32::Parse(date2[1]->Trim());
						int year2 = Int32::Parse(date2[2]->Trim());

						if (year1 > year2 || (year1 == year2 && month1 > month2) ||
							(year1 == year2 && month1 == month2 && day1 > day2)) {
							String^ temp = lines[j];
							lines[j] = lines[j + 1];
							lines[j + 1] = temp;
						}
					}
				}
			}
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
			BubbleSort1(linesArray);

			this->textBox1->Clear();
			for each (String ^ sortedLine in linesArray) {
				this->textBox1->AppendText(sortedLine + Environment::NewLine);
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
			BubbleSort2(linesArray);

			this->textBox1->Clear(); 
			for each (String ^ sortedLine in linesArray) {
				this->textBox1->AppendText(sortedLine + Environment::NewLine);
			}
		}
	};
}
