/*
 * uart_init.c
 *
 *  Created on: 2023��4��24��
 *      Author: С����
 */

#include "uart_init.h"

static XScuGic InterruptController;

// һ����ʼ��uart
u32 Uart_Init(XUartPs *UartPs) {
	u32 Status;
	//��ʼ��
	Status = uart_init(UartPs, UART_Device_Id);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	};
	//UART��������ʼ��
	Status = uart_intr_init(&InterruptController, UartPs, UART_INT_IRQ_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	};

	return XST_SUCCESS;
}

//UART��ʼ��
u32 uart_init(XUartPs *UartInstPtr,u16 DeviceId) {
	u32 Status;

	/* Initialize the UART driver */
	XUartPs_Config *Config = XUartPs_LookupConfig(DeviceId);
	if (NULL == Config) {
		return XST_FAILURE;
	}

	Status = XUartPs_CfgInitialize(UartInstPtr, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	//���ô�����ֵ
	XUartPs_SetFifoThreshold(UartInstPtr, 1);

	/* Use normal mode */
	XUartPs_SetOperMode(UartInstPtr, XUARTPS_OPER_MODE_NORMAL);

	/* Set the baud rate */
	Status = XUartPs_SetBaudRate(UartInstPtr, 115200);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/* Check hardware build */
	Status = XUartPs_SelfTest(UartInstPtr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}


//UART��������ʼ��
u32 uart_intr_init(XScuGic *IntcInstancePtr,XUartPs *UartInstancePtr,u16 UartIntrId)
{
    //UART�������жϳ�ʼ��
    XScuGic_Config *IntcConfig;
    IntcConfig = XScuGic_LookupConfig(INTC_DEVICE_ID);
    XScuGic_CfgInitialize(IntcInstancePtr, IntcConfig,
                        IntcConfig->CpuBaseAddress);
    Xil_ExceptionInit();
    Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
                    (Xil_ExceptionHandler) XScuGic_InterruptHandler,
                    IntcInstancePtr);
    u32 status = XScuGic_Connect(IntcInstancePtr, UartIntrId,
                          (Xil_ExceptionHandler) Uart_intr_handle,
                          (void *) UartInstancePtr);
	if(status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
    XUartPs_SetInterruptMask(UartInstancePtr, XUARTPS_IXR_RXOVR);//����UART���жϴ�����ʽ
    XScuGic_Enable(IntcInstancePtr, UartIntrId);//ʹ���ж��豸
    Xil_ExceptionEnable();
    return XST_SUCCESS;
}
