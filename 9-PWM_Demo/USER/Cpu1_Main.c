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

extern int16 global_bias;


void core1_main(void)
{
	disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    gtm_pwm_init(pwm_1_pos, 13000, 0);
        gtm_pwm_init(pwm_1_neg, 13000, 0);
    //�û��ڴ˴����ø��ֳ�ʼ��������

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
		//�û��ڴ˴���д�������
    	

    }
}





#pragma section all restore
