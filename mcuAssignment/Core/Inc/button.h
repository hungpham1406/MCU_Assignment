/*
 * button.h
 *
 *  Created on: Dec 2, 2023
 *      Author: Huy
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonPressed();

void getKeyInput();
