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

#pragma section all "cpu0_dsram"
extern uint16 signals_long[7];
extern uint16 signals_short[7];
int16 last_steering_pwm=1900;

int8 data_tf_flag=0;

int core0_main(void)
{
	disableInterrupts();
	get_clk();//获取时钟频率  务必保留

    //用户在此处调用各种初始化函数等
	//使用CCU6_0模块的通道0 产生一个 100ms的周期中断
	adclong_inits();
	adcshort_inits();
	//motor_init();
	gpt12_init(GPT12_T2, GPT12_T2INB_P33_7, GPT12_T2EUDB_P33_6);
	lcd_init();
	uart_init(UART_2,115200,uart_tx,uart_rx);
	steering_init();
	//中断函数在isr.c中 函数名称为cc60_pit_ch0_isr
	//中断相关的配置参数在isr_config.h内
	//可配置参数有 CCU6_0_CH0_INT_SERVICE 和 CCU6_0_CH0_ISR_PRIORITY
	//CCU6_0_CH0_INT_SERVICE 中断服务者
	//CCU6_0_CH0_ISR_PRIORITY 中断优先级 优先级范围1-255 越大优先级越高 与平时使用的单片机不一样

	//需要特备注意的是  不可以有优先级相同的中断函数 每个中断的优先级都必须是不一样的
    enableInterrupts();

    while (TRUE)
    {

        //pwm_duty(ftm_steering,2200);


        signal_long_read();
        signal_short_read();


        last_steering_pwm=steering_angle_ctrl(error_calculate());
        data_transfer(last_steering_pwm,data_tf_flag);

        //lcd_showint16(100,0,bias);
        lcd_showint16(60,1,last_steering_pwm);


        while(loss_line_detect()){
            loss_line_dispose(last_steering_pwm);

            for(int16 i=0;i<7;i++){
                lcd_showuint16(5, i, signals_long[i]);
                lcd_showuint16(120,i,signals_short[i]);
                }

        }
        pass_roundabout_dispose(pass_roundabout_detect());
        //enter_roundabout_dispose(enter_roundabout_detect());
        /*
        for(uint8 i=0;i<7;i++){
                            uint8*ptr =data_dev(signals_long [i]);
                            uart_putbuff(UART_2,ptr,4);
                            free(ptr);
                        }
        uart_putchar(UART_2,255);
        */
        /*
        for(int16 i=0;i<7;i++){
            lcd_showuint16(5, i, signals_long[i]);
            lcd_showuint16(120,i,signals_short[i]);
        }
        */



        /*
        for(uint8 i=0;i<7;i++){
                    uint8*ptr =data_dev(signals_short[i]);
                    uart_putbuff(UART_2,ptr,4);
                    free(ptr);
                }
        uint8* ptr_ftm=data_dev(last_steering_pwm);


        uart_putbuff(UART_2,ptr_ftm,4);
        free(ptr_ftm);
        uart_putchar(UART_2,255);
        */










		//程序运行之后 PIT中断每执行一次就会打印一次
        //将结果通过串口打印，可以先学习printf例程，了解如何使用printf
    }
}

#pragma section all restore
