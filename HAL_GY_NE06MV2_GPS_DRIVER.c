/*
 * HAL_GY_NE06MV2_GPS_DRIVER.c
 *
 *  Created on: 5 avr. 2021
 *      Author: arthur chevrier-chahidi
 */

#include "HAL_GY_NE06MV2_GPS_DRIVER.h"

uint8_t RX_Buffer[PACKET_SIZE];
GPGLL_t GLL;
GPRMC_t RMC;
UART_HandleTypeDef huart1;

void pull_GPS_all_data(uint8_t *buffer){

}

void pull_GPS_GPGGA_data(uint8_t *buffer, GPGGA_t *datastruct){

}

void pull_GPS_GPGLL_data(uint8_t *buffer,GPGLL_t *datastruct){//DONE
	uint16_t i;
	uint8_t j = 0;
	uint8_t k = 0;
	uint8_t done = 0;
	uint8_t count = 0;
	for (i=0;i < PACKET_SIZE;i++){
		if(buffer[i] == '$' && buffer[i+1] == 'G' && buffer[i+2] == 'P' && buffer[i+3] == 'G' && buffer[i+4] == 'L' && buffer[i+5] == 'L'){
			while(buffer[i] != '\n'){
				datastruct->trame_GLL[j] = buffer[i];
				i++;
				j++;
				if(i >= PACKET_SIZE){
					break;
				}
				if(datastruct->trame_GLL[0] != '$'){
					break;
				}
			}
			if(datastruct->trame_GLL[0] == '$'){
				done = 1;
				i = 0;
				break;
			}
			else{
				done = 0;
				break;
				__NOP(); //error
			}
		}
	}
	__NOP();
	if (done == 1 && datastruct->trame_GLL[0] == '$'){
		for(i=0;i < strlen(datastruct->trame_GLL);i++){
			if (datastruct->trame_GLL[i] == ','){
				i++;
				k = 0;
				while(datastruct->trame_GLL[i] != ','){
					datastruct->latitude[k] = datastruct->trame_GLL[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_GLL[i] != ','){
					datastruct->lat_dir = datastruct->trame_GLL[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_GLL[i] != ','){
					datastruct->longitude[k] = datastruct->trame_GLL[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_GLL[i] != ','){
					datastruct->long_dir = datastruct->trame_GLL[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_GLL[i] != ','){
					datastruct->time[k] = datastruct->trame_GLL[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_GLL[i] != ','){
					datastruct->data_check = datastruct->trame_GLL[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				count++;
				if(count == 6){
					break;
				}
			}
		}
		__NOP();
	}
}

void pull_GPS_GPGSA_data(uint8_t *buffer,GPGSA_t *datastruct){

}
void pull_GPS_GPGSV_data(uint8_t *buffer,GPGSV_t *datastruct){

}
void pull_GPS_GPVTG_data(uint8_t *buffer,GPVTG_t *datastruct){

}
void pull_GPS_GPRMC_data(uint8_t *buffer,GPRMC_t *datastruct){//done
	uint16_t i;
	uint8_t j = 0;
	uint16_t k = 0;
	uint8_t done = 0;
	uint8_t count = 0;
	for (i=0;i <= PACKET_SIZE;i++){
		if((buffer[i] == '$' && buffer[i+1] == 'G' && buffer[i+2] == 'P' && buffer[i+3] == 'R' && buffer[i+4] == 'M' && buffer[i+5] == 'C')){
			while(buffer[i] != '\n' || i == PACKET_SIZE){
				datastruct->trame_RMC[j] = buffer[i];
				i++;
				j++;
				if(i >= PACKET_SIZE){
					break;
				}
				if(datastruct->trame_RMC[0] != '$'){
					break;
					}
				}
			if(datastruct->trame_RMC[0] == '$'){
				done = 1;
				i = 0;
				break;
			}
			else{
				done = 0;
				break;
				__NOP(); //error
			}
		}
	}
	if (done == 1 && datastruct->trame_RMC[0] == '$'){
		for(i=0;i < strlen(datastruct->trame_RMC);i++){
			if (datastruct->trame_RMC[i] == ','){
				i++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->time[k] = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->warning = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->latitude[k] = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->lat_dir = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->longitude[k] = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->long_dir = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->speed_N[k] = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->cap_T[k] = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->day[k] = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != ','){
					datastruct->cap_R[k] = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != '*'){
					datastruct->cap_dir = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				i++;
				count++;
				k = 0;
				while(datastruct->trame_RMC[i] != '\r'){
					datastruct->checksum[k] = datastruct->trame_RMC[i];
					k++;
					i++;
					if(i >= TRAME_SIZE)break;
				}
				count++;
				if(count == 12){
					break;
				}
			}
			if(datastruct->warning != 'A'){
				__NOP();
			}
		}
		__NOP();

	}
}

void clear_buffer(uint8_t *buffer,uint16_t size){
	for(uint16_t i = 0;i < size;i++){
		buffer[i] = 0;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	pull_GPS_GPGLL_data(RX_Buffer, &GLL);
	pull_GPS_GPRMC_data(RX_Buffer, &RMC);
	__NOP();
	//HAL_UART_Receive_IT(&huart1, RX_Buffer, PACKET_SIZE);
}



