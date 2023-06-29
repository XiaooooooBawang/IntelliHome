/*
 * uart_init.h
 *
 *  Created on: 2023年4月24日
 *      Author: 小霸王
 */

#ifndef SRC_UART_INIT_H_
#define SRC_UART_INIT_H_

#include "xscugic.h"
#include "xuartps.h"
#include "xuartps_hw.h"

#define UART_Device_Id  XPAR_PS7_UART_1_DEVICE_ID  //串口设备ID
#define INTC_DEVICE_ID  XPAR_SCUGIC_SINGLE_DEVICE_ID  //中断ID
#define UART_INT_IRQ_ID     XPAR_XUARTPS_1_INTR  //串口中断ID


u32 Uart_Init();
u32 uart_init(XUartPs *UartInstPtr,u16 DeviceId);
u32 uart_intr_init(XScuGic *IntcInstancePtr,XUartPs *UartInstancePtr,u16 UartIntrId);
void Uart_intr_handle(void *call_back_ref);

#endif /* SRC_UART_INIT_H_ */
