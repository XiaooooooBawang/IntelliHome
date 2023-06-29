/*
 * door.h
 *
 *  Created on: 2023年5月30日
 *      Author: 小霸王
 */

#ifndef SRC_DOOR_H_
#define SRC_DOOR_H_

#include "PWM_Generator.h"

#define door	XPAR_PWM_GENERATOR_0_S_AXI_BASEADDR
#define period	2000000



void door_init();
void open_door();
void close_door();

void door_init() {
	PWM_GENERATOR_mDisableOutput(door);
	PWM_GENERATOR_mSetLoad(door, period);
	PWM_GENERATOR_mSetCompare(door, 100000); // 一开始为关门
	PWM_GENERATOR_mEnableOutput(door);
}

void open_door() {
	PWM_GENERATOR_mSetCompare(door, 150000 * 2);
	PWM_GENERATOR_mEnableOutput(door);
}


void close_door() {
	PWM_GENERATOR_mSetCompare(door, 100000);
	PWM_GENERATOR_mEnableOutput(door);
}



#endif /* SRC_DOOR_H_ */
