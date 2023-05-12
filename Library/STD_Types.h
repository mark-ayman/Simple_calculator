/*
 * STD_Types.h
 *
 * Created: 10/4/2022 11:08:05 PM
 *  Author: marka
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char uint8 ;
typedef char int8 ;
typedef unsigned short uint16 ;
typedef short int16;

//To Determine Level of Pin as input or output as {0,1} 
//Determination of STD as {LOW,HIGH} is more Generic
//Then determine {Low , High} as {0,1} or vice versa
//???? ???? ?? input ??  output  ????? high ??? low
	
typedef enum{
	STD_Low=0,  
	STD_High
	}STD_LevelTypes;


#endif /* STD_TYPES_H_ */