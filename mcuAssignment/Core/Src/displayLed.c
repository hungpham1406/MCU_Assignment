/*
 * displayLed.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Asus
 */

#include "displayLed.h"
#include "main.h"
#include "fsm_automatic.h"
int counter1 = 0;
int counter2 = 0;
int index_led = 0;

void turnOffLed() {
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);

	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
}

void displayLed(int led_index) {
	switch(led_index) {
	case RED_MAN:
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);

			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
		break;
	case YELLOW_MAN:
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);

			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		break;
	case GREEN_MAN:
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);

			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		break;
	case RED1_GREEN2:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);

		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		if(turnPedestrian_flag == 1){
			// pedestrian light
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		}
		break;
	case RED1_YELLOW2:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);

		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		if(turnPedestrian_flag == 1){
			// pedestrian light
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		}
		break;

	case GREEN1_RED2:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);

		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
		if(turnPedestrian_flag == 1){
			// pedestrian light
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
		}
		break;
	case YELLOW1_RED2:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);

		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
		if(turnPedestrian_flag == 1){
		// pedestrian light
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
		}
		break;

	default:
		break;
	}
}

