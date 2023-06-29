/*
 * gpio_init.c
 *
 *  Created on: 2023��5��28��
 *      Author: С����
 */

#include "gpio_init.h"
#include "gpio_pin.h"

#define GPIO_DEVICE_ID  XPAR_PS7_GPIO_0_DEVICE_ID


u32 GPIO_init(XGpioPs *GpioPs) {
	u32 Status;
	XGpioPs_Config *GPIOConfigPtr = XGpioPs_LookupConfig(GPIO_DEVICE_ID);
	Status = XGpioPs_CfgInitialize(GpioPs, GPIOConfigPtr, GPIOConfigPtr ->BaseAddr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*  0 for Input Direction, 1 for Output Direction */
	XGpioPs_SetDirectionPin(GpioPs, gas, 0);
	XGpioPs_SetDirectionPin(GpioPs, led, 1);
	XGpioPs_SetDirectionPin(GpioPs, light_sensor, 0);
	XGpioPs_SetDirectionPin(GpioPs, red_sensor, 0);
	XGpioPs_SetDirectionPin(GpioPs, fan, 1);
	XGpioPs_SetDirectionPin(GpioPs, buzzer, 1);

	//����gpio���ʹ�ܣ�0���ر�/1���򿪣�
	XGpioPs_SetOutputEnablePin(GpioPs, led, 1);
	XGpioPs_SetOutputEnablePin(GpioPs, fan, 1);
	XGpioPs_SetOutputEnablePin(GpioPs, buzzer, 1);


	return Status;
}

