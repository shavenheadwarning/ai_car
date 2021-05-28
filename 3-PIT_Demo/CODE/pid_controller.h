/*
 * pid_controller.h
 *
 *  Created on: 2021Äê3ÔÂ14ÈÕ
 *      Author: wby
 */

#ifndef CODE_PID_CONTROLLER_H_
#define CODE_PID_CONTROLLER_H_

#include "common.h"



int16 pid_incre_controller(int16 set_speed);
//int16 pid_pos_controller(uint16 servo_increment);
void motor_init();
void motor_stop();
void motor_stop2();


#endif /* CODE_PID_CONTROLLER_H_ */
