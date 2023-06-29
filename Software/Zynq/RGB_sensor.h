/*
 * RGB_sensor.h
 *
 *  Created on: 2023年5月28日
 *      Author: 小霸王
 */

#ifndef SRC_RGB_SENSOR_H_
#define SRC_RGB_SENSOR_H_

s32 TCS34725_init(XIicPs * iicPs);
void TCS34725_getRGB(XIicPs * iicPs, float *r, float *g, float *b);

#endif /* SRC_RGB_SENSOR_H_ */
