/*
 * car_math.c
 *
 *  Created on: 2021��4��28��
 *      Author: wby
 */

#include "car_math.h"
#include "stdlib.h"
uint8 send_buff[9]={0};
extern signals_short[7];
uint8* data_dev(uint16 data){
    uint8* data_array=(uint8*)malloc(sizeof(char)*4);
    data_array[0]=(data/1000)%10;
    data_array[1]=(data/100)%10;
    data_array[2]=(data/10)%10;
    data_array[3]=(data)%10;
    return data_array;
}

void data_transfer(int16 last_ftm,int8 data_tf_flag){
    if(data_tf_flag==0)return;
    for(int8 i=0;i<7;i++){
            send_buff[i]=signals_short[i];
    }
    send_buff[7]=(uint8)((int32)(last_ftm - 1500) * 255 / 501);
    send_buff[8]=0x5a;
    uart_putbuff(UART_2,send_buff,9);

}




