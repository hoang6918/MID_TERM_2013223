/*
 * fsm_button_run.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Acer
 */
#include "fsm_button_run.h"


void fsm_simple_buttons_run (){

	// BUTTON 1 IS RESET BUTTON
	// BUTTON 2 IS INC BUTTON
	// BUTTON 3 IS DEC BUTTON

	switch(status){
			case INIT:
				              if(button_flag1 == 1)  // Press Button 1 status
						  	   {
							   status = BUTTON_1;
						  	   }
						      if(button_flag2 == 1 && count1 == 200) // Press Button 2 Status
							   {
									status = BUTTON_4;
							   }
							   if(button_flag3 == 1 && count2 ==200) // Press Button 3 Status
										   {
								status = BUTTON_5;
										   }
						      if(button_flag2 == 1) // Press Button 2 Status
							   {
							   count2 = 0; // LONG_PRESSED CONTROLL
							   status = BUTTON_2;
							  	}
						       if(button_flag3 == 1) // Press Button 3 Status
						       		  	   {
						    	count1 = 0; // LONG_PRESSED CONTROLL
								status = BUTTON_3;
						       		  	   }
				break;
			case BUTTON_1:
				led_number = 0;
							   display7SEG(led_number);
							  button_flag1 = 0;
							   led_number2 = led_number;
							   status = INIT;
				break;
			case BUTTON_2:
				led_number = led_number + 1;
			   if(led_number>=10)
			   {
				   led_number = 0;
			   }
			   display7SEG(led_number);
			   button_flag2 = 0;
			   led_number2 = led_number;
				status = INIT;


				break;
			case BUTTON_3:
			   led_number = led_number - 1;
			   led_number2 = led_number;
			   if(led_number<=-1)
					  {
						led_number = 9;
					  }
			   display7SEG(led_number);
			   button_flag3 = 0;
				status = INIT;

				break;
			// FINITE STATE MACHINE 2
			case BUTTON_4:
				count1 = 0;
				status = INIT;
				break;
			case BUTTON_5:
				count2 = 0;
				status = INIT;
				break;
			default:
				break;
			}
	// FINITE STATE MACHINE 2

}

		/*  if(button_flag1 == 1)  // Press Button 1 status
		  	   {
			   led_number = 0;
			   display7SEG(led_number);
			   button_flag1 = 0;
			   led_number2 = led_number;
		  	   }
		   if(button_flag2 == 1) // Press Button 2 Status
			   {
			   led_number = led_number + 1;
				   if(led_number>=10)
				   {
					   led_number = 0;
				   }
				   display7SEG(led_number);
				   button_flag2 = 0;
				   led_number2 = led_number;
			  		  	   }
		       if(button_flag3 == 1) // Press Button 3 Status
		       		  	   {
				   led_number = led_number - 1;
				   led_number2 = led_number;
				   if(led_number<=-1)
				   		  {
				   			led_number = 9;
				   		  }
				   display7SEG(led_number);
				   button_flag3 = 0;
		       		  	   }*/


