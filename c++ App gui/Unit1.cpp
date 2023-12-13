//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
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

