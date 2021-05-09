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

#define ftm_steering  ATOM3_CH0_P33_10  //舵机
//#define ftm_steering  ATOM0_CH2_P33_11
#define uart_rx  UART0_RX_P14_1  //串口通信
#define uart_tx  URAT0_TX_P14_0


#define opa1  ADC0_CH0_A0   //运放板接口
#define opa2  ADC0_CH1_A1
#define opa3  ADC0_CH2_A2
#define opa4  ADC0_CH3_A3
#define opa5  ADC0_CH4_A4

#define opa8  ADC1_CH8_A24   //运放板接口
#define opa9  ADC1_CH9_A25
#define opa10 ADC2_CH3_A35
#define opa11 ADC2_CH4_A36
#define opa12  ADC2_CH5_A37
#define opa13  ADC2_CH6_A38
#define opa14  ADC2_CH7_A39



//oled的引脚宏定义在逐飞的库中已定义好

#define pwm_1_pos  ATOM1_CH0_P21_2//电机引脚
#define pwm_1_neg  ATOM1_CH1_P21_3
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
