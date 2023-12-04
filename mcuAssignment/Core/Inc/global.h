/*
 * global.h
 *
 *  Created on: Dec 2, 2023
 *      Author: Huy
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT					1
#define RED1_GREEN2_AUTO		2
#define RED1_YELLOW2_AUTO		3
#define GREEN1_RED2_AUTO		4
#define YELLOW1_RED2_AUTO		5

#define RED_MAN					10
#define YELLOW_MAN				11
#define GREEN_MAN				12
#define RED_MAN_MODIFY			13
#define YELLOW_MAN_MODIFY		14
#define GREEN_MAN_MODIFY		15

#define RED1_GREEN2				20
#define RED1_YELLOW2			21
#define GREEN1_RED2				22
#define YELLOW1_RED2			23

#define PES_ON					30
#define PES_OFF					31

#include "main.h"
#include "button.h"
#include "software_timer.h"
#include "displayLed.h"

extern int status;
extern int led_index;
extern int redTimer;
extern int yellowTimer;
extern int greenTimer;
extern int turnPedestrian_flag;
extern int statusPedestrian;

#endif /* INC_GLOBAL_H_ */
