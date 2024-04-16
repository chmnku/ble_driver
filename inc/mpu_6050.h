/*
 * mpu_6050.h
 *
 *  Created on: Apr 9, 2024
 *      Author: chmnq
 */

#ifndef FW_INC_MPU_6050_H_
#define FW_INC_MPU_6050_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

#define ADDRESS_WHO_AM_I     0x68 // Register 117(WHO AM I)

/* Register Written(Transmit) by the Master */
#define ADDRESS_SMPLRT_DIV   0x19 // Register  25(Sample Rate Divider)
#define ADDRESS_GYRO_CONFIG  0x1B // Register  27(Gyroscope Configuration)
#define ADDRESS_ACCEL_CONFIG 0x1C // Register  28(Accelerometer Configuration)
#define ADDRESS_PWR_MGMT_1   0x6B // Register 107(Power Management 1)

/* Register read(Receive) by the Master */
/* Register 59 to 64 (Accelerometer Measurements) */
#define ADDRESS_ACCEL_XOUT_H 0x3B // ACCEL_XOUT[15:8]
#define ADDRESS_ACCEL_XOUT_L 0x3C // ACCEL_XOUT[7:0]
#define ADDRESS_ACCEL_YOUT_H 0x3D // ACCEL_YOUT[15:8]
#define ADDRESS_ACCEL_YOUT_L 0x3E // ACCEL_YOUT[7:0]
#define ADDRESS_ACCEL_ZOUT_H 0x3F // ACCEL_ZOUT[15:8]
#define ADDRESS_ACCEL_ZOUT_L 0x40 // ACCEL_ZOUT[7:0]

/* Register 67 to 72 (Gyroscope Measurements) */
#define ADDRESS_GYRO_XOUT_H  0x43 // GYRO_XOUT[15:8]
#define ADDRESS_GYRO_XOUT_L  0x44 // GYRO_XOUT[7:0]
#define ADDRESS_GYRO_YOUT_H  0x45 // GYRO_YOUT[15:8]
#define ADDRESS_GYRO_YOUT_L  0x46 // GYRO_YOUT[7:0]
#define ADDRESS_GYRO_ZOUT_H  0x47 // GYRO_ZOUT[15:8]
#define ADDRESS_GYRO_ZOUT_L  0x48 // GYRO_ZOUT[7:0]

#define RX_DATA_SIZE         1
#define TIMEOUT_MS           1000

typedef struct
{
  /* Raw Data */
  int16_t ac_x;
  int16_t ac_y;
  int16_t ac_z;
  int16_t gy_x;
  int16_t gy_y;
  int16_t gy_z;

  /* Convert Unit */
  /* Gravity */
  float ac_x_g;
  float ac_y_g;
  float ac_z_g;

  /* DPS */
  float gy_x_dps;
  float gy_y_dps;
  float gy_z_dps;
} IMU_Data;

void wake_IMU(I2C_HandleTypeDef* hi2c);
void set_SampleRate_IMU(I2C_HandleTypeDef* hi2c);
void config_Sensor_IMU(I2C_HandleTypeDef* hi2c);
void read_Sensor_IMU(I2C_HandleTypeDef* hi2c, IMU_Data* __my_mpu6050);

#endif /* FW_INC_MPU_6050_H_ */
