/*
 * pin_distribution.h
 *
 *  Created on: 2021年3月14日
 *      Author: wby
 */

#ifndef CODE_PIN_DISTRIBUTION_H_
#define CODE_PIN_DISTRIBUTION_H_


#include "common.h"
#include "zf_uart.h"
#include "zf_vadc.h"
#include "zf_gpt12.h"

#define ftm_steering  ATOM2_CH0_P33_10  //舵机
//#define ftm_steering  ATOM0_CH2_P33_11
#define uart_rx  UART2_RX_P10_6  //串口通信
#define uart_tx  UART2_TX_P10_5



#define opa1_1 ADC2_CH7_A39   //长前瞻引脚定义
#define opa1_2 ADC2_CH5_A37
#define opa1_3 ADC2_CH6_A38
#define opa1_4 ADC2_CH3_A35
#define opa1_5 ADC2_CH4_A36
#define opa1_6 ADC1_CH8_A24
#define opa1_7 ADC1_CH9_A25


#define opa2_1 ADC0_CH5_A5    //短前瞻引脚定义
#define opa2_2 ADC0_CH6_A6
#define opa2_3 ADC0_CH4_A4
#define opa2_4 ADC0_CH3_A3
#define opa2_5 ADC0_CH1_A1
#define opa2_6 ADC0_CH2_A2
#define opa2_7 ADC0_CH0_A0


//oled的引脚宏定义在逐飞的库中已定义好

#define pwm_1_pos  ATOM1_CH1_P21_3//电机引脚
#define pwm_1_neg  ATOM1_CH0_P21_2
#define pwm_en     ATOM0_CH4_P21_6

//编码器
#define mini_1_a   GPT12_T2INB_P33_7
#define mini_1_b   GPT12_T2EUDB_P33_6

//蜂鸣器
#define speak  P02_6


//I2C接口
#define i2c_scl   P02_5
#define i2c_sda   P02_4




#endif /* CODE_PIN_DISTRIBUTION_H_ */
