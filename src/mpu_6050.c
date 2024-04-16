/*
 * mpu_6050.c
 *
 *  Created on: Apr 9, 2024
 *      Author: chmnq
 */

#include "mpu_6050.h"

void wake_IMU(I2C_HandleTypeDef* hi2c)
{
 uint8_t data;

 HAL_I2C_Mem_Write(hi2c, ADDRESS_WHO_AM_I << 1,
                   ADDRESS_PWR_MGMT_1, I2C_MEMADD_SIZE_8BIT,
                   &data, RX_DATA_SIZE, TIMEOUT_MS);
 HAL_Delay(100);
}


void set_SampleRate_IMU(I2C_HandleTypeDef* hi2c)
{
  uint8_t bit = 0x07;

  HAL_I2C_Mem_Write(hi2c, ADDRESS_WHO_AM_I << 1,
                   ADDRESS_SMPLRT_DIV, I2C_MEMADD_SIZE_8BIT,
                   &bit, RX_DATA_SIZE, TIMEOUT_MS);
}

void config_Sensor_IMU(I2C_HandleTypeDef* hi2c)
{
  uint8_t bit = 0x00;

  HAL_I2C_Mem_Write(hi2c, ADDRESS_WHO_AM_I << 1,
                    ADDRESS_GYRO_CONFIG, I2C_MEMADD_SIZE_8BIT,
                    &bit, RX_DATA_SIZE, TIMEOUT_MS);
  HAL_I2C_Mem_Write(hi2c, ADDRESS_WHO_AM_I << 1,
                    ADDRESS_ACCEL_CONFIG, I2C_MEMADD_SIZE_8BIT,
                    &bit, RX_DATA_SIZE, TIMEOUT_MS);
}

void read_Sensor_IMU(I2C_HandleTypeDef* hi2c, IMU_Data* mpu6050)
{
  uint8_t data[6];

  HAL_I2C_Mem_Read(hi2c, ADDRESS_WHO_AM_I << 1,
                   ADDRESS_ACCEL_XOUT_H, I2C_MEMADD_SIZE_8BIT,
                   data, sizeof(data), TIMEOUT_MS);
  mpu6050->ac_x = (int16_t)(data[0] << 8 | data[1]);
  mpu6050->ac_y = (int16_t)(data[2] << 8 | data[3]);
  mpu6050->ac_z = (int16_t)(data[4] << 8 | data[5]);

  HAL_I2C_Mem_Read(hi2c, ADDRESS_WHO_AM_I << 1,
                   ADDRESS_GYRO_XOUT_H, I2C_MEMADD_SIZE_8BIT,
                   data, sizeof(data), TIMEOUT_MS);
  mpu6050->gy_x = (int16_t)(data[0] << 8 | data[1]);
  mpu6050->gy_y = (int16_t)(data[2] << 8 | data[3]);
  mpu6050->gy_z = (int16_t)(data[4] << 8 | data[5]);

  mpu6050->ac_x_g = mpu6050->ac_x / 16384.0;
  mpu6050->ac_y_g = mpu6050->ac_y / 16384.0;
  mpu6050->ac_z_g = mpu6050->ac_z / 16384.0;

  mpu6050->gy_x_dps = mpu6050->gy_x / 131.0;
  mpu6050->gy_y_dps = mpu6050->gy_y / 131.0;
  mpu6050->gy_z_dps = mpu6050->gy_z / 131.0;
}



