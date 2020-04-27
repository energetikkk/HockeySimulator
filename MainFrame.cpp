// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrame.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	simulator = new Simulator();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	ShowMessage("You have done this!");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	int val = StrToInt(Edit1->Text);
	Edit2->Text = Edit1->Text;
	int newval = val + 2;
	Label1->Caption = newval;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	int angle_initial = StrToInt(SpinEdit1->Text);
	int normalized_angle = angle_initial % 360;
	int angle = round(normalized_angle / 15.0) * 15;
	Label4->Caption = "Piscture is displayed for " + IntToStr(angle) + "angle";
	String picture_path = "../../resources/hockeySticks/hockeyStick" +
		IntToStr(angle) + ".png";
	Image2->Picture->LoadFromFile(picture_path);
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::stop_buttonClick(TObject *Sender)
{
  simulator -> pause_experiment();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::reset_buttonClick(TObject *Sender)
{
	simulator -> reset_experiment();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StartButtonClick(TObject *Sender)
{
	simulator -> start_experiment();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PauseButtonClick(TObject *Sender)
{
	simulator -> pause_experiment();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetButtonClick(TObject *Sender)
{
	simulator -> reset_experiment();
}
//---------------------------------------------------------------------------

