/*
 * I2C_init.c
 *
 *  Created on: 2023年5月29日
 *      Author: 小霸王
 */

#include "I2C_init.h"


// 初始化IIC，并设置IIC速率
u32 I2C_init(XIicPs *IicPs, u16 Iic_Dev_Id, u32 Iic_Rate) {
	u32 status;
	// 1.查找外设的配置结构体
	XIicPs_Config *IicPs_Cfg = XIicPs_LookupConfig(Iic_Dev_Id);
	if (NULL == IicPs_Cfg) {
		return XST_FAILURE;
	}
	// 2.初始化
	status = XIicPs_CfgInitialize(IicPs, IicPs_Cfg, IicPs_Cfg->BaseAddress);
	if(status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	/*
	 * 设备自测 Perform a self-test to ensure that the hardware was built correctly.
	 */
	status = XIicPs_SelfTest(IicPs);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	//设置IIC速率
	status = XIicPs_SetSClk(IicPs, Iic_Rate);
	if(status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}
