/*
 * signal.h
 *
 *  Created on: 2021Äê3ÔÂ16ÈÕ
 *      Author: lenovo
 */

#ifndef CODE_SIGNAL_H_
#define CODE_SIGNAL_H_
#include    "common.h"


void adc_inits();
void signal_read();
void normalize();
int16 error_calculate();
float* get_signals_norma(float* ptr);
uint16* get_signals(uint16 *ptr);
float get_vertical_value();
uint32 std_deviation();
int16 loss_line();
uint16* get_signals_2(uint16 *ptr);



#endif /* CODE_SIGNAL_H_ */
