// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrame.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"

TForm1 *Form1;

const int PIXEL_METRE_RATIO = 10;
// Top left corner coordinates
const int ICE_RINK_X_COORD = 20;
const int ICE_RINK_Y_COORD = 200;
const int ICE_RINK_LENGTH = 630;
const int ICE_RINK_WIDTH = 280;
// Connected with picture alignment
const int HOCKEY_PUCK_X_ALIGNMEN = -10;
const int HOCKEY_PUCK_Y_ALIGNMEN = -10;
// Global coord for top left hockey puck picture relatively to ice rink
const int HOCKEY_PUCK_X_GLOBAL = ICE_RINK_X_COORD + HOCKEY_PUCK_X_ALIGNMEN;
const int HOCKEY_PUCK_Y_GLOBAL = ICE_RINK_Y_COORD + HOCKEY_PUCK_Y_ALIGNMEN;

void render(){
	std::pair<double, double> hockeyPuckCoords = simulator->get_hockey_puck_position();
	HockeyPuckTImage->Left = HOCKEY_PUCK_X_GLOBAL + hockeyPuckCoords.first * PIXEL_METRE_RATIO;
	HockeyPuckTImage->Top = HOCKEY_PUCK_Y_GLOBAL + hockeyPuckCoords.second * PIXEL_METRE_RATIO ;
	HockeyPuckTImage->Invalidate();
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	simulator = new Simulator(ICE_RINK_LENGTH / PIXEL_METRE_RATIO, ICE_RINK_WIDTH / PIXEL_METRE_RATIO);
	IceRinkTImage->Top = ICE_RINK_Y_COORD;
	IceRinkTImage->Left = ICE_RINK_X_COORD;
	IceRinkTImage->Width = ICE_RINK_LENGTH;
	IceRinkTImage->Height = ICE_RINK_WIDTH;
	IceRinkTImage->Invalidate();
	render();
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
  // To be implemented
}
//---------------------------------------------------------------------------

void TForm1::flip_flop_tedits(){
	SpeedTEdit->Enabled = !(SpeedTEdit->Enabled);
	AngleTEdit->Enabled = !(AngleTEdit->Enabled);
	FrictionCoeffTEdit->Enabled = !(FrictionCoeffTEdit->Enabled);
	IterationTimeTEdit->Enabled = !(IterationTimeTEdit->Enabled);
}

void __fastcall TForm1::reset_buttonClick(TObject *Sender)
{
	if(simulator->is_running){
		flip_flop_tedits();
	}
	simulator -> reset_experiment();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StartButtonClick(TObject *Sender)
{
	if(!(simulator->is_running)){
		flip_flop_tedits();
		simulator->set_hockey_puck_speed(StrToFloat(SpeedTEdit->Text), StrToFloat(AngleTEdit->Text));
		simulator->set_friction_coeff(StrToFloat(FrictionCoeffTEdit->Text));
		simulator->dt = StrToInt(IterationTimeTEdit->Text);
		simulator->solver = DynSolverMethodRadioGroup->ItemIndex;
	}
	simulator->is_running = true;
	for (i = 0; i < 10; i++) {
		simulator->integration_step();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PauseButtonClick(TObject *Sender)
{
	// To be implemented
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetButtonClick(TObject *Sender)
{
	simulator -> reset_experiment();
}
//---------------------------------------------------------------------------


