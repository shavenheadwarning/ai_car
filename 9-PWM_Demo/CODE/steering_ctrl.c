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

const uint16 steering_mid=1050;
const uint16 steering_left_max=925;
const uint16 steering_right_max=1250;//1100


int16 current_steering_error=0; //当前误差
//int16 cumulant_steering_error; //累积误差
int16 last_steering_error=0;//前一次误差
float init_kp=0.4;
float steering_kp=1.2;
extern float steering_kd=0;


void steering_init(){  //舵机初始化
    gtm_pwm_init(ftm_steering, 50, steering_mid);
}


void steering_angle_ctrl(int16 bias){
    /*
    float vertical=get_vertical_value();
    change_kp(vertical);
    */



    int16 loss=loss_line();


    if(!loss){
        gpio_set(speak, 0);

        current_steering_error=bias; //与通电导线的偏差

           int16 steering_increment=(int16)(steering_kp*current_steering_error+steering_kd*(current_steering_error-last_steering_error));

           int16 steering_duty=steering_mid+steering_increment;


           if(steering_duty<steering_left_max)steering_duty=steering_left_max;
           if(steering_duty>steering_right_max)steering_duty=steering_right_max;


           last_steering_error=current_steering_error;
           pwm_duty(ftm_steering, steering_duty);
    }
    else{
            gpio_set(speak, 1);
            lossline_dispose(bias);



         }


/*


    current_steering_error=bias; //与通电导线的偏差

    int16 steering_increment=(int16)(steering_kp*current_steering_error+steering_kd*(current_steering_error-last_steering_error));

    int16 steering_duty=steering_mid+steering_increment;


    if(steering_duty<steering_left_max)steering_duty=steering_left_max;
    if(steering_duty>steering_right_max)steering_duty=steering_right_max;


    last_steering_error=current_steering_error;
    pwm_duty(ftm_steering, steering_duty);

    //systick_delay_ms(STM0,5);
    //systick_delay_ms(STM1,10);
    //printf("%d\n",steering_duty);
    //systick_delay_ms(STM0,50);
    //pwm_duty(ftm_steering,steering_mid+bias);
*/
}

void change_kp(float v){
    v=(v>0)?v:-1*v;

    steering_kp=init_kp+0.1*(v*10);
    if(steering_kp>1.2)steering_kp=1.2;
}
void lossline_dispose(int16 bias){
    while(loss_line()){
        if(bias>0){pwm_duty(ftm_steering,1200);}
        else {pwm_duty(ftm_steering, 925);}
        if(!loss_line())return;
    }
}




