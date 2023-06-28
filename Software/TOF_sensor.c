/*
 * TOF_sensor.c
 *
 *  Created on: 2023��5��29��
 *      Author: С����
 */

#include "vl6180_parameters.h"
#include "I2C_init.h"
#include "TOF_sensor.h"


#define SLAVE_ADDR			VL6180_DEFAULT_I2C_ADDR // VL6180 7λ�豸��ַ 0x29


s32 i2c_writeReg3Byte(XIicPs * iicPs, u16 slaveAddr, u8 * writeBuf)
{
	s32 status;
	//IICд��Ĵ�����ַ��д������
	status = XIicPs_MasterSendPolled(iicPs, writeBuf, 3, SLAVE_ADDR);
	while (XIicPs_BusIsBusy(iicPs));  //�ȴ��ӿ�д�����
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	return status;
}

u8 i2c_readReg2Byte(XIicPs * iicPs, u16 slaveAddr, u8 * regAddr)
{
	s32 status ;
	u8 registerData;

	//�����豸��ַ���Ĵ�����ַ
	status = XIicPs_MasterSendPolled(iicPs, regAddr, 2, SLAVE_ADDR);
	while (XIicPs_BusIsBusy(iicPs));  //�ȴ��ӿ�д�����
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	//�ӼĴ����ж�������
	status = XIicPs_MasterRecvPolled(iicPs, &registerData, 1, SLAVE_ADDR);
	while (XIicPs_BusIsBusy(iicPs));  //�ȴ��ӿ�д�����
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	return registerData;
}

// ��16λ��ַ�ļĴ���д8λ������
s32 vl6180_write_reg(XIicPs * iicPs, u16 regAddr, u8 data) {
	s32 status;
	u8 writeBuf[3] = {(regAddr >> 8), (regAddr & 0xff), data};
	status = i2c_writeReg3Byte(iicPs, SLAVE_ADDR, writeBuf);
	if (status != XST_SUCCESS)
	{
//		printf("vl6180 write register failed! \n");
		return XST_FAILURE;
	}
	return status;
}

// ��16λ��ַ�ļĴ�����8λ������
u8 vl6180_read_reg(XIicPs * iicPs, u16 regAddr) {
	u8 reg_addr[2] = {(regAddr >> 8), (regAddr & 0xff)};
	return i2c_readReg2Byte(iicPs, SLAVE_ADDR, reg_addr);
}

u8 vl6180_read_id(XIicPs * iicPs) {
	return vl6180_read_reg(iicPs, VL6180_REG_IDENTIFICATION_MODEL_ID);
}

u32 vl6180_init(XIicPs * iicPs)
{
	vl6180_write_reg(iicPs, VL6180_REG_IDENTIFICATION_MODEL_ID, VL6180_DEFAULT_ID);
	u8 id = vl6180_read_id(iicPs);
	if(id == VL6180_DEFAULT_ID)
	{
		u16 config[39][2] = {
				{0x0207,0x01},
				{0x0208,0x01},
				{0x0096,0x00},
				{0x0097,0xfd},
				{0x00e3,0x00},
				{0x00e4,0x04},
				{0x00e5,0x02},
				{0x00e6,0x01},
				{0x00e7,0x03},
				{0x00f5,0x02},
				{0x00d9,0x05},
				{0x00db,0xce},
				{0x00dc,0x03},
				{0x00dd,0xf8},
				{0x009f,0x00},
				{0x00a3,0x3c},
				{0x00b7,0x00},
				{0x00bb,0x3c},
				{0x00b2,0x09},
				{0x00ca,0x09},
				{0x0198,0x01},
				{0x01b0,0x17},
				{0x01ad,0x00},
				{0x00ff,0x05},
				{0x0100,0x05},
				{0x0199,0x05},
				{0x01a6,0x1b},
				{0x01ac,0x3e},
				{0x01a7,0x1f},
				{0x0030,0x00},
				{0x0011,0x10},
				{0x010a,0x30},
				{0x003f,0x46},
				{0x0031,0xFF},
				{0x0040,0x63},
				{0x002e,0x01},
				{0x001b,0x09},
				{0x003e,0x31},
				{0x0014,0x24}
		};
		for (int i = 0; i < 31; i++) {
			vl6180_write_reg(iicPs, config[i][0], config[i][1]);
		}

		// Recommended : Public registers - See data sheet for more detail
		vl6180_write_reg(iicPs, config[31][0], config[31][1]);       // Enables polling for 'New Sample ready' when measurement completes
		vl6180_write_reg(iicPs, config[32][0], config[32][1]);       // Set the averaging sample period(compromise between lower noise and increased execution time)
		vl6180_write_reg(iicPs, config[33][0], config[33][1]);       // Sets the light and dark gain (uppernibble). Dark gain should not be changed. !�ϰ��ֽ�Ҫд��0x4	Ĭ��������1.0
		vl6180_write_reg(iicPs, config[34][0], config[34][1]);       // sets the # of range measurements after which auto calibration of system is performed
		vl6180_write_reg(iicPs, config[35][0], config[35][1]);       // Set ALS integration time to 100ms
		vl6180_write_reg(iicPs, config[36][0], config[36][1]);       // perform a single temperature calibration of the ranging sensor

		// Optional: Public registers - See data sheet for more detail
		vl6180_write_reg(iicPs, config[37][0], config[37][1]);    //�������	��ѯģʽ period to 100ms	ÿ��10ms->0-10ms
		vl6180_write_reg(iicPs, config[38][0], config[38][1]);      //��������	ALSģʽ to 500ms
		vl6180_write_reg(iicPs, config[39][0], config[39][1]);       // Configures interrupt on 'New Sample Ready threshold event'
		return XST_SUCCESS;
	} else {
		return XST_FAILURE;
	}

}

u8 vl6180_read_range(XIicPs * iicPs)
{
	u8 range = 0;
	//��������
	while(!(vl6180_read_reg(iicPs, VL6180_REG_RESULT_RANGE_STATUS) & 0x01));
	//���δ���ģʽ
	vl6180_write_reg(iicPs, VL6180_REG_SYSRANGE_START, 0x01);
	//�ȴ�������������ֵ�¼�(New Sample Ready threshold event)
	while(!(vl6180_read_reg(iicPs, VL6180_REG_RESULT_INTERRUPT_STATUS_GPIO) & 0x04));
	//����������
	range = vl6180_read_reg(iicPs, VL6180_REG_RESULT_RANGE_VAL);
	//��ȡ�����ݣ�����ж�λ 0111b �����range��als��Error�����жϱ�־
	vl6180_write_reg(iicPs, VL6180_REG_SYSTEM_INTERRUPT_CLEAR, 0x07);
	return range;
}

