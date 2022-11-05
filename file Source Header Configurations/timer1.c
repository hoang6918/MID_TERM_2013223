/*
 * timer1.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Acer
 */

#include "timer1.h"

int timer1_flag = 0;
int timer1_counter = 0;
int timer_cycle = 10;

void setTimer1(int duration){
	timer1_flag = 0;
	timer1_counter = duration / timer_cycle;
}

void timer_run1(){
	if(timer1_counter >= 0){
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}
}
