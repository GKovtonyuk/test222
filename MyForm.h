#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"DrawLine", L"DrawRectangle", L"FiilRectangle",
					L"DrawEllipse", L"FillEllipse", L"DrawPie", L"FillPie", L"Star"
			});
			this->listBox1->Location = System::Drawing::Point(152, 314);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(313, 164);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 513);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graf = CreateGraphics();
		Pen^ pn = gcnew System::Drawing::Pen(Color::Blue,3);
		Brush^ br = gcnew System::Drawing::SolidBrush(Color::DarkRed);
		graf->Clear(SystemColors::Control);
		array<Point>^ st;
		st = gcnew array<Point>(11);
		st[0].X = 150; st[0].Y = 60;
		st[1].X = 120; st[1].Y = 130;
		st[2].X = 50; st[2].Y = 140;
		st[3].X = 110; st[3].Y = 190;
		st[4].X = 110; st[4].Y = 260;
		st[5].X = 170; st[5].Y = 220;
		st[6].X = 240; st[6].Y = 250;
		st[7].X = 220; st[7].Y = 180;
		st[8].X = 260; st[8].Y = 130;
		st[9].X = 190; st[9].Y = 120;
		st[10].X = 150; st[10].Y = 60;
		switch (listBox1->SelectedIndex)
		{
		case 0:graf->DrawLine(pn, 150, 40, 380, 190); break;
		case 1:graf->DrawRectangle(pn,150,30,250,150 ); break;
		case 2:graf->FillRectangle(br, 150, 30, 250, 150); break;
		case 3:graf->DrawEllipse(pn, 150, 30, 250, 150); break;
		case 4:graf->FillEllipse(br, 150, 30, 250, 150); break;
		case 5:graf->DrawPie(pn, 150, 30, 200, 200,180,120); break;
		case 6:graf->FillPie(br, 150, 30, 200, 200, 180, 120); break;
		case 7: graf->FillPolygon(br, st);
		}
	}
	};
}
