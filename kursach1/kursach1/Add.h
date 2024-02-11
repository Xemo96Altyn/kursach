#pragma once
#include "PublicData.h";
namespace kursach1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Сводка для Add
	/// </summary>
	public ref class Add : public System::Windows::Forms::Form
	{

	public:
		Add()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Add()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ SNILSTextBox;
	private: System::Windows::Forms::TextBox^ summTextBox;
	private: System::Windows::Forms::TextBox^ cityTextBox;
	private: System::Windows::Forms::TextBox^ facTextBox;
	protected:






	private: System::Windows::Forms::Label^ SNILS;
	private: System::Windows::Forms::Label^ summ;
	private: System::Windows::Forms::Label^ city;
	private: System::Windows::Forms::Label^ fac;





	private: System::Windows::Forms::Button^ SaveButton;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma IDion Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SNILSTextBox = (gcnew System::Windows::Forms::TextBox());
			this->summTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->facTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SNILS = (gcnew System::Windows::Forms::Label());
			this->summ = (gcnew System::Windows::Forms::Label());
			this->city = (gcnew System::Windows::Forms::Label());
			this->fac = (gcnew System::Windows::Forms::Label());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// SNILSTextBox
			// 
			this->SNILSTextBox->Location = System::Drawing::Point(138, 12);
			this->SNILSTextBox->Name = L"SNILSTextBox";
			this->SNILSTextBox->Size = System::Drawing::Size(216, 20);
			this->SNILSTextBox->TabIndex = 1;
			// 
			// summTextBox
			// 
			this->summTextBox->Location = System::Drawing::Point(138, 60);
			this->summTextBox->Name = L"summTextBox";
			this->summTextBox->Size = System::Drawing::Size(216, 20);
			this->summTextBox->TabIndex = 2;
			// 
			// cityTextBox
			// 
			this->cityTextBox->Location = System::Drawing::Point(138, 103);
			this->cityTextBox->Name = L"cityTextBox";
			this->cityTextBox->Size = System::Drawing::Size(216, 20);
			this->cityTextBox->TabIndex = 3;
			// 
			// facTextBox
			// 
			this->facTextBox->Location = System::Drawing::Point(138, 148);
			this->facTextBox->Name = L"facTextBox";
			this->facTextBox->Size = System::Drawing::Size(216, 20);
			this->facTextBox->TabIndex = 4;
			// 
			// SNILS
			// 
			this->SNILS->AutoSize = true;
			this->SNILS->Location = System::Drawing::Point(13, 12);
			this->SNILS->Name = L"SNILS";
			this->SNILS->Size = System::Drawing::Size(45, 13);
			this->SNILS->TabIndex = 6;
			this->SNILS->Text = L"СНИЛС";
			// 
			// summ
			// 
			this->summ->AutoSize = true;
			this->summ->Location = System::Drawing::Point(13, 60);
			this->summ->Name = L"summ";
			this->summ->Size = System::Drawing::Size(103, 13);
			this->summ->TabIndex = 7;
			this->summ->Text = L"Сумма баллов ЕГЭ";
			// 
			// city
			// 
			this->city->AutoSize = true;
			this->city->Location = System::Drawing::Point(13, 109);
			this->city->Name = L"city";
			this->city->Size = System::Drawing::Size(37, 13);
			this->city->TabIndex = 8;
			this->city->Text = L"Город";
			// 
			// fac
			// 
			this->fac->AutoSize = true;
			this->fac->Location = System::Drawing::Point(13, 154);
			this->fac->Name = L"fac";
			this->fac->Size = System::Drawing::Size(75, 13);
			this->fac->TabIndex = 9;
			this->fac->Text = L"Направление";
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(265, 226);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 10;
			this->SaveButton->Text = L"Сохранить";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &Add::SaveButton_Click);
			// 
			// Add
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(366, 261);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->fac);
			this->Controls->Add(this->city);
			this->Controls->Add(this->summ);
			this->Controls->Add(this->SNILS);
			this->Controls->Add(this->facTextBox);
			this->Controls->Add(this->cityTextBox);
			this->Controls->Add(this->summTextBox);
			this->Controls->Add(this->SNILSTextBox);
			this->Name = L"Add";
			this->Text = L"Добавить нового абитуриента";
			this->Load += gcnew System::EventHandler(this, &Add::Add_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endIDion

	private: System::Void Add_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			SqlConnection^ sqlConn = gcnew SqlConnection(PublicData::connString);
			sqlConn->Open();

			String^ SNILS = this->SNILSTextBox->Text;
			String^ summ = this->summTextBox->Text;
			String^ city = this->cityTextBox->Text;
			String^ fac = this->facTextBox->Text;

			String^ insertQuery = String::Format("INSERT INTO {0} (СНИЛС, [Сумма баллов ЕГЭ], Город, Направление) VALUES (@SNILS, @summ, @city, @fac)", PublicData::SelectedItemComboBox);
			SqlCommand^ insertCommand = gcnew SqlCommand(insertQuery, sqlConn);
			insertCommand->Parameters->AddWithValue("@SNILS", SNILS);
			insertCommand->Parameters->AddWithValue("@summ", summ);	
			insertCommand->Parameters->AddWithValue("@city", city);
			insertCommand->Parameters->AddWithValue("@fac", fac);

			insertCommand->ExecuteNonQuery();

			sqlConn->Close();
			this->Close();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message,
				"Ошибка добавления нового абитуриента", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
