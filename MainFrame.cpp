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

void TForm1::render(){
	std::pair<double, double> hockeyPuckCoords = simulator->get_hockey_puck_position();
	HockeyPuckTImage->Left = HOCKEY_PUCK_X_GLOBAL + hockeyPuckCoords.first * PIXEL_METRE_RATIO;
	HockeyPuckTImage->Top = HOCKEY_PUCK_Y_GLOBAL + hockeyPuckCoords.second * PIXEL_METRE_RATIO ;
	HockeyPuckTImage->Invalidate();
	x_coord_label->Caption =  AnsiString::FormatFloat("#,##0.00;;zero", hockeyPuckCoords.first);
	y_coord_label->Caption = AnsiString::FormatFloat("#,##0.00;;zero", hockeyPuckCoords.second);

	std::pair<double, double> hockeyPuckSpeed = simulator->get_hockey_puck_speed();
	speed_v_x_label->Caption =  AnsiString::FormatFloat("#,##0.00;;zero", hockeyPuckSpeed.first);
	speed_v_y_label->Caption =  AnsiString::FormatFloat("#,##0.00;;zero", hockeyPuckSpeed.second);

	double current_time = simulator->get_current_time() * 1000;
	CurrentTimeLabel->Caption = IntToStr(div(current_time/60000, 60).rem) + ":" + div(div(current_time,1000).quot, 60).rem + ":" + div(current_time, 1000).rem;

	render_memo();
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
void __fastcall TForm1::Button3Click(TObject *Sender) {
	int angle_initial = StrToInt(SpinEdit1->Text);
	int normalized_angle = angle_initial % 360;
	int angle = round(normalized_angle / 15.0) * 15;
	Label4->Caption = "Piscture is displayed for " + IntToStr(angle) + "angle";
	String picture_path = "../../resources/hockeySticks/hockeyStick" +
		IntToStr(angle) + ".png";
	Image2->Picture->LoadFromFile(picture_path);
}
//---------------------------------------------------------------------------
void TForm1::flip_flop_tedits(){
	SpeedTEdit->Enabled = !(SpeedTEdit->Enabled);
	AngleTEdit->Enabled = !(AngleTEdit->Enabled);
	FrictionCoeffTEdit->Enabled = !(FrictionCoeffTEdit->Enabled);
	IterationTimeTEdit->Enabled = !(IterationTimeTEdit->Enabled);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartButtonClick(TObject *Sender)
{
	if(!is_running){
		flip_flop_tedits();
		simulator->set_hockey_puck_speed(StrToFloat(SpeedTEdit->Text), StrToFloat(AngleTEdit->Text));
		simulator->set_friction_coeff(StrToFloat(FrictionCoeffTEdit->Text));
		simulator->set_dt(StrToFloat(IterationTimeTEdit->Text)/1000);
		simulator->solver_method = DynSolverMethodRadioGroup->ItemIndex;
		simulator->solver_method = DynSolverMethodRadioGroup->ItemIndex;
		SimulationTimer->Interval = 40;
	}

	SimulationTimer->Enabled = true;
	is_running = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PauseButtonClick(TObject *Sender)
{
	SimulationTimer->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetButtonClick(TObject *Sender)
{
	if(is_running){
		flip_flop_tedits();
		SimulationTimer->Enabled = false;
		is_running = false;
	}

	simulator -> reset_experiment();
	render();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SimulationTimerTimer(TObject *Sender)
{
		simulator->do_one_step();
		if(simulator->is_goal()){
			SimulationTimer->Enabled = false;
			ShowMessage("GOAL!");
            Form1->ResetButtonClick(this);
		} else {
			if(simulator->enough_energy()){
				render();
			} else {
				SimulationTimer->Enabled = false;
				ShowMessage("Hockey puck has no energy");
				Form1->ResetButtonClick(this);
			}
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddStickButtonClick(TObject *Sender)
{
	double delta_t = StrToFloat(StickDeltaTEdit->Text);
	int gate = GateRadioGroup->ItemIndex;
	bool accelerate = AccelerationCheckBox->Checked;
	try{
		simulator->add_stick(delta_t, gate, accelerate);
		render_memo();
	} catch(...){
		Form1->PauseButtonClick(Form1);
		ShowMessage("You can't add stick with the same hit time!");
	}
}
//---------------------------------------------------------------------------

void TForm1::render_memo(){
	vector<vector<UnicodeString>> quee = simulator->get_stick_quee();
	StickListBox->Clear();
	int counter = 0;
	for(auto stick: quee){
        //Display no more than 8 sticks in List otherwise it renders it badly
		if(counter < 8){
			double time = StrToFloat(stick[0])*1000;
			UnicodeString stringified_time = IntToStr(div(time/60000, 60).rem) + ":" + div(div(time,1000).quot, 60).rem + ":" + div(time, 1000).rem;
			UnicodeString gate = StrToInt(stick[1]) == 0 ? "Left" : "Right";
			UnicodeString accelerate = stick[2] == 1 ? "True" : "False";
			StickListBox->Items->Add(stringified_time + " " + gate + " " + accelerate);
			counter++;
		}
    }
}

