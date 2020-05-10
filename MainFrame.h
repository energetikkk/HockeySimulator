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
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *IceRinkTImage;
	TImage *Image2;
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
	TLabel *CurrentTimeLabel;
	TLabel *x_coord_label;
	TLabel *y_coord_label;
	TStaticText *StaticText4;
	TLabel *speed_v_x_label;
	TListBox *StickListBox;
	TStaticText *StaticText5;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
	TGroupBox *InitialCondGroupBox;
	TGroupBox *GroupBox3;
	TCheckBox *AccelerationCheckBox;
	TButton *AddStickButton;
	TRadioGroup *GateRadioGroup;
	TStaticText *StaticText10;
	TSpinEdit *StickDeltaTEdit;
	TDockTabSet *DockTabSet1;
	TRadioGroup *DynSolverMethodRadioGroup;
	TEdit *FrictionCoeffTEdit;
	TEdit *IterationTimeTEdit;
	TEdit *AngleTEdit;
	TEdit *SpeedTEdit;
	TTimer *SimulationTimer;
	TStaticText *StaticText11;
	TLabel *speed_v_y_label;
	TLabel *Label5;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall StartButtonClick(TObject *Sender);
	void __fastcall PauseButtonClick(TObject *Sender);
	void __fastcall ResetButtonClick(TObject *Sender);
	void __fastcall SimulationTimerTimer(TObject *Sender);
	void __fastcall AddStickButtonClick(TObject *Sender);
private:	// User declarations
    bool is_running;
	Simulator *simulator;
	void flip_flop_tedits();
	void render();
    void render_memo();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
