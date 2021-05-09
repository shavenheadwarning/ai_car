#ifndef _steering_ctrl_h
#define _steering_ctrl_h



#include "common.h"



void steering_init();
int16 steering_angle_ctrl(int16 bias);
void right_angle_dispose();
void loss_line_dispose(int16 last_steering_pwm);
void pass_roundabout_dispose(int16 flag);
void enter_roundabout_dispose(int16 flag);
void change_kp(float v);
//void lossline_dispose(int16 bias);

#endif
