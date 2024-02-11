#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;

ref class PublicData {

	public: static String^ connString = "Data Source=ALIBABA;Initial Catalog=kursach;Integrated Security=True;Encrypt=False";
	public: static array<String^>^ ComboItems;
	public: static String^ SelectedItemComboBox;
	public: static DataGridView^ PublicDataGridView;
};

