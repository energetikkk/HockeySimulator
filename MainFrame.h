//---------------------------------------------------------------------------

#ifndef MainFrameH
#define MainFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.ButtonGroup.hpp>
#include "Simulator.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TImage *ControlButtons;
	TLabel *Label1;
	TButton *Button2;
	TEdit *Edit1;
	TEdit *Edit2;
	TImage *Image2;
	TLabel *Label2;
	TButton *Button3;
	TSpinEdit *SpinEdit1;
	TLabel *Label3;
	TLabel *Label4;
	TImage *Image3;
	TGroupBox *GroupBox1;
	TPanel *ControlButtonsPanel;
	TButton *StartButton;
	TButton *PauseButton;
	TButton *ResetButton;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall stop_buttonClick(TObject *Sender);
	void __fastcall reset_buttonClick(TObject *Sender);
	void __fastcall StartButtonClick(TObject *Sender);
	void __fastcall PauseButtonClick(TObject *Sender);
	void __fastcall ResetButtonClick(TObject *Sender);
private:	// User declarations
	Simulator *simulator;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
