/*
 * button.h
 *
 *  Created on: Oct 11, 2022
 *      Author: Acer
 */
#include"timer1.h"
#include"timer2.h"
#include"timer3.h"
#include"main.h"
#include "global.h"

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKeyInput1();
void getKeyInput2();
void getKeyInput3();

extern int button_flag1;
extern int button_flag2;
extern int button_flag3;

extern int count1;
extern int count2;

extern int flag1;
extern int flag2;



#endif /* INC_BUTTON_H_ */
