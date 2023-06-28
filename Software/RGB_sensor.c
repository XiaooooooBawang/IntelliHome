/*
 * RGB_sensor.c
 *
 *  Created on: 2023��5��28��
 *      Author: С����
 */


#include "TCS34725_parameters.h"
#include "I2C_init.h"
#include "RGB_sensor.h"


#define SLAVE_ADDR			TCS34725_ADDRESS // TCS34725 7λ�豸��ַ 0x29

s32 i2c_writeReg(XIicPs * iicPs, u16 slaveAddr, u8 * writeBuf)
{
	s32 status;
	//IICд��8λ��������(0x100xxxxx��xxxxxΪ5λ�Ĵ�����ַ)��д��8λ����
	status = XIicPs_MasterSendPolled(iicPs, writeBuf, 2, SLAVE_ADDR);
	while (XIicPs_BusIsBusy(iicPs));  //�ȴ��ӿ�д�����
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	return status;
}

u8 i2c_readReg(XIicPs * iicPs, u16 slaveAddr, u8 * regAddr)
{
	s32 status;
	u8 registerData;

	//д��8λ��������(0x100xxxxx��xxxxxΪ5λ�Ĵ�����ַ)
	status = XIicPs_MasterSendPolled(iicPs, regAddr, 1, SLAVE_ADDR);
	while (XIicPs_BusIsBusy(iicPs));  //�ȴ��ӿ�д�����
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	//�ӼĴ����ж���8λ����
	status = XIicPs_MasterRecvPolled(iicPs, &registerData, 1, SLAVE_ADDR);
	while (XIicPs_BusIsBusy(iicPs));  //�ȴ��ӿ�д�����
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	return registerData;
}

u16 i2c_readReg16(XIicPs * iicPs, u16 slaveAddr, u8 * regAddr)
{
	s32 status;
	u8 registerData[2] = {0,0};

	//д��8λ��������(0x100xxxxx��xxxxxΪ5λ�Ĵ�����ַ)
	status = XIicPs_MasterSendPolled(iicPs, regAddr, 1, SLAVE_ADDR);
	while (XIicPs_BusIsBusy(iicPs));  //�ȴ��ӿ�д�����
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	//�ӼĴ����ж���8λ����
	status = XIicPs_MasterRecvPolled(iicPs, registerData, 2, SLAVE_ADDR);
	while (XIicPs_BusIsBusy(iicPs));  //�ȴ��ӿ�д�����
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	return ((u16)(registerData[1]) << 8) | ((u16)(registerData[0]) & 0xFF);
}

// ��8λ��ַ�ļĴ���д8λ�����ݣ���Ҫд������ֵ���ɣ�
s32 TCS34725_write_reg(XIicPs * iicPs, u8 regAddr, u8 data) {
	s32 status;
	u8 writeBuf[2] = {(u8)(TCS34725_COMMAND_BIT | regAddr), data};
	status = i2c_writeReg(iicPs, SLAVE_ADDR, writeBuf);
	if (status != XST_SUCCESS)
	{
//		printf("TCS34725 write register failed! \n");
		return XST_FAILURE;
	}
	return status;
}

// ��8λ��ַ�ļĴ�����8λ������
u8 TCS34725_read_reg(XIicPs * iicPs, u8 regAddr) {
	u8 reg_addr = (u8)(TCS34725_COMMAND_BIT | regAddr);
	return i2c_readReg(iicPs, SLAVE_ADDR, &reg_addr);
}

// ��8λ��ַ�ļĴ�����16λ������
u16 TCS34725_read_reg16(XIicPs * iicPs, u8 regAddr) {
	u8 reg_addr = (u8)(TCS34725_COMMAND_BIT | regAddr);
	return i2c_readReg16(iicPs, SLAVE_ADDR, &reg_addr);
}

// ��TCS34725���豸id��Ӧ��Ϊ0x44
u8 TCS34725_read_id(XIicPs * iicPs) {
	return TCS34725_read_reg(iicPs, TCS34725_ID);
}

// TCS34725ʹ��
void TCS34725_enable(XIicPs * iicPs)
{
	TCS34725_write_reg(iicPs, TCS34725_ENABLE, TCS34725_ENABLE_PON);
	TCS34725_write_reg(iicPs, TCS34725_ENABLE, TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN);
}

// TCS34725ʧ��
void TCS34725_disable(XIicPs * iicPs)
{
	u8 cmd = TCS34725_read_reg(iicPs, TCS34725_ENABLE);
	cmd = cmd & ~(TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN);
	TCS34725_write_reg(iicPs, TCS34725_ENABLE, cmd);
}

// TCS34725 ��ʼ��
s32 TCS34725_init(XIicPs * iicPs)
{
	u8 id = TCS34725_read_id(iicPs);
	if(id == TCS34725_DEVICE_ID)
	{
		TCS34725_write_reg(iicPs, TCS34725_ATIME, TCS34725_INTEGRATIONTIME_50MS);
		TCS34725_write_reg(iicPs, TCS34725_CONTROL, TCS34725_GAIN_1X);
		TCS34725_enable(iicPs);
		return XST_SUCCESS;
	} else {
		return XST_FAILURE;
	}

}

// ��ȡ16λ����ɫͨ������
u16 TCS34725_GetChannelData(XIicPs * iicPs, u8 reg) {
	return TCS34725_read_reg16(iicPs, reg);
}

u8 TCS34725_getRawData(XIicPs * iicPs, u16 *r, u16 *g, u16 *b, u16 *c) {
	u8 status = TCS34725_STATUS_AVALID;

	status = TCS34725_read_reg(iicPs, TCS34725_STATUS);

	if(status & TCS34725_STATUS_AVALID)
	{
		*c = TCS34725_GetChannelData(iicPs, TCS34725_CDATAL);
		*r = TCS34725_GetChannelData(iicPs, TCS34725_RDATAL);
		*g = TCS34725_GetChannelData(iicPs, TCS34725_GDATAL);
		*b = TCS34725_GetChannelData(iicPs, TCS34725_BDATAL);
		return 1;
	}
	return 0;
}

void TCS34725_getRGB(XIicPs * iicPs, float *r, float *g, float *b) {
  u16 red, green, blue, clear;
  u8 status = TCS34725_getRawData(iicPs, &red, &green, &blue, &clear);
  u32 sum = clear;

  // Avoid divide by zero errors ... if clear = 0 return black
  // ������δ������Ҳ���ɶ�
  if (clear == 0 || !status) {
    *r = *g = *b = 0;
    return;
  }

  float x = (float)red / sum * 255.0;
  float y = (float)green / sum * 255.0;
  float z = (float)blue / sum * 255.0;

  *r = x;
  *g = y;
  *b = z;
}


