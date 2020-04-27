#pragma once

class Mechanics{
public:

//должна быть ссылка на инициализированную шайбу *HockeyPuck;

virtual void check_border_collision()=0;
virtual void check_stick_hit()=0;

private:
double barrier_angle;

void calculate_puck_angle(double barrier_angle);
void calculate_stick_angle();



};
