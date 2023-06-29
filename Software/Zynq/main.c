#include "xparameters.h"
#include "xil_types.h"
#include "xstatus.h"
#include "xil_printf.h"
#include <stdio.h>
#include "door.h"
#include "window.h"
#include "gpio_init.h"
#include "gpio_pin.h"
#include "uart_init.h"
#include "I2C_init.h"
#include "RGB_sensor.h"
#include "TOF_sensor.h"
#include "platform.h"
#include "sleep.h"
#include "xscugic.h"
#include "xuartps.h"
#include "xuartps_hw.h"




#define esp32_uart_baseaddr	XPAR_PS7_UART_1_BASEADDR
#define IIC0_DEV_ID 		XPAR_PS7_I2C_0_DEVICE_ID // IIC0 device ID
#define IIC0_RATE 			100000  // standard mode is 100kbit/s
#define IIC1_DEV_ID 		XPAR_PS7_I2C_1_DEVICE_ID // IIC1 device ID
#define IIC1_RATE 			400000  // fast mode is 400kbit/s

static XGpioPs GpioPs;
static XUartPs UartPs;
static XIicPs Iic0_Ps;
static XIicPs Iic1_Ps;

u32 red_sensor_value=0;
u8 tof_value=0;
u32 light_sensor_value=0;
u32 gas_sensor_value=0;
u8 operation=0;
int led_auto_mode=0;
int leave_mode=0;
int color=0;
int know_gas=0;
int know_invasion=0;
int gas_alert = 0;
float r = 0;
float g = 0;
float b = 0;
u8 red = 0;
u8 green = 0;
u8 blue = 0;



//uart�жϴ�����
void Uart_intr_handle(void *call_back_ref)
{
    XUartPs *uart_instance_ptr = (XUartPs *)call_back_ref;
    u8 rec_data = 0;
    u32 isr_status;

    isr_status = XUartPs_ReadReg(uart_instance_ptr->Config.BaseAddress,XUARTPS_IMR_OFFSET);
    isr_status &= XUartPs_ReadReg(uart_instance_ptr->Config.BaseAddress,XUARTPS_ISR_OFFSET);

    if(isr_status & XUARTPS_IXR_RXOVR)
    {
        rec_data = XUartPs_RecvByte(uart_instance_ptr->Config.BaseAddress);
        XUartPs_WriteReg(uart_instance_ptr->Config.BaseAddress,XUARTPS_ISR_OFFSET,XUARTPS_IXR_RXOVR);
    }

    /*���ݴ���*/
    operation = rec_data;
    printf("recv_op : %d\r\n", operation);
}


void open_led() {
	XGpioPs_WritePin(&GpioPs, led, 0);
}

void close_led() {
	XGpioPs_WritePin(&GpioPs, led, 1);
}

void open_buzzer() {
	XGpioPs_WritePin(&GpioPs, buzzer, 1);
}

void close_buzzer() {
	XGpioPs_WritePin(&GpioPs, buzzer, 0);
}

void open_fan() {
	XGpioPs_WritePin(&GpioPs, fan, 1);
}

void close_fan() {
	XGpioPs_WritePin(&GpioPs, fan, 0);
}

int main(void)
{
	init_platform();

	// init GPIO
	if (GPIO_init(&GpioPs) != XST_SUCCESS) {
		printf("gpio failed\r\n");
		return XST_FAILURE;
	};

	// init UART
	if (Uart_Init(&UartPs) != XST_SUCCESS) {
		printf("uart failed\r\n");
		return XST_FAILURE;
	};

	// init I2C0
	if (I2C_init(&Iic0_Ps, IIC0_DEV_ID, IIC0_RATE) != XST_SUCCESS) {
		printf("I2C0 failed\r\n");
		return XST_FAILURE;
	};

	// init I2C1
	if (I2C_init(&Iic1_Ps, IIC1_DEV_ID, IIC1_RATE) != XST_SUCCESS) {
		printf("I2C1 failed\r\n");
		return XST_FAILURE;
	};

	// init TOF vl6180
	if (vl6180_init(&Iic0_Ps) != XST_SUCCESS) {
		printf("TOF failed\r\n");
		return XST_FAILURE;
	};

	// init RGB TCS34725
	if (TCS34725_init(&Iic1_Ps) != XST_SUCCESS) {
		printf("RGB failed\r\n");
		return XST_FAILURE;
	};

	// init door and window
	door_init();
	window_init();

	printf("all init successfully\r\n");


	while(1)
	{

		switch (operation) {
			case 1:
				close_led();  // �ص�
				break;
			case 2:
				open_led(); // ����
				break;
			case 3:
				close_door(); // ����
				break;
			case 4:
				open_door(); // ����
				break;
			case 5:
				close_window(); // �ش�
				break;
			case 6:
				open_window(); // ����
				break;
			case 7:
				led_auto_mode = 0; //�ر��Զ�ledģʽ
				break;
			case 8:
				led_auto_mode = 1; //�����Զ�ledģʽ
				break;
			case 9:
				leave_mode = 0; // �ر����ģʽ
				break;
			case 10:
				leave_mode = 1; // �������ģʽ
				break;
			case 11:
				know_gas = 1;   // �û���֪��ȼ����
				break;
			case 12:
				know_invasion = 1;  // �û���֪����
				break;
			case 13:
				color = 0;  // ������ɫ���
				break;
			case 14:
				color = 1;  // �ر���ɫ���
				break;
			default:
				break;
		}
		operation = 0;



		/* ���ģʽ */
		if(leave_mode) {
			close_led(); //�ص�
			close_door();// ����
			close_window();// �ش�

//			red_sensor_value = XGpioPs_ReadPin(&GpioPs, red_sensor);
//			if (red_sensor_value == 0) {
//				open_buzzer();  // ??????????
//				XUartPs_SendByte(esp32_uart_baseaddr, 11);// ?????????????
//			}
//			if (know_invasion) {
//				close_buzzer();
//				know_invasion=0;
//			}

			tof_value = vl6180_read_range(&Iic0_Ps);
			if (tof_value > 0 && tof_value <= 30) {
				open_buzzer();  // ����������
				XUartPs_SendByte(esp32_uart_baseaddr, 11);// ֪ͨ�û�
			}
			if (know_invasion) {
				close_buzzer();
				know_invasion=0;
			}
		}


		/* led�Զ�ģʽ */
		if(led_auto_mode) {
			light_sensor_value = XGpioPs_ReadPin(&GpioPs, light_sensor);
			if(light_sensor_value) {
				open_led();  // ����
				close_window(); // �ش�������
			} else {
				close_led(); //�ص�
				open_window(); // ����������
			}
		}


		/* ����ȼ���� */
		gas_sensor_value = XGpioPs_ReadPin(&GpioPs, gas);
		if(gas_sensor_value) {
			close_fan();
			gas_alert=0;
		} else {
			open_fan();  // ������
			open_window(); // ����
			if (gas_alert==0) {
				XUartPs_SendByte(esp32_uart_baseaddr, 10);// ֪ͨ�û�
				gas_alert=1;
			}
		}
//		if (know_gas) {
//			gas_alert=0;
//			know_gas=0;
//		}

		/* ��ɫ��� */
		if (color) {
			TCS34725_getRGB(&Iic1_Ps, &r, &g, &b);
			red = (u8)r;
			green = (u8)g;
			blue = (u8)b;
			XUartPs_SendByte(esp32_uart_baseaddr, 12);//������ɫ����
			XUartPs_SendByte(esp32_uart_baseaddr, red);
			XUartPs_SendByte(esp32_uart_baseaddr, green);
			XUartPs_SendByte(esp32_uart_baseaddr, blue);
			usleep(300000);
			printf("r : %d g : %d b : %d \r\n", red, green, blue);
		}


		usleep(400000);
	}
	cleanup_platform();
	return 0;
}
