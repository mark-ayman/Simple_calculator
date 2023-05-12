/*
* DIO_CFG.c
*
* Created: 10/6/2022 11:33:50 AM
*  Author: marka
*/

# include "DIO_CFG.h"

//Any level of signal should be determined as out put or input
//WE configured pins as default output and level is high
//Here we don't Put In Register DDR "aware with data direction" ,
DIO_PinCFG pin_cfg [] ={
	
	//Port A
	{output,STD_High}, //A0
	{output,STD_High}, //A1
	{output,STD_High}, //A2
	{output,STD_High}, //A3
	{output,STD_High}, //A4
	{output,STD_High}, //A5 
	{output,STD_High}, //A6 
	{output,STD_High}, //A7
	//Port B
	{output,STD_High}, //B0
	{output,STD_High}, //B1
	{output,STD_High}, //B2
	{output,STD_High}, //B3
	{output,STD_High}, //B4
	{output,STD_High}, //B5
	{output,STD_High}, //B6
	{output,STD_High}, //B7
	//Port C
	{output,STD_High}, //C0
	{output,STD_High}, //C1
	{output,STD_High}, //C2
	{output,STD_High}, //C3
	{output,STD_High}, //C4
	{output,STD_High}, //C5
	{output,STD_High}, //C6
	{output,STD_Low}, //C7
	//Port D
	{output,STD_High}, //D0
	{output,STD_High}, //D1
	{output,STD_High}, //D2
	{output,STD_High}, //D3
	{input,STD_Low}, //D4
	{input,STD_Low}, //D5
	{input,STD_Low}, //D6
	{input,STD_Low}  //D7
};

void DIO_Init(void){
	DIO_PortTypes Portx ;
	DIO_ChannelTypes BitNo ;
	DIO_ChannelTypes count = DIO_ChannelA0 ;
	for(count=DIO_ChannelA0;count<PINCOUNT;count++)
	{
		
		Portx=count/8 ;
		BitNo=count%8 ;
		
		switch (Portx)
		{
			case DIO_PORTA :
			if (pin_cfg[count].PinDir==output)
			{
				SetBit(DDRA_Reg,BitNo);
			}
			else
			{
				ClearBit(DDRA_Reg,BitNo);
			}
			break;
			
			
			case DIO_PORTB :
			if (pin_cfg[count].PinDir==output)
			{
				SetBit(DDRB_Reg,BitNo);
			}
			else
			{
				ClearBit(DDRB_Reg,BitNo);
			}
			break;
			
			
			case DIO_PORTC :
			if ((pin_cfg[count].PinDir==output))
			{
				SetBit(DDRC_Reg,BitNo);
			}
			else
			{
				ClearBit(DDRC_Reg,BitNo);
			}
			break;
			
			
			case DIO_PORTD :
			if (pin_cfg[count].PinDir==output)
			{
				SetBit(DDRD_Reg,BitNo);
			}
			else
			{
				ClearBit(DDRD_Reg,BitNo);
			}
			break;
		}
		
	}
}