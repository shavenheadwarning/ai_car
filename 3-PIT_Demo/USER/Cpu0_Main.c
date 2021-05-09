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

#pragma section all "cpu0_dsram"
extern uint16 signals_long[7];
extern uint16 signals_short[7];
int16 last_steering_pwm=1900;

int8 data_tf_flag=0;

int core0_main(void)
{
	disableInterrupts();
	get_clk();//��ȡʱ��Ƶ��  ��ر���

    //�û��ڴ˴����ø��ֳ�ʼ��������
	//ʹ��CCU6_0ģ���ͨ��0 ����һ�� 100ms�������ж�
	adclong_inits();
	adcshort_inits();
	//motor_init();
	gpt12_init(GPT12_T2, GPT12_T2INB_P33_7, GPT12_T2EUDB_P33_6);
	lcd_init();
	uart_init(UART_2,115200,uart_tx,uart_rx);
	steering_init();
	//�жϺ�����isr.c�� ��������Ϊcc60_pit_ch0_isr
	//�ж���ص����ò�����isr_config.h��
	//�����ò����� CCU6_0_CH0_INT_SERVICE �� CCU6_0_CH0_ISR_PRIORITY
	//CCU6_0_CH0_INT_SERVICE �жϷ�����
	//CCU6_0_CH0_ISR_PRIORITY �ж����ȼ� ���ȼ���Χ1-255 Խ�����ȼ�Խ�� ��ƽʱʹ�õĵ�Ƭ����һ��

	//��Ҫ�ر�ע�����  �����������ȼ���ͬ���жϺ��� ÿ���жϵ����ȼ��������ǲ�һ����
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
        enter_roundabout_dispose(enter_roundabout_detect());
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










		//��������֮�� PIT�ж�ÿִ��һ�ξͻ��ӡһ��
        //�����ͨ�����ڴ�ӡ��������ѧϰprintf���̣��˽����ʹ��printf
    }
}

#pragma section all restore
