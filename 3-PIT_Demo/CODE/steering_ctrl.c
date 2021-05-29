/*
 * steering_ctrl.c
 *
 *  Created on: 2021年3月16日
 *      Author: wby
 */

#include "steering_ctrl.h"
#include "pin_distribution.h"
#include "zf_gtm_pwm.h"
#include "zf_stm_systick.h"
#include "signal.h"
#include "zf_gpio.h"
#include "SEEKFREE_18TFT.h"
#include "car_math.h"

const uint16 steering_mid=1900;
const uint16 steering_left_max=2200;
const uint16 steering_right_max=1600;

extern int8 data_tf_flag;

int16 current_steering_error=0; //当前误差
//int16 cumulant_steering_error; //累积误差
int16 last_steering_error=0;//前一次误差
float init_kp=0.4;
float steering_kp=0.5;
float steering_kd=0.2;
extern int16 last_steering_pwm0;
extern int16 last_steering_pwm1;

void steering_init(){  //舵机初始化
    gtm_pwm_init(ftm_steering, 100, steering_mid);
}


int16 steering_angle_ctrl(int16 bias){





    current_steering_error=bias; //与通电导线的偏差

   float steering_increment=(float)(steering_kp*(float)(current_steering_error)+steering_kd*((float)(current_steering_error)-(float)(last_steering_error)));

    int16 steering_duty=steering_mid+(int16)(steering_increment);


    if(steering_duty>steering_left_max)steering_duty=steering_left_max;
    if(steering_duty<steering_right_max)steering_duty=steering_right_max;


    last_steering_error=current_steering_error;

    pwm_duty(ftm_steering, steering_duty);
    //systick_delay_ms(STM0,10);

    return steering_duty;

    //systick_delay_ms(STM0,5);
    //systick_delay_ms(STM1,10);
    //printf("%d\n",steering_duty);
    //systick_delay_ms(STM0,50);
    //pwm_duty(ftm_steering,steering_mid+bias);
}
void loss_line_dispose(int16 last_steering_pwm){
    if(last_steering_pwm<steering_mid){
        pwm_duty(ftm_steering,steering_right_max);
        last_steering_pwm0=steering_right_max;
        last_steering_pwm1=steering_right_max;
        //data_transfer(steering_right_max,steering_right_max,data_tf_flag);
    }
    else {
        pwm_duty(ftm_steering, steering_left_max);
        last_steering_pwm0=steering_right_max;
        last_steering_pwm1=steering_right_max;
        //data_transfer(steering_left_max,steering_left_max,data_tf_flag);

    }
    //lcd_showint16(100,4,last_steering_pwm);
    //lcd_showchar(60,45,'L');

    signal_long_read();
    if(!loss_line_detect()){
        //lcd_showchar(60,45,'N');
        return;
    }

}

void pass_roundabout_dispose(int16 flag){
    if(!flag){

        return;
    }

    else if(flag==1){
        pwm_duty(ftm_steering,steering_mid);
        last_steering_pwm0=steering_mid;
         last_steering_pwm1=steering_mid;
        //data_transfer(1900,1900,data_tf_flag);
        systick_delay_ms(STM0,300);
    }
    else if(flag==-1){
        pwm_duty(ftm_steering,steering_mid);
        last_steering_pwm0=steering_mid;
        last_steering_pwm1=steering_mid;
        //data_transfer(1900,1900,data_tf_flag);
        systick_delay_ms(STM0,300);
    }
    return;


}
void enter_roundabout_dispose(int16 flag){
    if(!flag)return;
    while(flag){
           lcd_showchar(80,0,'R');
           if(flag==1){
               int16 last_pwm=steering_angle_ctrl(error_calculate_roundabout());
               //lcd_showint16(60,4,last_pwm);
               systick_delay_ms(STM0,500);
               data_transfer(last_pwm,last_pwm, data_tf_flag);
           }
           else if(flag==-1){
               pwm_duty(ftm_steering,1700);
               data_transfer(1700,1700,data_tf_flag);
               //systick_delay_ms(STM0,300);
           }
           signal_long_read();
           flag=enter_roundabout_detect();

       }
       lcd_showchar(80,0,'N');
       return;
}

void change_kp(float v){
    v=(v>0)?v:-1*v;

    steering_kp=init_kp+0.1*(v*10);
    if(steering_kp>1.2)steering_kp=1.2;
}
/*
void lossline_dispose(int16 bias){
    while(loss_line()){
        if(bias>0){pwm_duty(ftm_steering,1200);}
        else {pwm_duty(ftm_steering, 925);}
        if(!loss_line())return;
    }
}
*/




