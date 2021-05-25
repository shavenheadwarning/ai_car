/*
 * signal.c
 *
 *  Created on: 2021年3月16日
 *      Author: lenovo
 */
#include"signal.h"
#include"pin_distribution.h"
#include"zf_vadc.h"
#include "stdlib.h"
#include "math.h"
#include "SEEKFREE_18TFT.h"

uint16 signals_short[7]={0};
uint16 signals_long[7]={0};
int8 signals_short_convert[7]={0};
extern float signals_long_norma[7]={0};
float limit_amplitude_neg=250;//限幅参数，需要调出来 右
float limit_amplitude_pos=10.0;//左
float vertical_weight=1.2;


int16 roundabout_flag1=0;
int16 roundabout_flag2=0;
//int16 roundabout_flag3=0;
void adclong_inits(){



    adc_init(ADC_2,opa1_1);
    adc_init(ADC_2,opa1_2);
    adc_init(ADC_2,opa1_3);
    adc_init(ADC_2,opa1_4);
    adc_init(ADC_2,opa1_5);
    adc_init(ADC_1,opa1_6);
    adc_init(ADC_1,opa1_7);

}
void adcshort_inits(){
    adc_init(ADC_0,opa2_1);
    adc_init(ADC_0,opa2_2);
    adc_init(ADC_0,opa2_3);
    adc_init(ADC_0,opa2_4);
    adc_init(ADC_0,opa2_5);
    adc_init(ADC_0,opa2_6);
    adc_init(ADC_0,opa2_7);

}

void signal_long_read(){


   signals_long[0]=adc_mean_filter(ADC_2, opa1_1, ADC_12BIT, 3);
   signals_long[1]=adc_mean_filter(ADC_2, opa1_2, ADC_12BIT, 3);
   signals_long[2]=adc_mean_filter(ADC_2, opa1_3, ADC_12BIT, 3);
   signals_long[3]=adc_mean_filter(ADC_2, opa1_4, ADC_12BIT, 3);
   signals_long[4]=adc_mean_filter(ADC_2, opa1_5, ADC_12BIT, 3);
   signals_long[5]=adc_mean_filter(ADC_1, opa1_6, ADC_12BIT, 3);
   signals_long[6]=adc_mean_filter(ADC_1, opa1_7, ADC_12BIT, 3);

}

void signal_short_read(){

    signals_short[0]=adc_convert(ADC_0, opa2_1, ADC_8BIT);
    signals_short[1]=adc_convert(ADC_0, opa2_2, ADC_8BIT);
    signals_short[2]=adc_convert(ADC_0, opa2_3, ADC_8BIT);
    signals_short[3]=adc_convert(ADC_0, opa2_4, ADC_8BIT);
    signals_short[4]=adc_convert(ADC_0, opa2_5, ADC_8BIT);
    signals_short[5]=adc_convert(ADC_0, opa2_6, ADC_8BIT);
    signals_short[6]=adc_convert(ADC_0, opa2_7, ADC_8BIT);


}
void signal_short_convert(){
    for(int8 i=0;i<7;i++){
        signals_short_convert[i]=(int16)signals_short[i]-128;
    }
    return;
}

void normalize(){

    uint16 signals_min,signals_max;
    //找最值
    //x'=(x-min)/(max-min)
    int16 i;
    signals_min=signals_long[0];
    signals_max=signals_long[0];
    for(i=0;i<7;i++)
    {
        if(signals_long[i]<signals_min)signals_min=signals_long[i];
        if(signals_long[i]>signals_max)signals_max=signals_long[i];
    }

    signals_long_norma[0]=(float)(signals_long[0]-signals_min)/(float)(signals_max-signals_min);
    signals_long_norma[1]=(float)(signals_long[1]-signals_min)/(float)(signals_max-signals_min);
    signals_long_norma[2]=(float)(signals_long[2]-signals_min)/(float)(signals_max-signals_min);
    signals_long_norma[3]=(float)(signals_long[3]-signals_min)/(float)(signals_max-signals_min);
    signals_long_norma[4]=(float)(signals_long[4]-signals_min)/(float)(signals_max-signals_min);
    signals_long_norma[5]=(float)(signals_long[5]-signals_min)/(float)(signals_max-signals_min);
    signals_long_norma[6]=(float)(signals_long[6]-signals_min)/(float)(signals_max-signals_min);

}
int16 error_calculate(){

   signal_long_read();
   normalize();
   /*
   float induc1=signals_norma[0];
   float induc2=signals_norma[1];
   float induc3=signals_norma[2];
   float induc4=signals_norma[3];
   float induc5=signals_norma[4];
*/
   float horizontal_error=(signals_long_norma[0]-signals_long_norma[6])/(signals_long_norma[0]+signals_long_norma[6]);
   float vertical_error1=(signals_long_norma[1]-signals_long_norma[5])/(signals_long_norma[1]+signals_long_norma[5]);
   //float vertical_error2=(signals_long_norma[4]-signals_long_norma[2])/(signals_long_norma[4]+signals_long_norma[2]);
   float error=(horizontal_error*(signals_long[0]+signals_long[6])+vertical_error1*(signals_long[1]+signals_long[5]))/1000;

   /*
   float induc_error1=(induc5-induc1)/(induc5+induc1);
   float induc_error2=(induc4-induc2)/(induc4+induc2);
   float induc_error=induc_error1*(induc1+induc5)+induc_error2*(induc2+induc4)*6;
   float horizontal_error=
   //float induc_error=induc_error1;

    */
   int16 result=0;
   if(horizontal_error>0)result=(int16)(error*limit_amplitude_pos);
   else result=(int16)(error*limit_amplitude_neg);

   return result;
}


int16 error_calculate_roundabout(){
    signal_long_read();
    normalize();

     float horizontal_error=(signals_long_norma[0]-signals_long_norma[6])/(signals_long_norma[0]+signals_long_norma[6]);
     float vertical_error1=(signals_long_norma[2]-signals_long_norma[4])/(signals_long_norma[2]+signals_long_norma[4]);
     //float vertical_error2=(signals_long_norma[4]-signals_long_norma[2])/(signals_long_norma[4]+signals_long_norma[2]);
     float error=(horizontal_error*(signals_long[0]+signals_long[6])+vertical_error1*(signals_long[2]+signals_long[4]))/1000;

     /*
     float induc_error1=(induc5-induc1)/(induc5+induc1);
     float induc_error2=(induc4-induc2)/(induc4+induc2);
     float induc_error=induc_error1*(induc1+induc5)+induc_error2*(induc2+induc4)*6;
     float horizontal_error=
     //float induc_error=induc_error1;

      */
     int16 result=0;
     if(horizontal_error>0)result=(int16)(error*limit_amplitude_pos)/2;
     else result=(int16)(error*limit_amplitude_neg)/2;

     return result;
}

_Bool right_angle_detect(){
    int16 induc=(signals_long_norma[1]-signals_long_norma[5])/(signals_long_norma[1]+signals_long_norma[5]);
    if(induc==1||induc==-1){

        return 1;
    }
    else{

    }
    return 0;
}
_Bool loss_line_detect(){
    if(signals_long[3]<300)return 1;
    else return 0;
}

int16 pass_roundabout_detect(){
    if(signals_long[3]>900){
        if(signals_long[0]>900&&signals_long[1]>900&&signals_long[2]>900){
            //lcd_showchar(120, 100, 'p');
            return 1; //左转
        }
        else if(signals_long[4]>800&&signals_long[5]>800){
            //lcd_showchar(120, 100, 'p');
            return -1;
        }
    }

    return 0;
}
_Bool upslope_detect(){
    signal_long_read();
    if(signals_long[3]>800&&signals_long[1]<150&&signals_long[5]<150){
        return 1;
    }
    else return 0;
}
int16 enter_roundabout_detect(){
    _Bool flag1=((signals_long[3]>900||signals_long[0]>900)&&signals_long[2]>1150&&signals_long[1]<700)||signals_long[6]>800;


    if(flag1)return 1;
    return 0;
}
/*
float get_vertical_value(){
    float vertical_value=0;
    vertical_value=(float)(signals[1]-signals[3])/(float)(signals[1]+signals[3]);
    return vertical_value*vertical_weight;

}

float* get_signals_norma(float* ptr){
    ptr=signals_norma;
    return ptr;
}
uint16* get_signals(uint16 *ptr){
    ptr=signals;
    return ptr;
}

uint16* get_signals_2(uint16 *ptr){
    ptr=signals_2;
    return ptr;
}


uint32 std_deviation(){
    uint32 deviation=0;
    int32 avg=(int32)(signals[0]+signals[1]+signals[2]+signals[3]+signals[4])/5;
    for(uint16 i=0;i<5;i++){
        deviation+=(int32)pow((int32)(signals[i]-avg),2);
    }
    return (uint32)sqrt(deviation/5);
}

int16 loss_line(){
    int16 error=error_calculate();
    uint32 std_dev=std_deviation();
    if(std_dev<30&&abs(error)>50){
        return 1;
    }
    return 0;
}
*/

