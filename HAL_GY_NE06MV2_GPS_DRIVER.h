/*
 * HAL_GY_NE06MV2_GPS_DRIVER.h
 *
 *  Created on: 5 avr. 2021
 *       Author: arthur chevrier-chahidi
 */

#ifndef INC_HAL_GY_NE06MV2_GPS_DRIVER_H_
#define INC_HAL_GY_NE06MV2_GPS_DRIVER_H_

#include "main.h"
#include "string.h"

#define TRAME_SIZE 82	//GSP is 82 caratere maximum

extern uint8_t RX_Buffer[1500];

typedef struct {
	uint8_t time [6];
	uint8_t latitude [15];
	uint8_t longitude [15];
	uint8_t qualification;
	uint8_t chase [2];
	uint8_t HDO [3];
	uint8_t MSL_RAW [6];
	uint8_t MSL [6];
	uint8_t empty0;
	uint8_t empty1;
	uint8_t checksum;
}GPGGA;

typedef struct {
	uint8_t latitude [15];
	uint8_t longitude [15];
	uint8_t time [6];
	uint8_t data_check;
}GPGLL;

typedef struct {
	uint8_t mode;
	uint8_t FIX_3D;
	uint8_t ID_SAT [25];
	uint8_t PDOP [4];
	uint8_t HDOP [4];
	uint8_t VDOP [4];
	uint8_t checksum;
}GPGSA;

typedef struct {
	uint8_t NB_GVS;
	uint8_t T;
	uint8_t SAT_INSIGHT [2];
	uint8_t ID_SAT_1ST [2];
	uint8_t ABHOZ [2];
	uint8_t AZIMUT [3];
	uint8_t signal_power;
	uint8_t checksum;
}GPGSV;

typedef struct {
	uint8_t cap_R [7];
	uint8_t cap_T [7];
	uint8_t speed_N [7];
	uint8_t speed_K [7];
}GPVTG;

typedef struct {
	uint8_t time [6];
	uint8_t latitude [15];
	uint8_t longitude [15];
	uint8_t speed_N [7];
	uint8_t cap_T [7];
	uint8_t day [6];
	uint8_t cap_R [7];
	uint8_t checksum;
}GPRMC;

void pull_GSP_GPGGA_data(UART_HandleTypeDef handle,uint8_t *buffer,GPGGA *data);
void pull_GSP_GPGLL_data(UART_HandleTypeDef handle,uint8_t *buffer,GPGLL *data);
void pull_GSP_GPGSA_data(UART_HandleTypeDef handle,uint8_t *buffer,GPGSA *data);
void pull_GSP_GPGSV_data(UART_HandleTypeDef handle,uint8_t *buffer,GPGSV *data);
void pull_GSP_GPVTG_data(UART_HandleTypeDef handle,uint8_t *buffer,GPVTG *data);
void pull_GSP_GPRMC_data(UART_HandleTypeDef handle,uint8_t *buffer,GPRMC *data);


#endif /* INC_HAL_GY_NE06MV2_GPS_DRIVER_H_ */
