/*
 * button.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Acer
 */
#include"button.h"

int key01 = NORMAL_STATE;
int key11 = NORMAL_STATE;
int key21 = NORMAL_STATE;
int key31 = NORMAL_STATE;

int key02 = NORMAL_STATE;
int key12 = NORMAL_STATE;
int key22 = NORMAL_STATE;
int key32 = NORMAL_STATE;

int key03 = NORMAL_STATE;
int key13 = NORMAL_STATE;
int key23 = NORMAL_STATE;
int key33 = NORMAL_STATE;

int timerforpress1 = 100;
int timerforpress2 = 300;
int timerforpress3 = 300;

int count1 = 0;
int count2 = 0;

int flag1 = 0;
int flag2 = 0;

int button_flag1 = 0;
int button_flag2 = 0;
int button_flag3 = 0;

// BUTTON 1 IS RESET BUTTON
// BUTTON 2 IS INC BUTTON
// BUTTON 3 IS DEC BUTTON


void getKeyInput1(){
	key01 = key11;
	key11 = key21;
	key21 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
	if((key01 == key11) && (key11 == key21)){
		if(key31 != key21){
			key31 = key21;
			if(key21 == PRESSED_STATE){
				button_flag1= 1;
					timerforpress1 = 100;

			}
		}if(key31 == key21){
			timerforpress1--;
			if(timerforpress1 == 0){
				key31 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInput2(){
	key02 = key12;
	key12 = key22;
	key22 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
	if((key02 == key12) && (key12 == key22)){
		if(key32 != key22){
			key32 = key22;
			if(key22 == PRESSED_STATE){
				button_flag2= 1;

					timerforpress2 = 300 - count1; // LONG_PRESSED CONTROLL
			}
		}if(key32 == key22){
			timerforpress2--;
			if(timerforpress2 == 0){
				key32 = NORMAL_STATE;
				count1 = 280; // LONG_PRESSED CONTROLL
			}
		}
	}
}

void getKeyInput3(){
	key03 = key13;
	key13 = key23;
	key23 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
	if((key03 == key13) && (key13 == key23)){
		if(key33 != key23){
			key33 = key23;
			if(key23 == PRESSED_STATE){
				button_flag3= 1;
				if(button_flag2 == 1)
				{
					count2 = 0;
				}
					timerforpress3 = 300 - count2; // LONG_PRESSED CONTROLL
			}
		}if(key33 == key23){
			timerforpress3--;
			if(timerforpress3 == 0){
				key33 = NORMAL_STATE;
				count2 = 280; // LONG_PRESSED CONTROLL
			}
		}
	}
}
