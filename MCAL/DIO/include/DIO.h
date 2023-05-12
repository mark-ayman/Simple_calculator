/*
 * DIO.h
 *
 * Created: 10/6/2022 10:09:30 AM
 *  Author: marka
 */ 


#ifndef DIO_H_
#define DIO_H_


#define F_CPU 1000000UL
#include <util/delay.h>


#include "BitMath.h"
#include "DIO_HW.h"
#include "DIO_types.h"
#include "STD_Types.h"

//Make Pin of Port as Output and release level of output "NO NEED RETURN"
void DIO_Write_channel(DIO_ChannelTypes  ChannelId, STD_LevelTypes Level );
//Read level of Pin Of Port  "Need return type to return level type"
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes  ChannelId);

uint8 DIO_Read_Port (DIO_PortTypes PortId);

void DIO_Write_Port (DIO_PortTypes PortId,uint8 Port_Level);




#endif /* DIO_H_ */