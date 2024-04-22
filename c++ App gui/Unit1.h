//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TBevel *Bevel1;
	TEdit *Edit1;
	TButton *Button1;
	TEdit *Edit2;
	TBevel *Bevel2;
	TTrackBar *TrackBar1;
	TTrackBar *TrackBar2;
	TButton *Button2;
	TLabel *Temp;
	TLabel *Humid;
	TLabel *press;
	TTimer *Timer1;
	TComboBox *ComboBox1;
	TEdit *Edit3;
	TRichEdit *RichEdit1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
private:	// D�clarations utilisateur
	std::string IPServ;
public:		// D�clarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
