/*
 * uart_init.h
 *
 *  Created on: 2023��4��24��
 *      Author: С����
 */

#ifndef SRC_UART_INIT_H_
#define SRC_UART_INIT_H_

#include "xscugic.h"
#include "xuartps.h"
#include "xuartps_hw.h"

#define UART_Device_Id  XPAR_PS7_UART_1_DEVICE_ID  //�����豸ID
#define INTC_DEVICE_ID  XPAR_SCUGIC_SINGLE_DEVICE_ID  //�ж�ID
#define UART_INT_IRQ_ID     XPAR_XUARTPS_1_INTR  //�����ж�ID


u32 Uart_Init();
u32 uart_init(XUartPs *UartInstPtr,u16 DeviceId);
u32 uart_intr_init(XScuGic *IntcInstancePtr,XUartPs *UartInstancePtr,u16 UartIntrId);
void Uart_intr_handle(void *call_back_ref);

#endif /* SRC_UART_INIT_H_ */
