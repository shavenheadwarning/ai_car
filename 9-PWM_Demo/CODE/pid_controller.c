

#include "pid_controller.h"
#include "zf_gpt12.h"
#include "pin_distribution.h"
#include "zf_gtm_pwm.h"
#include "zf_stm_systick.h"

extern float pwm_kp=0.2;
extern float pwm_ki=0;
extern float pwm_kd=0;

int16 pwm_current_error=0;
int16 pwm_pre_error=0; //
int16 pwm_last_error=0; //

int16 current_pwm=3500;
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




