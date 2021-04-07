/*
 * HAL_GY_NE06MV2_GPS_DRIVER.h
 *
 *  Created on: 5 avr. 2021
 *       Author: arthur chevrier-chahidi
 */

#ifndef INC_HAL_GY_NE06MV2_GPS_DRIVER_H_
#define INC_HAL_GY_NE06MV2_GPS_DRIVER_H_

#include "main.h"
#include "strings.h"
#include "string.h"

#define PACKET_SIZE 503 //packet is 503 octets maximum
#define TRAME_SIZE 84	//GSP is 83 octets maximum

extern uint8_t RX_Buffer[PACKET_SIZE];

typedef struct {
	uint8_t trame_GGA [84];
	uint8_t time [6];
	uint8_t latitude [15];
	uint8_t lat_dir;
	uint8_t longitude [15];
	uint8_t long_dir;
	uint8_t qualification;
	uint8_t chase [2];
	uint8_t HDO [3];
	uint8_t MSL_RAW [6];
	uint8_t MSL_RAW_U;
	uint8_t MSL [6];
	uint8_t MSL_U;
	uint8_t empty0;
	uint8_t empty1;
	uint8_t checksum[2];
}GPGGA_t;

typedef struct {
	uint8_t trame_GLL [84];
	uint8_t latitude [15];
	uint8_t lat_dir;
	uint8_t longitude [15];
	uint8_t long_dir;
	uint8_t time [6];
	uint8_t data_check;
}GPGLL_t;

typedef struct {
	uint8_t trame_GSA [84];
	uint8_t mode;
	uint8_t FIX_3D;
	uint8_t ID_SAT [36];
	uint8_t PDOP [3];
	uint8_t HDOP [3];
	uint8_t VDOP [3];
	uint8_t checksum[2];
}GPGSA_t;

typedef struct {
	uint8_t trame_GSV [84];
	uint8_t NB_GVS;
	uint8_t T;
	uint8_t SAT_INSIGHT [2];
	uint8_t ID_SAT_1ST [2];
	uint8_t ABHOZ [2];
	uint8_t AZIMUT [3];
	uint8_t signal_power[2];
	uint8_t checksum[2];
}GPGSV_t;

typedef struct {
	uint8_t trame_VTG [84];
	uint8_t cap_R [7];
	uint8_t cap_R_U;
	uint8_t cap_T [7];
	uint8_t cap_T_U;
	uint8_t speed_N [7];
	uint8_t speed_N_U;
	uint8_t speed_K [7];
	int8_t speed_K_U;
}GPVTG_t;

typedef struct {
	uint8_t trame_RMC [84];
	uint8_t time [6];
	uint8_t warning;
	uint8_t latitude [15];
	uint8_t lat_dir;
	uint8_t longitude [15];
	uint8_t long_dir;
	uint8_t speed_N [7];
	uint8_t cap_T [7];
	uint8_t day [6];
	uint8_t cap_R [7];
	uint8_t cap_dir;
	uint8_t checksum[2];
}GPRMC_t;

void pull_GSP_GPGGA_data(uint8_t *buffer,GPGGA_t *datastruct);
void pull_GSP_GPGLL_data(uint8_t *buffer,GPGLL_t *datastruct);
void pull_GSP_GPGSA_data(uint8_t *buffer,GPGSA_t *datastruct);
void pull_GSP_GPGSV_data(uint8_t *buffer,GPGSV_t *datastruct);
void pull_GSP_GPVTG_data(uint8_t *buffer,GPVTG_t *datastruct);
void pull_GSP_GPRMC_data(uint8_t *buffer,GPRMC_t *datastruct);

extern GPGLL_t GLL;
extern GPRMC_t RMC;
extern GPGGA_t GGA;
extern GPGSA_t GSA;
extern GPVTG_t VTG;
extern GPGSV_t GSV;

#endif /* INC_HAL_GY_NE06MV2_GPS_DRIVER_H_ */
