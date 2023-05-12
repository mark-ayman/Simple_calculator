/*
 * LCD.h
 *
 * Created: 10/6/2022 6:43:30 PM
 *  Author: marka
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#define F_CPU 1000000UL
#include <util/delay.h>

#define LCD_RS DIO_ChannelB1
#define LCD_RW DIO_ChannelB2
#define LCD_E DIO_ChannelB3

#define LCD_DataPort DIO_PORTA 

void LCD_Init (void);
void LCD_Cmd (uint8 cmd);
void LCD_char (int8 data);
void LCD_string (int8* string);


#endif /* LCD_H_ */