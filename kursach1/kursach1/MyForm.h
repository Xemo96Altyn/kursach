#pragma once
#include "Add.h";
#include "DeleteForm.h";
#include "CreateTable.h";

namespace kursach1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Data::SqlClient;
	using namespace System::Collections::Generic;

	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ AddButton;

	protected:



	public: System::Windows::Forms::DataGridView^ dataGridView1;



	private: System::Windows::Forms::Button^ ExitButton;
	private: System::Windows::Forms::Button^ DeleteButton;
	private: System::Windows::Forms::TextBox^ filterbox;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ createTableButton;
	private: System::Windows::Forms::Button^ deleteTableButton;








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
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->filterbox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->createTableButton = (gcnew System::Windows::Forms::Button());
			this->deleteTableButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(185, 220);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(165, 33);
			this->AddButton->TabIndex = 1;
			this->AddButton->Text = L"Добавить запись";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &MyForm::AddButton_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(185, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(544, 202);
			this->dataGridView1->TabIndex = 2;
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(12, 220);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(135, 80);
			this->ExitButton->TabIndex = 3;
			this->ExitButton->Text = L"Выход!!!";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &MyForm::ExitButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(356, 220);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(165, 33);
			this->DeleteButton->TabIndex = 4;
			this->DeleteButton->Text = L"Удалить запись";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &MyForm::DeleteButton_Click);
			// 
			// filterbox
			// 
			this->filterbox->Location = System::Drawing::Point(737, 167);
			this->filterbox->Name = L"filterbox";
			this->filterbox->Size = System::Drawing::Size(139, 20);
			this->filterbox->TabIndex = 5;
			this->filterbox->TextChanged += gcnew System::EventHandler(this, &MyForm::filterbox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(734, 151);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Фильтр по направлениям:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(737, 196);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(180, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Вывод иногородних студентов";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->comboBox1->Location = System::Drawing::Point(737, 30);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(139, 21);
			this->comboBox1->TabIndex = 8;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(735, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Отображаемый список:";
			// 
			// createTableButton
			// 
			this->createTableButton->Location = System::Drawing::Point(12, 13);
			this->createTableButton->Name = L"createTableButton";
			this->createTableButton->Size = System::Drawing::Size(135, 80);
			this->createTableButton->TabIndex = 10;
			this->createTableButton->Text = L"Создать новый список";
			this->createTableButton->UseVisualStyleBackColor = true;
			this->createTableButton->Click += gcnew System::EventHandler(this, &MyForm::createTableButton_Click);
			// 
			// deleteTableButton
			// 
			this->deleteTableButton->Location = System::Drawing::Point(737, 57);
			this->deleteTableButton->Name = L"deleteTableButton";
			this->deleteTableButton->Size = System::Drawing::Size(139, 30);
			this->deleteTableButton->TabIndex = 11;
			this->deleteTableButton->Text = L"Удалить список";
			this->deleteTableButton->UseVisualStyleBackColor = true;
			this->deleteTableButton->Click += gcnew System::EventHandler(this, &MyForm::deleteTableButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 313);
			this->Controls->Add(this->deleteTableButton);
			this->Controls->Add(this->createTableButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->filterbox);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->AddButton);
			this->Name = L"MyForm";
			this->Text = L"Курсовая";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endIDion
	public:
		DataTable^ table;
		SqlDataAdapter^ adapter;
		SqlCommandBuilder^ command = gcnew SqlCommandBuilder(adapter);

	private: void UpdateComboBox() {
		comboBox1->Items->Clear();
		List<String^>^ names = gcnew List<String^>();

		String^ namesquery = "SELECT TABLE_NAME FROM information_schema.tables";
		SqlDataAdapter^ adapter = gcnew SqlDataAdapter(namesquery, PublicData::connString);
		DataTable^ tableNames = gcnew DataTable();
		adapter->Fill(tableNames);

		for (int i = 0; i < tableNames->Rows->Count; i++) {
			String^ name = tableNames->Rows[i]->ItemArray[0]->ToString();
			names->Add(name);
		}
		for (int i = 0; i < names->Count; i++) {
			comboBox1->Items->Add(names[i]);
		}
		comboBox1->SelectedItem = "Абитуриенты";
	}



	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			SqlConnection^ sqlConn = gcnew SqlConnection(PublicData::connString);
			adapter = gcnew SqlDataAdapter("SELECT * FROM Абитуриенты", sqlConn);
			table = gcnew DataTable();
			sqlConn->Open();
			adapter->Fill(table);

			UpdateComboBox();
			dataGridView1->DataSource = table;
			dataGridView1->Refresh();
			sqlConn->Close();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message,
				"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void TableButton_Click(System::Object^ sender, System::EventArgs^ e) {
		SqlConnection^ sqlConn = gcnew SqlConnection(PublicData::connString);
		sqlConn->Open();
		adapter = gcnew SqlDataAdapter("SELECT * FROM Абитуриенты", sqlConn);
		table = gcnew DataTable();
		adapter->Fill(table);
		dataGridView1->DataSource = table;
		dataGridView1->Refresh();
		sqlConn->Close();
	}


	private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Add^ addform = gcnew Add();
		addform->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::Add_Closed);
		addform->Show();
	}

	private: System::Void Add_Closed(System::Object^ sender, FormClosedEventArgs^ e) {
		SqlConnection^ sqlConn = gcnew SqlConnection(PublicData::connString);
		sqlConn->Open();
		String^ query = String::Format("SELECT * FROM {0}", comboBox1->Text);
		adapter = gcnew SqlDataAdapter(query, sqlConn);
		table = gcnew DataTable();
		adapter->Fill(table);
		dataGridView1->DataSource = table;
		dataGridView1->Refresh();
		sqlConn->Close();
	}

	private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteForm^ deleteform = gcnew DeleteForm();
		deleteform->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::DeleteForm_Closed);
		deleteform->Show();
	}

	private: System::Void DeleteForm_Closed(System::Object^ sender, FormClosedEventArgs^ e) {
		SqlConnection^ sqlConn = gcnew SqlConnection(PublicData::connString);
		sqlConn->Open();
		String^ query = String::Format("SELECT * FROM {0}", comboBox1->Text);
		adapter = gcnew SqlDataAdapter(query, sqlConn);
		table = gcnew DataTable();
		adapter->Fill(table);
		dataGridView1->DataSource = table;
		dataGridView1->Refresh();
		sqlConn->Close();
	}

	private: System::Void createTableButton_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateTable^ createtable = gcnew CreateTable();
		createtable->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::CreateTable_Closed);
		createtable->Show();
	}

	private: System::Void CreateTable_Closed(System::Object^ sender, FormClosedEventArgs^ e) {
		try {
			comboBox1->Items->Clear();
			comboBox1->Items->AddRange(PublicData::ComboItems);
			comboBox1->SelectedItem = PublicData::SelectedItemComboBox;
		}
		catch (Exception^ e) {
			UpdateComboBox();
		}
	}

	private: System::Void filterbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		String^ filter = "";
		DataView^ filteredView = table->DefaultView;
		if (checkBox1->Checked) {
			if (filter != "") {
				filter += " AND ";
			}
			filter += "Город NOT LIKE 'Зеленоград'";
		}

		if (filterbox->Text != "") {
			if (filter != "") {
				filter += " AND ";
			}
			filter += String::Format("Направление LIKE '%{0}%'", filterbox->Text);
		}
		filteredView->RowFilter = filter;
	}

	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		String^ filter = "";
		DataView^ filteredView = table->DefaultView;
		if (checkBox1->Checked) {
			if (filter != "") {
				filter += " AND ";
			}
			filter += "Город NOT LIKE 'Зеленоград'";
		}

		if (filterbox->Text != "") {
			if (filter != "") {
				filter += " AND ";
			}
			filter += String::Format("Направление LIKE '%{0}%'", filterbox->Text);
		}
		filteredView->RowFilter = filter;
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		SqlConnection^ sqlConn = gcnew SqlConnection(PublicData::connString);
		sqlConn->Open();

		PublicData::SelectedItemComboBox = comboBox1->Text;
		String^ gettable = String::Format("SELECT * FROM {0}", comboBox1->Text);
		adapter = gcnew SqlDataAdapter(gettable, sqlConn);
		table = gcnew DataTable();
		adapter->Fill(table);
		dataGridView1->DataSource = table;
		dataGridView1->Refresh();

		sqlConn->Close();
	}

	private: System::Void deleteTableButton_Click(System::Object^ sender, System::EventArgs^ e) {
		SqlConnection^ sqlConn = gcnew SqlConnection(PublicData::connString);
		sqlConn->Open();

		String^ deletetable = String::Format("DROP TABLE {0}", comboBox1->Text);
		if ((MessageBox::Show(
			"Вы точно хотите удалить список?",
			"Удаление списка", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)) {
			SqlCommand^ deleteCommand = gcnew SqlCommand(deletetable, sqlConn);
			deleteCommand->ExecuteNonQuery();
		}
		UpdateComboBox();
		sqlConn->Close();
	}
};

}
