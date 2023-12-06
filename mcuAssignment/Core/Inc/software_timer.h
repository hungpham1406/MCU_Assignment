/*
 * software_timer.h
 *
 *  Created on: Dec 2, 2023
 *      Author: Huy
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;			//Count down the total value
extern int timer2_flag;			//Update counter value
extern int timer3_flag;			//Pedestrian light time
extern int timerMan;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
