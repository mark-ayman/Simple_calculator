/*
 * DIO_CFG.h
 *
 * Created: 10/6/2022 11:33:20 AM
 *  Author: marka
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

#define PINCOUNT 32

// Any PIN Should Determined "Configured" by two varuables { Direction of Data(inout / output)  ; Level of signal (High/Low)   }
//Any level of signal should be determined as out put or input
 	
typedef struct{
	DIO_DirTypes PinDir ;
	STD_LevelTypes Level ;
	
	}DIO_PinCFG;

void DIO_Init(void);

#endif /* DIO_CFG_H_ */