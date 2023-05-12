/*
 * BitMath.h
 *
 * Created: 10/4/2022 11:07:15 PM
 *  Author: marka
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(Reg,BitNo) (Reg |=(1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg&=~(1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg^=(1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)

#endif /* BITMATH_H_ */