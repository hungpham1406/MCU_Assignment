/*
 * fsm_automatic.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Asus
 */

#include "fsm_automatic.h"


void switchMode2() {
	int len= sprintf(str,"%s\r\n","Welcome to Manual Mode");
	HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
	status = RED_MAN;
	counter1 = redTimer;
	setTimer2(100);
	setTimer4(25);
	statusPedestrian = PES_OFF;
}

void fsm_pedestrian(){
	switch(statusPedestrian){
	case PES_ON:
		turnPedestrian_flag = 1;

		break;
	case PES_OFF:
		turnPedestrian_flag = 0;
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
		break;
	default:
		break;
	}

	if(timer6_flag == 1) {
		statusPedestrian = PES_OFF;
	}
}

void fsm_automatic_run() {
	switch(status) {
	case INIT:
		statusPedestrian = PES_OFF;
		status = RED1_GREEN2_AUTO;
		counter1 = redTimer;
		counter2 = greenTimer;

		setTimer1(greenTimer*100);
		setTimer2(100);
		setTimer5(25);
		break;
	case RED1_GREEN2_AUTO:
		displayLed(RED1_GREEN2);

		if(timer2_flag == 1) {
			int len= sprintf(str,"LED RED      = %d    LED GREEN    = %d\r\n",counter1,counter2);
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			setTimer2(100);
			counter1--;
			counter2--;
			if(turnPedestrian_flag == 1) {
				__HAL_TIM_SET_AUTORELOAD(&htim3, 5*value_buzzer);
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0.6 * (5*value_buzzer));
				value_buzzer = value_buzzer - value_buzzer/(greenTimer+yellowTimer);
			}
		}

		if(timer1_flag == 1) {
			status = RED1_YELLOW2_AUTO;
			setTimer1((redTimer-greenTimer)*100);
			counter1 = redTimer-greenTimer;
			counter2 = yellowTimer;
		}

		if(isButtonPressed(0)) {
			switchMode2();
		}

		break;
	case RED1_YELLOW2_AUTO:
		displayLed(RED1_YELLOW2);

		if(timer2_flag == 1) {
			int len= sprintf(str,"LED RED      = %d    LED YELLOW   = %d\r\n",counter1,counter2);
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			setTimer2(100);
			counter1--;
			counter2--;
			if(turnPedestrian_flag == 1) {
				__HAL_TIM_SET_AUTORELOAD(&htim3, 5*value_buzzer);
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0.6 * (5*value_buzzer));
				value_buzzer = value_buzzer - value_buzzer/(greenTimer+yellowTimer);
			}
		}

		if(timer1_flag == 1) {
			status = GREEN1_RED2_AUTO;
			setTimer1(greenTimer*100);
			counter1 = greenTimer;
			counter2 = redTimer;
		}

		if(isButtonPressed(0)) {
			switchMode2();
		}
		break;
	case GREEN1_RED2_AUTO:
		displayLed(GREEN1_RED2);
		if (isButtonPressed(3)) {
			statusPedestrian = PES_ON;
//			setTimer3((redTimer+greenTimer+yellowTimer)*100 - 400);
			setTimer6((3*redTimer)*100);
			value_buzzer = 2000;
		}

		if(turnPedestrian_flag == 1) {
			__HAL_TIM_SET_AUTORELOAD(&htim3, 5*value_buzzer);
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0);
		}

		if(timer2_flag == 1) {
			int len= sprintf(str,"LED GREEN    = %d    LED RED      = %d\r\n",counter1,counter2);
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			setTimer2(100);
			counter1--;
			counter2--;
//			if(turnPedestrian_flag == 1) {
//						__HAL_TIM_SET_AUTORELOAD(&htim3, 5*value_buzzer);
//						__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0);
//					}
		}

		if(timer1_flag == 1) {
			status = YELLOW1_RED2_AUTO;
			setTimer1((redTimer-greenTimer)*100);
			counter1 = yellowTimer;
			counter2 = redTimer-greenTimer;
		}

		if(isButtonPressed(0)) {
			switchMode2();
		}
		break;
	case YELLOW1_RED2_AUTO:
		displayLed(YELLOW1_RED2);

		if(turnPedestrian_flag == 1) {
			__HAL_TIM_SET_AUTORELOAD(&htim3, 5*value_buzzer);
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0);
		}
		if(timer2_flag == 1) {
			int len= sprintf(str,"LED YELLOW   = %d    LED RED      = %d\r\n",counter1,counter2);
			HAL_UART_Transmit(&huart2,(uint8_t*) str, len, 1000);
			setTimer2(100);
			counter1--;
			counter2--;
//			if(turnPedestrian_flag == 1) {
//						__HAL_TIM_SET_AUTORELOAD(&htim3, 5*value_buzzer);
//						__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0);
//					}
		}

		if(timer1_flag == 1) {
			status = RED1_GREEN2_AUTO;
			setTimer1(greenTimer*100);
			counter1 = redTimer;
			counter2 = greenTimer;
		}

		if(isButtonPressed(0)) {
			switchMode2();
		}
		break;
	default:
		break;
	}
};
