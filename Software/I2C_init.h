/*
 * I2C_init.h
 *
 *  Created on: 2023年5月29日
 *      Author: 小霸王
 */

#ifndef SRC_I2C_INIT_H_
#define SRC_I2C_INIT_H_

#include "xiicps.h"


u32 I2C_init(XIicPs *IicPs, u16 Iic_Dev_Id, u32 Iic_Rate);

#endif /* SRC_I2C_INIT_H_ */
