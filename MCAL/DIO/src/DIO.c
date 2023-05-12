/*
* DIO.c
*
* Created: 10/6/2022 10:33:03 AM
*  Author: marka
*/

#include "DIO.h"

//Make Pin of Port as Output and release level of output "NO NEED RETURN"
void DIO_Write_channel(DIO_ChannelTypes  ChannelId, STD_LevelTypes Level ){
	
	DIO_PortTypes Portx= ChannelId/8;		    // Determine port of Micro_controller need to use
	DIO_ChannelTypes BitNo =  ChannelId%8;		// Determine which " PinNo == BitNo " of port of Micro_controller need to use
	
	switch (Portx)
	{
		case DIO_PORTA :
		if (Level == STD_High)
		{
			SetBit(PORTA_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTA_Reg,BitNo);
		}
		break;
		
		case DIO_PORTB :
		if (Level == STD_High)
		{
			SetBit(PORTB_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTB_Reg,BitNo);
		}
		break;
		
		case DIO_PORTC :
		if (Level == STD_High)
		{
			SetBit(PORTC_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTC_Reg,BitNo);
		}
		break;
		
		case DIO_PORTD :
		if (Level == STD_High)
		{
			SetBit(PORTD_Reg,BitNo);
		}
		else
		{
			ClearBit(PORTD_Reg,BitNo);
		}
		break;
		
	}
}
//Read level of Pin Of Port  "Need return type to return level type"
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes  ChannelId){
	
	DIO_PortTypes Portx= ChannelId/8;		    // Determine port of Micro_controller need to use
	DIO_ChannelTypes BitNo =  ChannelId%8;		// Determine which " PinNo == BitNo " of port of Micro_controller need to use
	STD_LevelTypes Bit_Value = STD_Low ;
	
	switch (Portx)
	{
		case DIO_PORTA :
		Bit_Value = GetBit(PINA_Reg,BitNo);
		break;
		
		case DIO_PORTB :
		Bit_Value = GetBit(PINB_Reg,BitNo);
		break;
		
		case DIO_PORTC :
		Bit_Value = GetBit(PINC_Reg,BitNo);
		break;
		
		case DIO_PORTD :
		Bit_Value = GetBit(PIND_Reg,BitNo);
		break;
		
	}
	return Bit_Value ;
}


//Read data f Port A from Register Port A
//Remember [Port_Register / PIN_Register / DDR_Register ] = [Reg_of_Data_Output  / Reg_of_data_input / Reg_of_Data_dir ]

uint8 DIO_Read_Port (DIO_PortTypes PortId){
	uint8 Data=0;
	switch (PortId)
	{
		case DIO_PORTA :
		Data = PORTA_Reg;
		break;
		
		case DIO_PORTB :
		Data = PORTB_Reg;
		break;
		
		case DIO_PORTC :
		Data = PORTC_Reg;
		break;
		
		case DIO_PORTD :
		Data = PORTD_Reg;
		break;
	}
	return Data ;
}

void DIO_Write_Port(DIO_PortTypes PortId,uint8 Port_Level){
	uint8 Data = Port_Level ;
	switch (PortId)
	{
		case DIO_PORTA :
		PORTA_Reg = Data;
		break;
		
		case DIO_PORTB :
		PORTB_Reg = Data;
		break;
		
		case DIO_PORTC :
		PORTC_Reg = Data;
		break;
		
		case DIO_PORTD :
		PORTD_Reg = Data;
		break;
	}
}