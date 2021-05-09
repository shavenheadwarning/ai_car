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
float* ptr_norma=NULL;
uint16* ptr=NULL;
int16 last_avg_error=0;
int16 global_bias=0;
int core0_main(void)
{
	disableInterrupts();
	get_clk();//获取时钟频率  务必保留
	gpio_init(speak, GPO, 0,PUSHPULL);
    //用户在此处调用各种初始化函数等
	//gtm_pwm_init(ATOM0_CH1_P33_9, 50, 1200);
	steering_init();

	adc_inits();
	//lcd_init();

    enableInterrupts();

    while (TRUE)
    {



        pwm_duty(ftm_steering, 5000);
        //systick_delay_ms(STM0,500);
/*
        signal_read();
        ptr=get_signals_2(ptr);
        for(uint16 i=0;i<7;i++){
                   printf("%d ",ptr[i]);
               }
        printf("\n");
        systick_delay_ms(STM0,1000);
        */
        /*
        uint16 d=std_deviation(ptr);
        if(d<50)gpio_set(speak, 1);
        else gpio_set(speak, 0);
        */
        //systick_delay_ms(STM0,1000);



        /*
        int16 b=error_calculate();
        ptr_norma=get_signals_norma(ptr_norma);
        for(int16 j=0;j<5;j++){
                    printf("%.2f\n",ptr_norma[j]);
                }
        printf("\n");

        systick_delay_ms(STM0,1000);
        */
        //pwm_duty(ftm_steering, 1250);

/*
        int16 avg_error=0;

        for(uint16 i=0;i<5;i++){
            int16 b=error_calculate();
            avg_error+=b;//求平均
        }
        avg_error=avg_error/5;
        steering_angle_ctrl(avg_error);//舵机控制
        global_bias=avg_error;
        */
/*
        uint16 d=std_deviation(ptr); //判断是否丢线
        avg_error=avg_error/2;
        if(d<40){
            gpio_set(speak, 1);//丢线，蜂鸣器响
        }
        else{
            gpio_set(speak, 0);
        }
*/








        //printf("last_error:%d\n",last_avg_error);
        /*
        last_avg_error=avg_error;
        printf("%d\n",avg_error);
        for(uint16 i=0;i<5;i++){
            printf("%d ",ptr[i]);
        }
        printf("\nover\n");
        */
        //systick_delay_ms(STM0,1000);


/*
        ptr=get_signals(ptr);
        //uint16 d=std_deviation(ptr);
        uint16 d=170;
        if(ptr[0]<d&&ptr[1]<d&&ptr[2]<d&&ptr[3]<d&&ptr[4]<d)
        {
            gpio_set(speak, 1);
            steering_angle_ctrl(last_avg_error);
        }
        else
        {
            gpio_set(speak, 0);
            steering_angle_ctrl(avg_error);
        }
        */
        //printf("%d\n",avg_error);


        /*
        printf("%d\n",b);


        */
        /*
        ptr_norma=get_signals_norma(ptr_norma);

        for(int16 j=0;j<5;j++){
            printf("%.2f\n ",ptr_norma[j]);
        }*/
        /*
        ptr=get_signals(ptr);
        for(int16 j=0;j<5;j++){
                    printf("%d ",ptr[j]);
                }
        printf("\nover\n");
        systick_delay_ms(STM0,1000);
        */




        //int16 b=error_calculate();
        //oled_uint16(60,3,20);
        //printf("%d\n",steering_angle_ctrl(25));
        //pwm_duty(ATOM0_CH1_P33_9,100);
        //systick_delay_ms(STM0,500);


    }

}

#pragma section all restore
