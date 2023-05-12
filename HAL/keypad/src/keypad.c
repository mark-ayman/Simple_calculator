/*
* keypad.c
*
* Created: 10/6/2022 10:37:40 PM
*  Author: marka
*/
#include "Keypad.h"

uint8 keypad_row[4]={r0,r1,r2,r3};
uint8 keypad_col[4]={c0,c1,c2,c3};
	
/*
uint8 keypad [4][4]={{'7','8','9','/'},
					 {'4','5','6','*'},
					 {'1','2','3','-'},
					 {'C','0','=','+'}};
					 
*/
uint8 keypad [4][4]={{ 7 , 8 , 9 ,'/'},
					 { 4 , 5 , 6 ,'*'},
					 { 1 , 2 , 3 ,'-'},
					 {'C', 0 ,'=','+'}};

uint8 GetKey (void){

	for (uint8 count = 0 ; count <4 ;count++){
		
		DIO_Write_channel(keypad_row[count],STD_High);// output 5v
		DIO_Write_channel(keypad_col[count],STD_High);// pull up res
	}
	for (uint8 i =0;i<4 ; i++)
	{
		
		DIO_Write_channel(keypad_row[i],STD_Low);
		for(uint8 j =0;j<4 ; j++)
		{
			if (DIO_ReadChannel(keypad_col[j])==STD_Low)
			{
				while (DIO_ReadChannel(keypad_col[j])==STD_Low);
					return keypad[i][j];
				
			}
		}
		DIO_Write_channel(keypad_row[i],STD_High);
	}
	return STD_Low ;
}