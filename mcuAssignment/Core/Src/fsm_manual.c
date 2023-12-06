/*
 * fsm_manual.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Asus
 */
//hello

#include "fsm_manual.h"

void switchMode3() {
	status = YELLOW_MAN;
}

void switchMode4() {
	status = GREEN_MAN;
}

void fsm_manual_run() {
	switch(status) {

	case RED_MAN:
		displayLed(RED_MAN);

//		if(timer2_flag == 1) {
//			setTimer2(100);
//		}

		if(isButtonPressed(0)) {
			switchMode3();
		}

		if(isButtonPressed(1)) {
			status = RED_MAN_MODIFY;
			timerMan = redTimer;
		}
		break;
	case RED_MAN_MODIFY:
		displayLed(RED_MAN);

		if(isButtonPressed(0)) {
			status = RED_MAN;
		}

		if(isButtonPressed(1)) {
			timerMan++;
			int len= sprintf(str,"LED RED    =  %d\r\n",timerMan);
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			if(timerMan > 99) timerMan = 1;
		}

		if(isButtonPressed(2)) {
			status = INIT;
			int len= sprintf(str,"%s\r\n","save successfully");
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			redTimer = timerMan;
			greenTimer = redTimer - yellowTimer;
		}

		break;
	case YELLOW_MAN:
		displayLed(YELLOW_MAN);

//		if(timer2_flag == 1) {
//			setTimer2(100);
//		}

		if(isButtonPressed(0)) {
			switchMode4();
		}

		if(isButtonPressed(1)) {
			status = YELLOW_MAN_MODIFY;
			timerMan = yellowTimer;
		}
		break;
	case YELLOW_MAN_MODIFY:
		displayLed(YELLOW_MAN);

		if(isButtonPressed(0)) {
			status = YELLOW_MAN;
		}

		if(isButtonPressed(1)) {
			timerMan++;
			int len= sprintf(str,"LED YELLOW =  %d\r\n",timerMan);
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			if(timerMan >= redTimer) timerMan = 1;
		}

		if(isButtonPressed(2)) {
			status = INIT;
			int len= sprintf(str,"%s\r\n","save successfully");
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			yellowTimer = timerMan;
			greenTimer = redTimer-yellowTimer;
		}
		break;
	case GREEN_MAN:
		displayLed(GREEN_MAN);

//		if(timer2_flag == 1) {
//			setTimer2(100);
//		}

		if(isButtonPressed(0)) {
			status = INIT;
		}

		if(isButtonPressed(1)) {
			status = GREEN_MAN_MODIFY;
			timerMan = greenTimer;
		}
		break;
	case GREEN_MAN_MODIFY:
		displayLed(GREEN_MAN);

		if(isButtonPressed(0)) {
			status = GREEN_MAN;
		}

		if(isButtonPressed(1)) {
			timerMan++;
			int len= sprintf(str,"LED GREEN  =  %d\r\n",timerMan);
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			if(timerMan >= redTimer) timerMan = 1;
		}

		if(isButtonPressed(2)) {
			status = INIT;
			int len= sprintf(str,"%s\r\n","save successfully");
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			greenTimer = timerMan;
			yellowTimer = redTimer - greenTimer;
		}
		break;
	default:
		break;
	}
};
