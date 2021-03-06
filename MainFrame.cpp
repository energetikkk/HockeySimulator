// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrame.h"
#include <stdlib.h>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"

TForm1 *Form1;

const double INIT_FRICTION = 0.1;
const double INIT_PIXEL_METRE_RATIO = 10;
double PIXEL_METRE_RATIO = INIT_PIXEL_METRE_RATIO;
// Form stating size
const double INIT_FORM_WIDTH = 1200;
const double INIT_FORM_HEIGHT = 600;
double LAST_FORM_WIDTH = 1200;
double LAST_FORM_HEIGHT = 600;
const int FORM_SIZE_RATIO = 2;
double SCALE = 1.0;
// Top left corner coordinates
double ICE_RINK_X_COORD = 20;
double ICE_RINK_Y_COORD = 220;
const int ICE_RINK_WIDTH_METERS = 63;
const int ICE_RINK_HEIGHT_METERS = 28;
double ICE_RINK_WIDTH = 630;
double ICE_RINK_HEIGHT = 280;
// Connected with pictures alignment
const int HOCKEY_PUCK_X_ALIGNMEN = -10;
const int HOCKEY_PUCK_Y_ALIGNMEN = -10;
const int HOCKEY_STICK_X_ALIGNMEN = -70;
const int HOCKEY_STICK_Y_ALIGNMEN = -70;
// Global coord for top left hockey puck picture relatively to ice rink
const int HOCKEY_PUCK_X_GLOBAL = ICE_RINK_X_COORD + HOCKEY_PUCK_X_ALIGNMEN;
const int HOCKEY_PUCK_Y_GLOBAL = ICE_RINK_Y_COORD + HOCKEY_PUCK_Y_ALIGNMEN;
// Settings
const int STICK_SHOW_TIME = 2; // How long display stick after hit in sec

void TForm1::render(){

	IceRinkTImage->Top = ICE_RINK_Y_COORD;
	IceRinkTImage->Left = ICE_RINK_X_COORD;
	IceRinkTImage->Width = ICE_RINK_WIDTH * SCALE;
	IceRinkTImage->Height = ICE_RINK_HEIGHT * SCALE;

	std::pair<double, double> hockeyPuckCoords = simulator->get_hockey_puck_position();
	double hockey_puck_x = HOCKEY_PUCK_X_GLOBAL + hockeyPuckCoords.first * PIXEL_METRE_RATIO;
	double hockey_puck_y = HOCKEY_PUCK_Y_GLOBAL + hockeyPuckCoords.second * PIXEL_METRE_RATIO;
	HockeyPuckTImage->Left = hockey_puck_x;
	HockeyPuckTImage->Top =  hockey_puck_y;
	HockeyPuckTImage->Invalidate();
	x_coord_label->Caption =  AnsiString::FormatFloat("#,##0.00;;zero", hockeyPuckCoords.first);
	y_coord_label->Caption = AnsiString::FormatFloat("#,##0.00;;zero", hockeyPuckCoords.second);

	std::pair<double, double> hockeyPuckSpeed = simulator->get_hockey_puck_speed();
	speed_v_x_label->Caption =  AnsiString::FormatFloat("#,##0.00;;zero", hockeyPuckSpeed.first);
	speed_v_y_label->Caption =  AnsiString::FormatFloat("#,##0.00;;zero", hockeyPuckSpeed.second);

	double current_time = simulator->get_current_time() * 1000;
	CurrentTimeLabel->Caption = IntToStr(div(current_time/60000, 60).rem) + ":" + div(div(current_time,1000).quot, 60).rem + ":" + div(current_time, 1000).rem;

	if(simulator->is_stick_hit){
		int normalized_angle = abs((int)simulator->stick_hit_angle % 360);
		int angle = round(normalized_angle / 15.0) * 15;
		String picture_path = "./resources/hockeySticks/hockeyStick" + IntToStr(angle) + ".png";
		StickImage->Picture->LoadFromFile(picture_path);
		StickImage->Left = hockey_puck_x + HOCKEY_STICK_X_ALIGNMEN;
		StickImage->Top =  hockey_puck_y + HOCKEY_STICK_X_ALIGNMEN;
		StickImage->Visible = true;

		last_hit_time = simulator->get_current_time();
	}

	if(last_hit_time + STICK_SHOW_TIME < simulator->get_current_time()){
	   StickImage->Visible = false;
	}

	render_canvas();
	render_memo();

}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	try{
		simulator = new Simulator(63, 28);
	} catch (...) {
		ShowMessage("Bad initialization!");
        exit(EXIT_FAILURE);
	}

	Form1->ClientWidth = INIT_FORM_WIDTH;
	Form1->ClientHeight = INIT_FORM_HEIGHT;

	FrictionCoeffTEdit->Text = FloatToStr(INIT_FRICTION);
	render();
 }
// ---------------------------------------------------------------------------
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
        StickImage->Visible = false;
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
	if (delta_t < 0) {
        Form1->PauseButtonClick(Form1);
		ShowMessage("You can't set negative time!");
	} else {
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

void TForm1::render_canvas(){
	// Render gates
	Form1->Canvas->MoveTo(ICE_RINK_X_COORD + 40*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 - 20)*SCALE);
	Form1->Canvas->LineTo(ICE_RINK_X_COORD + 40*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 + 20)*SCALE);
	Form1->Canvas->MoveTo(ICE_RINK_X_COORD + 60*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 - 20)*SCALE);
	Form1->Canvas->LineTo(ICE_RINK_X_COORD + 60*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 + 20)*SCALE);

	Form1->Canvas->MoveTo(ICE_RINK_X_COORD + 40*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 - 20)*SCALE);
	Form1->Canvas->LineTo(ICE_RINK_X_COORD + 60*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 - 20)*SCALE);
	Form1->Canvas->MoveTo(ICE_RINK_X_COORD + 40*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 + 20)*SCALE);
	Form1->Canvas->LineTo(ICE_RINK_X_COORD + 60*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 + 20)*SCALE);

	Form1->Canvas->MoveTo(ICE_RINK_X_COORD + (ICE_RINK_WIDTH - 40)*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 - 20)*SCALE);
	Form1->Canvas->LineTo(ICE_RINK_X_COORD + (ICE_RINK_WIDTH - 40)*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 + 20)*SCALE);
	Form1->Canvas->MoveTo(ICE_RINK_X_COORD + (ICE_RINK_WIDTH - 60)*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 - 20)*SCALE);
	Form1->Canvas->LineTo(ICE_RINK_X_COORD + (ICE_RINK_WIDTH - 60)*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 + 20)*SCALE);

	Form1->Canvas->MoveTo(ICE_RINK_X_COORD + (ICE_RINK_WIDTH - 40)*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 - 20)*SCALE);
	Form1->Canvas->LineTo(ICE_RINK_X_COORD + (ICE_RINK_WIDTH - 60)*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 - 20)*SCALE);
	Form1->Canvas->MoveTo(ICE_RINK_X_COORD + (ICE_RINK_WIDTH - 40)*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 + 20)*SCALE);
	Form1->Canvas->LineTo(ICE_RINK_X_COORD + (ICE_RINK_WIDTH - 60)*SCALE, ICE_RINK_Y_COORD + (ICE_RINK_HEIGHT/2 + 20)*SCALE);

}


void __fastcall TForm1::FormResize(TObject *Sender)
{
	int delta_width = Form1->ClientWidth - LAST_FORM_WIDTH;
	int delta_height = Form1->ClientHeight - LAST_FORM_HEIGHT;
	if (abs(delta_width) > abs(delta_height * FORM_SIZE_RATIO)){
		Form1->ClientHeight = Form1->ClientWidth / FORM_SIZE_RATIO;
	} else {
		Form1->ClientWidth = Form1->ClientHeight * FORM_SIZE_RATIO;
	}
	LAST_FORM_WIDTH = Form1->ClientWidth;
	LAST_FORM_HEIGHT = Form1->ClientHeight;
	SCALE = Form1->ClientWidth / INIT_FORM_WIDTH;
	PIXEL_METRE_RATIO = SCALE * INIT_PIXEL_METRE_RATIO;
    Form1->Invalidate();
	render();

}
//---------------------------------------------------------------------------

