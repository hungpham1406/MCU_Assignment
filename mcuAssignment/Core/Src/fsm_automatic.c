/*
 * fsm_automatic.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Asus
 */

#include "fsm_automatic.h"


void switchMode2() {
	status = RED_MAN;
	counter1 = redTimer;
	setTimer2(100);
	setTimer4(25);

//	updateLedBufferVal(counter1/10, 2, counter1%10, 2);
}
int turnPedestrianLight = 0;
int statusPedestrian = 0;


int ledPedestrian = 0;
void displayLedPes (int ledPedestrian) {
	switch(ledPedestrian){

	case PES_GREEN:
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		break;
	case PES_RED:
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
		break;

	default:
		break;
	}
}
void fsm_pedestrian(){
	switch(statusPedestrian){
	case GREEN_ON:
		displayLedPes(PES_GREEN);
		if(timer6_flag == 1){
			statusPedestrian = RED_ON;
			setTimer6(redTimer*100);
		}
		break;
	case RED_ON:
		displayLedPes(PES_RED);
		if(timer6_flag == 1){
			statusPedestrian = GREEN_ON;
			setTimer6((greenTimer + yellowTimer)*100);
		}
		break;
	default:
		break;
	}
}
void fsm_automatic_run() {
	switch(status) {
	case INIT:
		//turnOffLed();

		status = RED1_GREEN2_AUTO;
		counter1 = redTimer;
		counter2 = greenTimer;


//		updateLedBufferVal(counter1/10, counter2/10, counter1%10, counter2%10);
		setTimer1(greenTimer*100);
		setTimer2(100);
		setTimer5(25);
		setTimer6(3);
		break;
	case RED1_GREEN2_AUTO:
		displayLed(RED1_GREEN2);
		if (isButtonPressed(3)) {
			statusPedestrian = GREEN_ON;
			setTimer6((greenTimer + yellowTimer)*100);
		}
		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			counter2--;
//			updateLedBufferVal(counter1/10, counter2/10, counter1%10, counter2%10);
		}

		if(timer1_flag == 1) {
			status = RED1_YELLOW2_AUTO;
			setTimer1((redTimer-greenTimer)*100);
			counter1 = redTimer-greenTimer;
			counter2 = yellowTimer;
//			updateLedBufferVal(counter1/10, counter2/10, counter1%10, counter2%10);
		}

		if(isButtonPressed(0)) {
			switchMode2();
		}

		break;
	case RED1_YELLOW2_AUTO:
		displayLed(RED1_YELLOW2);
		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			counter2--;
//			updateLedBufferVal(counter1/10, counter2/10, counter1%10, counter2%10);
		}

		if(timer1_flag == 1) {
			status = GREEN1_RED2_AUTO;
			setTimer1(greenTimer*100);
			counter1 = greenTimer;
			counter2 = redTimer;
//			updateLedBufferVal(counter1/10, counter2/10, counter1%10, counter2%10);
		}
//		if (isButtonPressed(3)) {
//					turnPedestrianLight = 1;
//				}

		if(isButtonPressed(0)) {
			switchMode2();
		}
		break;
	case GREEN1_RED2_AUTO:
		displayLed(GREEN1_RED2);

		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			counter2--;
//			updateLedBufferVal(counter1/10, counter2/10, counter1%10, counter2%10);
		}

		if(timer1_flag == 1) {
			status = YELLOW1_RED2_AUTO;
			setTimer1((redTimer-greenTimer)*100);
			counter1 = yellowTimer;
			counter2 = redTimer-greenTimer;
//			updateLedBufferVal(counter1/10, counter2/10, counter1%10, counter2%10);
		}
//		if (isButtonPressed(3)) {
//			turnPedestrianLight = 1;
//		}


		if(isButtonPressed(0)) {
			switchMode2();
		}
		break;
	case YELLOW1_RED2_AUTO:
		displayLed(YELLOW1_RED2);

		if(timer2_flag == 1) {
			setTimer2(100);
			counter1--;
			counter2--;
//			updateLedBufferVal(counter1/10, counter2/10, counter1%10, counter2%10);
		}

		if(timer1_flag == 1) {
			status = RED1_GREEN2_AUTO;
			setTimer1(greenTimer*100);
			counter1 = redTimer;
			counter2 = greenTimer;
//			updateLedBufferVal(counter1/10, counter2/10, counter1%10, counter2%10);
		}
//		if (isButtonPressed(3)) {
//			turnPedestrianLight = 1;
//		}

		if(isButtonPressed(0)) {
			switchMode2();
		}
		break;
	default:
		break;
	}
};
