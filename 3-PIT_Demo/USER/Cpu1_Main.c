/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		ADS v1.2.2
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 ********************************************************************************************************************/

#include "headfile.h"
#pragma section all "cpu1_dsram"

volatile extern uint16 signals_long[7];
int16 pwm_pos_init=5000;
int16 pwm_neg_init=1700;
float pwm_pos=0;
int16 pwm_neg=0;
const int16 neg_max=2500;
const int16 pos_max=9000;

void core1_main(void)
{
	disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    motor_init();
    //gpt12_init(GPT12_T2, GPT12_T2INB_P33_7, GPT12_T2EUDB_P33_6);
    //lcd_init();
    //uart_init(UART_2,115200,uart_tx,uart_rx);
    //lcd_init();
    //�û��ڴ˴����ø��ֳ�ʼ��������

    enableInterrupts();
    while (TRUE)
    {

        pwm_duty(pwm_1_pos,4500);
        pwm_duty(pwm_1_neg,0);



        uint16 max_signals_6=0;
        for(uint16 i=0;i<7;i++){
            if(i==3)continue;
            else{
                if(max_signals_6<signals_long[i])max_signals_6=signals_long[i];
             }
     }


     pwm_pos=(float)pwm_pos_init+(float)(signals_long[3])*2.7;
     pwm_neg=pwm_neg_init+max_signals_6*2;
     if(pwm_neg>neg_max)pwm_neg=neg_max;
     if(pwm_pos>pos_max)pwm_pos=pos_max;

     _Bool flag3=((signals_long[3]>900||signals_long[0]>900)&&signals_long[2]>1150&&signals_long[1]<700)||signals_long[6]>800;
     while(flag3){
         pwm_duty(pwm_1_pos, 3500);
         pwm_duty(pwm_1_neg,0);
     }

     pwm_duty(pwm_1_pos, (uint16)pwm_pos);
     pwm_duty(pwm_1_neg,pwm_neg);

     //systick_delay_ms(STM0,10);

        //pwm_duty(pwm_1_pos, 5000);
        //pid_incre_controller(3000);
     //_Bool upslope_flag=signals_long[3]<800&&signals_long[1]&&signals_long[5];
     /*
     while(upslope_flag){
         pwm_duty(pwm_1_pos,7000);
         pwm_duty(pwm_1_neg,0);
     }*/







		//�û��ڴ˴���д�������
        /*
        pwm_duty(pwm_1_pos, 5000);
        int16 speed = gpt12_get(GPT12_T2);
        gpt12_clear(GPT12_T2);
        uint8*ptr=data_dev(speed);
        uart_putbuff(UART_2,ptr,4);
        lcd_showint16(120, 7, speed);
        //lcd_showint16(120, 6, speed);
    	  */

    }
}





#pragma section all restore
