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
	/// Сводка для MyForm1
	/// </summary>
	public ref class DeleteForm : public System::Windows::Forms::Form
	{
	public:
		DeleteForm(void)
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
		~DeleteForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ IDDeleteBox;

	private: System::Windows::Forms::Button^ DeleteButton1;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->IDDeleteBox = (gcnew System::Windows::Forms::TextBox());
			this->DeleteButton1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(42, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID абитуриента для удаления:";
			// 
			// IDDeleteBox
			// 
			this->IDDeleteBox->Location = System::Drawing::Point(67, 34);
			this->IDDeleteBox->Name = L"IDDeleteBox";
			this->IDDeleteBox->Size = System::Drawing::Size(106, 20);
			this->IDDeleteBox->TabIndex = 1;
			// 
			// DeleteButton1
			// 
			this->DeleteButton1->Location = System::Drawing::Point(67, 58);
			this->DeleteButton1->Name = L"DeleteButton1";
			this->DeleteButton1->Size = System::Drawing::Size(106, 23);
			this->DeleteButton1->TabIndex = 2;
			this->DeleteButton1->Text = L"Удалить";
			this->DeleteButton1->UseVisualStyleBackColor = true;
			this->DeleteButton1->Click += gcnew System::EventHandler(this, &DeleteForm::DeleteButton1_Click);
			// 
			// DeleteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(237, 93);
			this->Controls->Add(this->DeleteButton1);
			this->Controls->Add(this->IDDeleteBox);
			this->Controls->Add(this->label1);
			this->Name = L"DeleteForm";
			this->Text = L"Удаление записи";
			this->Load += gcnew System::EventHandler(this, &DeleteForm::DeleteForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void DeleteForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void DeleteButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			SqlConnection^ sqlConn = gcnew SqlConnection(PublicData::connString);
			sqlConn->Open();

			String^ deleteQuery = String::Format("DELETE FROM {0} WHERE ID = {1}", PublicData::SelectedItemComboBox, IDDeleteBox->Text);
			if ((MessageBox::Show(
				"Вы точно хотите удалить запись?",
				"Удаление записи", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)) {

				SqlCommand^ deleteCommand = gcnew SqlCommand(deleteQuery, sqlConn);
				deleteCommand->ExecuteNonQuery();

				sqlConn->Close();
				this->Close();
			}
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message,
				"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}
