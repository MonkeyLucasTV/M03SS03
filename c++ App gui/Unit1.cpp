//---------------------------------------------------------------------------

#include <vcl.h>
#include "IRClientTCP.h"
#pragma hdrstop
#include <iostream>
#include <string>
#include "LampeMulticolore.h"
#include "Domotique.h"
#include "Unit1.h"
#include "CapteurTemperature.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button1Click(TObject *Sender)
{

	Timer1->Enabled = true;
	


}

//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	CapteurTemperature temp(((AnsiString)Edit1->Text).c_str() ,"F276DD7951", "Temp A7-1");

	Temp->Caption =  "Temperature : " + UnicodeString(temp.Temperature().c_str());
	Humid->Caption = "Humidit� : "+ UnicodeString(temp.Humidite().c_str());
	press->Caption = "Pression : "+ UnicodeString(temp.Pression().c_str());

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	LampeMulticolore Lampe("172.20.21.22","F276DD7951","Extended Lights 3","3");
	Lampe.Teinte(AnsiString(TrackBar1->Position).c_str());

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
	LampeMulticolore Lampe1("172.20.21.22","F276DD7951","Extended Lights 3","3");
	Lampe1.Intensite(AnsiString(TrackBar2->Position).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

	LampeMulticolore Lampe2("172.20.21.22","F276DD7951","Extended Lights 3","3");

	if (Button2->Caption == "0") {
		Lampe2.Allumer("true");
		Button2->Caption = "1";
	}
	else if (Button2->Caption == "1") {
		Lampe2.Allumer("false");
		Button2->Caption = "0";
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	int NmbreL = ComboBox1->ItemIndex;
	if (NmbreL== 0) {
		LampeMulticolore LampeListe("172.20.21.22","F276DD7951","Extended Lights 3","3");
		Edit3->Text = "Extended Lights 3";
	}
	else if (NmbreL == 1) {
		LampeMulticolore LampeListe("172.20.21.22","F276DD7951","Extended Lights 4","4");
    	Edit3->Text = "Extended Lights 4";
	}

}
//---------------------------------------------------------------------------

