/*
* fsm_10s.c
*
*  Created on: Nov 5, 2022
*      Author: Acer
*/
#include "fsm_10s.h"

int counter = 1000;
int flag = 0;

void check(){
if(counter != 0){
counter = counter - 1;
}
if(button_flag1 == 1 && flag == 0)
{
counter = 1000;
flag = 0;
}
if(button_flag2 == 1 && flag == 0 )
{
counter = 1000;
flag = 0;
}
if(button_flag3 == 1 && flag == 0)
{
counter = 1000;
flag = 0;
}
if(button_flag1 == 1 && flag == 1)
{
counter = 1000;
flag = 0;
}
if(button_flag2 == 1 && flag == 1)
{
counter = 1000;
flag = 0;
led_number = led_number2;
}
if(button_flag3 == 1 && flag == 1)
{
counter = 1000;
flag = 0;
led_number = led_number2;
}
if(counter == 0)
{
flag = 1;
if(timer2_flag == 1)
{
led_number2--;
display7SEG(led_number2);
setTimer2(1000);
}
if(led_number2 == 0){
counter = 1000;
flag = 1;
}
}
}
