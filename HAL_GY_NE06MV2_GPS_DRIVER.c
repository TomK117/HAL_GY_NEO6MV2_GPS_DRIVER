/*
 * HAL_GY_NE06MV2_GPS_DRIVER.c
 *
 *  Created on: 5 avr. 2021
 *      Author: arthur chevrier-chahidi
 */

#include "HAL_GY_NE06MV2_GPS_DRIVER.h"

uint8_t RX_Buffer[1500];

void pull_GSP_GPGGA_data(UART_HandleTypeDef handle,uint8_t *buffer, GPGGA *data){

}

void pull_GSP_GPGLL_data(UART_HandleTypeDef handle,uint8_t *buffer,GPGLL *data){

}
void pull_GSP_GPGSA_data(UART_HandleTypeDef handle,uint8_t *buffer,GPGSA *data){

}
void pull_GSP_GPGSV_data(UART_HandleTypeDef handle,uint8_t *buffer,GPGSV *data){

}
void pull_GSP_GPVTG_data(UART_HandleTypeDef handle,uint8_t *buffer,GPVTG *data){

}
void pull_GSP_GPRMC_data(UART_HandleTypeDef handle,uint8_t *buffer,GPRMC *data){

}
void clear_buffer(uint8_t *buffer,uint16_t size){
	for(uint16_t i = 0;i < size;i++){
		buffer[i] = 0;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	__NOP();
	//clear_buffer(RX_Buffer, 1500);
}



