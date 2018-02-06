/*********************************************************************************************
@file - conversion.c

@brief - conversion.c file a source file for conversions

This is the source file for conversion functions
The included function declarations are
1. itoa (integer to ASCII)
2. atoi (ASCII to integer)

@author - Scott McElroy

@date: Feburary 5, 2018

Created for ECEN5813
**********************************************************************************************/

#include "conversion.h"

/*********************************************************************************************/
/******************************itoa***********************************************************/
/**********************************************************************************************
@brief- This function changes an integer to an ASCII number

The ITOA function is passed 32 bit data and a pointer plus a base type.
It will convert the base type value to an ASCII number and it returns the length.
The function can handle signed values.

@param - NA
@return - Returns the length of the converted value
**********************************************************************************************/

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{   
}

/*********************************************************************************************/
/******************************atoi***********************************************************/
/**********************************************************************************************
@brief- This function changes an ASCII number to an integer number

The ATOI function is passed a pointer plus a base type and the number of digits in the ASCII
It will convert the base type value to an ASCII number and it returns the length.
value. The function returns a 32-bit value of the converted data.

@param - NA
@return - Returns the converted value
**********************************************************************************************/

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{   
}