/*
 * RGB_sensor.h
 *
 *  Created on: 2023��5��28��
 *      Author: С����
 */

#ifndef SRC_RGB_SENSOR_H_
#define SRC_RGB_SENSOR_H_

s32 TCS34725_init(XIicPs * iicPs);
void TCS34725_getRGB(XIicPs * iicPs, float *r, float *g, float *b);

#endif /* SRC_RGB_SENSOR_H_ */
