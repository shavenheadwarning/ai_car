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

extern int16 global_bias;


void core1_main(void)
{
	disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    gtm_pwm_init(pwm_1_pos, 13000, 0);
        gtm_pwm_init(pwm_1_neg, 13000, 0);
    //用户在此处调用各种初始化函数等

    enableInterrupts();
    while (TRUE)
    {
        pwm_duty(pwm_1_pos,3000);
        //pid_incre_controller(700);
/*
        int16 speed=5000-abs(global_bias)*50;
        speed=(speed<3000)?3000:speed;
        pwm_duty(pwm_1_pos,speed);
*/
		//用户在此处编写任务代码
    	

    }
}





#pragma section all restore
