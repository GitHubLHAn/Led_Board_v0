/*
 * rs485.h
 * Created on: 19-Apr-2024
 * Author: Le Huu An
 */

#ifndef RS485_H_
#define RS485_H_

#include<main.h>
/*Include the type of stm32*/
#include "stm32f1xx_hal.h"
#include "scan_led.h"



/*DEFINE*/
#define USART_RX_END 2
#define USART_READING 1
#define USART_WAIT 0

#define SIZE_RS485 16

#define MACH_SENSOR 0X01
#define MACH_LED	0x02
#define MACH_SAC	0x03

#define MAIN_OK		0x10
#define MAIN_ERROR	0x20

			

/************************************************************************************/
/*DECLARE STRUCT*/
	typedef struct{
		uint8_t rxBuff[SIZE_RS485];
		uint8_t txBuff[SIZE_RS485];
		uint32_t RxFlag;
		uint8_t STATE;
		uint8_t rxByte, rxPointer;
		uint8_t header, ender;					// header: 0xFE, ender: 0xFF
		uint8_t ID_board;							
		uint8_t cmd_type;							// loai lenh
		uint16_t cnt_mess_send;				// dem so ban tin da gui
		uint16_t cnt_mess_received;		// dem so ban tin nhan duoc
		
	}rs485_t;

	
/*DECLARE FUNCTION*/
void RS485_Read(rs485_t *pRx);
void RS485_Init(rs485_t *pRS, uint8_t ID);
	
void handle_dataRx(rs485_t *pRS, flag_irq_t *pFL);



/************************************************************************************/
#endif /* RS485_H_*/


