#ifndef _steering_ctrl_h
#define _steering_ctrl_h



#include "common.h"



void steering_init();
void steering_angle_ctrl(int16 bias);
void change_kp(float v);
void lossline_dispose(int16 bias);

#endif
