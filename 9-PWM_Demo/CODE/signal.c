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

extern uint16 signals[5]={0};
extern uint16 signals_2[7]={0};
extern float signals_norma[5]={0};
float limit_amplitude_neg=150.0;//限幅参数，需要调出来
float limit_amplitude_pos=150.0;
float vertical_weight=1.2;

void adc_inits(){

    adc_init(ADC_0,opa1);
    adc_init(ADC_0,opa2);
    adc_init(ADC_0,opa3);
    adc_init(ADC_0,opa4);
    adc_init(ADC_0,opa5);



    adc_init(ADC_1,opa8);
    adc_init(ADC_1,opa9);
    adc_init(ADC_2,opa10);
    adc_init(ADC_2,opa11);
    adc_init(ADC_2,opa12);
    adc_init(ADC_2,opa13);
    adc_init(ADC_2,opa14);

}
void signal_read(){

    signals[0]=adc_mean_filter(ADC_0, opa1, ADC_12BIT, 5);
    signals[1]=adc_mean_filter(ADC_0, opa2, ADC_12BIT, 5);
    signals[2]=adc_mean_filter(ADC_0, opa3, ADC_12BIT, 5);
    signals[3]=adc_mean_filter(ADC_0, opa4, ADC_12BIT, 5);
    signals[4]=adc_mean_filter(ADC_0, opa5, ADC_12BIT, 5);

   signals_2[0]=adc_mean_filter(ADC_1, opa8, ADC_12BIT, 5);
   signals_2[1]=adc_mean_filter(ADC_1, opa9, ADC_12BIT, 5);
   signals_2[2]=adc_mean_filter(ADC_2, opa10, ADC_12BIT, 5);
   signals_2[3]=adc_mean_filter(ADC_2, opa11, ADC_12BIT, 5);
   signals_2[4]=adc_mean_filter(ADC_2, opa12, ADC_12BIT, 5);
   signals_2[5]=adc_mean_filter(ADC_2, opa13, ADC_12BIT, 5);
   signals_2[6]=adc_mean_filter(ADC_2, opa14, ADC_12BIT, 5);


/*
    signals[0]=85;
    signals[1]=83;
    signals[2]=97;
    signals[3]=111;
    signals[4]=96;
*/

}
void normalize(){

    uint16 signals_min,signals_max;
    //找最值
    //x'=(x-min)/(max-min)
    int16 i;
    signals_min=signals[0];
    signals_max=signals[0];
    for(i=0;i<5;i++)
    {
        if(signals[i]<signals_min)signals_min=signals[i];
        if(signals[i]>signals_max)signals_max=signals[i];
    }

    signals_norma[0]=(float)(signals[0]-signals_min)/(float)(signals_max-signals_min);
    signals_norma[1]=(float)(signals[1]-signals_min)/(float)(signals_max-signals_min);
    signals_norma[2]=(float)(signals[2]-signals_min)/(float)(signals_max-signals_min);
    signals_norma[3]=(float)(signals[3]-signals_min)/(float)(signals_max-signals_min);
    signals_norma[4]=(float)(signals[4]-signals_min)/(float)(signals_max-signals_min);

}
int16 error_calculate(){

   signal_read();
   normalize();
   float induc1=signals_norma[0];
   float induc2=signals_norma[1];
   float induc3=signals_norma[2];
   float induc4=signals_norma[3];
   float induc5=signals_norma[4];

   float induc_error1=(induc5-induc1)/(induc5+induc1);
   float induc_error2=(induc4-induc2)/(induc4+induc2);
   float induc_error=induc_error1*(induc1+induc5)+induc_error2*(induc2+induc4)*6;
   //float induc_error=induc_error1;
   int16 result=0;
   if(induc_error1>0)result=(int16)(induc_error*limit_amplitude_pos);
   else result=(int16)(induc_error*limit_amplitude_neg);

   return result;
}

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

