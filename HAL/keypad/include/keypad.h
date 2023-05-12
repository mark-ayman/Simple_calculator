/*
 * keypad.h
 *
 * Created: 10/6/2022 10:37:27 PM
 *  Author: marka
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

#define r0 DIO_ChannelD0 
#define r1 DIO_ChannelD1 
#define r2 DIO_ChannelD2 
#define r3 DIO_ChannelD3 

#define c0 DIO_ChannelD4
#define c1 DIO_ChannelD5
#define c2 DIO_ChannelD6
#define c3 DIO_ChannelD7 

uint8 GetKey (void);

#endif /* KEYPAD_H_ */