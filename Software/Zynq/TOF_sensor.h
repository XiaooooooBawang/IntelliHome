/*
 * TOF_sensor.h
 *
 *  Created on: 2023��5��28��
 *      Author: С����
 */

#ifndef SRC_TOF_SENSOR_H_
#define SRC_TOF_SENSOR_H_

u32 vl6180_init(XIicPs * iicPs);
u8 vl6180_read_range(XIicPs * iicPs);

#endif /* SRC_TOF_SENSOR_H_ */
