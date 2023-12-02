/*
 * displayLed.h
 *
 *  Created on: Dec 2, 2023
 *      Author: Asus
 */

#ifndef INC_DISPLAYLED_H_
#define INC_DISPLAYLED_H_

#include "global.h"

void update7SEG(int index);
void scanLedBuffer();
void updateLedBufferVal(int val0, int val1, int val2, int val3);
void display7SEG(int counter);

void displayLed(int index);

const int MAX_LED;

extern int counter1;
extern int counter2;
extern int index_led;
extern int led_buffer[4];

#endif /* INC_DISPLAYLED_H_ */
