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
#include "cspin.h"
#include <Vcl.DockTabSet.hpp>
#include <Vcl.Tabs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TImage *IceRinkTImage;
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
	TImage *HockeyPuckTImage;
	TGroupBox *GroupBox1;
	TPanel *ControlButtonsPanel;
	TButton *StartButton;
	TButton *PauseButton;
	TButton *ResetButton;
	TGroupBox *GroupBox2;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TLabel *current_time_label;
	TLabel *x_coord_label;
	TLabel *y_coord_label;
	TStaticText *StaticText4;
	TLabel *speed_label;
	TListBox *ListBox1;
	TStaticText *StaticText5;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
	TGroupBox *InitialCondGroupBox;
	TGroupBox *GroupBox3;
	TCheckBox *CheckBox1;
	TButton *Button4;
	TRadioGroup *RadioGroup1;
	TStaticText *StaticText10;
	TSpinEdit *SpinEdit2;
	TDockTabSet *DockTabSet1;
	TRadioGroup *DynSolverMethodRadioGroup;
	TEdit *FrictionCoeffTEdit;
	TEdit *IterationTimeTEdit;
	TEdit *AngleTEdit;
	TEdit *SpeedTEdit;
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
	void flip_flop_tedits();
	void render();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
