

#include "pid_controller.h"
#include "zf_gpt12.h"
#include "pin_distribution.h"
#include "zf_gtm_pwm.h"
#include "zf_stm_systick.h"
#include "zf_gpio.h"
float pwm_kp=0.2;
float pwm_ki=0;
float pwm_kd=0;

int16 pwm_current_error=0;
int16 pwm_pre_error=0; //
int16 pwm_last_error=0; //

int16 current_pwm=4000;
int8 motor_run_flag=0;
int16 pid_incre_controller(int16 set_speed)
{
    systick_delay_ms(STM1,5);
    int16 current_speed=gpt12_get(GPT12_T2);

    gpt12_clear(GPT12_T2);
    pwm_current_error=set_speed-current_speed;
    int16 motor_duty_increment=(pwm_kp)*(pwm_current_error-pwm_last_error)-(pwm_ki)*(pwm_current_error)+(pwm_kd)*(pwm_current_error-2*pwm_last_error+pwm_pre_error);


    pwm_duty(pwm_1_pos,current_pwm+motor_duty_increment);
    current_pwm+=motor_duty_increment;

    pwm_pre_error=pwm_last_error;
    pwm_last_error=pwm_current_error;
    return current_speed;



}
void motor_init(){
    gtm_pwm_init(pwm_1_pos, 14000, 0);
    gtm_pwm_init(pwm_1_neg, 14000, 0);
}
void motor_stop(){
   pwm_duty(pwm_1_pos,0);
   pwm_duty(pwm_1_neg,0);
   systick_delay(STM1, 1000);
   return;
}
void motor_stop2(){
    gpio_init(P21_2, 0, 0, NO_PULL);
    gpio_init(P21_3, 0, 0, NO_PULL);
    return;
}



