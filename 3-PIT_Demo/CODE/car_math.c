/*
 * car_math.c
 *
 *  Created on: 2021Äê4ÔÂ28ÈÕ
 *      Author: wby
 */

#include "car_math.h"
#include "stdlib.h"
#include "signal.h"
uint8 send_buff[11]={0};
extern int8 signals_short_convert[7];
uint8* data_dev(uint16 data){
    uint8* data_array=(uint8*)malloc(sizeof(char)*4);
    data_array[0]=(data/1000)%10;
    data_array[1]=(data/100)%10;
    data_array[2]=(data/10)%10;
    data_array[3]=(data)%10;
    return data_array;
}

void data_transfer(int16 last_ftm0,int8 data_tf_flag){
    if(data_tf_flag==0)return;
    signal_short_convert();
    for(int8 i=0;i<7;i++){
            send_buff[i+2]=signals_short_convert[i];
    }
    //send_buff[9]=(uint8)((int32)(last_ftm1 - 1900) * 255 / 601);
    send_buff[9]=(uint8)((int32)(last_ftm0 - 1900) * 255 / 601);
    send_buff[10]=0x5a;
    uart_putbuff(UART_2,send_buff,11);
    return;

}





