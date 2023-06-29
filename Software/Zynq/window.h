/*
 * window.h
 *
 *  Created on: 2023年5月30日
 *      Author: 小霸王
 */

#ifndef SRC_WINDOW_H_
#define SRC_WINDOW_H_

#include "PWM_Generator.h"


#define window	XPAR_PWM_GENERATOR_1_S_AXI_BASEADDR
#define period	2000000


void window_init();
void open_window();
void close_window();


void window_init() {
	PWM_GENERATOR_mDisableOutput(window);
	PWM_GENERATOR_mSetLoad(window, period);
	PWM_GENERATOR_mSetCompare(window, 150000 * 1);
	PWM_GENERATOR_mEnableOutput(window);
}

void open_window() {
	PWM_GENERATOR_mSetCompare(window, 150000 * 2);
	PWM_GENERATOR_mEnableOutput(window);
}

void close_window() {
	PWM_GENERATOR_mSetCompare(window, 150000 * 1);
	PWM_GENERATOR_mEnableOutput(window);
}

#endif /* SRC_WINDOW_H_ */
