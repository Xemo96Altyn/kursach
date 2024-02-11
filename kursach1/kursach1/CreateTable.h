#pragma once
#include "PublicData.h";

namespace kursach1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Сводка для CreateTable
	/// </summary>
	public ref class CreateTable : public System::Windows::Forms::Form
	{
	public:
		CreateTable(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CreateTable()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ saveButton;
	public: System::Windows::Forms::ComboBox^ comboBox2;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(52, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(135, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(49, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите название списка:";
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(82, 58);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(75, 23);
			this->saveButton->TabIndex = 2;
			this->saveButton->Text = L"Сохранить";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &CreateTable::saveButton_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(220, 60);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 3;
			this->comboBox2->Visible = false;
			// 
			// CreateTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(237, 93);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"CreateTable";
			this->Text = L"Создание списка";
			this->Load += gcnew System::EventHandler(this, &CreateTable::CreateTable_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CreateTable_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			SqlConnection^ sqlConn = gcnew SqlConnection(PublicData::connString);
			sqlConn->Open();
			String^ createQuery = String::Format("CREATE TABLE {0} (ID int PRIMARY KEY IDENTITY, СНИЛС nchar(40), [Сумма баллов ЕГЭ] int, Город nchar(40), Направление nchar(40))", textBox1->Text);
			SqlCommand^ insertCommand = gcnew SqlCommand(createQuery, sqlConn);
			insertCommand->ExecuteNonQuery();

			String^ namesquery = "SELECT TABLE_NAME FROM information_schema.tables";
			SqlDataAdapter^ adapter = gcnew SqlDataAdapter(namesquery, PublicData::connString);
			DataTable^ tableNames = gcnew DataTable();
			adapter->Fill(tableNames);

			List<String^>^ names = gcnew List<String^>();

			for (int i = 0; i < tableNames->Rows->Count; i++) {
				String^ name = tableNames->Rows[i]->ItemArray[0]->ToString();
				names->Add(name);
			}
			comboBox2->Items->Clear();
			for (int i = 0; i < names->Count; i++) {
				comboBox2->Items->Add(names[i]);
			}
			array<String^>^ temp = gcnew array<String^>(comboBox2->Items->Count);
			comboBox2->Items->CopyTo(temp, 0);
			PublicData::ComboItems = temp;
			PublicData::SelectedItemComboBox = textBox1->Text;

			sqlConn->Close();
			this->Close();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message,
				"Ошибка создания списка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}
