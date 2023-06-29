/*
 * I2C_init.c
 *
 *  Created on: 2023��5��29��
 *      Author: С����
 */

#include "I2C_init.h"


// ��ʼ��IIC��������IIC����
u32 I2C_init(XIicPs *IicPs, u16 Iic_Dev_Id, u32 Iic_Rate) {
	u32 status;
	// 1.������������ýṹ��
	XIicPs_Config *IicPs_Cfg = XIicPs_LookupConfig(Iic_Dev_Id);
	if (NULL == IicPs_Cfg) {
		return XST_FAILURE;
	}
	// 2.��ʼ��
	status = XIicPs_CfgInitialize(IicPs, IicPs_Cfg, IicPs_Cfg->BaseAddress);
	if(status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	/*
	 * �豸�Բ� Perform a self-test to ensure that the hardware was built correctly.
	 */
	status = XIicPs_SelfTest(IicPs);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	//����IIC����
	status = XIicPs_SetSClk(IicPs, Iic_Rate);
	if(status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}
