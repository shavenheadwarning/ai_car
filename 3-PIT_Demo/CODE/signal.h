/*
 * signal.h
 *
 *  Created on: 2021Äê3ÔÂ16ÈÕ
 *      Author: lenovo
 */

#ifndef CODE_SIGNAL_H_
#define CODE_SIGNAL_H_
#include    "common.h"


void adclong_inits();
void adcshort_inits();
void signal_long_read();
void signal_short_read();
void signal_short_convert();

void normalize();


int16 error_calculate();
int16 error_calculate_roundabout();
_Bool right_angle_detect();
_Bool loss_line_detect();
int16 pass_roundabout_detect();
_Bool upslope_detect();
int16 enter_roundabout_detect();


/*
float* get_signals_norma(float* ptr);
uint16* get_signals(uint16 *ptr);
float get_vertical_value();
uint32 std_deviation();
int16 loss_line();
uint16* get_signals_2(uint16 *ptr);
*/



#endif /* CODE_SIGNAL_H_ */
