///*
// * ble.c
// *
// *  Created on: Apr 11, 2024
// *      Author: chmnq
// */
//
//#include "ble.h"
//
//uint32_t rx_in  = 0;
//uint32_t rx_out = 0;
//uint32_t rx_len = 512;
//uint8_t rx_buf[512];
//
//uint32_t bleAvailable(void)
//{
//  uint32_t ret;
//
//  ret = (rx_in - rx_out) % rx_len;
//
//  return ret;
//}
//
//uint8_t readData(IMU_Data* pdata)
//{
//  int8_t lengh = sprintf(rx_buf, "{\"ac_x\":%d,\"ac_y\":%d,\"ac_z\":%d,\"gy_x\":%d,\"gy_y\":%d,\"gy_z\":%d,\"ac_x_g\":%.2f,\"ac_y_g\":%.2f,\"ac_z_g\":%.2f,\"gy_x_dps\":%.2f,\"gy_y_dps\":%.2f,\"gy_z_dps\":%.2f}",
//                          pdata->ac_x, pdata->ac_y, pdata->ac_z, pdata->gy_x, pdata->gy_y, pdata->gy_z, pdata->ac_x_g, pdata->ac_y_g, pdata->ac_z_g, pdata->gy_x_dps, pdata->gy_y_dps, pdata->gy_z_dps);
//}
//
//void bleDataIn(IMU_Data* pdata)
//{
//  uint32_t next_rx_in;
//
//  rx_buf[rx_in] = rx_data;
//
//  next_rx_in = (rx_in + 1) % rx_len;
//
//  if(next_rx_in != rx_out)
//  {
//    rx_in = next_rx_in;
//  }
//}
//
//void bleTransmit(UART_HandleTypeDef huart1, IMU_Data* pdata, uint16_t size, uint32_t timeOut)
//{
//  uint32_t pre_time;
//
//  uint8_t ret;
//
//  pre_time = millis();
//
//  while(1)
//  {
//    ret = HAL_UART_Transmit(huart1, pdata, size, timeOut);
//
//    if (ret == HAL_OK)
//    {
//      return length;
//    }
//    else if (ret == HAL_ERROR)
//    {
//      return 0;
//    }
//
//    if (millis() - pre_time >= 100)
//    {
//      return HAL_TIMEOUT;
//    }
//  }
//  return 0;
//}
//
