/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
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
    //用户在此处调用各种初始化函数等

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







		//用户在此处编写任务代码
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
