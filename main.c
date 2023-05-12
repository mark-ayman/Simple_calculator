/*
* Simple_project.c
*
* Created: 10/6/2022 10:32:29 PM
* Author : marka
*/



#include <avr/io.h>
#include <stdlib.h>
#include <ctype.h>
#include "LCD.h"
#include "DIO.h"
#include "keypad.h"
#include "DIO_CFG.h"
#include "DIO_types.h"
#include "BitMath.h"


//Calculator Level 1
/*
int main(void)
{
	DIO_Init();
	LCD_Init();
	uint8 x = 1;
	uint8 arr[5];
	uint8 counter = 0 ;
	int result = 0;
	while(1)
	{
		x=GetKey();
		if(x!=STD_Low)
		{
			
			LCD_char(x);
			arr[counter]=x;
			//LCD_char(x);
			//int8 arr[10];
			//itoa(x,arr,10);
			//LCD_string(arr);	
			if(arr[3]=='=')
			{
			counter++;
			x=STD_Low;
			break;
			}
		counter++;						
		x=STD_Low;
		}
	}

	switch (arr[1])
	{
		case '+' :
		result=((int)(arr[0]-'0'))+((int)(arr[2]-'0')) ;
		LCD_char((uint8)(result)+'0');
		break;
		
		case '-' :
		result=((int)(arr[0]-'0'))-((int)(arr[2]-'0')) ;
		LCD_char((uint8)(result)+'0');
		break;
		
		case '*' :
		result=((int)(arr[0]-'0'))*((int)(arr[2]-'0')) ;
		LCD_char((uint8)(result)+'0');
		break;
		
		case '/' :
		result=((int)(arr[0]-'0'))/((int)(arr[2]-'0')) ;
		LCD_char((uint8)(result)+'0');
		break;
	}
	
}

*/
//Calculator Level 2

int main(void)
{
	DIO_Init();
	LCD_Init();
	uint8 x = 1;


	while(1)
	{
		x=GetKey();
		if(x!=STD_Low)
		{
			LCD_char(x);
			//int8 arr[10];
			//itoa(x,arr,10);
			//LCD_string(arr);
			x=STD_Low;
		}
	}
}
