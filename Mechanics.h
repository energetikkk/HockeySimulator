#pragma once

class Mechanics{
public:
//*HockeyPuck;

void check_border_collision();
void check_stick_hit();
Mechanics();

private:
double barrier_angle;

void calculate_puck_angle(double barrier_angle);
void calculate_stick_angle();



};
