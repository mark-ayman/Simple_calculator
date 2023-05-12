/*
* LCD.c
*
* Created: 10/6/2022 6:43:40 PM
*  Author: marka
*/

#include "LCD.h"



void LCD_Cmd (uint8 cmd){
	uint8 Port_value = 0 ;
	DIO_Write_channel(LCD_RW,STD_Low); // DIO_ChannelB1 for (cmd/data) as (0/1) level
	Port_value = DIO_Read_Port(LCD_DataPort);
	Port_value = ( (Port_value & 0x0F) | (cmd & 0xF0 )); //to prevent any coming command "cmd"  low enable of port"A"
	DIO_Write_Port(LCD_DataPort,Port_value);
	DIO_Write_channel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_Write_channel(LCD_E,STD_High);
	
	_delay_ms(5);
	// that  treat with cmd by two steps(highe_nable+lowe_nable)
	
	Port_value = DIO_Read_Port(LCD_DataPort);
	//           ( keep team port value part constant ) | second part of CMD
	Port_value = ( (Port_value & 0x0F) | (cmd << 4 ));
	DIO_Write_Port(LCD_DataPort,Port_value);
	DIO_Write_channel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_Write_channel(LCD_E,STD_High);
	
	_delay_ms(2);
}

void LCD_Init (void){
	DIO_Write_channel(LCD_RW,STD_Low);
	DIO_Write_channel(LCD_E,STD_High);
	_delay_ms(20);
	LCD_Cmd(0x33);
	_delay_us(100);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);
	LCD_Cmd(0x06);
	LCD_Cmd(0x0C);
	LCD_Cmd(0x01);
}

void LCD_char (int8 data){
	uint8 Port_value = 0 ;
	DIO_Write_channel(LCD_RS,STD_High);
	Port_value = DIO_Read_Port(LCD_DataPort);
	Port_value = ( (Port_value & 0x0F) | (data & 0xF0 ));
	DIO_Write_Port(LCD_DataPort,Port_value);
	DIO_Write_channel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_Write_channel(LCD_E,STD_High);
	
	_delay_ms(5);
	
	Port_value = DIO_Read_Port(LCD_DataPort);
	//           ( keep team port value part constant ) | second part of CMD
	Port_value = ( (Port_value & 0x0F) | (data << 4 ));
	DIO_Write_Port(LCD_DataPort,Port_value);
	DIO_Write_channel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_Write_channel(LCD_E,STD_High);
	
	_delay_ms(2);
}

void LCD_string (int8 * string){
	uint8 i =0 ;
	while (string[i] != '\0' ) 
	{
		LCD_char(string[i]);
		i++;
	}
}